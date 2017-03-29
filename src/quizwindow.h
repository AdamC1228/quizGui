#ifndef QUIZWINDOW_H
#define QUIZWINDOW_H

#include <QMainWindow>
#include <quiz.h>
#include <question.h>

namespace Ui {
class quizWindow;
}

class quizWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void imClosing();

public:
    explicit quizWindow(QWidget *parent = 0);
    ~quizWindow();

    void beginQuiz();
    void setQuiz(quiz *);

private slots:
        void closeEvent(QCloseEvent *event);
        void on_btnSubmit_clicked();

        void on_btnQuit_clicked();

private:
    //Variables
    quiz *theQuiz;
    QVector<question *> dataArray;

    //Members
    Ui::quizWindow *ui;
    void checkAnswer();
    void updateQuestion();
};

#endif // QUIZWINDOW_H
