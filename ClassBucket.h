#ifndef BUCKET_H
#define BUCKET_H

#include <iostream>
#include "ClassAVLTree.h"
using namespace std;

class Pair
{
private:
    string* pairId;
    AVLTree* AVLTreePtr;
public:
    Pair(string*);
    ~Pair();
    string* getPairId();
    AVLTree* getAVLTreePtr();
};

class Bucket
{
private:
    int bucketSize;
    int currentPairs;
    Pair** pairsArray;
public:
    Bucket(int);
    ~Bucket();
    int getBucketSize();
    int getCurrentPairs();
    Pair** getPairsArray();
    void insertPair(string*, Record*);
    void printArray();
    bool isFull();

    //Query Funtions
    void getOccurences();
    void getCertainOccurences(string* date1, string* date2);
    void getAllCurNumOfPatients();

};

#endif