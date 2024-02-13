/* P2Sets.cpp
 *
 * CS 121.Bolden.........Jackson Staples
 * 2/12/2024.............stap2053@vandals.uidaho.edu
 *
 * Brief description of program and objective.
 *---------------------------------------------------------------------
 */

#include<iostream>
#include<fstream>

using namespace std;


struct Node{
    string data;
    Node* next;
};

void intersection(Node*, Node*);// find intersection betweeen linked lists
void Union(Node*, Node*); // finds union between linked lists
void printlist(Node*); // displays linked list
void readfile(Node*&, string); // reads in file 
void wordcheck(Node*); //check for duplicate strings in file




int main(){
    Node* S1Head = NULL; //creating heads for list nodes. 
    Node* S2Head = NULL;
    string x = "s1.txt";
    string y = "s2.txt";
    readfile(S1Head, x);
    readfile(S2Head, y);
    printlist(S1Head);
    printlist(S2Head);


return 0;
}


void readfile(Node*& head, string z){
    string filename = z;
    ifstream infile;
    string temp;
    infile.open(filename.c_str());
    
 while(infile >> temp){
    Node* p = new Node;
    p-> data = temp;
    p-> next = head;
    head = p;
    }
    infile.close();
}

void printlist(Node* head){
  
   if(head == NULL){
    cout << "list is empty.\n" << endl;
    return;
   }
   
    Node* p = head;    
    while(p != NULL){
       cout << p-> data << endl;
        p = p-> next;
    }
    cout << "Code ran :)\n\n" << endl;
}