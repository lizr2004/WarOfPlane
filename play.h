#ifndef PLAY_H
#define PLAY_H

#include <QWidget>
#include "plane.h"
#include <QList>
#include <QTimer>

namespace Ui {
class play;
}

class play : public QWidget
{
	Q_OBJECT

public:
	explicit play(QWidget *parent = 0);
	~play();

private:
	Ui::play *ui;
	QList<plane*> pls;
	QTimer *move_timer;

private slots:
	void restart();
	void update(bool x);
	void update();
	void timeout();
	void addPlane();
};

#endif // PLAY_H
