#ifndef AVLTREENODE_H
#define AVLTREENODE_H

#include <iostream>
#include "ClassRecord.h"
using namespace std;


class AVLTreeNode
{
private:
    Record* recordPtr;
    AVLTreeNode* rightNode;
    AVLTreeNode* leftNode;
    int height;
public:
    AVLTreeNode(Record*);
    ~AVLTreeNode();
    AVLTreeNode* getRightNode();
    AVLTreeNode* getLeftNode();
    Record* getRecordPtr();
    int getHeight();
    void setRightNode(AVLTreeNode*);
    void setLeftNode(AVLTreeNode*);
    AVLTreeNode* insert(Record*);
    int getBalance(AVLTreeNode*);
    AVLTreeNode* rightRotate();
    AVLTreeNode* leftRotate();
    void setHeight(int);
    void inOrder();

    //Query Functions
    void getCertainOccurences(Date*, Date*, int&);
    void getCertainOccurencesCountry(Date*, Date*, string*, int&);
    void getCurNumOfPatients(int&);
};


#endif
