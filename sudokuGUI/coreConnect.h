#pragma once
#include "transGUI.h"
#include <QObject>
class coreConnect :public QObject{
	Q_OBJECT
public:
	coreConnect(Ui_sudokuGUIClass UI, transGUI *Trans);
	void startConnect();
private:
	Ui_sudokuGUIClass ui;
	transGUI *trans;
};