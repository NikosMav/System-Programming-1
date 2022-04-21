#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <iostream>
#include "ClassRecord.h"
using namespace std;


class LinkedListNode
{
private:
    Record* recordPtr;
    LinkedListNode* nextNode;
public:
    LinkedListNode(Record*);
    ~LinkedListNode();
    LinkedListNode* getNextNode();
    Record* getRecordPtr();
    void setNextNode(LinkedListNode*);
};


#endif