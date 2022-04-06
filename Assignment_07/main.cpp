// Date: 04/01/2022
// Description: Chapter 7 - Assignment
// Group 3: Alavi Isa, Eduardo Garcia, Matthew Batres, and Victor Huerta

#include <iostream>
#include "input.h" // checks input
#include "simpleCalculator.h"
#include "infixToPostfix.h"
#include "nQueensBacktrack.h"

using namespace std;
// Prototype
int menuOption();
void removeSpaces(string& infix);

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1:
        {
            string infix;
            cout << "\n\tEnter a fully parenthesized arithmetic expression: ";
            getline(cin, infix);
            removeSpaces(infix);
            simpleCalculator simp;
            simp.simpleCalculatorMain(infix);
        } break;
        case 2:
        {
            infixToPostfix i;
            string infix = "a+b*(c^d-e)^(f+g*h)-i";
            i.infixToPostfixMain(infix);
            infix = "((a+b)*(c+e))";
            i.infixToPostfixMain(infix);
            cout << "\n\n\tInput a fully parenthesized infix expression: ";
            getline(cin, infix);
            removeSpaces(infix);
            i.infixToPostfixMain(infix);
        } break;
        case 3:
        {
            nQueensBacktrack newGame;
            newGame.nQueensBacktrackMain();
        } break;
        default: cout << "\n\tERROR - Invalid option. Please re-enter.\n"; break;
        }
    } while (true);
    return EXIT_SUCCESS;
}

// return a valid option (0...3)
int menuOption()
{
    system("cls");
    cout << "\n\t=================================================================";
    cout << "\n\tCMPR131 Chapter 7: Applications using Stacks (04/01/2022)";
    cout << "\n\tDeveloped by Group 3: Alavi Isa, Eduardo Garcia, Matthew Batres, and Victor Huerta";
    cout << "\n\t=================================================================";
    cout << "\n\t\t1> Simple Calculator (problem 9, pg 391)";
    cout << "\n\t\t2> Translation of arithmetic expression (problem 10, pg 391)";
    cout << "\n\t\t3> n-Queens Problem (problem 11, pg 391-392)";
    cout << "\n\t-----------------------------------------------------------------";
    cout << "\n\t\t0> Exit";
    cout << "\n\t==================================================================\n";

    int option = inputInteger("\tOption: ", 0, 3);
    system("cls");

    return option;
}

//removing spaces from the string
void removeSpaces(string& infix)
{
    infix.erase(remove(infix.begin(), infix.end(), ' '), infix.end());
}
