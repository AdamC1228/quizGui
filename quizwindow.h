#ifndef QUIZWINDOW_H
#define QUIZWINDOW_H

#include <QMainWindow>

namespace Ui {
class quizWindow;
}

class quizWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit quizWindow(QWidget *parent = 0);
    ~quizWindow();

private:
    Ui::quizWindow *ui;
};

#endif // QUIZWINDOW_H
