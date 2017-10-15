#include "sudokuGUI.h"

sudokuGUI::sudokuGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	trans = new transGUI(ui);
	coreCo = new coreConnect(ui, trans);
	connect(ui.quitSureButton, SIGNAL(clicked()), this, SLOT(send()));
	connect(ui.awayButton, SIGNAL(clicked()), this, SLOT(send()));
}

void sudokuGUI::send() {
	trans->writeRecord();
	emit sureOut();
}
