#include <iostream>
#include "ClassBucket.h"
using namespace std;

Pair::Pair(string* pairId){
    this->pairId = pairId;
    this->AVLTreePtr = new AVLTree();
}

Pair::~Pair(){
    delete this->pairId;
    delete this->AVLTreePtr;
}

string* Pair::getPairId(){
    return this->pairId;
}

AVLTree* Pair::getAVLTreePtr(){
    return this->AVLTreePtr;
}

Bucket::Bucket(int bucketSize){
    this->bucketSize = bucketSize;
    this->currentPairs = 0;

    int i;
    string* pairId;
    Pair* pairPtr = new Pair(pairId);
    int ArraySize = this->bucketSize / sizeof(pairPtr);

    this->pairsArray = (Pair**)malloc(ArraySize * sizeof(pairPtr));
    for(i = 0; i < ArraySize; i++){
        this->pairsArray[i] = new Pair(NULL);
    }
}

Bucket::~Bucket(){
    for(int i = 0; i < this->currentPairs; i++){
        delete this->pairsArray[i];
    }

    //delete[] pairsArray;
}

int Bucket::getBucketSize(){
    return this->bucketSize;
}

int Bucket::getCurrentPairs(){
    return this->currentPairs;
}

Pair** Bucket::getPairsArray(){
    return this->pairsArray;
}

void Bucket::insertPair(string* pairId, Record* recordPtr){
    Pair* pairPtr = new Pair(pairId);

    //Assign it to the PairsArray
    this->pairsArray[this->currentPairs] = pairPtr;
    //Inserting Record inside the newly made tree
    this->pairsArray[this->currentPairs]->getAVLTreePtr()->insertItem(recordPtr);
    //Increase currentPairs of the current Bucket Node
    this->currentPairs++;
}

void Bucket::printArray(){
    int i;
    for(i = 0; i < this->currentPairs; i++){
        cout << *this->pairsArray[i]->getPairId() << endl;
    }
}

bool Bucket::isFull() {
    if(this->currentPairs == this->bucketSize / sizeof(Pair)){
        return true;
    }else{
        return false;
    }
}

//Query Functions
void Bucket::getOccurences(){
    int i;
    for(i = 0; i < this->currentPairs; i++){
        cout << "For virus: " << *this->pairsArray[i]->getPairId() << " there are: " << this->pairsArray[i]->getAVLTreePtr()->getSize() << " occurences!" << endl;
    }
}

void Bucket::getCertainOccurences(string* date1, string* date2){
    int i;
    for(i = 0; i < this->currentPairs; i++){
        cout << "For virus: " << *this->pairsArray[i]->getPairId() << " there are: " << this->pairsArray[i]->getAVLTreePtr()->getCertainOccurences(date1, date2) << " occurences between " << *date1 << " and " << *date2 << "!" << endl;
    }
}

void Bucket::getAllCurNumOfPatients(){
    int i;
    for(i = 0; i < this->currentPairs; i++){
        cout << "For virus: " << *this->pairsArray[i]->getPairId() << " there are: " << this->pairsArray[i]->getAVLTreePtr()->getCurNumOfPatients() << " patients who have not been cured yet!" << endl;
    }
}