#include "settings.h"
#include "ui_settings.h"

settings::settings(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    ui->lblError->setText("");
}

settings::~settings()
{
    delete ui;
}

void settings::closeEvent(QCloseEvent *event)
{   
    emit imClosing();
}

void settings::setQuiz(quiz *temp)
{
    theQuiz = temp;
}

int settings::getTime()
{
    return oldTime*1000;
}

QString settings::getInfo()
{
    return "\n \tQuizFile: "+ QFileInfo(fileName).fileName() +
           "\n \tQuestions: " + QString::number(numToAsk) +
           "\n \tTime: " + QString::number(oldTime);
}

void settings::on_btnFileBrowse_clicked()
{
    fileName = QString();

    fileName = QFileDialog::getOpenFileName(this,tr("Open Quiz File"), QDir::currentPath(), tr("All Files (*.*)"));

    ui->txtFile->setText(fileName);
    qDebug()<< "setupQuizFile Function Filename is: " + fileName;

    if(theQuiz->setup(fileName)==0)
    {
        ui->lblError->setText("");
        ui->txtNumQuest->setDisabled(false);
        ui->txtTime->setDisabled(false);
        ui->txtNumQuest->setPlaceholderText("1 to "+QString::number(theQuiz->maxQuestions()));
    }
    else
    {
        ui->lblError->setText("Error: Question file is invalid.");
        ui->txtNumQuest->setDisabled(true);
        ui->txtTime->setDisabled(true);
    }
}

void settings::on_btnOk_clicked()
{
    if(!(ui->txtNumQuest->isEnabled()))
    {
        ui->lblError->setText("Error: Question file is invalid.");
        return;
    }
    if(theQuiz->setQuizLength(ui->txtNumQuest->toPlainText().toInt())!=0)
    {
        valid = false;
        ui->lblError->setText("Error: Invalid number of questions.");
        return;
    }
    if(ui->txtTime->toPlainText().toInt()<=1)
    {
        valid = false;
        ui->lblError->setText("Error: Invalid time limit.");
        return;
    }

    fileName = ui->txtFile->toPlainText();
    numToAsk = ui->txtNumQuest->toPlainText().toInt();
    oldTime = ui->txtTime->toPlainText().toInt();
    valid = true;
    this->close();
}

void settings::on_btnCancel_clicked()
{
    ui->txtFile->setText(fileName);
    ui->txtNumQuest->setText((QString)numToAsk);
    ui->txtTime->setText((QString)time);
    this->close();
}

bool settings::isValid()
{
    return valid;
}
