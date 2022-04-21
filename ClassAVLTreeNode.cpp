#include <iostream>
#include "ClassRecord.h"
#include "ClassAVLTreeNode.h"
using namespace std;

AVLTreeNode::AVLTreeNode(Record* recordPtr) {
    this->recordPtr = recordPtr;
    this->rightNode = NULL;
    this->leftNode = NULL;
    this->height = 0;
}

AVLTreeNode::~AVLTreeNode(){
    // delete this->recordPtr;
    // delete this->leftNode;
    // delete this->rightNode;
}

AVLTreeNode* AVLTreeNode::getRightNode() {
    return this->rightNode;
}

AVLTreeNode* AVLTreeNode::getLeftNode() {
    return this->leftNode;
}

Record* AVLTreeNode::getRecordPtr() {
    return this->recordPtr;
}

void AVLTreeNode::setRightNode(AVLTreeNode* Node){
    this->rightNode = Node;
}

void AVLTreeNode::setLeftNode(AVLTreeNode* Node){
    this->leftNode = Node;
}

int AVLTreeNode::getHeight()
{
   return (this == NULL ? -1 : this->height);
}

int AVLTreeNode::getBalance(AVLTreeNode* Node){
    return (this->getLeftNode()->getHeight() - this->getRightNode()->getHeight());
}

AVLTreeNode* AVLTreeNode::insert(Record* recordPtr){
    AVLTreeNode* newNode;

    if(*(recordPtr->getEntryDate()) < *(this->getRecordPtr()->getEntryDate())){
        if(this->getLeftNode() == NULL){
            newNode = new AVLTreeNode(recordPtr);
            this->setLeftNode(newNode);
            if(this->getRightNode() != NULL){
                this->height = 1 + max(this->getRightNode()->getHeight(), this->getLeftNode()->getHeight());
            }else{
                this->height = 1;
            }
            return this;
        }
        this->setLeftNode(this->getLeftNode()->insert(recordPtr));
        this->height = 1 + max(this->getRightNode()->getHeight(), this->getLeftNode()->getHeight());
    }else{ //if is equal then go right too.
        if(this->getRightNode() == NULL){
            newNode = new AVLTreeNode(recordPtr);
            this->setRightNode(newNode);
            if(this->getLeftNode() != NULL){
                this->height = 1 + max(this->getRightNode()->getHeight(), this->getLeftNode()->getHeight());
            }else{
                this->height = 1;
            }
            return this;
        }
        this->setRightNode(this->getRightNode()->insert(recordPtr));
        this->height = 1 + max(this->getRightNode()->getHeight(), this->getLeftNode()->getHeight());
    }

    this->height = 1 + max(this->getRightNode()->getHeight(), this->getLeftNode()->getHeight());

    int balance = getBalance(this);

    //Left Left Case
    if(balance > 1 && *recordPtr->getEntryDate() < *this->getLeftNode()->getRecordPtr()->getEntryDate()){
        return this->rightRotate();
    }

    //Right Right Case
    if (balance < -1 && (*recordPtr->getEntryDate() > *this->getRightNode()->getRecordPtr()->getEntryDate() || *recordPtr->getEntryDate() == *this->getRightNode()->getRecordPtr()->getEntryDate())){
        return this->leftRotate();
    }

    // Left Right Case  
    if (balance > 1 && (*recordPtr->getEntryDate() > *this->getLeftNode()->getRecordPtr()->getEntryDate() || *recordPtr->getEntryDate() == *this->getLeftNode()->getRecordPtr()->getEntryDate())){
        this->setLeftNode(this->getLeftNode()->leftRotate());
        this->height = 1 + max(this->getRightNode()->getHeight(), this->getLeftNode()->getHeight());
        return this->rightRotate(); 
    }  
  
    // Right Left Case  
    if (balance < -1 && *recordPtr->getEntryDate() < *this->getRightNode()->getRecordPtr()->getEntryDate()){
        this->setRightNode(this->getRightNode()->rightRotate());
        this->height = 1 + max(this->getRightNode()->getHeight(), this->getLeftNode()->getHeight());
        return this->leftRotate();
    }
    return this;
}

AVLTreeNode* AVLTreeNode::rightRotate(){
    AVLTreeNode* leftChild = this->getLeftNode();
    AVLTreeNode* leftRightChild = leftChild->getRightNode();

    //Rotation
    leftChild->setRightNode(this);
    this->setLeftNode(leftRightChild);

    //Update Heights
    this->setHeight(max(this->getLeftNode()->getHeight(), this->getRightNode()->getHeight()) + 1);  
    leftChild->setHeight(max(leftChild->getLeftNode()->getHeight(), leftChild->getRightNode()->getHeight()) + 1);  
  
    // Return new root  
    return leftChild; 
}

AVLTreeNode* AVLTreeNode::leftRotate(){
    AVLTreeNode* rightChild = this->getRightNode();
    AVLTreeNode* rightLeftChild = rightChild->getLeftNode();  
  
    // Perform rotation  
    rightChild->setLeftNode(this);
    this->setRightNode(rightLeftChild);
  
    // Update heights  
    this->setHeight(max(this->getLeftNode()->getHeight(), this->getRightNode()->getHeight()) + 1);
    rightChild->setHeight(max(rightChild->getLeftNode()->getHeight(), rightChild->getRightNode()->getHeight()) + 1); 
  
    // Return new root  
    return rightChild;  
}

void AVLTreeNode::setHeight(int newHeight){
    this->height = newHeight;
}

void AVLTreeNode::inOrder(){  
    if(this->getLeftNode() != NULL){
        this->getLeftNode()->inOrder();   
    } 

    cout << this->getRecordPtr()->getEntryDate()->getYear() << " " << endl;

    if(this->getRightNode() != NULL){
        this->getRightNode()->inOrder(); 
    }
}

//Query Functions
void AVLTreeNode::getCertainOccurences(Date* date1, Date* date2, int& counter) {
    if (this == NULL){
        return;
    }

    if ((*this->getRecordPtr()->getEntryDate() > *date1 || *this->getRecordPtr()->getEntryDate() == *date1) && (*this->getRecordPtr()->getEntryDate() < *date2 || *this->getRecordPtr()->getEntryDate() == *date2)){
        counter++;
    }

     /* then recur on left sutree */
    this->leftNode->getCertainOccurences(date1, date2, counter); 
  
    /* node is not found in left, so recur on right subtree */
    this->rightNode->getCertainOccurences(date1, date2, counter);
}

void AVLTreeNode::getCertainOccurencesCountry(Date* date1, Date* date2, string* country, int& counter) {
    if (this == NULL){
        return;
    }

    if ((*this->getRecordPtr()->getEntryDate() > *date1 || *this->getRecordPtr()->getEntryDate() == *date1) && (*this->getRecordPtr()->getEntryDate() < *date2 || *this->getRecordPtr()->getEntryDate() == *date2)){
        if(this->getRecordPtr()->getCountry() == *country){
            counter++;
        }
    }

     /* then recur on left sutree */
    this->leftNode->getCertainOccurencesCountry(date1, date2, country, counter); 
  
    /* node is not found in left, so recur on right subtree */
    this->rightNode->getCertainOccurencesCountry(date1, date2, country, counter);
}

void AVLTreeNode::getCurNumOfPatients(int& counter) {
    if (this == NULL){
        return;
    }

    if (this->getRecordPtr()->getExitDate() == NULL){
        counter++;
    }

     /* then recur on left sutree */
    this->leftNode->getCurNumOfPatients(counter); 
  
    /* node is not found in left, so recur on right subtree */
    this->rightNode->getCurNumOfPatients(counter);
}