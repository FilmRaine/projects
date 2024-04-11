/* P2Sets.cpp
 *
 * CS 121.Bolden.........Jackson Staples
 * 2/12/2024.............stap2053@vandals.uidaho.edu
 *
<<<<<<< HEAD
 * Program designed to take two text files as input for data in a linked list, then print the intersection and union of both the linked lists.
=======
 * Program to take input of two text files, turn their contents into linked lists,
 * Then find the Union and Intersection between them. 
>>>>>>> refs/remotes/origin/main
 *---------------------------------------------------------------------
 */

#include<iostream>
#include<fstream>

using namespace std;


struct Node{ // Struct declaration
    string data;
    Node* next;
};


//Prototypes
Node* findintersection(Node*&, Node*&);// find intersection betweeen linked lists
Node* addlists(Node*&, Node*&); // Combines two linked lists
void printlist(Node*); // displays full list 
void readfile(Node*&, string); // reads in file 
<<<<<<< HEAD
Node* findUnion(Node*&, Node*&); // Finds union between linked lists
string alphanum(string); // Removes all aplhanumerical characters, except hypens and single apostrophes. 
bool isAlpha(char); 
void appendtolist(Node*&, string); // adds string as data memeber of linked list
bool searchlist(Node*&, string); // Checks if string passed to function is a member of data from the list passed to function.
void removeNode(Node*&, string); // Removes node if data of passed function matches string passed to function.
=======
Node* findUnion(Node*&, Node*&);
string alphanum(string);
bool isLetter(char);
void appendtolist(Node*&, string);
bool isMember(Node*&, string);
void removeNode(Node*&, string);
>>>>>>> refs/remotes/origin/main



int main(){
   // Initialize heads for list nodes. 
    Node* L1Head = NULL; 
    Node* L2Head = NULL;

 
   // assigns names of input files
    string x = "L1.txt"; 
    string y = "L2.txt";
    
    //reads in file
    readfile(L1Head, x); 
    readfile(L2Head, y);
    
    // Passes in L1 and L2
    Node* intersect = findintersection(L1Head, L2Head); 
    Node* Union = addlists(L1Head, L2Head);

    // Passes in intersect and Union
    findUnion(intersect, Union);    
    
    // Print lists
   cout << "\nUnion: " << endl;
    printlist(Union); 
   cout << endl;

   cout << "Intersection: " << endl;
   printlist(intersect);
   cout << endl;


return 0;
}


void readfile(Node* &head, string z){

string filename = z; 
ifstream infile;
string temp;

infile.open(filename.c_str());
    
 while(infile >> temp){
    temp = alphanum(temp);
<<<<<<< HEAD
    // Adds string to list if not already a member
    if(!searchlist(head, temp)){   
=======
    if(!isMember(head, temp)){   
>>>>>>> refs/remotes/origin/main
    appendtolist(head, temp);
        }
    }
    infile.close();
}

string alphanum(string stringMem){
    string buffer;
    
    // Iterate through list
    for(char c : stringMem){
<<<<<<< HEAD
        if(isAlpha(c)){ 
            buffer += c; // Writes strings to buffer ignoring alphanumerics
=======
        if(isLetter(c)){
            buffer += c;
>>>>>>> refs/remotes/origin/main
        }
    }
    return buffer;
}

<<<<<<< HEAD
bool isAlpha(char temp){ // Returns true value if char is alpha, hyphen or single apostrophe
=======
bool isLetter(char temp){
>>>>>>> refs/remotes/origin/main
    if((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || temp == '-'  || temp == '\''){
        return true;
    }
    return false;
}

void printlist(Node* head){
  
   if(head == NULL){
    cout << "list is empty.\n" << endl;
    return;
   }
   // start at front of list
    Node* p = head;    
    while(p != NULL){
       cout << p-> data << endl;
        p = p-> next;
    }
}

void appendtolist(Node*& head, string newData){
   // Start of list
    Node* p = new Node;


    p-> data = newData;
    p->next = head;
    if(head == NULL){ 
        head = p;
    }else{
        p-> next = head;
        head = p;
    }
}

<<<<<<< HEAD
bool searchlist(Node*& head, string search){
   // start of list
=======
bool isMember(Node*& head, string search){
>>>>>>> refs/remotes/origin/main
    Node* p = head;

    // iterate through list
    while(p != NULL){ 
        if(p->data == search){ // Checks if data was already in list
            return true;
        }
            p=p->next; 

    } 
    return false;
}

Node* findintersection(Node*& L1Head, Node*& L2Head){
    Node* intersect = NULL;
    string search;
    Node* p = L1Head;

    while(p != NULL){
        search = p -> data;
<<<<<<< HEAD
        // if string is in L1 & L2, add to intersect
        if(searchlist(L2Head, search)){
=======
        if(isMember(S2Head, search)){
>>>>>>> refs/remotes/origin/main
            appendtolist(intersect, search);
        }
        p = p-> next; 
    }
    return intersect;
}

Node* addlists(Node*& L1Head, Node*& L2Head){
    Node* Union = NULL;
    Node* p = L1Head;

<<<<<<< HEAD
    while(p != NULL){ // Adds data from L1 to Union
=======

    while(p != NULL){
>>>>>>> refs/remotes/origin/main
        appendtolist(Union, p -> data);
        p = p-> next;
    }
    
    p = L2Head; 

    while(p != NULL){ // Adds data from L2 to Union
        appendtolist(Union, p-> data);
        p = p-> next;
    }
    return Union;
}

void removeNode(Node*& head, string search){
    // Beginning of list
    Node* p = head;

<<<<<<< HEAD
    // Check first member of list
=======
if(head == NULL){
    cout << "Head is NULL.\n" << endl;
    return;
   }
>>>>>>> refs/remotes/origin/main
    if(p -> data == search){
        // Move to next node
        head = p -> next;
        // set previous node to NULL
        p-> next = NULL;
        delete(p);
        return;
    }

    // Check each member 
    while(p != NULL){
        Node* mNode = p-> next;
        if(mNode == NULL){
            return;
        }

        if(mNode -> data == search){
            // Move to next node, set previous to NULL 
            p -> next = mNode -> next;
            mNode -> next = NULL;
            delete(mNode);
            return; // Exits loop to prevent removing multiple of same string
        }
        p=p-> next;
    }
}

Node* findUnion(Node*& intersect, Node*& Union){ 
    Node* p = intersect;
    string search;
<<<<<<< HEAD
    while(p != NULL){ // Iterate through Union, removing single nodes if they match 1 intersect
=======

    while(p != NULL){
>>>>>>> refs/remotes/origin/main
        search = p-> data;
        removeNode(Union, search);
        p=p-> next;
    }
    return Union;
}