#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include "quiz.h"

namespace Ui {
    class settings;
}

class settings : public QMainWindow
{
    Q_OBJECT
signals:
    void imClosing();

public:
    explicit settings(QMainWindow *parent = 0);
    void setQuiz(quiz *);
    ~settings();

    bool isValid();
private slots:
    void closeEvent(QCloseEvent *event);

    void on_btnFileBrowse_clicked();

    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    //Variables
    QString oldFileName;
    QString fileName;
    int oldNumToAsk;
    int numToAsk;
    int oldTime;
    int time;
    bool valid =false;
    quiz *theQuiz;

    //Private Members
    Ui::settings *ui;
};

#endif // SETTINGS_H
