#include "landing.h"
#include "ui_landing.h"
#include <QCloseEvent>
#include <QTimer>
#include <QMessageBox>

landing::landing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::landing)
{
    ui->setupUi(this);


    //On Form Load
    theQuiz = new quiz();

    mySheet = new scoreSheet();

    mySettings = new settings();
    mySettings->setQuiz(theQuiz);
    QObject::connect(mySettings,SIGNAL(imClosing()),this,SLOT(onSettingsClose()));

    myQuizWindow = new quizWindow();
    myQuizWindow->setQuiz(theQuiz);
    QObject::connect(myQuizWindow,SIGNAL(imClosing()),this,SLOT(onQuizClose()));

    myTimer = new QTimer();
    QObject::connect(myTimer,SIGNAL(timeout()),this,SLOT(onQuizClose()));
    QObject::connect(mySheet,SIGNAL(imClosing()),this,SLOT(onSheetClose()));
}

landing::~landing()
{
    delete ui;
}




/*********************************************************************************
 *********************************************************************************

                                      EVENT HANDLING

 *********************************************************************************
 ********************************************************************************/


void landing::on_btnSettings_clicked()
{
    qDebug()<<"Button Settings!";
    mySettings->show();
    this->setDisabled(true);
}

void landing::onSettingsClose()
{
    qDebug()<<"Window Settings Closed!";
    this->setDisabled(false);

    if(mySettings->isValid())
    {
        ui->btnStart->setDisabled(false);
        mySheet->quizChanged(mySettings->getInfo());
    }
    else
    {
        ui->btnStart->setDisabled(true);
    }
}

void landing::onQuizClose()
{
    myTimer->stop();
    myQuizWindow->hide();

    QMessageBox thankYou;
    thankYou.setWindowTitle("Quiz Over");
    thankYou.setText(theQuiz->quizOver());
    thankYou.exec();

    mySheet->appendScore(theQuiz->quizOver());

    this->setDisabled(false);
}

void landing::onSheetClose()
{
    mySheet->hide();
    this->setDisabled(false);
}


//Override form close to prevent closing of the landing if
//secondary form is open at present.
void landing::closeEvent(QCloseEvent *event)
{
    if (this->isEnabled())
    {
        event->accept();
    } else
    {
        event->ignore();
    }
}

//Button Events

void landing::on_btnStart_clicked()
{
    qDebug()<<"Button Start!";

    theQuiz->reset();

    myQuizWindow->beginQuiz();
    myQuizWindow->show();

    myTimer->start(mySettings->getTime());
    this->setDisabled(true);
}

void landing::on_btnScores_clicked()
{
    qDebug()<<"Button Scores!";
    this->setDisabled(true);
    mySheet->show();
}

void landing::on_btnExit_clicked()
{
    qDebug()<<"Button Exit!";
    exit(EXIT_SUCCESS);
}
