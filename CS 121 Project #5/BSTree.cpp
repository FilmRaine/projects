/*BSTree.cpp
 *
 * CS 121.Bolden...........Jackson Staples
 * 4/23/2024 .................stap2053@vandals.uidaho.edu
 *
 * Implementation of the BST class, including functions
 *---------------------------------------------------------------------
*/ 

#include<iostream> 
using namespace std;

#include "BSTree.h"
#include "actorlist.h"

bool BinarySearchTree::IsLeaf(TreePtr treePtr){ // checks if node is a leaf
    return ((treePtr -> leftPtr = NULL) && (treePtr-> rightPtr ==NULL));
}

void BinarySearchTree::AddNode (STRING_TYPE newCategory, STRING_TYPE newSeries, DATA_TYPE sYear, DATA_TYPE eYear, ActorList* aListPtr ){
    TreePtr newPtr;

    newPtr = new BSTreeNode;

    newPtr -> Category = newCategory;
    newPtr-> SeriesName = newSeries; 
    newPtr-> startyear = sYear;
    newPtr-> endyear = eYear;
    newPtr-> actorPtr = aListPtr;  // pointer to linked list of actor names
    newPtr-> leftPtr = NULL;
    newPtr-> rightPtr = NULL;

    if(rootPtr == NULL){
        rootPtr = newPtr;
    }

    else{
        TreePtr treePtr = rootPtr;
        TreePtr targetNodePtr;

        while(treePtr != NULL){
            targetNodePtr = treePtr;
            if(newSeries == treePtr->SeriesName){ // ignore duplicates
                return;
            }
        else if(newSeries < treePtr->SeriesName){
            treePtr = treePtr->leftPtr;
        }
        
        else{
            treePtr = treePtr->rightPtr;
        }
      
      }
      
      if(newSeries < targetNodePtr->SeriesName){
        targetNodePtr-> leftPtr = newPtr;
      }else{
        targetNodePtr->rightPtr = newPtr;
      }

    }
}

// search for series
/*void BinarySearchTree::SearchSeries(STRING_TYPE searchKey){
    TreePtr searchPtr = NULL;

    searchPtr = SearchNodeInBST(rootPtr, searchKey);

    if(searchPtr != NULL){
        cout << "\n Node: " << searchPtr->SeriesName << " found in the BST" << endl;
    }
    else{
        cout << "\n Node: " << searchKey << " not found" << endl;

    }
}
*/

int BinarySearchTree::SearchActor(ActorList* namePtr, STRING_TYPE searchKey){ // check if actor is in a show
   
    SearchNameInList(rootPtr, searchKey, namePtr);
    return 1;
}

void BinarySearchTree::SearchNameInList(TreePtr current, STRING_TYPE searchKey, ActorList* namePtr) {
    if (current == NULL) {
        return;
    }

    // Check if the actor is in this show
    if (namePtr->InShow(current->actorPtr, searchKey)) {
        cout <<  "\n Actor is in " << current->SeriesName << endl << endl;
    }

    // Recur for left and right subtrees
    SearchNameInList(current->leftPtr, searchKey, namePtr);
    SearchNameInList(current->rightPtr,searchKey, namePtr );
}




BinarySearchTree::TreePtr
 BinarySearchTree::SearchNodeInBST(TreePtr treePtr, STRING_TYPE key)//normal search for a show title.
{
    if(treePtr != NULL){
        if(key == treePtr->SeriesName)
        {
            return treePtr;
        }
       
        else if(key < treePtr->SeriesName)
        {
          return  SearchNodeInBST(treePtr->leftPtr, key);
        }
       
        else
        {
          return  SearchNodeInBST(treePtr->rightPtr, key);
        }
    }

    else
        return NULL;
}



void BinarySearchTree::PrintTree(){ //redundancy for print function
    PrintBST_InOrder(rootPtr);
}

void BinarySearchTree::PrintInOrder(){ // redundancy for print function
    PrintBST_InOrder(rootPtr);
}

void BinarySearchTree::PrintBST_InOrder(TreePtr treePtr){
    if(treePtr != NULL){
        PrintBST_InOrder(treePtr->leftPtr); // start from left side of tree working to right side. 
        cout << treePtr->SeriesName << endl;

        PrintBST_InOrder(treePtr->rightPtr);

    }
}

void BinarySearchTree::findDateRange(TreePtr treePtr, DATA_TYPE startDate, DATA_TYPE endDate){

    if(treePtr == NULL){
        return;
    }
    if(treePtr->startyear >= startDate && treePtr->startyear <= endDate){ // if the show started between the given
        cout  << treePtr->SeriesName << endl << endl;
    }

    findDateRange(treePtr->leftPtr, startDate, endDate);
    findDateRange(treePtr->rightPtr, startDate, endDate);

}

int BinarySearchTree::fActorList(STRING_TYPE title){ // public function to access private member
    PrintActors(rootPtr, title);
    return 1;
}

/*void BinarySearchTree::PrintActors(TreePtr treePtr, STRING_TYPE title) 
{
    if (treePtr == NULL) {
        cout << "Show " << title << " not found in the tree" << endl;
        return;
    }

    if(treePtr != NULL){ // prints all actors in a show 
        if(title == treePtr->SeriesName){
        cout << "Actors in " << treePtr->SeriesName << ":" << endl;
                    cout << "treePtr->actorPtr: " << treePtr->actorPtr << endl; // Check the value of actorPtr
                        if (treePtr->actorPtr != NULL) {
                          cout << "head->name: " << treePtr->actorPtr->getHead()->getName() << endl; // Check the name of the first actor
                        }
                    
            if (treePtr->actorPtr != NULL) {
                treePtr->actorPtr->Print();
            } else {
                cout << "No actors found for this show." << endl;
            }

         } else if(title < treePtr->SeriesName)
        {
         //   cout << "left reached";
            PrintActors(treePtr->leftPtr, title); // check left subtree
        }
       
        else
        {
          //  cout << "right reached";
            PrintActors(treePtr->rightPtr, title); // check right subtree
        }
    }
        else {
        cout << "Show " << title << " not found in the tree" << endl;
         }

}
*/


void BinarySearchTree::PrintActors(TreePtr treePtr, STRING_TYPE title) 
{
    if (treePtr == NULL) {
        cout  << "Show " << title << " not found in the tree" << endl;
        return;
    }

    if (title == treePtr->SeriesName) {
        cout << endl << "Actors in " << treePtr->SeriesName << ":" << endl;
        AListPtr p = treePtr->actorPtr;
        while (p != NULL) {
            cout << p->getName() << endl;
            p = p->getNext();
        }
    } else if (title < treePtr->SeriesName) {
        PrintActors(treePtr->leftPtr, title); // check left subtree
    } else {
        PrintActors(treePtr->rightPtr, title); // check right subtree
    }
}