#ifndef VECTOR_2F
#define VECTOR_2F

struct Vector2f{
  Vector2f();
  Vector2f(float _x, float _y);
  Vector2f(int angleInDegrees, float magnitude);
  // Vector2f(const Point2f& point);

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
  Vector2f& Normalize();

  float Dot(const Vector2f& other) const;
  float Cross(const Vector2f& other) const;

  Vector2f& RotateByDegrees(int degrees);
  Vector2f& RotateByRadians(float radians);

  void Print(const char* prefaceMsg = "");
};

#endif