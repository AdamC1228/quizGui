#include "scoresheet.h"
#include "ui_scoresheet.h"

scoreSheet::scoreSheet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scoreSheet)
{
    ui->setupUi(this);
    count = 0;
}

scoreSheet::~scoreSheet()
{
    delete ui;
}

void scoreSheet::on_btnFinished_clicked()
{
    emit imClosing();
}

void scoreSheet::appendScore(QString temp)
{
    count++;
    QString old = ui->txtScores->toPlainText();
    ui->txtScores->setText("Attempt "+QString::number(count)+"\t"+QTime::currentTime().toString().trimmed()+"\n"+temp+"\n\n\n"+old);
}

void scoreSheet::quizChanged(QString info)
{

    QString old = ui->txtScores->toPlainText();
    ui->txtScores->setText("<-------------------------------------------------------------------------------------->\n" + QTime::currentTime().toString().trimmed() +"\tUser selected new quiz:"+info+"\n"+
                           "<-------------------------------------------------------------------------------------->\n"+old);
}

void scoreSheet::closeEvent(QCloseEvent *event)
{
    emit imClosing();
}
