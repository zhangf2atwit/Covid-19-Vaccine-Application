#include "UserDialog2.h"
#include "UserDialog1.h"
#include "ui_UserDialog2.h"

UserDialog2::UserDialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog2)
{
    ui->setupUi(this);
}

UserDialog2::~UserDialog2()
{
    delete ui;
}
