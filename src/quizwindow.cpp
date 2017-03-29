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
