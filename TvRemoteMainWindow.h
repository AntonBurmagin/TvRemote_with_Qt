

#ifndef HW_37_4_3_TV_REMOTE_TVREMOTEMAINWINDOW_H
#define HW_37_4_3_TV_REMOTE_TVREMOTEMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <iostream>
#include <QTime>
#include <QTimer>
#include <ctime>

class TvRemoteMainWindow : public QMainWindow {
    Q_OBJECT
public:
    QLineEdit *lineEdit = nullptr;
    time_t timeStart=0;
    time_t timeEnd=0;
    int channel = -1;
    int volume = 0;
    QTimer *timer = nullptr;


    TvRemoteMainWindow (QWidget *parent = nullptr) : QMainWindow(parent) {}

public slots:
    void on() {
        if (channel==-1) {
            channel = 0;
            lineEdit->setText("playing: "+QString::number(channel) + ", volume: " + QString::number(volume));
        } else {
            channel=-1;
            lineEdit->setText("");
        }
    };

    void resetTime () {
        timeStart=0;
        timeEnd=0;
    }

    void changeChannel () {
        lineEdit->setText("playing: " + QString::number(channel) + ", volume: " + QString::number(volume));
        resetTime();
        timer->stop();
        timer=nullptr;
    }

    bool timeOff () {
        if (timeStart!=0) {
            timeEnd = time(0);
            if (timeStart + 3 < timeEnd)
                return true;
        }
        return false;
    }

    time_t getTimeStart () {
        return timeStart;
    }
    time_t getTimeEnd () {
        return timeEnd;
    }
    void buttonSame (QString number) {
        if(channel!=-1) {
            timeStart=time(0);
            if (lineEdit->text()[0] == 'p') {
                lineEdit->setText(number);
                channel = lineEdit->text().toInt();
            } else {
                lineEdit->setText(lineEdit->text() + number);
                channel = lineEdit->text().toInt();
            }
            if (timer==nullptr && lineEdit->text().count()<2) {
                timer=new QTimer(0);
                QObject::connect(timer, &QTimer::timeout, [&]() {
                    std::cout << timeStart << " - " << timeEnd << std::endl;
                    if (timeOff())
                        changeChannel();
                });
                timer->start(1000);
            }
        }
    }

    void zero() {
        buttonSame("0");
    };
    void one() {
        buttonSame("1");
    };
    void two() {
        buttonSame("2");
    };
    void three() {
        buttonSame("3");
    };
    void four() {
        buttonSame("4");
    };
    void five() {
        buttonSame("5");
    };
    void six() {
        buttonSame("6");
    };
    void seven() {
        buttonSame("7");
    };
    void eight() {
        buttonSame("8");
    };
    void nine() {
        buttonSame("9");
    };


    void plus(int volumeChange=10) {
        if (channel!=-1) {
            if ((volumeChange > 0 && volume < 100) || (volumeChange < 0 && volume > 0)) {
                volume += volumeChange;
                lineEdit->setText("playing: " + QString::number(channel) + ", volume: " + QString::number(volume));
                resetTime();
            }
        }
    };

    void minus() {
        plus(-10);
    };

    void next(int x=1) {
        if (channel>0 || (channel==0 && x!=-1)) {
            channel += x;
            lineEdit->setText("playing: " + QString::number(channel) + ", volume: " + QString::number(volume));
            resetTime();
        }
    };

    void previous() {
        next(-1);
    };

};


#endif //HW_37_4_3_TV_REMOTE_TVREMOTEMAINWINDOW_H
