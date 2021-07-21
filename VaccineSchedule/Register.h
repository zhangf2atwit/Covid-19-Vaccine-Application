#ifndef REGISTER_H
#define REGISTER_H

#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <QObject>

class Register : public QObject{

    Q_OBJECT

private:
    QString firstName;
    QString lastName;

    QString username;
    QString password;

    int workCode;  // for the admin, have high level to check and uodate information.

public:
    Register(QString firstName,QString lastName,QString username,QString password);// for everyone

    // all of these infor will get from the Qt EditLine, When the User doing register.
    QString getFirstName();
    QString getLastName();
    QString getUsername();
    QString getPassword();

    // seters
    void setFirstName(QString firstName);
    void setLastName(QString lastName);
    void stUsername(QString username);
    void setPassword(QString password);

    // for match the login information.
    bool isUser(QString username,QString password);

    // see if the admin login and check high level update
    bool isAdmin(QString username,QString password,int workCode);

    //virtual void addToDatabase(QSqlDatabase);// adding and store all the data to file.

};

#endif // REGISTER_H

