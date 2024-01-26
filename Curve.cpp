#include "pch.h"
#include "Curve.h"

Point::Point(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::reset()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Point Point::operator* (float val)
{
	return Point(x * val, y * val, z * val);
}

Point Point::operator/ (float val)
{
	return Point(x / val, y / val, z / val);
}

Point& Point::operator*= (float val)
{
	x *= val;
	y *= val;
	z *= val;

	return *this;
}


Curve::Curve()
{

}

Curve::~Curve()
{

}

Circle::Circle(float R1)
	:Curve()
{

	// x(t) = r1 * cos(t)
	// y(t) = r1 * sin(t)
	// y' = -ctg(t) { -cos(t) / sin(t) }

	SetRadius1(R1);
}

Circle::~Circle()
{
}

Point Circle::GetPoint(float t) const
{
	return Point(Radius1 * cosf(t), Radius1 * sinf(t));
}

//bool Circle::GetFirstDerivative(double t, Point& result)
//{
//
//	result.reset();
//	
//	if (isEqualDouble(sin(t),0)) {
//		return false;
//	}
//
//	
//	return true;
//}

void Circle::SetRadius1(float R1)
{
	if (R1 >= 0)
		Radius1 = R1;
}

Ellipse::Ellipse(float R1, float R2)
	:Circle(R1)
{
	// x(t) = r1 * cos(t)
	// y(t) = r2 * sin(t)
	// y' = - r2/r1 * ctg(t)

	SetRadius2(R2);
}

Ellipse::~Ellipse()
{

}

Point Ellipse::GetPoint(float t) const
{
	return Point(Radius1 * cosf(t), Radius2 * sinf(t));
}

//bool Ellipse::GetFirstDerivative(double t, Point& result)
//{
//	result.reset();
//
//	if(!Circle::GetFirstDerivative(t, result) || Radius1 == 0)
//		return false;
//
//	//result *= (radius2 / radius1);
//
//	return true;
//}

void Ellipse::SetRadius2(float R2)
{
	if (R2 >= 0)
		Radius2 = R2;
}

Helix::Helix(float R1, float R2, float S)
	: Ellipse(R1, R2)
{
	SetStep(S);
}

Helix::~Helix()
{

}

Point Helix::GetPoint(float t) const
{
	auto res = Ellipse::GetPoint(t);

	res.z += Step;
	
	return res;
}

//bool Helix::GetFirstDerivative(float t, Point& result)
//{
//	return false;
//}

void Helix::SetStep(float S)
{
	if (!isEqualDouble(S, Step))
		Step = S;
}
