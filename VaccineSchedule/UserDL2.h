#ifndef USERDL2_H
#define USERDL2_H

#include <QDialog>

namespace Ui {
class UserDL2;
}

class UserDL2 : public QDialog
{
    Q_OBJECT

public:
    explicit UserDL2(QWidget *parent = nullptr);
    ~UserDL2();

private:
    Ui::UserDL2 *ui;
};

#endif // USERDL2_H
