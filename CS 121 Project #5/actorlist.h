/*actorlist.h
 *
 * CS 121.Bolden...........Jackson Staples
 * 4/23/2024 .................stap2053@vandals.uidaho.edu
 *
 * Header file for the linked list class of the actors in a given show
 *---------------------------------------------------------------------
*/ 

#include <string>
#include <cstddef>

using namespace std;

#ifndef _ACTORLIST_H_
#define _ACTORLIST_H_

int IndexOf(char s[], char c);


void GetSubString(char s[], int start, int end, char res[]);
void RemoveBlanksFromString(char s[]);

typedef int DATA_TYPE;
typedef string STRING_TYPE;


 
typedef struct ActorList *AListPtr;

class ActorList{
   public:
    ActorList();

    void Add(string b);

    void Print();

    int* returnHead();

    bool InShow(AListPtr actorPtr, STRING_TYPE key);

    ActorList* getHead() const {
        return head;
    }

    string getName() const {
        return name;
    }

    ActorList* getNext() const{
        return next;
    }

    private:
        string name;
        ActorList* next;
        AListPtr head;

};










#endif