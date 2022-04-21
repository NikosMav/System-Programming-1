#ifndef AUXILIARY_H
#define AUXILIARY_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include "ClassHashTable.h"
#include "ClassHeapTree.h"
#include "ClassLinkedList.h"
using namespace std;

string* getArgument(string, int, char**);
int getCountOfArgs(string);

//Queries
void firstQuery(HashTable, string*, int);
void secondQuery(HashTable, string*, int);
void thirdQuery(LinkedList&, string*, int);
void fourthQuery(LinkedList&, string*, int);
void fifthQuery(LinkedList&, string*, int);
void sixthQuery(LinkedList&, string*);
void seventhQuery(HashTable, string*, int);

#endif