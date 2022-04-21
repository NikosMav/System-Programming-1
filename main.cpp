#include <iostream>
#include <string>
#include <fstream>
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

    LinkedList list;
    AVLTree tree;
    ifstream infile;
    HashTable hashTable1(countryHashtableNumOfEntries);
    HashTable hashTable2(diseaseHashtableNumOfEntries);
    HeapTree heap;

    //Reading the given file line by line
    infile.open(*patientRecordsFile);
    string line;
    Record* recordPtr;
    string* countryStr;
    string* diseaseStr;

    if (infile.is_open()) {
        while (getline(infile, line)) {
            recordPtr = new Record(line);
            //printf("%s\n", line.c_str());
            if(!(list.contains(recordPtr->getRecordId()))){
                // list.insertItem(recordPtr);
                // tree.insertItem(recordPtr);
                countryStr = new string(recordPtr->getCountry());
                diseaseStr = new string(recordPtr->getDisease());
                hashTable1.insertItem(countryStr, bucketSize, recordPtr);
                hashTable2.insertItem(diseaseStr, bucketSize, recordPtr);


                heap.insertItem(recordPtr);
            }
        }
    }  

    //list.printList();
    //tree.printTree();
    hashTable1.displayHash();
    hashTable2.displayHash();

    cout << "SHOWING HEAP" << endl;
    heap.showHeap();
    heap.deleteRoot();
    cout << "SHOWING HEAP" << endl;
    heap.showHeap();
    // heap.deleteRoot();
    // heap.showHeap();
    // heap.deleteRoot();
    // heap.showHeap();
    // heap.deleteRoot();
    // heap.showHeap();


}