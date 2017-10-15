#pragma once
#include "transGUI.h"
#include <QObject>
#include <QTimer>
class coreConnect :public QObject{
	Q_OBJECT
public:
	coreConnect(Ui_sudokuGUIClass UI, transGUI *Trans);

private:
	Ui_sudokuGUIClass ui;
	transGUI *trans;
	QTimer *timer;
	void startConnect();
	void timeConnect();
	void resetTimeConnect();
	void backConnect();
	void quitConnect();
	void quitCancelConnect();
	void informConnect();
	void submitConnect();
	void setTimer();
	void againConnect();
signals:
	private slots:
	void reSetTimer();
};