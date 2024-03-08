/* In2PostFix.cpp
 *
 * CS 121.Bolden...........Jackson Staples
 * 3/8/2024 .................stap2053@vandals.uidaho.edu
 *
 * Program to take a user-input equation and reformat it to postfix. 
 *---------------------------------------------------------------------
 */

#include "stack.h"
#include<iostream>
#include<string>

using namespace std;

// Prototypes
bool IsOpen(char c);
bool IsClose(char c);
bool IsOperator(char c);
int OpOrder(char c);


int main(){

    string symbol; // User Input
    string postfix; // The output postfix string

    Stack s;
    while(symbol != "Quit" && symbol != "quit" && symbol != "QUIT"){

    cout << "enter your phrase goober and hit enter. " << endl;
    cout << "Or, type 'quit' and hit enter if you would like to exit the program. " << endl; 
         getline(cin, symbol); // take user input

    for( char c: symbol){ //iterate through each character in the user-given string

        if(c >= '0' && c <= '9'){  // if character is number
            postfix += c; // add to postfix string
        }
        
        else if(IsOpen(c)){ 
            s.Push('('); // push open parenthesis onto stack
        }
        else if(IsOperator(c)){ 
            while(!s.IsEmpty() && !IsOpen(c) && OpOrder(c) <= OpOrder(s.Peek())){ // while stack not empty, and operator is of equal or lesser
                postfix += s.Pop();                                               // value on stack, add to postfix and pop. 
            }
            s.Push(c); // push operator onto stack
        }
        else if(IsClose(c)){ 
            while(!IsOpen(c) && !IsOpen(s.Peek()) ){ // if stack is not empty, and top of stack is not open parenthesis, add to postfix and pop.
            postfix += s.Pop();
        }
        s.Pop(); // removes the matching open parenthesis
        }
    }
    while(!s.IsEmpty()){
        postfix += s.Pop(); //removes remaining operators
    }
    
    cout << postfix << endl; // print postfix!
    postfix = ' ';
    }

};


bool IsOpen( char c ){ //Checks if char is Open Parenthesis
    if( (c == '(') )
        return true;
    else
        return false;
}

bool IsClose( char c ){ // checks if char is closed parethesis
    if( (c == ')') )
        return true;
    else
        return false;
}


bool IsOperator(char c){ // checks if char is an operator
    if(c == '-' || c == '+' || c == '/' || c == '*')
        return true;
    else    
        return false;
}


int OpOrder(char c){ // sets precedence for operators
    if(c == '/' || c == '*'){
        return 2;
}
    else if(c == '-' || c == '+'){
        return 1;
    }
    return 0;
}