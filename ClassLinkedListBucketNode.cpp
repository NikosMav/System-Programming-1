#include <iostream>
#include <string>
#include "ClassLinkedListBucketNode.h"
using namespace std;

LinkedListBucketNode::LinkedListBucketNode(Bucket* bucketPtr){   
    this->bucketPtr = bucketPtr;
    this->nextBucketNode = NULL;
}

LinkedListBucketNode::~LinkedListBucketNode()
{
    // delete this->bucketPtr;
    // delete this->nextBucketNode;
}

LinkedListBucketNode* LinkedListBucketNode::getNextBucketNode() {
    return this->nextBucketNode;
}

Bucket* LinkedListBucketNode::getBucketPtr() {
    return this->bucketPtr;
}

void LinkedListBucketNode::setNextBucketNode(LinkedListBucketNode* BucketNode){
    this->nextBucketNode = BucketNode;
}