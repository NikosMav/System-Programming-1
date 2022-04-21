#include <iostream>
#include "ClassHeapTree.h"
using namespace std;

HeapTree::HeapTree()
{
    this->root = NULL;
    this->tail = NULL;
    this->size = 0;
}

HeapTree::~HeapTree()
{
//     delete this->root;
}

HeapTreeNode* HeapTree::getRoot(){
    return this->root;
}

int HeapTree::getSize(){
    return this->size;
}

//CLASS FUNCTIONS
void HeapTree::insertItem(Record* recordPtr){
    //If item already exists in our heap then just update its data, else insert it in heap
    if(this->root->contains(recordPtr)){
        this->updateNode(recordPtr);
    } else {
        if(this->root == NULL){
            this->root = new HeapTreeNode(recordPtr);
            this->tail = this->root;
        } else if (tail->getLeftNode() == NULL){
            HeapTreeNode* newNode = new HeapTreeNode(recordPtr);
            this->tail->setLeftNode(newNode);
            this->tail->getLeftNode()->setParentNode(this->tail);
            this->tail->getLeftNode()->maxHeapify();

            //delete newNode;
        } else {
            HeapTreeNode* newNode = new HeapTreeNode(recordPtr);
            this->tail->setRightNode(newNode);
            this->tail->getRightNode()->setParentNode(this->tail);
            this->tail->getRightNode()->maxHeapify();
            HeapTreeNode* prevTail = this->tail;
            this->setTail(this->tail);
            this->tail->setPrevTail(prevTail);

            //delete newNode;
            //delete prevTail;
        }
        this->size++;
    }
}

void HeapTree::setTail(HeapTreeNode* node){
    /*
    If we reach this stage that means a level is completely filled
    and we need to proceed to the next level by going to the extreme left.
    */
    if (node->getParentNode() == NULL){
        this->tail = node;
        while(this->tail->getLeftNode() != NULL){
            this->tail = this->tail->getLeftNode();
        }
    }
    /*
    If current node is the left node, go to the right node and
    proceed left from there to reach the left most node.
    */
    else if (node->getParentNode()->getLeftNode() == node){
        this->tail = node->getParentNode()->getRightNode();
        while(this->tail->getLeftNode() != NULL){
            this->tail = this->tail->getLeftNode();
        }
    }
    else if(node->getParentNode()->getRightNode() == node){
        this->setTail(node->getParentNode());
    }
}

void HeapTree::showHeap(){
    int space = 0;
    this->root->printHeap(space);
}

void HeapTree::updateNode(Record* recordPtr){
    HeapTreeNode* toBeUpdated = this->root->searchNode(recordPtr);
    toBeUpdated->increaseKey();
    toBeUpdated->maxHeapify();
}

void HeapTree::deleteRoot(){
    if(this->size == 1){ //When only the root exists
        this->root = NULL;
        this->size = 0;
        return;
    }

    if(this->size == 2){ //One root one children
        if(this->root->getRightNode() != NULL){
            this->root->swap(this->root->getRightNode());
            this->root->setRightNode(NULL);
        }else{
            this->root->swap(this->root->getLeftNode());
            this->root->setLeftNode(NULL);
        }
    }else if(this->tail == this->root){ //One root two children
        this->tail = NULL;
        
        HeapTreeNode* max = this->root->getLeftNode();
        if(max < this->root->getRightNode()){
            this->root->swap(this->root->getRightNode());
            this->root->setRightNode(NULL);
        }else{
            this->root->swap(this->root->getLeftNode());
            this->root->setLeftNode(NULL);
        }
    }else{
        if(this->tail->getRightNode() != NULL){
            this->root->swap(this->tail->getRightNode());
            this->tail->setRightNode(NULL);
            this->root->revMaxHeapify();
        }else if(this->tail->getLeftNode() != NULL){
            this->root->swap(this->tail->getLeftNode());
            this->tail->setLeftNode(NULL);
            this->root->revMaxHeapify();
        }else{
            this->tail = this->tail->getPrevTail();
            this->deleteRoot();
            this->size++;
        }
    }
    this->size--;
}

//Query Functions
void HeapTree::getTopKDiseases(int K){
    int i;
    HeapTreeNode* node;
    for(i = 0; i < K; i++){
        if(this->root == NULL){
            cout << "No more results!" << endl;
            return;
        }
        node = this->getRoot();
        cout << "Virus: " << node->getRecordPtr()->getDisease() << endl;
        this->deleteRoot();
    }
}

void HeapTree::getTopKCountries(int K){
    int i;
    HeapTreeNode* node;
    for(i = 0; i < K; i++){
        if(this->root == NULL){
            cout << "No more results!" << endl;
            return;
        }
        node = this->getRoot();
        cout << "Country: " << node->getRecordPtr()->getCountry() << endl;
        this->deleteRoot();
    }
}