#pragma once
#include <math.h> 
class Vector2f
{
public:
	Vector2f();

	Vector2f(float ax, float aY);

	const Vector2f operator-(const Vector2f&) const;

	const Vector2f operator+(const Vector2f&) const;

	const Vector2f operator*(const float) const;


	Vector2f& operator*=(const float);

	//Vector2f& operator-=(const float);


	//const bool operator==(const Vector2f&) const;

	//const bool operator!=(const Vector2f&) const;

	float Length() const;

	void Normalize();

	float x;

	float y;
};

