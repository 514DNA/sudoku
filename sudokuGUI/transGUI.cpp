#include "transGUI.h"
transGUI::transGUI(Ui_sudokuGUIClass UI) {
	ui = UI;
}

void transGUI::mode() {

}

void transGUI::option() {
	ui.gridLayoutWidget->hide();
	ui.verticalLayoutWidget->hide();
	ui.verticalLayoutWidget_3->hide();
}

void transGUI::play() {
	ui.gridLayoutWidget->show();
	ui.verticalLayoutWidget->show();
	ui.verticalLayoutWidget_3->show();
	int i = 0, j = 0;
	int **sudoku = new int*[9];
	for (i = 0; i < 9; i++) {
		sudoku[i] = new int[9];
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0) {
				sudokuLineEdit[i][j] = new QLineEdit(ui.gridLayoutWidget);
				sudokuLineEdit[i][j]->setObjectName(QStringLiteral("lineedit"));
				sudokuLineEdit[i][j]->setPlaceholderText(QStringLiteral());
				ui.sudokuLayout->addWidget(sudokuLineEdit[i][j], i, j, 1, 1);
				sudokuLineEdit[i][j]->show();
			}
			else {
				sudokuLabel[i][j] = new QLabel(ui.gridLayoutWidget);
				sudokuLabel[i][j]->setObjectName(QStringLiteral("label"));
				sudokuLabel[i][j]->setText(QString::number(sudoku[i][j], 10));
				ui.sudokuLayout->addWidget(0, i, j, 1, 1);
				sudokuLabel[i][j]->show();
			}

		}
	}
}