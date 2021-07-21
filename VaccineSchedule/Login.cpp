#include "Login.h"
#include "ui_Login.h"
#include "UserDialog1.h"
#include <QMessageBox>
#include "userMain.h"
#include "user.h"
#include "user.cpp"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QException>

Login::Login(QWidget *parent): QMainWindow(parent), ui(new Ui::Login){  
    ui->setupUi(this);
    if(!connOpen()){
        ui->label->setText("Failed to open the database!");
        qDebug()<<"The database Not connected ";
    }else{
        ui->label->setText("Connected database........");
        qDebug()<<"The database connected ";
    }
}

Login::~Login(){
    delete ui;
}

// for action admin register....(admin_username,admin_password,admin_code)
void Login::on_pushButton_adminRegister_clicked(){   
    Login conn;
    QString adminUsername, adminPassword, adminCode;

    adminUsername = ui->lineEdit_adminUsername->text();
    adminPassword = ui->lineEdit_adminPW->text();
    adminCode = ui->lineEdit_adminCode->text();

    if(!connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    connOpen();   // open the database function
    QSqlQuery qry;
    qry.prepare("insert into admin (admin_username,admin_password,admin_code) values ('"+adminUsername+"','"+adminPassword+"','"+adminCode+"')" );

    qDebug()<<qry.executedQuery();
    if(qry.exec()) {
        QMessageBox::information(this,tr("Save"),tr("Admin Data Saved!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

// for action admin login select 3 columns from database
void Login::on_pushButton_adminLogin_clicked(){  
    int count = 0;
    //.........................................................Exception.....................................//
    try {
        QString adminUsername = ui ->lineEdit_adminUsername->text();   // login and get the text of username and password form user input.
        QString adminPassword = ui->lineEdit_adminPW->text();
        QString adminCode = ui->lineEdit_adminCode->text();
        connOpen();
        QSqlQuery qry;
        qry.prepare("select* from admin where admin_username='"+adminUsername + "'and admin_password = '"+adminPassword+"'and admin_code = '"+adminCode+"'");

        if(qry.exec()) {
            while(qry.next()){
                count++;
            }

            qDebug() << count;
            if(count==1){
                connClose();    // close the database before open next window
                this->hide();
                adminP1 = new AdminDialog1(this);
                adminP1->show();
            }else{
                throw("Error");
            }
        }
    }
    catch (...) {
        ui->label ->setText("Username or password or work code is NOT correct.");
        qDebug() << "Catch Error： Username or password or work code is NOT correct. ";
    }

}

// for action  user login select 2 columns
void Login::on_pushButton_userLogin_clicked(){  
    int count = 0;
    //.........................................................Exception.....................................//
    try {
        QString userUsername = ui ->lineEdit_userUsername->text();     // login and get the text of username and password form user input.
        QString userPassword = ui->lineEdit_userPW->text();
        connOpen();                                                    // open the database function, there are debug in the function.
        QSqlQuery qry;
        qry.prepare("select* from userInfo where username='"+userUsername+ "' and password = '"+userPassword+"'" );

        if(qry.exec()) {
            while(qry.next()){
                count++;
            }
            qDebug() << count;
            if(count==1){
                ui->label ->setText("Username and password is correct.");
                connClose();
                this->hide();
                userP1 = new UserDialog1(this);
                userP1->user_name = userUsername;
                userP1->pw = userPassword;

                qDebug() << userP1->user_name + " has logged in";
                userP1->show();
            }
            else if (count == 0) {
                throw("Error");
            }
        }
    }
    catch (...) {
        ui->label ->setText("Username or password is NOT correct.");
        qDebug() << "Catch Error： Username or password is NOT correct. ";
    }
}


void Login::on_pushButton_userRegister_clicked(){
    Login conn;
    User curUser;
    curUser.username = ui->lineEdit_userUsername->text();
    curUser.password = ui->lineEdit_userPW->text();

    if(!connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    connOpen();
    QSqlQuery qry;
    qry.prepare("insert into userInfo (username,password) values ('"+curUser.username+"','"+curUser.password+"')" );
    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        QMessageBox::information(this,tr("Save"),tr("User Data Saved!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}


void Login::on_pushButton_loginQuit_clicked(){
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the login page? ", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "Answer 'NO' Button is clicked";
    }
}
