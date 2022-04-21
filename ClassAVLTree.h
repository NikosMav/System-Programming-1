#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "ClassAVLTreeNode.h"
using namespace std;

class AVLTree
{
private:
    AVLTreeNode* firstNode;
    int size;
public:
    AVLTree();
    //void DestroyRecursive(AVLTreeNode*);
    ~AVLTree();
    void insertItem(Record*);
    void printTree();
    AVLTreeNode* getFirstNode();
    int getSize();

    //Query Funtions
    int getCertainOccurences(string*, string*);
    int getCertainOccurencesOfVirus(string*, string*);
    int getCertainOccurencesOfVirusCountry(string*, string*, string*);
    int getCurNumOfPatients();
};

#endif