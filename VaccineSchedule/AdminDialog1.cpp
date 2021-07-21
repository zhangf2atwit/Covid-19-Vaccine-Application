#include "AdminDialog1.h"
#include "ui_AdminDialog1.h"
#include "Login.h"
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QTableView>
#include <QListView>
#include <QLineEdit>
#include <QSqlTableModel>
#include <QComboBox>
#include "user.h"

AdminDialog1::AdminDialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog1){
    ui->setupUi(this);
}

AdminDialog1::~AdminDialog1(){
    delete ui;
}

void AdminDialog1::on_pushButton_loadInfo_clicked(){
    Login conn;
    QSqlQueryModel * modal = new QSqlQueryModel();  // create model
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select username,password,insurance,firstName,lastName,age,vaccine,shot,date,time from userInfo");
    qry->exec();
    modal->setQuery(*qry);

    ui->listView->setModel(modal);
    ui->comboBox->setModel(modal);

    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug()<<(modal->rowCount());

}

void AdminDialog1::on_comboBox_currentIndexChanged(const QString &arg1){   
    QString username = ui->comboBox->currentText();
    Login conn;
    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("select * from userInfo where username='"+username+"'");
    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        while(qry.next()){
            ui->lineEdit_username->setText(qry.value(0).toString());
            ui->lineEdit_pw->setText(qry.value(1).toString());
            ui->lineEdit_insur->setText(qry.value(2).toString());
            ui->lineEdit_fName->setText(qry.value(3).toString());
            ui->lineEdit_lName->setText(qry.value(4).toString());
            ui->lineEdit_age->setText(qry.value(5).toString());
            ui->lineEdit_vaccine->setText(qry.value(6).toString());
            ui->lineEdit_shot->setText(qry.value(7).toString());
            ui->lineEdit_date->setText(qry.value(8).toString());
            ui->lineEdit_time->setText(qry.value(9).toString());
        }
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}


void AdminDialog1::on_tableView_activated(const QModelIndex &index){

    QString val = ui->tableView->model()->data(index).toString();
    Login conn;
    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from userInfo where username='"+val+"' or password='"+val+"' or insurance='"+val+"' or firstName='"+val+"' or lastName='"+val+"'"
             " or age='"+val+"' or vaccine='"+val+"' or shot='"+val+"' or date='"+val+"' or time='"+val+"' ");

    qDebug()<<qry.executedQuery();
    if(qry.exec()) {

        while(qry.next()){
            ui->lineEdit_username->setText(qry.value(0).toString());
            ui->lineEdit_pw->setText(qry.value(1).toString());
            ui->lineEdit_insur->setText(qry.value(2).toString());
            ui->lineEdit_fName->setText(qry.value(3).toString());
            ui->lineEdit_lName->setText(qry.value(4).toString());
            ui->lineEdit_age->setText(qry.value(5).toString());
            ui->lineEdit_vaccine->setText(qry.value(6).toString());
            ui->lineEdit_shot->setText(qry.value(7).toString());
            ui->lineEdit_date->setText(qry.value(8).toString());
            ui->lineEdit_time->setText(qry.value(9).toString());
        }
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}


