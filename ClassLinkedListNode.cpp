#include <iostream>
#include "ClassLinkedListNode.h"
#include "ClassRecord.h"
using namespace std;


LinkedListNode::LinkedListNode(Record* recordPtr)
{   
    this->recordPtr = recordPtr;
    this->nextNode = NULL;
}

LinkedListNode::~LinkedListNode()
{
    delete recordPtr;
    delete nextNode;
}

LinkedListNode* LinkedListNode::getNextNode() {
    return this->nextNode;
}

Record* LinkedListNode::getRecordPtr() {
    return this->recordPtr;
}

void LinkedListNode::setNextNode(LinkedListNode* Node){
    this->nextNode = Node;
}