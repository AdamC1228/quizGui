#include "quizwindow.h"
#include "ui_quizwindow.h"

quizWindow::quizWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::quizWindow)
{
    ui->setupUi(this);
}

quizWindow::~quizWindow()
{
    delete ui;
}

void quizWindow::setQuiz(quiz *temp)
{
    theQuiz = temp;
}

void quizWindow::beginQuiz()
{
    theQuiz->start();
    dataArray = theQuiz->getDataArray();

    updateQuestion();
}

void quizWindow::closeEvent(QCloseEvent *event)
{
    emit imClosing();
}



/************************************************************
 ************************************************************
 ************************************************************

                    Logic Methods

 ************************************************************
 ************************************************************
 ***********************************************************/

void quizWindow::checkAnswer()
{
    QList<QRadioButton *> allButtons = ui->grpAnswer->findChildren<QRadioButton *>(); //groupBox->findChildren<QRadioButton *>();

    for(int i = 0; i < allButtons.size(); ++i)
    {
        for(int j=0;j<allButtons.size();j++)
        {
            if(allButtons[i]->objectName()==("rdo"+QString::number(j)))
            {
                if(allButtons[i]->isChecked())
                {
                    if(j==((dataArray.at(theQuiz->getCurrentQuestion())->getAnswer())-1))
                    {
                        theQuiz->checkAnswer(j+1);

                    }
                    else
                    {
                        theQuiz->checkAnswer(j+1);

                    }
                    break;
                }
            }
        }
    }

    ui->lblCorrect->setText(QString::number(theQuiz->getCorrect()));
    ui->lblWrong->setText(QString::number(theQuiz->getWrong()));
}

/************************************************************
 ************************************************************
 ************************************************************

                        GUI Stuff

 ************************************************************
 ************************************************************
 ***********************************************************/

void quizWindow::updateQuestion()
{
    ui->lblQuestion->setText(dataArray.at(theQuiz->getCurrentQuestion())->getQuestion());


    ui->rdo0->setText(dataArray.at(theQuiz->getCurrentQuestion())->getChoices().at(0));
    ui->rdo1->setText(dataArray.at(theQuiz->getCurrentQuestion())->getChoices().at(1));

    if(2<dataArray.at(theQuiz->getCurrentQuestion())->getChoices().count())
    {
        ui->rdo2->setVisible(true);
        ui->rdo2->setText(dataArray.at(theQuiz->getCurrentQuestion())->getChoices().at(2));
    }
    else
        ui->rdo2->setVisible(false);

    if(3<dataArray.at(theQuiz->getCurrentQuestion())->getChoices().count())
    {
        ui->rdo3->setText(dataArray.at(theQuiz->getCurrentQuestion())->getChoices().at(3));
        ui->rdo3->setVisible(true);
    }
    else
    {
        ui->rdo3->setVisible(false);
    }

    if(4<dataArray.at(theQuiz->getCurrentQuestion())->getChoices().count())
    {
        ui->rdo4->setText(dataArray.at(theQuiz->getCurrentQuestion())->getChoices().at(4));
        ui->rdo4->setVisible(true);
    }
    else
    {
        ui->rdo4->setVisible(false);
    }

    if(5<dataArray.at(theQuiz->getCurrentQuestion())->getChoices().count())
    {
        ui->rdo5->setText(dataArray.at(theQuiz->getCurrentQuestion())->getChoices().at(5));
        ui->rdo5->setVisible(true);
    }
    else
    {
        ui->rdo5->setVisible(false);
    }

    if(6<dataArray.at(theQuiz->getCurrentQuestion())->getChoices().count())
    {
        ui->rdo6->setText(dataArray.at(theQuiz->getCurrentQuestion())->getChoices().at(6));
        ui->rdo6->setVisible(true);
    }
    else
    {
        ui->rdo6->setVisible(false);
    }

    if(7<dataArray.at(theQuiz->getCurrentQuestion())->getChoices().count())
    {
        ui->rdo7->setText(dataArray.at(theQuiz->getCurrentQuestion())->getChoices().at(7));
        ui->rdo7->setVisible(true);
    }
    else
    {
        ui->rdo7->setVisible(false);
    }

    if(8<dataArray.at(theQuiz->getCurrentQuestion())->getChoices().count())
    {
        ui->rdo8->setText(dataArray.at(theQuiz->getCurrentQuestion())->getChoices().at(8));
        ui->rdo8->setVisible(true);
    }
    else
    {
        ui->rdo8->setVisible(false);
    }

    if(9<dataArray.at(theQuiz->getCurrentQuestion())->getChoices().count())
    {
        ui->rdo9->setText(dataArray.at(theQuiz->getCurrentQuestion())->getChoices().at(9));
        ui->rdo9->setVisible(true);
    }
    else
    {
        ui->rdo9->setVisible(false);
    }
}

void quizWindow::on_btnSubmit_clicked()
{
    qDebug()<< "AT START";
    checkAnswer();
    qDebug()<< "AT IF";

    if(theQuiz->getCurrentQuestion()<theQuiz->numToAsk())
    {
        qDebug()<< "IN IF";
        theQuiz->nextQuestion();
        updateQuestion();
    }
    else
    {
        qDebug()<< "IN ELSE";
        emit imClosing();
    }
}

void quizWindow::on_btnQuit_clicked()
{
    emit imClosing();
}