void AdminDialog1::on_listView_activated(const QModelIndex &index){

    QString val = ui->listView->model()->data(index).toString();
    Login conn;

    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("select * from userInfo where username='"+val+"' ");

    qDebug()<<qry.executedQuery();
    if(qry.exec()) {
        while(qry.next()){
            ui->lineEdit_username->setText(qry.value(0).toString());
            ui->lineEdit_pw->setText(qry.value(1).toString());
            ui->lineEdit_insur->setText(qry.value(2).toString());
            ui->lineEdit_fName->setText(qry.value(3).toString());
            ui->lineEdit_lName->setText(qry.value(4).toString());
            ui->lineEdit_age->setText(qry.value(5).toString());
            ui->lineEdit_vaccine->setText(qry.value(6).toString());
            ui->lineEdit_shot->setText(qry.value(7).toString());
            ui->lineEdit_date->setText(qry.value(8).toString());
            ui->lineEdit_time->setText(qry.value(9).toString());
        }
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

void AdminDialog1::on_pushButton_save_clicked(){  // insert
    Login conn;
    User user;
    user.username = ui->lineEdit_username->text();
    user.password = ui->lineEdit_pw->text();
    user.insurance = ui->lineEdit_insur->text();
    user.firstName = ui->lineEdit_fName->text();
    user.lastName = ui->lineEdit_lName->text();
    user.age = ui->lineEdit_age->text();
    user.vaccine = ui->lineEdit_vaccine->text();
    user.shot = ui->lineEdit_shot->text();
    user.date = ui->lineEdit_date->text();
    user.time = ui->lineEdit_time->text();
    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into userInfo (username,password,insurance,firstName,lastName,age,vaccine,shot,date,time) "
     "values ('"+user.username+"','"+user.password+"','"+user.insurance+"','"+user.firstName+"','"+user.lastName+"','"+user.age+"','"+user.vaccine+"','"+user.shot+"','"+user.date+"','"+user.time+"' )" );

    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        QMessageBox::information(this,tr("Save"),tr("Data Saved!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
    qDebug()<< user.username + " saved her (his) infomation: ";
    qDebug()<< user.username + " , " + user.password + " , " + user.insurance + " , " + user.firstName + " , " + user.lastName +
               " , " + user.age + " , " + user.vaccine + " , " + user.shot + " , " + user.date + " , " + user.time;
}


void AdminDialog1::on_pushButton_update_clicked(){  // update
    Login conn;
    User user;
    user.username = ui->lineEdit_username->text();
    user.password = ui->lineEdit_pw->text();
    user.insurance = ui->lineEdit_insur->text();
    user.firstName = ui->lineEdit_fName->text();
    user.lastName = ui->lineEdit_lName->text();
    user.age = ui->lineEdit_age->text();
    user.vaccine = ui->lineEdit_vaccine->text();
    user.shot = ui->lineEdit_shot->text();
    user.date = ui->lineEdit_date->text();
    user.time = ui->lineEdit_time->text();

    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("update userInfo set username='"+user.username+"',password='"+user.password+"',insurance='"+user.insurance+"',firstName='"+user.firstName+"',lastName='"+user.lastName+"'"
             ",age='"+user.age+"',vaccine='"+user.vaccine+"',shot='"+user.shot+"',date='"+user.date+"',time='"+user.time+"' where username='"+user.username+"'" );

    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        QMessageBox::information(this,tr("Edit"),tr("Data Updated!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }

    qDebug()<< user.username + " Updated infomation: ";
    qDebug()<< user.username + " , " + user.password + " , " + user.insurance + " , " + user.firstName + " , " + user.lastName +
               " , " + user.age + " , " + user.vaccine + " , " + user.shot + " , " + user.date + " , " + user.time;

}


void AdminDialog1::on_pushButton_delete_clicked(){ // delete
    Login conn;
    User user;
    user.username = ui->lineEdit_username->text();   //only need a unique variable, find whole row and delete

    if(!conn.connOpen()){
        qDebug() <<"Failed to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("Delete from userInfo where username='"+user.username+"'");
    qDebug()<<qry.executedQuery();

    if(qry.exec()) {
        QMessageBox::information(this,tr("Delete"),tr("Data Deleted!"));
        conn.connClose();
    }else{
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }

    qDebug()<< user.username + " deleted infomation: ";
    qDebug()<< user.username + " , " + user.password + " , " + user.insurance + " , " + user.firstName + " , " + user.lastName +
               " , " + user.age + " , " + user.vaccine + " , " + user.shot + " , " + user.date + " , " + user.time;
}

void AdminDialog1::on_pushButton_quit_clicked(){
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the login page? ", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "Answer 'NO' Button is clicked";
    }
}
