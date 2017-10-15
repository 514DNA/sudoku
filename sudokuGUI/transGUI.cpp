#include "transGUI.h"
#include <string.h>
#include <QJsonDocument>

transGUI::transGUI(Ui_sudokuGUIClass UI) {
	ui = UI;
	option();
	core.set_play(true);
	answer = new int*[9];
	puzzle = new int*[9];
	for (int i = 0; i < 9; i++) {
		answer[i] = new int[9];
		puzzle[i] = new int[9];
		memset(answer[i], 0, sizeof(int) * 9);
		memset(puzzle[i], 0, sizeof(int) * 9);
	}
	ui.informButton->setFocusPolicy(Qt::NoFocus);
}

void transGUI::option() {
	ui.normalOption->setChecked(true);
	ui.gridLayoutWidget->hide();
	ui.submitButton->hide();
	ui.gridLayoutWidget_2->hide();
	ui.verticalLayoutWidget_3->hide();
	ui.gridLayoutWidget_3->hide();
	ui.gridLayoutWidget_5->hide();
	return;
}

void transGUI::updateTime() {
	recTime = recTime.addSecs(1);
	ui.timeLcd->display(recTime.toString("HH:mm:ss"));
	return;
}

void transGUI::stop() {
	ui.stopButton->setText(QStringLiteral("¼ÌÐø"));
	return;
}

void transGUI::goOn() {
	ui.stopButton->setText(QStringLiteral("ÔÝÍ£"));
	return;
}

void transGUI::play() {
	bool hard = ui.hardOption->isChecked();
	bool normal = ui.normalOption->isChecked();
	bool simple = ui.simpleOption->isChecked();
	if (hard) {
		mode = 3;
	}
	else if (normal) {
		mode = 2;
	}
	else if (simple) {
		mode = 1;
	}
	else {
	}
	ui.InformNumber->setText("");
	ui.recordNum->setText("");
	ui.gridLayoutWidget->show();
	ui.gridLayoutWidget_2 ->show();
	ui.verticalLayoutWidget_3->show();
	ui.submitButton->show();
	recTime.setHMS(0, 0, 0);
	int i = 0, j = 0, k = 0;
	int **result = new int *[2];
	result[0] = new int[81];
	result[1] = new int[81];
	core.generate(1, mode, result);
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			answer[i][j] = result[0][k];
			puzzle[i][j] = result[1][k++];
		}
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (puzzle[i][j] == 0) {
				sudokuLineEdit[i][j] = new QLineEdit(ui.gridLayoutWidget);
				sudokuLineEdit[i][j]->setFocusPolicy(Qt::ClickFocus);
				sudokuLineEdit[i][j]->setObjectName(QString::number(i*9+j));
				sudokuLineEdit[i][j]->setFixedSize(30, 30);
				sudokuLineEdit[i][j]->setStyleSheet(QStringLiteral("font: 75 12pt \"Microsoft YaHei UI\";"));
				ui.sudokuLayout->addWidget(sudokuLineEdit[i][j], i, j, 1, 1);
				sudokuLineEdit[i][j]->show();
			}
			else {
				sudokuLabel[i][j] = new QLabel(ui.gridLayoutWidget);
				sudokuLabel[i][j]->setObjectName(QStringLiteral("label"));
				sudokuLabel[i][j]->setText(QString::number(puzzle[i][j], 10));
				sudokuLabel[i][j]->setAlignment(Qt::AlignHCenter);
				sudokuLabel[i][j]->setFixedSize(30, 30);
				sudokuLabel[i][j]->setStyleSheet(QStringLiteral("font: 75 12pt \"Microsoft YaHei UI\";"));
				ui.sudokuLayout->addWidget(sudokuLabel[i][j], i, j, 1, 1);
				sudokuLabel[i][j]->show();
			}
		}
	}
	return;
}

void transGUI::quit() {
	ui.gridLayoutWidget_3->show();
	ui.submitButton->setDisabled(true);
	ui.quitButton->setDisabled(true);
	ui.backButton->setDisabled(true);
	ui.informButton->setDisabled(true);
	ui.stopButton->setDisabled(true);
	ui.timeLcd->setDisabled(true);
	return;
}

void transGUI::quitCancel() {
	ui.gridLayoutWidget_3->hide();
	ui.submitButton->setDisabled(false);
	ui.quitButton->setDisabled(false);
	ui.backButton->setDisabled(false);
	ui.informButton->setDisabled(false);
	ui.stopButton->setDisabled(false);
	ui.timeLcd->setDisabled(false);
	return;
}

void transGUI::inform() {
	int num = 0, result = 0;
	QWidget *f = QApplication::focusWidget();
	if (f != NULL && f->inherits("QLineEdit")) {
		num = (f->objectName()).toInt();
		result = answer[num / 9][num % 9];
		ui.InformNumber->setText(QString::number(result));
		ui.InformNumber->setAlignment(Qt::AlignHCenter);
	}
	return;
}

void transGUI::submit() {
	int i = 0, j = 0, num = 0, sign = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (puzzle[i][j] == 0) {
				try {
					num = (sudokuLineEdit[i][j]->text()).toInt();
				}
				catch (exception e) {
					sign = -1;
					break;
				}
				if (num != answer[i][j]) {
					sign = -1;
					break;
				}
			}
		}
	}
	if (sign == -1) {
		ui.SubmitLabel->setText("Fail");
	}
	else {
		ui.SubmitLabel->setText("Win");
	}

	ui.SubmitLabel->setAlignment(Qt::AlignHCenter| Qt::AlignVCenter);
	ui.gridLayoutWidget_5->show();
	return;
}