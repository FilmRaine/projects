/*stack.cpp 
 *
 * CS 121.Bolden...........Jackson Staples
 * 3/8/2024 .................stap2053@vandals.uidaho.edu
 *
 * Application of Stack class 
 *---------------------------------------------------------------------
*/ 


#include <iostream>

using namespace std;

#include "stack.h"



void Stack::Push(char c){
    StackNodePtr newNode = new StackNode;

    newNode->info = c;
    newNode->next=top;

    top = newNode;
}

char Stack::Pop(){ // removes item from top of stack 
    char c = 'A';
    StackNodePtr del; 

    if(top == NULL){
        cout << "error::pop: stack empty" << endl;
    }
    else{
        c= top->info;
        del = top;
        top = top->next;

        del->next = NULL;
         
        delete del;
    }
    return c;
}

bool Stack::IsEmpty(){ // returns value if top = NULL
    return top == NULL;
}

void Stack::Print(){ //iterate through stack and print values 
    StackNodePtr p = top;

    cout << "{ ";
    while(p!=NULL){
        cout << p->info << ", ";
        p= p->next;
    }
    cout << "}";

}

char Stack::Peek(){ // returns info from top item of stack 
    if(top == NULL){
        cout << "error" << endl;
        return 'Z';
    }
    else{
        return top-> info;
    }
    
}