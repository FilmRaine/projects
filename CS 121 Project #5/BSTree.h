/*BSTree.h
 *
 * CS 121.Bolden...........Jackson Staples
 * 4/23/2024 .................stap2053@vandals.uidaho.edu
 *
 * Header file for BST class
 *---------------------------------------------------------------------
*/ 

using namespace std;

#include<string>

#include "actorlist.h"

#ifndef _BSTREE_H_
#define _BSTREE_H_

class BinarySearchTree{
    private:
        typedef struct BSTreeNode{
            DATA_TYPE startyear;
            DATA_TYPE endyear;
            STRING_TYPE Category;
            STRING_TYPE SeriesName;
            BSTreeNode *leftPtr;
            BSTreeNode *rightPtr;
            ActorList *actorPtr;
    } *TreePtr;

    TreePtr rootPtr;

    void InitBSTree(){
        rootPtr = NULL;
    }

    bool IsLeaf (TreePtr treePtr);

    TreePtr SearchNodeInBST(TreePtr treePtr, STRING_TYPE searchKey);

    void PrintBST_InOrder(TreePtr treePtr);

public:
    BinarySearchTree() 
        {InitBSTree();}

    bool IsEmpty()
        { return(rootPtr == NULL);}

    void AddNode(STRING_TYPE newCategory, STRING_TYPE newSeries, DATA_TYPE sYear, DATA_TYPE eYear, ActorList* AListPtr);

    void SearchSeries(STRING_TYPE searchKey);

    int SearchActor(ActorList* namePtr, STRING_TYPE searchKey);

    void SearchNameInList(TreePtr treePtr, STRING_TYPE key, ActorList *namePtr);

    void findDateRange(TreePtr treePtr, DATA_TYPE startDate, DATA_TYPE endDate);

    void PrintTree();

    void PrintInOrder();

    int fActorList(STRING_TYPE title);

    ActorList* getActorPtr() const{
        return rootPtr->actorPtr;
    }

     BinarySearchTree::TreePtr getTreePtr() const  {
        return rootPtr;
    }

    void PrintActors(TreePtr treePtr, STRING_TYPE title);

};

#endif