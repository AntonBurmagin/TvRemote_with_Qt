#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QDesktopWidget>
#include <./ui_tv_remote.h>
#include "TvRemoteMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    TvRemoteMainWindow window( nullptr);
    Ui::MainWindow tv_remote;
    tv_remote.setupUi(&window);
    window.lineEdit=tv_remote.lineEdit;
    QDesktopWidget *desc = QApplication::desktop();
    window.move(desc->width()/2-120, 0);
    window.resize(240, 680);
    window.show();
    return QApplication::exec();
}
