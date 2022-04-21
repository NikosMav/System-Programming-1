#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include "Auxiliary.h"
using namespace std;

string* getArgument(string arg, int argc, char **argv){
    int i;
    for(i = 1; i < argc - 1; i++){
        if(arg == argv[i]){
            return new string(argv[i + 1]); 
        }
    }
}

int getCountOfArgs(string str){
    istringstream  stream(str);
    string        oneWord;
    unsigned int       count = 0;

    while(stream >> oneWord) { ++count;}
    // count now has the number of words in the string.
    return count;
}

//Queries
void firstQuery(HashTable hashTable2, string* ArrayOfStrings, int count)
{

    if (count == 3){  //Which means that user has given date1 and date2 arguments
        string* myDate1 = new string(ArrayOfStrings[1]);
        string* myDate2 = new string(ArrayOfStrings[2]);
        hashTable2.getCertainOccurences(myDate1, myDate2);

        delete myDate1;
        delete myDate2;

    }else if(count == 1){ //Which means that user has not given date1 and date2 arguments
        hashTable2.getOccurences();

    } else { //Wrong input
        cout << "User gave inadequate arguments. Please try again" << endl;
    }
}

void secondQuery(HashTable hashTable2, string* ArrayOfStrings, int count)
{

    string* myVirus = new string(ArrayOfStrings[1]);
    string* myDate1 = new string(ArrayOfStrings[2]);
    string* myDate2 = new string(ArrayOfStrings[3]);

    if (count == 4){  //Which means that user has not given a country argument
        hashTable2.getCertainOccurencesOfVirus(myVirus, myDate1, myDate2);

    }else if(count == 5){ //Which means that user has given a country argument
        string* myCountry = new string(ArrayOfStrings[4]);
        hashTable2.getCertainOccurencesOfVirusCountry(myVirus, myDate1, myDate2, myCountry);

        delete myCountry;
    } else { //Wrong input
        cout << "User gave inadequate arguments. Please try again" << endl;
    }

    delete myVirus;
    delete myDate1;
    delete myDate2;
}

void thirdQuery(LinkedList &list, string* ArrayOfStrings, int count)
{

    int realK = stoi(ArrayOfStrings[1]);
    string* myCountry = new string(ArrayOfStrings[2]);

    HeapTree heap;
    Record* recordPtr;
    LinkedListNode* node = list.getFirstNode();

    if (count == 3){  //Which means that user has not given date1 and date2 arguments

        //Building Heap on-the-fly
        while (node != NULL) {
            recordPtr = new Record(*node->getRecordPtr());
            if(*myCountry == recordPtr->getCountry()){
                heap.insertItem(recordPtr);
            }
            node = node->getNextNode();
        }

        cout << "Top " << realK << " Viruses in Country: " << *myCountry << endl;
        heap.getTopKDiseases(realK);
        
    }else if(count == 5){ //Which means that user has given date1 and date2 arguments
        Date* myDate1 = new Date(ArrayOfStrings[3]);
        Date* myDate2 = new Date(ArrayOfStrings[4]);
        
        //Building Heap on-the-fly
        while (node != NULL) {
            recordPtr = new Record(*node->getRecordPtr());
            if(*myCountry == recordPtr->getCountry() && (*node->getRecordPtr()->getEntryDate() > *myDate1 || *node->getRecordPtr()->getEntryDate() == *myDate1) && (*node->getRecordPtr()->getEntryDate() < *myDate2 || *node->getRecordPtr()->getEntryDate() == *myDate2)){
                heap.insertItem(recordPtr);
            }
            node = node->getNextNode();
        }

        cout << "Top " << realK << " Viruses in Country: " << *myCountry << " between " << ArrayOfStrings[3] << " and " << ArrayOfStrings[4] << " :" << endl;
        heap.getTopKDiseases(realK);

        delete myDate1;
        delete myDate2;

    } else { //Wrong input
        cout << "User gave inadequate arguments. Please try again" << endl;
    }

    delete myCountry;
    delete recordPtr;
    delete node;
}

