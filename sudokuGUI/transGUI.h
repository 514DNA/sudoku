#pragma once
#include <QLineEdit>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QString>
#include <ui_sudokuGUI.h>
#include <QObject>
#include <QWidget>
#include <QJsonArray>
#include "core.h"
class transGUI : public QObject{
	Q_OBJECT
public:
	QTimer *timer;
	QLineEdit *sudokuLineEdit[9][9];
	transGUI(Ui_sudokuGUIClass UI);
	void writeRecord();
signals:
	public slots:
	void play();
	void updateTime();
	void stop();
	void goOn();
	void option();
	void quit();
	void quitCancel();
	void inform();
	void submit();
private:
	Ui_sudokuGUIClass ui;
	Core core;
	QTime recTime;
	QLabel *sudokuLabel[9][9];
	int **answer, **puzzle;
	int mode = 0;
	FILE *fp;
	QTime recTimes[3];
	void readRecord();

};