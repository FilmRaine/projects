/* stack.h
 *
 * CS 121.Bolden...........Jackson Staples
 * 3/8/2024 .................stap2053@vandals.uidaho.edu
 *
 * Header file 
 *---------------------------------------------------------------------
*/
#ifndef STACK_H
#define STACK_H

#include <cstddef>

class Stack
{
    public: 
        Stack(){
            top = NULL;
        }

        void Push(char c);
        char Pop();
        bool IsEmpty();
        void Print();
        char Peek();
    private:
        struct stackNode
        {
            char info;
            struct stackNode* next;
        };
        typedef struct stackNode StackNode;
        typedef StackNode *StackNodePtr;
        StackNodePtr top;
};
#endif

