#include "user.h"
#include "Login.h"
#include <iostream>
#include <QString>
using namespace std;

// Default constructor
User::User() {
    QString username = NULL,
            password = NULL,
            insurance = NULL,
            firstName = NULL,
            lastName = NULL,
            age = NULL,
            vaccine = NULL,
            shot = NULL,
            date = NULL,
            time = NULL;
}

// constructor for first login page, two variables
User::User(QString un, QString pw){
    this->username = un;
    this->password = pw;
    this->insurance = "0";
    this->firstName = "NULL",
            this->lastName = "NULL",
            this->age = "0",
            this->vaccine = "NULL",
            this->shot = "0",
            this->date = "xx-xx-xxxx",
            this->time = "0:00 - 0:00";
}

User::User(QString un, QString pw, QString insur, QString fn, QString ln, QString age, QString vacc, QString shot, QString date, QString time){
    this->username = un;
    this->password = pw;
    this->insurance = insur;
    this->firstName = fn;
    this->lastName = ln;
    this->age = age;
    this->vaccine = vacc;
    this->shot = shot;
    this->date = date;
    this->time = time;
}






