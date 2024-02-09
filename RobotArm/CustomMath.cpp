#include "CustomMath.h"
#include <HardwareSerial.h>

float ConvertDegreesToRadians(int angleInDegrees)
{
  return angleInDegrees * M_PI / 180;
}

int ConvertRadiansToDegrees(float angleInRadians)
{
  return int(angleInRadians / M_PI * 180);
}

int SimplifyDegrees(int angleInDegrees)
{
  const int radianCircle{360};
  while(angleInDegrees < 0)
  {
    angleInDegrees += radianCircle;
  }
  return angleInDegrees % radianCircle;
}

float SimplifyRadians(float angleInRadians)
{
  const float radianCircle{2 * M_PI};
  while(angleInRadians > radianCircle )
  {
    angleInRadians -= radianCircle;
  }

  while(angleInRadians < 0.f)
  {
    angleInRadians += radianCircle;
  }
  return angleInRadians;
}

Vector2f::Vector2f()
  : x{0.f}, y{0.f}
{};

Vector2f::Vector2f(float _x, float _y)
  : x{_x}, y{_y}
{};

Vector2f::Vector2f(int angleInDegrees, float magnitude)
{
  double angleInRadians = double(angleInDegrees) * M_PI / 180;
  x = cos(angleInRadians) * magnitude;
  y = sin(angleInRadians) * magnitude;
};

Vector2f::Vector2f(const Point2f& point)
  : x{point.x}, y{point.y}
{};

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

Vector2f& Vector2f::Normalize()
{
  auto magnitude{GetMagnitude()};
  *this /= magnitude;
  return *this;
}

void Vector2f::Print(const char* prefaceMsg)
{
  Serial.print(prefaceMsg);
  Serial.print(x);
  Serial.print(", ");
  Serial.println(y);
}

const float Vector2f::GetAngleInRadians() const
{
  return atan2f(y, x);
}

const int Vector2f::GetAngleInDegrees() const
{
  return ConvertRadiansToDegrees(GetAngleInRadians());
}

float Vector2f::Dot(const Vector2f& other) const
{
  return x * other.x + y * other.y;
}

float Vector2f::Cross(const Vector2f& other) const
{
  return x * other.y - y * other.x;
}

Vector2f& Vector2f::RotateByDegrees(int degrees)
{
  const float radians{ConvertDegreesToRadians(degrees)};
  return RotateByRadians(radians);
}

Vector2f& Vector2f::RotateByRadians(float radians)
{
  const float cosine{cos(radians)};
  const float sine{sin(radians)};

  float newX{cosine * x - sine * y};
  float newY{sine * x + cosine * y};

  x = newX;
  y = newY;

  return *this;
}