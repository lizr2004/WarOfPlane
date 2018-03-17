#include "play.h"
#include "ui_play.h"
#include <QDebug>
play::play(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::play)
{
	ui->setupUi(this);
	setFixedSize(1200,900);
	move_timer = new QTimer();
//	spawn_timer = new QTimer();
	connect(move_timer, SIGNAL(timeout()), this, SLOT(update()));
//	connect(spawn_timer, SIGNAL(timeout()), this, SLOT(addPlane()));
	connect(ui->restartButton, SIGNAL(clicked()), this, SLOT(restart()));
//	connect(ui->restartButton, SIGNAL(clicked()), this, SLOT(addPlane()));
	move_timer->start(15);
//	spawn_timer->start(2000);
	addPlane();
}

void play::addPlane()
{
	plane *pl = new plane;
	pls.append(pl);
	ui->continer->addWidget(pl);
	return;
}
void play::update(bool x)
{
	const int R = RAND_MAX >> 8;
	if(qrand()<R)addPlane();
	for(auto it = pls.begin();it!=pls.end();it++)
	{
		plane *now = *it;
//		now->y+=x;
//		now->setGeometry(QRect(now->x,now->y,now->x+80,now->y+120));
		emit now->update(x);
		if(now->hp <=0 || now->y >=800)
		{
			ui->continer->removeWidget(now);
			delete now;
			pls.erase(it);
		}
	}
//	ui->infoBar->setGeometry(QRect(0,130,400,300));
	return;
}

void play::update()
{
	update(true);
}

void play::timeout()
{
	update(true);
}

void play::restart()
{
	return;
}

play::~play()
{
	delete ui;
}
