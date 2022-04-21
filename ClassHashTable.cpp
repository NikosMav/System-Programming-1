#include <iostream>
#include "ClassHashTable.h"
using namespace std;

HashTable::HashTable(int numOfEntries){
    int i;
    this->numOfEntries = numOfEntries;
    LinkedListBucket* bucketList = new LinkedListBucket();

    this->Array = (LinkedListBucket**)malloc((this->numOfEntries) * sizeof(bucketList));
    for (i = 0; i < numOfEntries; i++){
        this->Array[i] = new LinkedListBucket();
    }
}

HashTable::~HashTable(){
    // for(int i = 0; i < this->numOfEntries; i++){
    //     delete Array[i];
    // }

    // //delete[] Array;
}

int HashTable::hashFunction(string toBeHashed)
{
    unsigned int hashVal = 0;
    for (int x = 0; x < toBeHashed.length(); x++){
        hashVal ^= (hashVal << 5) +
                   (hashVal >> 2) +
                   toBeHashed[x];
    }
    //cout << "identifier " << toBeHashed << " hashed to " << hashVal % this->numOfEntries << endl;
    return hashVal % this->numOfEntries;
}

int HashTable::getNumOfEntries(){
    return this->numOfEntries;
}

void HashTable::insertItem(string* item, int bucketSize, Record* recordPtr)
{
    //Hashing the given item
    int index = hashFunction(*item);
    //Inserting it in the appropriate LinkedList
    this->Array[index]->insertItem(item, bucketSize, recordPtr);
}

void HashTable::displayHash() { 
  for (int i = 0; i < this->numOfEntries; i++) { 
    this->Array[i]->printList(); 
  } 
}

//Query Functions
void HashTable::getOccurences(){
    for(int i = 0; i < this->numOfEntries; i++){
        this->Array[i]->getOccurences();
    }
}

void HashTable::getCertainOccurences(string* date1, string* date2){
    for(int i = 0; i < this->numOfEntries; i++){
        this->Array[i]->getCertainOccurences(date1, date2);
    }
}

void HashTable::getCertainOccurencesOfVirus(string* virus, string* date1, string* date2){
    //Hashing the given item
    int index = this->hashFunction(*virus);
    this->Array[index]->getCertainOccurencesOfVirus(virus, date1, date2);
}

void HashTable::getCertainOccurencesOfVirusCountry(string* virus, string* date1, string* date2, string* country){
    //Hashing the given item
    int index = this->hashFunction(*virus);
    this->Array[index]->getCertainOccurencesOfVirusCountry(virus, date1, date2, country);
}

void HashTable::getCurNumOfPatients(string* myDisease){
    //Hashing the given item
    int index = this->hashFunction(*myDisease);
    this->Array[index]->getCurNumOfPatients(myDisease);
}

void HashTable::getAllCurNumOfPatients(){
    for(int i = 0; i < this->numOfEntries; i++){
        this->Array[i]->getAllCurNumOfPatients();
    }
}