#include "play.h"
#include "ui_play.h"
#include <QDebug>
play::play(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::play)
{
	ui->setupUi(this);
	setFixedSize(800, 600);
	move_timer = new QTimer();
	connect(move_timer, SIGNAL(timeout()), this, SLOT(update()));
	connect(ui->restartButton, SIGNAL(clicked()), this, SLOT(restart()));
	move_timer->start(50);
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
	const int R = RAND_MAX >> 6;
	if(qrand()<R)addPlane();
	for(auto it = pls.begin();it!=pls.end();it++)
	{
		plane *now = *it;
		now->do_update(x);
		if(now->hp <=0 || now->y >=800)
		{
			ui->continer->removeWidget(now);
			pls.erase(it);
			delete now;	
		}
	}
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
