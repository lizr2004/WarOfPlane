#include "plane.h"
#include "ui_plane.h"
#include <QDebug>
plane::plane(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::plane)
{
	ui->setupUi(this);
	this->setFixedSize(80,120);
	hp = 100;
	x = qrand()%1100; y = -100;
	qDebug() << x << ' ' << y << ' ' << hp;
	connect(this, SIGNAL(update(bool)), this, SLOT(do_update(bool)));
	emit update(false);
}

void plane::subHp(int sub)
{
	hp-=sub;
	emit update(false);
	return;
}

void plane::do_update(bool move)
{
	if(move)y++;
	setGeometry(QRect(x,y,x+80,y+120));
	ui->hpLabel->setText(QString::number(hp));
}

plane::~plane()
{
	delete ui;
}
