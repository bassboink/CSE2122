/* File: main.cpp
   Created by: Mitchell Wendt
   Created on: 6/27/16
   Synopsis: This program evaluates a hard coded tree expression (sin(pi/4)+cos(8*2)) using recursion. The program then prompts the user infinitely for different expressions, which are then parsed, displayed, and evaluated. Operations supported are: +, -, *, /, ^, sin, cos, tan, log (natural log), and abs. This program requires the use of all other files in the hw4.zip file
*/

#include <iostream>
#include <string>
#include <cmath>
#include "math_tree.h"
#include "calc_parser.h"
using namespace std;

double evalOp(string op, double val)
{
    //Sin
    if (op == "sin") {
        return sin(val);
    }

    //Cos
    else if (op == "cos") {
        return cos(val);
    }

    //Tan
    else if (op == "tan") {
        return tan(val);
    }

    //Log
    else if (op == "log") {
        return log(val);
    }

    //Abs
    else if (op == "abs") {
        return abs(val);
    }

    //Default value if an incorrect call is made
    return 0.0;
}

double evalOp(string op, double val1, double val2)
{
    //Addition
    if (op == "+") {
        return val1 + val2;
    }

    //Subtraction
    else if (op == "-") {
        return val1 - val2;
    }

    //Multiplication
    else if (op == "*") {
        return val1 * val2;
    }

    //Division
    else if (op == "/") {
        return val1 / val2;
    }

    //Exponent
    else if (op == "^") {
        return pow(val1, val2);
    }

    //Default value if incorrect function call is made
    return 0.0;
}

double eval(Tree *tree)
{
    if (tree->right == NULL) {
        if (tree->left == NULL) {
            //value
            return tree->val;
        }
        else {
            //operation w/ 1 argument
            return evalOp(tree->op, eval(tree->left));
        }
    }
    else {
        //operation w/ 2 arguments
        return evalOp(tree->op, eval(tree->left), eval(tree->right));     
    }
}

// this is a global variable used by the parser
Tree* math_tree;

int main()
{
    // hand-code a tree for this expression:
    //  sin(3.14159/4.0)+cos(8.0*2.0)

    //Set root tree object (last operation to be performed)
    Tree p;
    p.op = "+";
    Tree* root = &p;

    //Create other tree objects and define their values/operations
    Tree sin;
    sin.op = "sin";

    Tree cos;
    cos.op = "cos";

    Tree d;
    d.op = "/";

    Tree m;
    m.op = "*";

    Tree vpi;
    vpi.val = 3.14159;

    Tree v4;
    v4.val = 4.0;

    Tree v8;
    v8.val = 8.0;

    Tree v2;
    v2.val = 2.0;

    //Link Tree Objects
    p.left = &sin;
    p.right = &cos;
    sin.left = &d;
    cos.left = &m;
    d.left = &vpi;
    d.right = &v4;
    m.left = &v8;
    m.right = &v2;

    //Set left and right pointers of values to null
    vpi.left = vpi.right = v4.left = v4.right = v8.left = v8.right = v2.left = v2.right = NULL;

    //Set right pointers of sin and cos to null
    sin.right = cos.right = NULL;

    // ...

    // here we print your hand-coded tree
    print_ascii_tree(root);

    // and evaluate the hand-coded tree (should equal -0.25)
    cout << "Result: " << eval(root) << endl << endl << endl;


    // this is the user-input loop; there is no need to change it
    while(true)
    {
        Parser parser;
        cout << "Enter expression: ";

        // this function gets the input and does the parsing
        parser.yyparse();

        // the yyparse() function sets the global variable math_tree
        // to a new tree; if that tree is NULL (no tree), just quit
        if(math_tree == NULL)
            break;

        // otherwise, print the tree
        print_ascii_tree(math_tree);

        // and evaluate it
        cout << "Result: " << eval(math_tree) << endl << endl;

        // reset the tree back to NULL before looping
        math_tree = NULL;
    }

    return 0;
}
