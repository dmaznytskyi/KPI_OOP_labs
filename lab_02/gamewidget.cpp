#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("TETRIS");
	setFixedSize(500,500);

	main_layout.addWidget(&prog_bar);
	main_layout.setAlignment(Qt::AlignBottom);
	setLayout(&main_layout);
	prog_bar.setMinimum(0);
	prog_bar.setMaximum(100);
	connect(&timer,SIGNAL(timeout()),SLOT(progBar()));
	timer.start();
}

GameWidget::~GameWidget()
{

}

void GameWidget::progBar()
{
	if (prog_bar.value() < prog_bar.maximum())
		prog_bar.setValue(prog_bar.value()+1);
	else
	{
		prog_bar.setHidden(true);
		timer.stop();
	}
}

void GameWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	//TODO with pixmap
	QPoint p0;
	QImage bckg(":/main_menu/00.jpg");
	painter.drawImage(p0, bckg);

}
