#ifndef SCORESHEET_H
#define SCORESHEET_H

#include <QMainWindow>
#include <QTime>

namespace Ui {
class scoreSheet;
}


class scoreSheet : public QMainWindow
{
    Q_OBJECT
signals:
    void imClosing();

public:
    explicit scoreSheet(QWidget *parent = 0);
    ~scoreSheet();

    void appendScore(QString);
    void quizChanged(QString fileName);
private slots:
    void on_btnFinished_clicked();

private:
    Ui::scoreSheet *ui;
    long count;
    void closeEvent(QCloseEvent *event);
};

#endif // SCORESHEET_H
