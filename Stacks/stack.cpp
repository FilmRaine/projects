// stack.cpp


#include <iostream>

using namespace std;

#include "stack.h"



void Stack::Push(char c){
    StackNodePtr newNode = new StackNode;

    newNode->info = c;
    newNode->next=top;

    top = newNode;
}

char Stack::Pop(){
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

bool Stack::IsEmpty(){
    return top == NULL;
}

void Stack::Print(){
    StackNodePtr p = top;

    cout << "{ ";
    while(p!=NULL){
        cout << p->info << ", ";
        p= p->next;
    }
    cout << "}";

}