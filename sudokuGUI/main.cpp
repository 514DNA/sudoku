#include "sudokuGUI.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	sudokuGUI w;
	w.show();
	a.connect(&w,SIGNAL(sureOut()),&a, SLOT(quit()));
	return a.exec();
}
