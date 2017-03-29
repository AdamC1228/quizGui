#include "landing.h"
#include "ui_landing.h"
#include <QCloseEvent>

landing::landing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::landing)
{
    ui->setupUi(this);


    //On Form Load
    theQuiz = new quiz();

    mySettings = new settings();
    mySettings->setQuiz(theQuiz);
    QObject::connect(mySettings,SIGNAL(imClosing()),this,SLOT(onSettingsClose()));


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
        ui->btnStart->setDisabled(false);
    else
        ui->btnStart->setDisabled(true);


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
}

void landing::on_btnScores_clicked()
{
    qDebug()<<"Button Scores!";
}

void landing::on_btnExit_clicked()
{
    qDebug()<<"Button Exit!";
    exit(EXIT_SUCCESS);
}
