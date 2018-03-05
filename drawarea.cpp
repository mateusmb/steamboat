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
	dragged = translate = rotate = scale = false;
}

QSize DrawArea::minimumSizeHint() const {
	return QSize(100,400);
}

QSize DrawArea::sizeHint() const {
	return QSize(400,400);
}

void DrawArea::mousePressEvent(QMouseEvent *event) {
	if(event->button() == Qt::LeftButton) {
		dragged = true;
		x0 = xf = QCursor::pos().x() - 67;
		y0 = yf = QCursor::pos().y() - 162;
	}
}

void DrawArea::mouseMoveEvent(QMouseEvent *event)
{
	if(dragged) {
		xf = QCursor::pos().x() - 67;
		yf = QCursor::pos().y() - 162;
		update();
	}
}

void DrawArea::mouseReleaseEvent(QMouseEvent *event)
{
	dragged = false;
	update();
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

	shape  = new Shape;
	shape->setX(x0);
	shape->setY(y0);
	shape->setWidth(xf-x0);
	shape->setHeight(yf-y0);
	painter.drawRect(shape->X(),shape->Y(),shape->Width(),shape->Height());

	if(!dragged) {
		shapes.push_back(*shape);
	}
}
