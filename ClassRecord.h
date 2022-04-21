#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(string);
    ~Date();
    int getDay();
    int getMonth();
    int getYear();
    friend bool operator==(Date&, Date&);
    friend bool operator<(Date&, Date&);
    friend bool operator>(Date&, Date&);
};

class Record
{
private:
    string recordId;
    string patientFirstName;
    string patientLastName;
    string diseaseID;
    string country;
    Date* entryDate;
    Date* exitDate;
public:
    Record(string, bool);
    ~Record();
    string getRecordId();
    Date* getEntryDate();
    string getCountry();
    string getDisease();
    Date* getExitDate();
    void setExitDate(string);
};

#endif