#include "Structs.h"
#include <HardwareSerial.h>

const float Vector2f::GetMagnitude() const
{
  return sqrt(GetMagnitudeSquared());
}

const float Vector2f::GetMagnitudeSquared() const
{
  return x * x + y * y;
}

Vector2f Vector2f::operator*(float factor)
{
  return Vector2f{x * factor, y * factor};
}

Vector2f Vector2f::operator/(float factor)
{
  return Vector2f{x/factor, y/factor};
}

Vector2f Vector2f::operator+(const Vector2f &other)
{
  return Vector2f{x + other.x, y + other.y};
}

Vector2f Vector2f::operator-(const Vector2f &other)
{
  return Vector2f{x - other.x, y - other.y};
}

Vector2f& Vector2f::operator*=(float factor)
{
  x *= factor;
  y *= factor;
  return *this;
}

Vector2f& Vector2f::operator/=(float factor)
{
  x /= factor;
  y /= factor;
  return *this;
}

Vector2f& Vector2f::operator+=(const Vector2f& other)
{
  x += other.x;
  y += other.y;
  return *this;
}

Vector2f& Vector2f::operator-=(const Vector2f& other)
{
  x -= other.x;
  y -= other.y;
  return *this;
}

void Vector2f::Normalize()
{
  auto magnitude{GetMagnitude()};
  *this /= magnitude;
}

void Vector2f::Print()
{
  Serial.print(x);
  Serial.print(", ");
  Serial.println(y);
}

const float Vector2f::GetAngleInRadians() const
{
  // TODO: Implement!
  return 0.f;
}

const int Vector2f::GetAngleInDegrees() const
{
  // TODO: Implement!
  return 0;
}

float Vector2f::Dot(const Vector2f& other) const
{
  return x * other.x + y * other.y;
}

float Vector2f::Cross(const Vector2f& other) const
{
  return x * other.y - y * other.x;
}