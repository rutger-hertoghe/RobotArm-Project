#ifndef STRUCTS_H
#define STRUCTS_H

#include <math.h>

#define _USE_MATH_DEFINES

struct Point2f{
  Point2f()
    : x{0.f}, y{0.f}
  {};

  Point2f(float _x, float _y)
    : x{_x}, y{_y}
  {};

  float x;
  float y;
};

struct Vector2f{
  Vector2f()
    : x{0.f}, y{0.f}
  {};

  Vector2f(float _x, float _y)
    : x{_x}, y{_y}
  {};

  Vector2f(int angleInDegrees, float magnitude)
  {
    double angleInRadians = double(angleInDegrees) * M_PI / 360;
    x = cos(angleInRadians) * magnitude;
    y = sin(angleInRadians) * magnitude;
  };

  Vector2f(const Point2f& point)
    : x{point.x}, y{point.y}
  {};

  float x;
  float y;

  Vector2f operator*(float factor);
  Vector2f operator/(float factor);
  Vector2f operator+(const Vector2f& other);
  Vector2f operator-(const Vector2f& other);

  Vector2f& operator*=(float factor);
  Vector2f& operator/=(float factor);
  Vector2f& operator+=(const Vector2f& other);
  Vector2f& operator-=(const Vector2f& other);

  const float GetMagnitude() const;
  const float GetMagnitudeSquared() const;
  const float GetAngleInRadians() const;
  const int GetAngleInDegrees() const;
  void Normalize();

  float Dot(const Vector2f& other) const;
  float Cross(const Vector2f& other) const;

  void Print();
};

#endif