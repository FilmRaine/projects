// This is where main, and functions that are not in the stack implementation


#include "stack.h"
#include<iostream>

using namespace std;


bool IsOpen(char symbol);
bool IsClose(char symbol);
bool Matches(char symbol, char openSymbol);

int main(){

    char symbol;
    char openSymbol;

    Stack s;
    bool balanced = true;

    cout << "enter your phrase goober and hit enter. " << endl;
    cin.get(symbol);

    while(symbol != '\n' && balanced){
        if(IsOpen(symbol)){
            s.Push(symbol);
        }
        else if(IsClose(symbol)){
            if(s.IsEmpty())
                balanced = false;
            else{
                openSymbol = s.Pop();
                balanced = Matches(symbol, openSymbol);
            }
        }
        cin.get(symbol);
    }
    if(balanced)
        cout << "phrase is balanced :3" << endl;
    else
        cout << "phrase is not balanced TwT" << endl;

    return 0;
}

bool IsOpen( char c ){
    if( (c == '(') )
        return true;
    else
        return false;
}

bool IsClose( char c ){
    if( (c == ')') )
        return true;
    else
        return false;
}


bool Matches( char symbol, char openSymbol ){
    return ( (openSymbol == '(') && (symbol == ')') );
}