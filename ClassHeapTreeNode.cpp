#include <iostream>
#include "ClassRecord.h"
#include "ClassHeapTreeNode.h"
using namespace std;

HeapTreeNode::HeapTreeNode(Record* recordPtr) {
    this->recordPtr = recordPtr;
    this->rightNode = NULL;
    this->leftNode = NULL;
    this->parentNode = NULL;
    this->prevTail = NULL;
    this->occurences = 1;
}

HeapTreeNode::~HeapTreeNode(){
//     delete this->recordPtr;
//     delete this->leftNode;
//     delete this->rightNode;
}

Record* HeapTreeNode::getRecordPtr() {
    return this->recordPtr;
}

HeapTreeNode* HeapTreeNode::getParentNode() {
    return this->parentNode;
}

HeapTreeNode* HeapTreeNode::getRightNode() {
    return this->rightNode;
}

HeapTreeNode* HeapTreeNode::getLeftNode() {
    return this->leftNode;
}

HeapTreeNode* HeapTreeNode::getPrevTail() {
    return this->prevTail;
}

int HeapTreeNode::getOccurences()
{
   return this->occurences;
}

void HeapTreeNode::setRecordPtr(Record* recordPtr){
    this->recordPtr = recordPtr;
}

void HeapTreeNode::setParentNode(HeapTreeNode* Node){
    this->parentNode = Node;
}

void HeapTreeNode::setRightNode(HeapTreeNode* Node){
    this->rightNode = Node;
}

void HeapTreeNode::setLeftNode(HeapTreeNode* Node){
    this->leftNode = Node;
}

void HeapTreeNode::setPrevTail(HeapTreeNode* Node){
    this->prevTail = Node;
}

void HeapTreeNode::setOccurences(int newOccurences){
    this->occurences = newOccurences;
}

//CLASS FUNCTIONS
void HeapTreeNode::maxHeapify(){
    if(this->getParentNode() != NULL){
        if(this->getParentNode()->getOccurences() < this->getOccurences()){
            this->swap(this->getParentNode());
            this->getParentNode()->maxHeapify();
        }
    }
}

void HeapTreeNode::swap(HeapTreeNode* newNode){
    int temp = this->getOccurences();
    this->setOccurences(newNode->getOccurences());
    newNode->setOccurences(temp);

    Record* tempPtr = this->getRecordPtr();
    this->setRecordPtr(newNode->getRecordPtr());
    newNode->setRecordPtr(tempPtr);
}

bool HeapTreeNode::contains(Record* recordPtr) {
    if (this == NULL){
        return false;
    }

    if (this->recordPtr->getCountry() == recordPtr->getCountry() && this->recordPtr->getDisease() == recordPtr->getDisease()){
        return true;
    }

     /* then recur on left sutree */
    bool res1 = this->leftNode->contains(recordPtr); 
  
    if(res1) return true; // node found, no need to look further 
  
    /* node is not found in left, so recur on right subtree */
    bool res2 = this->rightNode->contains(recordPtr);
  
    return res2;
}

void HeapTreeNode::increaseKey(){
    this->occurences++;
}

HeapTreeNode* HeapTreeNode::searchNode(Record* recordPtr){
    HeapTreeNode* res = NULL;

    // Base Cases: this is null or key is present at root 
    if (this == NULL) {
        return NULL;
    }

    if (this->getRecordPtr()->getCountry() == recordPtr->getCountry() && this->getRecordPtr()->getDisease() == recordPtr->getDisease()) 
       return this; 
     
    // recur on left subtree 
    res = this->leftNode->searchNode(recordPtr);

    if(res != NULL){
        return res;
    }
  
    // recur on right subtree
    res = this->rightNode->searchNode(recordPtr);

    return res;
}

void HeapTreeNode::revMaxHeapify(){

    if(this == NULL || this->getLeftNode() == NULL){
        return;
    }
    HeapTreeNode* max = this->getLeftNode();

    if(this->getRightNode() != NULL && max->getOccurences() < this->getRightNode()->getOccurences()){
        max = this->getRightNode();
    }
    
    if(max->getOccurences() > this->getOccurences()){
        this->swap(max);
        max->revMaxHeapify();
    }
}

void HeapTreeNode::printHeap(int space){

    if(this == NULL){
        return;
    }

    space += 10;

    this->getRightNode()->printHeap(space);

    cout << endl;
    for(int i = 10; i < space; i++){
        cout << " ";
    }
    cout << this->getRecordPtr()->getDisease() << "/" << this->getOccurences() << endl;

    this->getLeftNode()->printHeap(space);
}