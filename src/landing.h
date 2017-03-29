#ifndef LANDING_H
#define LANDING_H

#include <QMainWindow>
#include <QDebug>
#include "settings.h"
#include "quiz.h"


namespace Ui {
class landing;
}

class landing : public QMainWindow
{
    Q_OBJECT

public:
    explicit landing(QWidget *parent = 0);
    ~landing();

private slots:
    void on_btnSettings_clicked();
    void onSettingsClose();
    void on_btnStart_clicked();
    void on_btnScores_clicked();

    void on_btnExit_clicked();

    void closeEvent(QCloseEvent *event);
private:
    //Variables
    settings *mySettings;
    quiz *theQuiz;

    //Members
    Ui::landing *ui;
};

#endif // LANDING_H
