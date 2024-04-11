#include<iostream>

using namespace std;

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* right;
    BinaryTreeNode* left;
};

typedef struct  BinaryTreeNode *BinaryTreeNodePtr;

/*BinaryTreeNode* createnode(int newVal){
    BinaryTreeNode* newNode = new BinaryTreeNode;

    newNode->data = newVal;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
*/

bool IsLeaf(BinaryTreeNode* t){
    return((t->left == NULL) && (t->right == NULL));
}

int TreeSize(BinaryTreeNode* t){
    if(t == NULL){
        return 0;
    }else{
        return 1+
            TreeSize(t->left)+
            TreeSize(t->right);
    }
}

BinaryTreeNode* CreateNode( // c++ style of creating tree, creates a default for the 
    int newVal,
    BinaryTreeNode* leftPtr = NULL,
    BinaryTreeNode* rightPtr = NULL)
{
    BinaryTreeNode* newNode = new BinaryTreeNode;
   
    newNode->data = newVal;
    newNode->left = leftPtr;
    newNode->right = rightPtr;

    return newNode;
}