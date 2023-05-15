#include "Vector2f.h"

Vector2f::Vector2f()
	:x(0.0f),y(0.0f)
{
}

Vector2f::Vector2f(float aX, float aY)
	:x(aX),y(aY)
{
}

const Vector2f Vector2f::operator-(const Vector2f& other) const
{
	return Vector2f(x-other.x,y-other.y);
}

const Vector2f Vector2f::operator+(const Vector2f& other) const
{
	return Vector2f(x+other.x,y+other.y);
}

const Vector2f Vector2f::operator*(const float other) const
{
	return Vector2f(x * other, y * other);
}

Vector2f& Vector2f::operator*=(const float other)
{
	x *= other;
	y *= other;

	return *this;
}

float Vector2f::Length() const
{
	return sqrt(x * x + y * y);
}

void Vector2f::Normalize()
{
	float length = Length();

	if (length > 0.f)
		*this *= (1/length);
}
