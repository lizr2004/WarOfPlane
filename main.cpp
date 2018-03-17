#include "play.h"
#include <QApplication>
#include <QTime>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
	play w;
	w.show();
	return a.exec();
}
