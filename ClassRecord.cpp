#include <iostream>
#include "ClassRecord.h"
#include <string>
#include <bits/stdc++.h>
using namespace std;

Date::Date(string Date)
{
    string strday, strmonth, temp;
    size_t index1, index2;

    index1 = Date.find("-");
    strday = Date.substr(0, index1);
    this->day = stoi(strday);

    temp = Date.substr(index1 + 1);

    index2 = temp.find("-");
    strmonth = temp.substr(0, index2);
    this->month = stoi(strmonth);

    temp = temp.substr(index2 + 1);
    this->year = stoi(temp);

    // cout << this->day << endl;
    // cout << this->month << endl;
    // cout << this->year << endl;
}

int Date::getDay(){
    return this->day;
}

int Date::getMonth(){
    return this->month;
}

int Date::getYear(){
    return this->year;
}

bool operator==(Date& date1, Date& date2){
        return (date1.getDay() == date2.getDay() && date1.getMonth() == date2.getMonth()
        && date1.getYear() == date2.getYear());
}

bool operator<(Date& date1, Date& date2){
    if(date1.getYear() < date2.getYear()){
        return true;
    }else if(date1.getYear() == date2.getYear() && date1.getMonth() < date2.getMonth()){
        return true;
    } else if(date1.getYear() == date2.getYear() && date1.getMonth() == date2.getMonth() && date1.getDay() < date2.getDay()){
        return true;
    }else{
        return false;
    }
}

bool operator>(Date& date1, Date& date2){
    return !(date1 < date2 || date1 == date2);
}

Date::~Date(){
}

Record::Record(string BigString, bool query)
{
    string entryDate;
    string exitDate;

    istringstream ss(BigString);

    ss >> this->recordId;
    ss >> this->patientFirstName;
    ss >> this->patientLastName;
    ss >> this->diseaseID;
    if(!query){
        ss >> this->country;
    }
    ss >> entryDate;
    ss >> exitDate;

    if(exitDate == "-"){
        //cout << "Patient Not Out Yet" << endl;
        this->exitDate = NULL;
        this->entryDate = new Date(entryDate);
    }else{
        this->entryDate = new Date(entryDate);
        this->exitDate = new Date(exitDate);
    }

    if(this->exitDate != NULL){
        if(*this->entryDate > *this->exitDate) {
            cout << "Error: entryDate is after exitDate" << endl;
        }
    }
}

Record::~Record(){
    delete entryDate;
    delete exitDate;
}

string Record::getRecordId() {
    return this->recordId;
}

Date* Record::getEntryDate(){
    return this->entryDate;
}

string Record::getCountry(){
    return this->country;
}

string Record::getDisease(){
    return this->diseaseID;
}

Date* Record::getExitDate(){
    return this->exitDate;
}

void Record::setExitDate(string newExitDate){
    this->exitDate = new Date(newExitDate);
}