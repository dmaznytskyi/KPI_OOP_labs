#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("TETRIS");
	setFixedSize(500,500);

	QImage logo(":/main_menu/TetrisLogo.png");
	QPixmap logomap = QPixmap::fromImage(logo);
	logo_pic.setPixmap(logomap.scaledToWidth(400));
	logo_pic.setHidden(true);
	logo_pic.setAlignment(Qt::AlignHCenter);
	main_layout.addWidget(&logo_pic);
	main_layout.addStretch(true);
	main_layout.addWidget(&prog_bar);
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
		logo_pic.setHidden(false);
	}
}

void GameWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QPoint p0;
	QImage bckg(":/main_menu/00.jpg");
	painter.drawImage(p0, bckg);
}
