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
		void nextAnimFrame();

	protected:
		void paintEvent(QPaintEvent *);

	private:
		int frameNo;
};

#endif // GAMEWIDGET_H
