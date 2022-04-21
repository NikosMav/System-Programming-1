#include <iostream>
#include "ClassLinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    this->firstNode = NULL;
    this->size = 0;
}

LinkedList::~LinkedList()
{
    delete this->firstNode;
}

LinkedListNode* LinkedList::getFirstNode(){
    return this->firstNode;
}

int LinkedList::getSize(){
    return this->size;
}

void LinkedList::insertItem(Record* recordPtr)
{
    LinkedListNode* newNode = new LinkedListNode(recordPtr);

    LinkedListNode* oldFirstNode = this->getFirstNode();
    newNode->setNextNode(oldFirstNode);
    this->firstNode = newNode;

    this->size++;
}

void LinkedList::printList(){
    LinkedListNode* node;

    node = this->getFirstNode();

    while(node != NULL) {
        cout << node->getRecordPtr()->getRecordId() << "/" << node->getRecordPtr()->getCountry() << endl;
        node = node->getNextNode();
    }

    cout << "Size of List: " << this->getSize() << endl;
}

bool LinkedList::contains(string id){
    LinkedListNode* node = this->getFirstNode();

    while(node != NULL){
        if(node->getRecordPtr()->getRecordId() == id){
            cout << "Found a Patient Record with same ID! Ignoring this Record!" << endl;
            return true;
        }
        node = node->getNextNode();
    }
    return false;
}