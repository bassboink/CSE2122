/* File: homework-4.cpp
   Created by: Mitchell Wendt
   Created on: 6/22/16
   Synopsis: This program functions as a calculator using a stack, which is created from a linked list. The calculator performs operations in the postfix (RPN) form (so 5 - 2 is instead written 5 2 - and 5 - (2 + 1) written 5 2 1 + -, etc.) This calculator only supports the binary operators +, -, *, and /. Only integers are supported (which means, only integer division is supported). Any invalid input (such as a, #, 5t3, etc.) will be ignored and the expression will be evaluated without the invalid terms. 
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Class definition of a node
class Node {
public:
    int value;                            //Stores the value of the node
    Node* pnext;                          //Pointer that points to the next node of the stack. Empty if the last node of the stack
};

//Class definition of the stack used in postfix operations
class Stack {
public:
    Node* first;                          //Pointer that points to the first node of the stack. Empty if the stack is empty
    int count;                            //Stores the number of values in the stack
};

//Function Prototypes
void push_back(Stack* stack, int value);
void pop_back(Stack* stack);
void delete_stack(Stack* stack);
bool isnum(char a);
bool isoperator(char a);
int determine_digit(char a);
int perform_operation(Stack *stack, char a, bool &div_by_0, bool &invalid_exp);

int main()
{
    bool keepGoing = true;                //Boolean that stores whether or not the user wants to make another calculation
    char keepGoingInput;                  //User input that is user to change keepGoing
    Stack* stack = new Stack;             //Stack of numbers used in postfix expressions
    stack->count = 0;                     //Set count to zero

    while (keepGoing) {
        cout << endl;

        string input;                     //Stores user input (one number/operator at a time)
        bool enteringExpression = true;   //Boolean that stores whether or not the user is entering more numbers/operators or not
        bool div_by_0 = false;            //Boolean that indicates that division by zero occurs in the expression
        bool invalid_exp = false;         //Boolean that becomes true when an operation is attempted with less than 2 values in the stack

        //Prompt the user for an expression
        cout << "Enter expression in postfix form. Enter '$' (without single quotes, separated by a space) when expression is finished: ";

        //Keep reading until a '.' is entered
        while (enteringExpression) {

            //Read in numbers/operators one at a time (NOTE: I am using cin with strings intentionally so that each time a space is entered, the string is split and the system reads in a different number or operator
            cin >> input;

            if (input.length() > 1) {

                bool isMultidigitNum = true;   //Boolean that indicates that the input is a multidigit or negative number

                //Check that the input is a multidigit or negative number (the only valid multicharacter input)
                for (int i = 0; i < input.length(); i++) {

                    //First character can be the negative sign as well, so first character evaluated separately
                    if (i == 0) {
                        if (!isnum(input[i]) && input[i] != '-') {
                            isMultidigitNum = false;
                        }
                    }
                    //Next characters can only be numbers
                    else if (!isnum(input[i])) {
                        isMultidigitNum = false;
                    }

                }

                if (isMultidigitNum) {
                    
                    int val = 0;             //Initial value of multidigit/negative number

                    //Negative multidigit number
                    if (input[0] == '-') {
                        for (int i = 1; i < input.length(); i++) {
                             int digit = determine_digit(input[i]);
                             val += digit * pow(10, (input.length() - 1 - i));
                        }
                        val = val * -1;
                    }

                    //Nonnegative multidigit number
                    else {
                        for (int i = 0; i < input.length(); i++) {
                            int digit = determine_digit(input[i]);
                            val += digit * pow(10, (input.length() - 1 - i));
                        }
                    }

                    //Push multidigit number onto the stack
                    push_back(stack, val);
                    
                }

            }

            else if (input.length() == 1) {
 
                //User enters '$' to finish entering expression
                if (input[0] == '$') {
                    enteringExpression = false;
                }

                //User enters a number
                else if (isnum(input[0])) {

                    //Determine digit and push it onto the stack
                    push_back(stack, determine_digit(input[0]));

                }

                //User enter an expression
                else if (isoperator(input[0])) {

                    //Determine the answer to the operation
                    int answer = perform_operation(stack, input[0], div_by_0, invalid_exp);

                    //Remove last 2 values
                    pop_back(stack);
                    pop_back(stack);

                    //Push answer onto stack
                    push_back(stack, answer);
                }

            }

        }

        //Display answer to user, or throw an error
        if (div_by_0) {
            cout << "Error: Div by 0." << endl << endl;
        }
        else if (invalid_exp) {
            cout << "Error: Operation attempted with less than 2 values in the stack" << endl << endl;
        }
        else if (stack->count == 1) {
            cout << "Answer: " << stack->first->value << endl << endl;
        }
        else {
            cout << "Error: Invalid postfix expression, or no expression entered. Only one value should remain in the stack." << endl << endl;
        }

        //Delete memory stored in the stack
        delete_stack(stack);

        //Ask the user if they would like to perform a new calculation
        cout << "Would you like to make another calculation? Enter 'Y' or 'y' for yes, 'N' or 'n' for no: ";
        cin >> keepGoingInput;

        //Check for valid input
        while (!((keepGoingInput == 'Y') || (keepGoingInput == 'y') || (keepGoingInput == 'N') || (keepGoingInput == 'n'))) {
            cout << "Invalid input. Please enter 'Y', 'y', 'N', or 'n' without the single quotes: ";
            cin >> keepGoingInput;
        }

        //End program if user says no
        if ((keepGoingInput == 'N') || (keepGoingInput == 'n')) {
            keepGoing = false;
            delete stack;
        }

    }

    return 0;
}

//This function adds a value at the top of the stack
//stack is the stack that the value is being added to
//value is the value being assigned to the new node of the stack
void push_back(Stack* stack, int value)
{
    //If the stack is empty
    if(stack->count == 0)
    {
        Node* n = new Node;
        n->value = value;

        //Assign the new node as the first node
        stack->first = n;
        stack->count++;
    }

    //If the stack isn't empty
    else
    {
        Node* n = new Node;
        n->value = value;

        //Determine the last node, make it point to the new node
        Node* nlast = stack->first;
        for(int j = 0; j < (stack->count - 1); j++)
        {
            nlast = nlast->pnext;
        }

        //Link new node and increment count
        nlast->pnext = n;
        stack->count++;
    }

    return;
}

//This function removes the top element of the stack 
//stack is the stack fo numbers used in postfix expressions
void pop_back(Stack* stack)
{
    //Only pop if there is an element to pop
    if (stack->count > 0) {

        //Find last node
        Node* nlast = stack->first;
        for(int j = 0; j < (stack->count - 1); j++)
        {
            nlast = nlast->pnext;
        }

        //Delete node and decrement count
        delete nlast;
        stack->count--;
    }

    return;
}

//This funciton deletes all the memory stored in the stack (used when the user asks to perform a new calculation)
//stack is the stack of numbers used in postfix expressions
void delete_stack(Stack* stack)
{
    Node* n = stack->first;
    Node* n2;
    for(int i = 0; i < stack->count; i++)
    {
        n2 = n;
        n = n->pnext;
        delete n2;
    }
    stack->count = 0;

    return;
}

//This function determines if a given character is a digit or not
//a is the character being checked
bool isnum(char a)
{
    if ((int(a) >= 48) && (int(a) <= 57)) {
        return true;
    }
    return false;
}

//This function determines if a given character is an operator (+, -, *, or /) or not
//a is the character being checked
bool isoperator(char a)
{
    if ((a == '+') || (a == '-') || (a == '*') || (a == '/')) {
        return true;
    }
    return false;
}

//This function determines the digit value of a character (preverified to be a digit)
//a is the character being converted to a digit
int determine_digit(char a)
{
    int digit;
    switch(int(a)) {
        case 48:
            digit = 0;
            break;
        case 49:
            digit = 1;
            break;
        case 50:
            digit = 2;
            break;
        case 51:
            digit = 3;
            break;
        case 52:
            digit = 4;
            break;
        case 53:
            digit = 5;
            break;
        case 54:
            digit = 6;
            break;
        case 55:
            digit = 7;
            break;
        case 56:
            digit = 8;
            break;
        case 57:
            digit = 9;
            break;
    }
        
    return digit;
}

//This function performs an operation from the stack and returns the answer from the operator
//stack is the stack of which the operation is occurring
//a is the operation being performed
//div_by_0 is a boolean that stores whether or not division by 0 occurs
//invalid_exp is a boolean that is true if an operation is attempted with 1 or 0 values in the stack
int perform_operation(Stack *stack, char a, bool &div_by_0, bool &invalid_exp)
{
    int answer;                   //Answer from the operation
    int first_val;                //First value of the operation
    int second_val;               //Second value of the operation

    //Must have 2 or more values in the stack to perform an operation
    if (stack->count >= 2) {

        //Determine first val (the second to last value in the stack)
        Node* nfirst = stack->first;
        for(int j = 0; j < (stack->count - 2); j++)
        {
            nfirst = nfirst->pnext;
        }
        first_val = nfirst->value;

        //Determine second val (the last value in the stack)
        Node* nsecond = stack->first;
        for(int j = 0; j < (stack->count - 1); j++)
        {
            nsecond = nsecond->pnext;
        }
        second_val = nsecond->value;

        //Addition
        if (a == '+') {
            answer = first_val+second_val;
        }

        //Subtraction
        else if (a == '-') {
            answer = first_val-second_val;
        }

        //Multiplication
        else if (a == '*') {
            answer = first_val*second_val;
        }

        //Division
        else {

            //Check for division by 0
            if (second_val == 0) {
                div_by_0 = true;
            }

            else {
                answer = first_val/second_val;
            }

        }

    }

    //When there's less than 2 values in the stack
    else {
        invalid_exp = true;
    }

    return answer;
}


