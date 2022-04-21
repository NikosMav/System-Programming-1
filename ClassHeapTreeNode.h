#ifndef HEAPTREENODE_H
#define HEAPTREENODE_H

#include <iostream>
#include "ClassRecord.h"
using namespace std;


class HeapTreeNode
{
private:
    Record* recordPtr;
    HeapTreeNode* parentNode; 
    HeapTreeNode* rightNode;
    HeapTreeNode* leftNode;
    HeapTreeNode* prevTail;
    int occurences;
public:
    HeapTreeNode(Record*);
    ~HeapTreeNode();
    Record* getRecordPtr();
    HeapTreeNode* getParentNode();
    HeapTreeNode* getRightNode();
    HeapTreeNode* getLeftNode();
    HeapTreeNode* getPrevTail();
    int getOccurences();
    void setRecordPtr(Record*);
    void setParentNode(HeapTreeNode*);
    void setRightNode(HeapTreeNode*);
    void setLeftNode(HeapTreeNode*);
    void setPrevTail(HeapTreeNode*);
    void setOccurences(int);

    void maxHeapify();
    void swap(HeapTreeNode*);
    bool contains(Record*);
    void increaseKey();
    HeapTreeNode* searchNode(Record*);
    void revMaxHeapify();
    void printHeap(int);
};


#endif