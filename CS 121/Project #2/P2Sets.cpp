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


//Prototypes
void findintersection(Node*, Node*);// find intersection betweeen linked lists
void findUnion(Node*, Node*); // finds union between linked lists
void printlist(Node*); // displays full list 
void readfile(Node*&, string); // reads in file 
void wordcheck(Node*&); //check for duplicate strings in file




int main(){
    Node* S1Head = NULL; //creating heads for list nodes. 
    Node* S2Head = NULL;
    string x = "s1.txt";
    string y = "s2.txt";
   

    readfile(S1Head, x); //reads in file
    readfile(S2Head, y);
    wordcheck(S1Head);
    wordcheck(S2Head);
    printlist(S1Head); // prints full list
    printlist(S2Head);
   
   // Node* Intersect = findintersection(S1Head, S2Head);
   // Node* Union = findUnion(S1Head,S2Head);
    

   cout << "Union: " << endl;
  // printlist(Union);
   cout << endl;

   cout << "Intersection: " << endl;
  // printlist(Intersect);
   cout << endl;


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

