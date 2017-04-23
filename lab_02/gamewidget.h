#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QtWidgets>

class GameWidget : public QWidget
{
    Q_OBJECT

	public:
		GameWidget(QWidget *parent = 0);
		~GameWidget();

	public slots:
		void progBar();

	protected:
		void paintEvent(QPaintEvent *);

	private:
		QHBoxLayout main_layout;
		QProgressBar prog_bar;
		QTimer timer;
};

#endif // GAMEWIDGET_H
