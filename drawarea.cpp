#include "drawarea.h"
#include <QPaintEvent>
#include <QPainter>
#include "shape.h"
#include <vector>
#include <iostream>

DrawArea::DrawArea(QWidget *parent) : QWidget(parent)
{
	setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize DrawArea::minimumSizeHint() const {
	return QSize(100,400);
}

QSize DrawArea::sizeHint() const {
	return QSize(400,400);
}

void DrawArea::mousePressEvent(QMouseEvent *event) {
	if(event->button() == Qt::LeftButton) {
		Shape *s = new Shape;
		s->setX(QCursor::pos().x()-67);
		s->setY(QCursor::pos().y()-162);
		s->setWidth(QCursor::pos().x()+30);
        s->setHeight(QCursor::pos().y()+30);
		std::cout << "X0: " << QCursor::pos().x() << ", Y0: " << QCursor::pos().y() << std::endl;
		shapes.push_back(*s);
		update();
	}
}

void DrawArea::paintEvent(QPaintEvent *event) {
	Q_UNUSED(event);
	QPainter painter(this);
	painter.drawRect(this->rect());
	painter.setPen(palette().dark().color());
	painter.setBrush(Qt::NoBrush);
	vector<Shape>::iterator it;
	for(it = shapes.begin(); it != shapes.end(); ++it) {
		painter.drawRect(it->X(),it->Y(),it->Width(),it->Height());
	}
}
