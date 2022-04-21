#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include "ClassLinkedList.h"
#include "ClassLinkedListNode.h"
#include "ClassRecord.h"
#include "Auxiliary.h"
#include "ClassAVLTreeNode.h"
#include "ClassAVLTree.h"
#include "ClassHashTable.h"
#include "ClassHeapTree.h"
#include "ClassHeapTreeNode.h"

using namespace std;

int main(int argc, char **argv){

    string* patientRecordsFile;
    string* dhtNumOfEntriesStr;
    string* chtNumOfEntriesStr;
    string* bucketSizeStr;
    int diseaseHashtableNumOfEntries;
    int countryHashtableNumOfEntries;
    int bucketSize;

    //Getting the values of given arguments
    patientRecordsFile = getArgument("-p", argc, argv);
    dhtNumOfEntriesStr = getArgument("-h1", argc, argv);
    chtNumOfEntriesStr = getArgument("-h2", argc, argv);
    bucketSizeStr = getArgument("-b", argc, argv);

    diseaseHashtableNumOfEntries = stoi(*dhtNumOfEntriesStr);
    countryHashtableNumOfEntries = stoi(*chtNumOfEntriesStr);
    bucketSize = stoi(*bucketSizeStr);

    ifstream infile;
    infile.open(*patientRecordsFile);

    string line;
    Record* recordPtr;
    string* countryStr;
    string* diseaseStr;

    LinkedList list;
    HashTable hashTable1(countryHashtableNumOfEntries);
    HashTable hashTable2(diseaseHashtableNumOfEntries);

    while (getline(infile, line)) {

        recordPtr = new Record(line, false);
        if(!(list.contains(recordPtr->getRecordId()))){
            list.insertItem(recordPtr);    //List of Records creation
            countryStr = new string(recordPtr->getCountry());
            diseaseStr = new string(recordPtr->getDisease());
            hashTable1.insertItem(countryStr, bucketSize, recordPtr);
            hashTable2.insertItem(diseaseStr, bucketSize, recordPtr);
        }
    }

    infile.close();

    int i, count;
    bool exit = 0;
    string str;

    while(!exit){

        cout << "Type the query and its requirements: ";
        getline(cin, str);

        count = getCountOfArgs(str);

        string* ArrayOfStrings = new string[count];
        istringstream ss(str);
        string word;
        // Traverse through all words and keep them in an array
        i = 0;
        while(ss >> word) {
            ArrayOfStrings[i] = word;
            i++;
        }

    
        if(ArrayOfStrings[0] == "/globalDiseaseStats"){
            firstQuery(hashTable2, ArrayOfStrings, count);
        }else if(ArrayOfStrings[0] == "/diseaseFrequency"){
            secondQuery(hashTable2, ArrayOfStrings, count);
        }else if(ArrayOfStrings[0] == "/topk-Diseases"){
            thirdQuery(list, ArrayOfStrings, count);
        }else if(ArrayOfStrings[0] == "/topk-Countries"){
            fourthQuery(list, ArrayOfStrings, count);
        }else if(ArrayOfStrings[0] == "/insertPatientRecord"){
            fifthQuery(list, ArrayOfStrings, count);
        }else if(ArrayOfStrings[0] == "/recordPatientExit"){
            sixthQuery(list, ArrayOfStrings);
        }else if(ArrayOfStrings[0] == "/numCurrentPatients"){
            seventhQuery(hashTable2, ArrayOfStrings, count);
        }else if(ArrayOfStrings[0] == "/exit"){
            exit = 1;

            cout << "Exiting..." << endl;
        }else{
            cout << "Wrong input. Please try again!" << endl;
        }

        delete[] ArrayOfStrings;
    }

    delete patientRecordsFile;
    delete dhtNumOfEntriesStr;
    delete chtNumOfEntriesStr;
    delete bucketSizeStr;
    delete recordPtr;
    delete countryStr;
    delete diseaseStr;

}