#-------------------------------------------------
#
# Project created by QtCreator 2017-03-25T17:03:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = quiz
TEMPLATE = app


SOURCES += main.cpp\
        quizwindow.cpp \
    landing.cpp \
    settings.cpp \
    quiz.cpp \
    question.cpp \
    filehelper.cpp \
    scoresheet.cpp

HEADERS  += quizwindow.h \
    landing.h \
    settings.h \
    question.h \
    filehelper.h \
    quiz.h \
    scoresheet.h

FORMS    += quizwindow.ui \
    landing.ui \
    settings.ui \
    scoresheet.ui

DISTFILES += \
    MyIcon.ico

RC_ICONS = MyIcon.ico
