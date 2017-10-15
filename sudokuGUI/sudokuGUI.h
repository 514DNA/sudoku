#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_sudokuGUI.h"
#include "transGUI.h"
#include "coreConnect.h"

class sudokuGUI : public QMainWindow
{
	Q_OBJECT

public:
	sudokuGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::sudokuGUIClass ui;
	transGUI *trans;
	coreConnect *coreCo;

signals :
	void sureOut();
private slots:
	void send();
};
