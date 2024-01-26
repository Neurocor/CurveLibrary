#pragma once


#ifdef CURVELIBRARY_EXPORTS
#define CURVELIBRARY_API __declspec(dllexport)
#else
#define CURVELIBRARY_API __declspec(dllimport)
#endif


/*For multithreading*/
#include "omp.h"

#define _USE_MATH_DEFINES
#include "math.h"

struct CURVELIBRARY_API Point {

	Point(float x = 0, float y = 0, float z = 0);
	void reset();

	Point operator * (float val);
	Point operator / (float val);
	Point &operator *= (float val);


	float x{ 0 };
	float y{ 0 };
	float z{ 0 };
};


/*!
	* Abstract class  Curve for next impl.
*/
class CURVELIBRARY_API Curve
{
public :

	explicit Curve();
	virtual ~Curve();

	virtual Point GetPoint(float t) const = 0;
	//virtual bool GetFirstDerivative(double t, Point& result) = 0;


	inline bool isEqualDouble(double a, double b, double eps = 1E-10) const {
		return fabs(a - b) <= eps;
	}
	
protected:

private:

};

/*!
	* class Circle extended from Curve
*/

class CURVELIBRARY_API Circle : public Curve
{
public:
	
	explicit Circle(float R1 = 0);
	virtual ~Circle();

	virtual Point GetPoint(float t) const override;
	//virtual bool GetFirstDerivative(float t, Point& result) override;

	void SetRadius1(float R1);
	inline float GetRadius1()const {
		return Radius1;
	}

protected:
	/*!
	
	*/
	float Radius1{ 0 };
};

/*!
	* class Ellipse extended from Circle
*/

class CURVELIBRARY_API Ellipse : public Circle
{
public:

	explicit Ellipse(float R1 = 0, float R2 = 0);
	virtual ~Ellipse();

	virtual Point GetPoint(float t) const override;
	//virtual bool GetFirstDerivative(double t, Point& result) override;

	void SetRadius2(float R2);

protected:

	double Radius2{ 0 };
};

class CURVELIBRARY_API Helix : public Ellipse
{
public:
	explicit Helix(float R1 = 0, float R2 = 0, float S = 0);
	virtual ~Helix();

	virtual Point GetPoint(float t) const override;
	//virtual bool GetFirstDerivative(double t, Point& result) override;

	void SetStep(float S);

protected:

	float Step {0};
};

