#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "ClassLinkedListNode.h"
using namespace std;

class LinkedList
{
private:
    LinkedListNode* firstNode;
    int size;
public:
    LinkedList();
    ~LinkedList();
    void insertItem(Record*);
    void printList();
    LinkedListNode* getFirstNode();
    int getSize();
    bool contains(string);
};


#endif
