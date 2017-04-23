#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("TETRIS");
	setFixedSize(500,500);
	QTimer *timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(nextAnimFrame()));
	timer->start(1);
	update();
}

GameWidget::~GameWidget()
{

}

void GameWidget::nextAnimFrame()
{
	++frameNo;
	update();
}

void GameWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	//TODO with pixmap
	QPoint p0;
	QImage bckg(":/main_menu/00.jpg");
	painter.drawImage(p0, bckg);
	//anim
	painter.translate(500,500);
}
