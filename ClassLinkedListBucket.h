#ifndef LINKEDLISTBUCKET_H
#define LINKEDLISTBUCKET_H

#include <iostream>
#include <string>
#include "ClassLinkedListBucketNode.h"
using namespace std;

class LinkedListBucket
{
private:
    LinkedListBucketNode* firstBucketNode;
    int size;
public:
    LinkedListBucket();
    ~LinkedListBucket();
    void insertItem(string*, int, Record*);
    int getSize();
    void printList();
    LinkedListBucketNode* getFirstBucketNode();
    AVLTree* contains(string*);

    //Query Functions
    void getOccurences();
    void getCertainOccurences(string*, string*);
    void getCertainOccurencesOfVirus(string*, string*, string*);
    void getCertainOccurencesOfVirusCountry(string*, string*, string*, string*);
    void getCurNumOfPatients(string*);
    void getAllCurNumOfPatients();
};


#endif