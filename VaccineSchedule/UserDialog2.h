#ifndef USERDIALOG2_H
#define USERDIALOG2_H

#include <QDialog>
#include <UserDialog1.h>

namespace Ui {
class UserDialog2;
}

class UserDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog2(QWidget *parent = nullptr);
    ~UserDialog2();

private:
    Ui::UserDialog2 *ui;

};

#endif // USERDIALOG2_H
