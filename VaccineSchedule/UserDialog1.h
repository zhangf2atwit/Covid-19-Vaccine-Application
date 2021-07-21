#ifndef USERDIALOG1_H
#define USERDIALOG1_H

#include <QDialog>
#include "UserDL2.h"

namespace Ui {
class UserDialog1;
}

class UserDialog1 : public QDialog
{
    Q_OBJECT

public:

    explicit UserDialog1(QWidget *parent = nullptr);
    ~UserDialog1();

    QString user_name;    // make suer the longin user and edit their own information. Make is same person.
    QString pw;

private slots:

    void on_pushButton_userNextPage_clicked();

    void on_radioButton_Jonson_clicked();

    void on_radioButton_moderna_clicked();

    void on_radioButton_pfizer_clicked();


    void on_radioButton_under18_clicked();

    void on_radioButton_over18_clicked();

    void on_radioButton_over50_clicked();

    void on_radioButton_over65_clicked();


    void on_radioButton_firstShot_clicked();

    void on_radioButton_secondShot_clicked();


    void on_comboBox_hours_activated(const QString &arg1);

private:
    Ui::UserDialog1 *ui;
    UserDL2 *userP2;

};

#endif // USERDIALOG1_H
