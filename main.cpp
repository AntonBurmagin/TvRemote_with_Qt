#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <./ui_tv_remote.h>
#include <QTimer>
#include "TvRemoteMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    TvRemoteMainWindow window( nullptr);
    Ui::MainWindow tv_remote;
    tv_remote.setupUi(&window);
    window.lineEdit=tv_remote.lineEdit;
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &window, [&]() {
        std::cout << window.timeOff() << " - " << window.getTimeStart() << " - " << window.getTimeEnd() << std::endl;
        if (window.timeOff())
            window.changeChannel();

    });
    timer.start(1000);
    window.resize(240, 680);
    window.show();
    return QApplication::exec();
}