void fourthQuery(LinkedList &list, string* ArrayOfStrings, int count)
{ 

    int realK = stoi(ArrayOfStrings[1]);
    string* myDisease = new string(ArrayOfStrings[2]);

    HeapTree heap;
    Record* recordPtr;
    LinkedListNode* node = list.getFirstNode();

    if (count == 3){  //Which means that user has not given date1 and date2 arguments

        //Building Heap on-the-fly
        while (node != NULL) {
            recordPtr = new Record(*node->getRecordPtr());
            if(*myDisease == recordPtr->getDisease()){
                heap.insertItem(recordPtr);
            }
            node = node->getNextNode();
        }

        cout << "Top " << realK << " Countries infected by: " << *myDisease << endl;
        heap.getTopKCountries(realK);
        
    }else if(count == 5){ //Which means that user has given date1 and date2 arguments
        Date* myDate1 = new Date(ArrayOfStrings[3]);
        Date* myDate2 = new Date(ArrayOfStrings[4]);

        //Building Heap on-the-fly
        while (node != NULL) {
            recordPtr = new Record(*node->getRecordPtr());
            if(*myDisease == recordPtr->getDisease() && (*node->getRecordPtr()->getEntryDate() > *myDate1 || *node->getRecordPtr()->getEntryDate() == *myDate1) && (*node->getRecordPtr()->getEntryDate() < *myDate2 || *node->getRecordPtr()->getEntryDate() == *myDate2)){
                heap.insertItem(recordPtr);
            }
            node = node->getNextNode();
        }

        cout << "Top " << realK << " Countries infected by: " << *myDisease << " between " << ArrayOfStrings[3] << " and " << ArrayOfStrings[4] << " :" << endl;
        heap.getTopKCountries(realK);

        delete myDate1;
        delete myDate2;

    } else { //Wrong input
        cout << "User gave inadequate arguments. Please try again" << endl;
    }

    delete myDisease;
    delete recordPtr;
    delete node;
}

void fifthQuery(LinkedList& list, string* ArrayOfStrings, int count){

    string bigString, recordStr;
    for(int i = 0; i < count; i++){
        bigString += ArrayOfStrings[i] + " ";
    }

    size_t index;
    index = bigString.find(" ");
    recordStr = bigString.substr(index + 1);

    //Searching if record already exists in List
    LinkedListNode* node = list.getFirstNode();
    Record* recordPtr;
    while (node != NULL) {
        recordPtr = new Record(*node->getRecordPtr());
        if(ArrayOfStrings[1] == recordPtr->getRecordId()){
            cout << "Record ID already exists in List. Try again with different record ID!" << endl;
            return;
        }
        node = node->getNextNode();
    }    
    
    if (count == 7){  //Which means user has given an exit Date
        recordPtr = new Record(recordStr, true);
        list.insertItem(recordPtr);
    }else if(count == 6){  //User has not given an exit Date
        recordStr += "-";
        recordPtr = new Record(recordStr, true);
        list.insertItem(recordPtr);
    }else{
        cout << "User gave inadequate arguments. Please try again" << endl;
    }
    
    cout << "Patient Record inserted successfully!" << endl;
    delete node;
}

void sixthQuery(LinkedList& list, string* ArrayOfStrings){

    LinkedListNode* node = list.getFirstNode();
    Record* recordPtr;

    while (node != NULL) {
        recordPtr = new Record(*node->getRecordPtr());
        if(ArrayOfStrings[1] == recordPtr->getRecordId()){
            if(recordPtr->getExitDate() == NULL){  //Record does not have an exit Date
                recordPtr->setExitDate(ArrayOfStrings[2]);
                cout << "Patient's Exit Date updated successfully!" << endl;
            }else{
                cout << "Patient has already an Exit Date. Please try again!" << endl;
            }
        }
        node = node->getNextNode();
    }

    delete node;
}

void seventhQuery(HashTable hashTable2, string* ArrayOfStrings, int count){
    if(count == 2){
        string* myDisease = new string(ArrayOfStrings[1]);
        hashTable2.getCurNumOfPatients(myDisease);

        delete myDisease;
    }else if(count == 1){
        hashTable2.getAllCurNumOfPatients();
    }else{
        cout << "User gave inadequate arguments. Please try again" << endl;
    }
}
