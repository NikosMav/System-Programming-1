#include <iostream>
#include "ClassAVLTree.h"
using namespace std;

AVLTree::AVLTree()
{
    this->firstNode = NULL;
    this->size = 0;
}

AVLTree::~AVLTree()
{
    //delete this->firstNode;
}

// void AVLTree::DestroyRecursive(AVLTreeNode* node)
// {
//     if (node)
//     {
//         this->DestroyRecursive(node->getLeftNode());
//         this->DestroyRecursive(node->getRightNode());
//         delete node;
//     }
// }

AVLTreeNode* AVLTree::getFirstNode(){
    return this->firstNode;
}

void AVLTree::insertItem(Record* recordPtr){
    if(this->firstNode == NULL){
        AVLTreeNode* newNode = new AVLTreeNode(recordPtr);
        this->firstNode = newNode;
    } else {
        this->firstNode = this->firstNode->insert(recordPtr);
    }
    this->size++;
}

void AVLTree::printTree(){
    this->firstNode->inOrder();
}

int AVLTree::getSize(){
    return this->size;
}

//Query Functions
int AVLTree::getCertainOccurences(string* date1, string* date2){

    Date* newDate1 = new Date(*date1);
    Date* newDate2 = new Date(*date2);
    int counter = 0;
    this->firstNode->getCertainOccurences(newDate1, newDate2, counter);

    return counter;
}

int AVLTree::getCertainOccurencesOfVirus(string* date1, string* date2){

    Date* newDate1 = new Date(*date1);
    Date* newDate2 = new Date(*date2);
    int counter = 0;
    this->firstNode->getCertainOccurences(newDate1, newDate2, counter);

    return counter;
}

int AVLTree::getCertainOccurencesOfVirusCountry(string* date1, string* date2, string* country){

    Date* newDate1 = new Date(*date1);
    Date* newDate2 = new Date(*date2);
    int counter = 0;
    this->firstNode->getCertainOccurencesCountry(newDate1, newDate2, country, counter);

    return counter;
}

int AVLTree::getCurNumOfPatients(){
    int counter = 0;
    this->firstNode->getCurNumOfPatients(counter);

    return counter;
}