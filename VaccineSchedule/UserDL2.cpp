#include "UserDL2.h"
#include "ui_UserDL2.h"

UserDL2::UserDL2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDL2)
{
    ui->setupUi(this);
}

UserDL2::~UserDL2()
{
    delete ui;
}
