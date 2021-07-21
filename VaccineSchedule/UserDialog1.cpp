#include <QDialog>
#include "ui_UserDialog1.h"
#include "UserDialog1.h"
#include "UserDL2.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include "Login.h"
#include "user.h"

UserDialog1::UserDialog1(QWidget *parent) : QDialog(parent),ui(new Ui::UserDialog1){
    ui->setupUi(this);
    int w = ui->label_chooseVaccine->width();
    int h = ui->label_chooseVaccine->height();
    QPixmap pic1(":/img/vaccinePic1.png");
    ui->label_chooseVaccine->setPixmap(pic1.scaled(w,h,Qt::KeepAspectRatio));

    Login conn;     // create a new object
    if(!conn.connOpen()){
        ui->label_userP1->setText("Failed to open the database!");
        qDebug()<<"The database Not connected with UserDialog1 page.";
    }else{
        ui->label_userP1->setText("Connected database........");
        qDebug()<<"The database connected with UsserDialog1 page.";
    }
}
// google variables for save the data from different actions.
QString age;
QString vaccine;
QString shot;
QString date;
QString tim;

UserDialog1::~UserDialog1(){
    delete ui;
}


void UserDialog1::on_pushButton_userNextPage_clicked(){
    Login conn;
    User user;
    user.username = user_name;
    user.password = pw;
    user.insurance = ui->lineEdit_insurNum->text();
    user.firstName = ui->lineEdit_fName->text();
    user.lastName = ui->lineEdit_lName->text();
    user.age = age;
    user.vaccine = vaccine;
    user.shot = shot;
    user.date = ui->dateEdit->text();
    user.time = tim;

    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("update userInfo set username='"+user.username+"',password='"+user.password+"',insurance='"+user.insurance+"',firstName='"+user.firstName+"',lastName='"+user.lastName+"'"
             ",age='"+user.age+"',vaccine='"+user.vaccine+"',shot='"+user.shot+"',date='"+user.date+"',time='"+user.time+"' where username='"+user.username+"'");

    qDebug()<<qry.executedQuery();
    if(qry.exec()) {
        QMessageBox::information(this,tr("Save"),tr("Data Saved!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }

    window()->hide();

    qDebug()<< user.username + " saved infomation: ";
    qDebug()<< user.username + " , " + user.password + " , " + user.insurance + " , " + user.firstName + " , " + user.lastName +
               " , " + user.age + " , " + user.vaccine + " , " + user.shot + " , " + user.date + " , " + user.time;

    //............................Writing / Creating into a new file in Qt.................................//

    QString filename="UserInfomation.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );

        stream<<"Hi, I am writting the user's vaccine infomation form My Qt to this file : " << Qt::endl ;

        stream<<"Username: " +user.username <<Qt::endl;
        stream <<"password: " + user.password <<Qt::endl;
        stream <<"insurance: " + user.insurance <<Qt::endl;
        stream <<"First Name: " + user.firstName <<Qt::endl;
        stream <<"Last Name: " + user.lastName <<Qt::endl;
        stream <<"Age: " + user.age <<Qt::endl;
        stream <<"Vaccine: " + user.vaccine <<Qt::endl;
        stream <<"Shot: " + user.shot <<Qt::endl;
        stream <<"Date: " + user.date <<Qt::endl;
        stream <<"Time: " + user.time <<Qt::endl;
    }

    //................................Writing / Creating into a new file in Qt..............................//

    // qry.prepare("insert into userInfo (username,password,insurance,firstName,lastName,age,vaccine,shot,date,time) "
    //  "values ('"+user.username+"','"+user.password+"','"+user.insurance+"','"+user.firstName+"','"+user.lastName+"','"+user.age+"','"+user.vaccine+"','"+user.shot+"','"+user.date+"','"+user.time+"' )" );

    /* qry.prepare("INSERT INTO userInfo(username,password,insurance,firstName,lastName,age,vaccine,shot(1st, 2nd),date,time) "
               "VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    qry.addBindValue(user.username);
    qry.addBindValue(user.password);
    qry.addBindValue(user.insurance);
    qry.addBindValue(user.firstName);
    qry.addBindValue(user.lastName);
    qry.addBindValue(user.age);
    qry.addBindValue(user.vaccine);
    qry.addBindValue(user.shot);
    qry.addBindValue(user.date);
    qry.addBindValue(user.time);
    qry.exec();
  */
}


// for Radio Buttom, choose vaccine, user can only choose one kind of vaccine
void UserDialog1::on_radioButton_Jonson_clicked(){
    vaccine = "Jonson & Jonson";
}

void UserDialog1::on_radioButton_moderna_clicked(){
    vaccine = "Moderna";
}

void UserDialog1::on_radioButton_pfizer_clicked(){
    vaccine = "Pfizer-BioNTech";
}


// for Radio Buttom, choose age, only can choose one
void UserDialog1::on_radioButton_under18_clicked(){
    age = "Under 18";
}

void UserDialog1::on_radioButton_over18_clicked(){
    age = "Between 18~50";
}

void UserDialog1::on_radioButton_over50_clicked(){
    age = "Over 50";
}

void UserDialog1::on_radioButton_over65_clicked(){
    age = "Over 65";
}


// for Radio Buttom, choose shot, first or second shot
void UserDialog1::on_radioButton_firstShot_clicked(){
    shot = "First shot";
}

void UserDialog1::on_radioButton_secondShot_clicked(){
    shot = "Seecond shot";
}

void UserDialog1::on_comboBox_hours_activated(const QString &arg1){
    tim = arg1;
}
