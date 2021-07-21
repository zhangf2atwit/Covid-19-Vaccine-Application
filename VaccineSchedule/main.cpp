#include "Login.h"

#include <QApplication>
#include <QTabWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //set the app style sheet
    QFile styleSheetFile(":/qss/Irrorater.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    Login w;
    w.show();   // window is fefault when it built. So need be show by reset "show";
    return a.exec();  // make the program keep running, wait the event happen
}

