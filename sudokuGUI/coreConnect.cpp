#include "coreConnect.h"
#include "transGUI.h"

coreConnect::coreConnect(Ui_sudokuGUIClass UI, transGUI *Trans) {
	ui = UI;
	trans = Trans;
	startConnect();
	timeConnect();
	resetTimeConnect();
	backConnect();
	quitConnect();
	quitCancelConnect();
	informConnect();
	submitConnect();
	againConnect();
}

void coreConnect::startConnect() {
	connect(ui.startButton, SIGNAL(clicked()), this, SLOT(reSetTimer()));
}

void coreConnect::timeConnect() {
	setTimer();
	connect(timer, SIGNAL(timeout()), trans, SLOT(updateTime()));
	return;
}

void coreConnect::resetTimeConnect() {
	connect(ui.stopButton, SIGNAL(clicked()), this, SLOT(reSetTimer()));
	return;
}

void coreConnect::backConnect() {
	connect(ui.backButton, SIGNAL(clicked()), trans, SLOT(option()));
	return;
}

void coreConnect::quitConnect() {
	connect(ui.quitButton, SIGNAL(clicked()), trans, SLOT(quit()));
	return;
}

void coreConnect::quitCancelConnect() {
	connect(ui.quitCancelButton, SIGNAL(clicked()), trans, SLOT(quitCancel()));
	return;
}

void coreConnect::informConnect() {
	connect(ui.informButton, SIGNAL(clicked()), trans, SLOT(inform()));
	return;
}

void coreConnect::submitConnect() {
	connect(ui.submitButton, SIGNAL(clicked()), trans, SLOT(submit()));
	return;
}

void coreConnect::againConnect() {
	connect(ui.againButton, SIGNAL(clicked()), trans, SLOT(option()));
	return;
}

void coreConnect::setTimer() {
	timer = new QTimer();
	timer->setInterval(1000);
	timer->start();
	return;
}

void coreConnect::reSetTimer() {
	if (ui.startButton->hasFocus()) {
			timer->start();
			trans->goOn();
			trans->play();
	}
	else if (timer->isActive()) {
		timer->stop();
		trans->stop();
	}
	else {
		timer->start();
		trans->goOn();
	}
	return;
}

