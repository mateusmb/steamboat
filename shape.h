#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
public:
	Shape();
	void setX(int x) { this->x = x; };
	int  X() const { return this->x; };
	void setY(int y) { this->y = y; };
	int  Y() const { return this->y; };
	void setWidth(int width) { this->width = width; };
	int  Width() const { return this->width; };
	void setHeight(int height) { this->height = height; };
	int  Height() const { return this->height; };

private:
	int x,y,width,height;

};

#endif // SHAPE_H
