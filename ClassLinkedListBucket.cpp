#include <iostream>
#include "ClassLinkedListBucket.h"
using namespace std;

LinkedListBucket::LinkedListBucket(){
    this->firstBucketNode = NULL;
    this->size = 0;
}

LinkedListBucket::~LinkedListBucket(){
    //delete this->firstBucketNode;
}

int LinkedListBucket::getSize(){
    return this->size;
}

LinkedListBucketNode* LinkedListBucket::getFirstBucketNode(){
    return this->firstBucketNode;
}

void LinkedListBucket::insertItem(string* item, int bucketSize, Record* recordPtr)
{
    LinkedListBucketNode* node;
    //Checking if item has already been inserted in our List
    AVLTree* AVLTreePtr = NULL;
    AVLTreePtr = this->contains(item);

    if(AVLTreePtr == NULL){  //Which means it is not inserted

        //Checking if LinkedList is empty...
        if(this->size == 0){
            Bucket* bucketPtr = new Bucket(bucketSize);
            LinkedListBucketNode* newBucketNode = new LinkedListBucketNode(bucketPtr);

            //First create the new node
            LinkedListBucketNode* oldFirstBucketNode = this->getFirstBucketNode();
            newBucketNode->setNextBucketNode(oldFirstBucketNode);
            this->firstBucketNode = newBucketNode;
            this->size++;

            //Then insert Pair inside new node
            this->firstBucketNode->getBucketPtr()->insertPair(item, recordPtr);
        }else{ //If list is not empty, then...

            node = this->getFirstBucketNode();
            //Finding the last node of our LinkedList
            while(node->getNextBucketNode() != NULL){
                node = node->getNextBucketNode();
            }
            
            //Checking if last bucket node is full
            if(node->getBucketPtr()->isFull()){
                Bucket* bucketPtr = new Bucket(bucketSize);
                LinkedListBucketNode* newNode = new LinkedListBucketNode(bucketPtr);

                node->setNextBucketNode(newNode);
                this->size++;

                //Then insert Pair inside new node
                newNode->getBucketPtr()->insertPair(item, recordPtr);
            }else{
                node->getBucketPtr()->insertPair(item, recordPtr);
            }
        }
    }else{  //Which means it is already inserted
        AVLTreePtr->insertItem(recordPtr);
    }
}

AVLTree* LinkedListBucket::contains(string* item){
    LinkedListBucketNode* node = this->getFirstBucketNode();
    int i;
    Pair** pairsArray;
    
    while(node != NULL){
        pairsArray = node->getBucketPtr()->getPairsArray();
        for(i = 0; i < node->getBucketPtr()->getCurrentPairs(); i++){

            if(*pairsArray[i]->getPairId() == *item){
                return pairsArray[i]->getAVLTreePtr();
            }
        }
        node = node->getNextBucketNode();
    }
    return NULL;
}

void LinkedListBucket::printList(){
    LinkedListBucketNode* node;
    int i;

    node = this->getFirstBucketNode();

    while(node != NULL) {
        node->getBucketPtr()->printArray();
        node = node->getNextBucketNode();
    }

    //cout << this->getSize() << endl;
}

//Query Funtions
void LinkedListBucket::getOccurences(){
    LinkedListBucketNode* node;
    int i;

    node = this->getFirstBucketNode();

    while(node != NULL){
        node->getBucketPtr()->getOccurences();
        node = node->getNextBucketNode();
    }
}

void LinkedListBucket::getCertainOccurences(string* date1, string* date2){
    LinkedListBucketNode* node;
    int i;

    node = this->getFirstBucketNode();

    while(node != NULL){
        node->getBucketPtr()->getCertainOccurences(date1, date2);
        node = node->getNextBucketNode();
    }    
}

void LinkedListBucket::getCertainOccurencesOfVirus(string* virus, string* date1, string* date2){
    LinkedListBucketNode* node;
    int i;

    node = this->getFirstBucketNode();
    Pair** pairsArray;

    while(node != NULL){
        pairsArray = node->getBucketPtr()->getPairsArray();
        for(i = 0; i < node->getBucketPtr()->getCurrentPairs(); i++){
            if(*pairsArray[i]->getPairId() == *virus){
                cout << "For Virus: " << *virus << " there are: " << pairsArray[i]->getAVLTreePtr()->getCertainOccurencesOfVirus(date1, date2) << " occurences between " << *date1 << " and " << *date2 << "!" << endl;
            }
        }
        node = node->getNextBucketNode();
    }   
}

void LinkedListBucket::getCertainOccurencesOfVirusCountry(string* virus, string* date1, string* date2, string* country){
    LinkedListBucketNode* node;
    int i;

    node = this->getFirstBucketNode();
    Pair** pairsArray;

    while(node != NULL){
        pairsArray = node->getBucketPtr()->getPairsArray();
        for(i = 0; i < node->getBucketPtr()->getCurrentPairs(); i++){
            if(*pairsArray[i]->getPairId() == *virus){
                cout << "For Virus: " << *virus << " there are: " << pairsArray[i]->getAVLTreePtr()->getCertainOccurencesOfVirusCountry(date1, date2, country) << " occurences between " << *date1 << " and " << *date2 << " in country: " << *country << "!" << endl;
            }
        }
        node = node->getNextBucketNode();
    }   
}

void LinkedListBucket::getCurNumOfPatients(string* myDisease){
    LinkedListBucketNode* node;
    int i;

    node = this->getFirstBucketNode();
    Pair** pairsArray;

    while(node != NULL){
        pairsArray = node->getBucketPtr()->getPairsArray();
        for(i = 0; i < node->getBucketPtr()->getCurrentPairs(); i++){
            if(*pairsArray[i]->getPairId() == *myDisease){
                cout << "For Virus: " << *myDisease << " there are: " << pairsArray[i]->getAVLTreePtr()->getCurNumOfPatients() << " patients who have not been cured yet!" << endl;
            }
        }
        node = node->getNextBucketNode();
    }   
}

void LinkedListBucket::getAllCurNumOfPatients(){
    LinkedListBucketNode* node;
    int i;

    node = this->getFirstBucketNode();

    while(node != NULL){
        node->getBucketPtr()->getAllCurNumOfPatients();
        node = node->getNextBucketNode();
    }
}