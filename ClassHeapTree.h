#ifndef HEAPTREE_H
#define HEAPTREE_H

#include <iostream>
#include "ClassHeapTreeNode.h"
using namespace std;

class HeapTree
{
private:
    HeapTreeNode* root;
    HeapTreeNode* tail;
    int size;
public:
    HeapTree();
    ~HeapTree();
    HeapTreeNode* getRoot();
    int getSize();

    void insertItem(Record*);
    void setTail(HeapTreeNode*);
    void showHeap();
    void updateNode(Record*);
    void deleteRoot();

    //Query Functions
    void getTopKDiseases(int);
    void getTopKCountries(int);
};

#endif