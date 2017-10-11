#include "sudokuGUI.h"
#include "coreConnect.h"

sudokuGUI::sudokuGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	transGUI *trans = new transGUI(ui);
	trans->option();
	coreConnect *core = new coreConnect(ui, trans);
	core->startConnect();
}
