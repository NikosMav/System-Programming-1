#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include "ClassLinkedListBucket.h"
using namespace std;

class HashTable
{
private:
    int numOfEntries;
    LinkedListBucket** Array; 
public:
    int hashFunction(string);
    HashTable(int);
    ~HashTable();
    int getNumOfEntries();
    void insertItem(string*, int, Record*);
    void displayHash();

    //Query Funtions
    void getOccurences();
    void getCertainOccurences(string*, string*);
    void getCertainOccurencesOfVirus(string*, string*, string*);
    void getCertainOccurencesOfVirusCountry(string*, string*, string*, string*);
    void getCurNumOfPatients(string*);
    void getAllCurNumOfPatients();
};

#endif
