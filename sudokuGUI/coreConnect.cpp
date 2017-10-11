#include "coreConnect.h"
#include "transGUI.h"

coreConnect::coreConnect(Ui_sudokuGUIClass UI, transGUI *Trans) {
	ui = UI;
	trans = Trans;
}

void coreConnect::startConnect() {
	connect(ui.startButton, SIGNAL(clicked()), trans, SLOT(play()));
}