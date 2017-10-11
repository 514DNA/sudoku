#pragma once
#include <QLineEdit>
#include <QTimer>
#include <QLabel>
#include <QString>
#include <ui_sudokuGUI.h>
#include <QObject>
class transGUI : public QObject{
	Q_OBJECT
public:
	transGUI(Ui_sudokuGUIClass UI);
	void mode();
	void option();
signals:
	public slots:
	void play();
private:
	Ui_sudokuGUIClass ui;
	QLineEdit *sudokuLineEdit[9][9];
	QLabel *sudokuLabel[9][9];
	QTimer *timer;
};