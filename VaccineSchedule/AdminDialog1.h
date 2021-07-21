#ifndef ADMINDIALOG1_H
#define ADMINDIALOG1_H

#include <QDialog>


namespace Ui {
class AdminDialog1;
}

class AdminDialog1 : public QDialog
{
    Q_OBJECT

public:

    explicit AdminDialog1(QWidget *parent = nullptr);
    ~AdminDialog1();

private slots:
    void on_pushButton_loadInfo_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_listView_activated(const QModelIndex &index);

    void on_pushButton_update_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_quit_clicked();

private:
    Ui::AdminDialog1 *ui;

};

#endif // ADMINDIALOG1_H
