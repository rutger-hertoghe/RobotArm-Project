#include <math.h>
#include <HardwareSerial.h>
#include "MathHelpers.h"
#include "Vector3f.h"

Vector3f::Vector3f()
  : x{0.f}, y{0.f}
{};

Vector3f::Vector3f(float _x, float _y, float _z)
  : x{_x}, y{_y}, z{_z}
{};

const float Vector3f::GetMagnitude() const
{
  return sqrt(GetMagnitudeSquared());
}

const float Vector3f::GetMagnitudeSquared() const
{
  return x * x + y * y + z * z;
}

Vector3f Vector3f::operator*(float factor)
{
  return Vector3f{x * factor, y * factor, z * factor};
}

Vector3f Vector3f::operator/(float factor)
{
  return Vector3f{x/factor, y/factor, z/factor};
}

Vector3f Vector3f::operator+(const Vector3f &other)
{
  return Vector3f{x + other.x, y + other.y, z + other.z};
}

Vector3f Vector3f::operator-(const Vector3f &other)
{
  return Vector3f{x - other.x, y - other.y, z - other.z};
}

Vector3f& Vector3f::operator*=(float factor)
{
  x *= factor;
  y *= factor;
  z *= factor;
  return *this;
}

Vector3f& Vector3f::operator/=(float factor)
{
  x /= factor;
  y /= factor;
  z /= factor;
  return *this;
}

Vector3f& Vector3f::operator+=(const Vector3f& other)
{
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}

Vector3f& Vector3f::operator-=(const Vector3f& other)
{
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return *this;
}

Vector3f& Vector3f::Normalize()
{
  auto magnitude{GetMagnitude()};
  *this /= magnitude;
  return *this;
}

void Vector3f::Print(const char* prefaceMsg)
{
  Serial.print(prefaceMsg);
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.println(z);
}

// const float Vector3f::GetAngleInRadians() const
// {
//   return atan2f(y, x);
// }

// const int Vector3f::GetAngleInDegrees() const
// {
//   return ConvertRadiansToDegrees(GetAngleInRadians());
// }

float Vector3f::Dot(const Vector3f& other) const
{
  return x * other.x + y * other.y + z * other.z;
}

Vector3f Vector3f::Cross(const Vector3f& other) const
{
  return Vector3f{
    y * other.z - z * other.y,
    z * other.x - x * other.z,
    x * other.y - y * other.x
  };
}

Vector3f& Vector3f::RotateByDegrees(int degrees)
{
  const float radians{ConvertDegreesToRadians(degrees)};
  return RotateByRadians(radians);
}

Vector3f& Vector3f::RotateByRadians(float radians)
{
  const float cosine{cos(radians)};
  const float sine{sin(radians)};

  float newX{cosine * x - sine * y};
  float newY{sine * x + cosine * y};

  x = newX;
  y = newY;

  return *this;
}