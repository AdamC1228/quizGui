#ifndef LANDING_H
#define LANDING_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include "quizwindow.h"
#include "settings.h"
#include "quiz.h"
#include "scoresheet.h"


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
    void onQuizClose();

    void onSheetClose();
private:
    //Variables
    settings *mySettings;
    quizWindow *myQuizWindow;
    quiz *theQuiz;
    QTimer *myTimer;
    scoreSheet *mySheet;

    //Members
    Ui::landing *ui;

};

#endif // LANDING_H
