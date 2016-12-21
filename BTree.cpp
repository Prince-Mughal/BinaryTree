/*
.  #GCT
.  @PrinceMughal_ 
.  #LinuxC 
.   Date[DD-MM-YYYY] 22-12-2016
.   Time 01:02 am THUR
*/

#include <iostream>
#include <cstdlib> /* exit() */
using namespace std;

struct NODE{
    int data;
    NODE* leftChild;
    NODE* rightChild;};


NODE* getNewNode(const int& iData){
    NODE* newNode = new NODE;
    if(newNode == NULL){
        cerr<<"Error: Out of Memory."<<endl;
        exit(EXIT_FAILURE);
   }else{
        newNode->data = iData;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        return newNode;}
    }

/* Insert NODE */
void insertNodeHandler(NODE** iNode,const int& iData){
    /* Create new Node */
    NODE* newNode = getNewNode(iData);
    /* If Tree is not Exist*/
    if((*iNode) == NULL){
       *iNode = newNode;}
    /* Insert at left if Data is smallest than NODE's data */
    else if( iData < (*iNode)->data){
        insertNodeHandler(&((*iNode)->leftChild),iData);}
   /* Insert at right if Data is largest than NODE's data */
    else if( iData > (*iNode)->data){
        insertNodeHandler(&((*iNode)->rightChild),iData);}
  /* Display Warning when data is duplicate */
    else{
        cerr<<"Warning: Replication has been occured."<<endl;
        delete newNode;}
}


/* Pre-Order Traversal */
void preOrderHandler(NODE* iRoot){
    if(iRoot != NULL){
        cout<<iRoot->data<<' ';
        preOrderHandler(iRoot->leftChild);
        preOrderHandler(iRoot->rightChild);}
     }
/* Post-Order Traversal */
void postOrderHandler(NODE* iRoot){
     if(iRoot != NULL){
         postOrderHandler(iRoot->leftChild);
         postOrderHandler(iRoot->rightChild);
         cout<<iRoot->data<<' ';}
     }
/*  In-Order Traversal */
void inOrderHandler(NODE* iRoot){
     if(iRoot != NULL){
         inOrderHandler(iRoot->leftChild);
         cout<<iRoot->data<<' ';
         inOrderHandler(iRoot->rightChild);}
     }

int main(void){

/* Create Tree */
NODE* root = NULL;
/* Linear Array */
int Array[7]={20,9,53,79,5,15,11};
/* Insert Data into Tree */
for(int i = 0; i < 7; i++){
    insertNodeHandler(&root,Array[i]);}
/* inOrder Traversing */
cout<<"In-Order Traversal: "<<endl;
cout<<'\t';
inOrderHandler(root);
/* preOrder Traversing */
cout<<endl<<"Pre-Order Traversal: "<<endl;
cout<<'\t';
preOrderHandler(root);
cout<<endl<<"Post-Order Traversal: "<<endl;
cout<<'\t';
/* postOrder Traversing */
postOrderHandler(root);
cout<<endl;
return 0;}
