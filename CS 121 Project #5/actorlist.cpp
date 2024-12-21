/*actorlist.cpp
 *
 * CS 121.Bolden...........Jackson Staples
 * 4/23/2024 .................stap2053@vandals.uidaho.edu
 *
 * Implementation of the linked list for the actors. 
 *---------------------------------------------------------------------
*/ 

#include<iostream>

using namespace std;

#include"actorlist.h"

ActorList::ActorList(){
    head = NULL;
}

void ActorList::Add(string b){
    AListPtr n = new ActorList;

    n->name = b;
    n->next = NULL;

    if(head == NULL){
        head = n;
      //  cout << endl << "added first actor" << endl;
      //  cout << n->name << endl;    //debug output
        return;
    }

    AListPtr p = head;
    while(p-> next != NULL){
        p = p->next;
    }
    p->next = n;
   // cout << n->name << endl; // debug output
}



bool ActorList::InShow(AListPtr listPtr, STRING_TYPE key) { //check if given actor is in a show
    if (listPtr != NULL) {
        while (listPtr != NULL) {
            if (listPtr->name == key) {
                return true;
            }
            listPtr = listPtr->next;
        }
        return false;
    } else {
        cout << "list empty" << endl;
        return false; 
    }
}


void ActorList::Print(){
   cout << "reached print function" << endl; // debug output

    AListPtr p = head;
    if(p == NULL){
        cout << "LL is empty" << endl << endl; // debug output
    }
    while (p!= NULL){
        cout << p->name << endl;
        p = p->next; // iterate through list
    }
}