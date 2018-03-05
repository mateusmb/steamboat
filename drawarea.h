#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QColor>
#include <vector>
#include "shape.h"

using namespace std;

class DrawArea : public QWidget
{
	Q_OBJECT
public:
	explicit DrawArea(QWidget *parent = nullptr);

	enum ShapeOption { Rect };
//	void   setBackgroundColor(QColor color) { background_color = color; repaint(); }
//	QColor getBackgroundColor() const { return background_color; }
	void   setShape(ShapeOption so) { shape_option = so; };
	QSize  minimumSizeHint() const Q_DECL_OVERRIDE;
	QSize  sizeHint() const Q_DECL_OVERRIDE;
	void   mousePressEvent(QMouseEvent *event);
	void   mouseMoveEvent(QMouseEvent *event);
	void   mouseReleaseEvent(QMouseEvent *event);
protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;


private:
	ShapeOption shape_option;
//	QColor background_color;
    vector<Shape> shapes;
	Shape *shape;
	int x0, y0, xf, yf;
	bool dragged, translate, rotate, scale;

signals:

public slots:
};

#endif // DRAWAREA_H
