#ifndef LINKEDLISTBUCKETNODE_H
#define LINKEDLISTBUCKETNODE_H

#include <iostream>
#include "ClassBucket.h"
using namespace std;

class LinkedListBucketNode
{
private:
    Bucket* bucketPtr;
    LinkedListBucketNode* nextBucketNode;
public:
    LinkedListBucketNode(Bucket*);
    ~LinkedListBucketNode();
    LinkedListBucketNode* getNextBucketNode();
    Bucket* getBucketPtr();
    void setNextBucketNode(LinkedListBucketNode*);
};

#endif