#ifndef PLANE_H
#define PLANE_H

#include <QWidget>

namespace Ui {
class plane;
}

class plane : public QWidget
{
	Q_OBJECT

public:
	explicit plane(QWidget *parent = 0);
	~plane();
	int hp,x,y;

public slots:
	void subHp(int sub);
	void do_update(bool move);

private:
	Ui::plane *ui;

};

#endif // PLANE_H
