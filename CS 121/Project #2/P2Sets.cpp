/* P2Sets.cpp
 *
 * CS 121.Bolden.........Jackson Staples
 * 2/12/2024.............stap2053@vandals.uidaho.edu
 *
 * Program to take input of two text files, turn their contents into linked lists,
 * Then find the Union and Intersection between them. 
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
Node* findintersection(Node*&, Node*&);// find intersection betweeen linked lists
Node* addlists(Node*&, Node*&); // finds union between linked lists
void printlist(Node*); // displays full list 
void readfile(Node*&, string); // reads in file 
Node* findUnion(Node*&, Node*&);
string alphanum(string);
bool isLetter(char);
void appendtolist(Node*&, string);
bool isMember(Node*&, string);
void removeNode(Node*&, string);



int main(){
    Node* S1Head = NULL; //creating heads for list nodes. 
    Node* S2Head = NULL;
    string x = "L1.txt";
    string y = "L2.txt";
    
    readfile(S1Head, x); //reads in file
    readfile(S2Head, y);
    
    Node* intersect = findintersection(S1Head, S2Head);
    Node* Union = addlists(S1Head, S2Head);
    findUnion(intersect, Union);    
    
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
    if(!isMember(head, temp)){   
    appendtolist(head, temp);
        }
    }
    infile.close();
}

string alphanum(string stringMem){
    string buffer;
    for(char c : stringMem){
        if(isLetter(c)){
            buffer += c;
        }
    }
    return buffer;
}

bool isLetter(char temp){
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
   
    Node* p = head;    
    while(p != NULL){
       cout << p-> data << endl;
        p = p-> next;
    }
}

void appendtolist(Node*& head, string newData){
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

bool isMember(Node*& head, string search){
    Node* p = head;

    while(p != NULL){
        if(p->data == search){
            return true;
        
        }
        p=p->next;
        
    } 
    return false;
}

Node* findintersection(Node*& S1Head, Node*& S2Head){
    Node* intersect = NULL;
    string search;
    Node* p = S1Head;

    while(p != NULL){
        search = p -> data;
        if(isMember(S2Head, search)){
            appendtolist(intersect, search);
        }
        p = p-> next; 
    }
    return intersect;
}

Node* addlists(Node*& S1Head, Node*& S2Head){
    Node* Union = NULL;
    Node* p = S1Head;


    while(p != NULL){
        appendtolist(Union, p -> data);
        p = p-> next;
    }
    
    p = S2Head;

    while(p != NULL){
        appendtolist(Union, p-> data);
        p = p-> next;
    }
    return Union;
}

void removeNode(Node*& head, string search){
    Node* p = head;

if(head == NULL){
    cout << "Head is NULL.\n" << endl;
    return;
   }
    if(p -> data == search){
        head = p -> next;

        p-> next = NULL;
        delete(p);
        return;
    }

    while(p != NULL){
        Node* mNode = p-> next;
        if(mNode == NULL){
            return;
        }
        if(mNode -> data == search){
            p -> next = mNode -> next;
            mNode -> next = NULL;
            delete(mNode);
            return;
        }
        p=p-> next;
    }
}

Node* findUnion(Node*& intersect, Node*& Union){
    Node* p = intersect;
    string search;

    while(p != NULL){
        search = p-> data;
        removeNode(Union, search);
        p=p-> next;
    }
    return Union;
}