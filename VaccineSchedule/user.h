#pragma once

#ifndef USER_H
#define USER_H
#include <iostream>
#include <QString>
using namespace std;

class User{
private:

public:
    QString username,password,insurance,firstName,lastName,age,vaccine,shot,date,time; //private will be better

    // constructors
    User();
    User(QString un, QString pw);
    User(QString un, QString pw, QString insur, QString fn, QString ln, QString age, QString vacc, QString shot, QString date, QString time);


    // ******* Mutators
    void setUsername(QString un);
    void setPassword(QString pw);
    void setInsurance(QString insur);
    void setFirstName(QString fn);
    void setLastName(QString ln);
    void setAge(QString age);
    void setVaccine(QString vacc);
    void setShot(QString shot);
    void setDate(QString date);
    void setTime(QString time);

    // ********* Accessors
    QString getUsername();
    QString getPassword();
    QString getInsurance();
    QString getFirstName();
    QString getLastName();
    QString getAge();
    QString getVaccine();
    QString getShot();
    QString getDate();
    QString getTime();

};
































#endif // USER_H
