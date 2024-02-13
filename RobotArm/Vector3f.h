#ifndef VECTOR_3F
#define VECTOR_3F

struct Vector3f{
  Vector3f();
  Vector3f(float _x, float _y, float _z);
  // Vector3f(int angleInDegrees, float magnitude);

  float x;
  float y;
  float z;

  Vector3f operator*(float factor);
  Vector3f operator/(float factor);
  Vector3f operator+(const Vector3f& other);
  Vector3f operator-(const Vector3f& other);

  Vector3f& operator*=(float factor);
  Vector3f& operator/=(float factor);
  Vector3f& operator+=(const Vector3f& other);
  Vector3f& operator-=(const Vector3f& other);

  const float GetMagnitude() const;
  const float GetMagnitudeSquared() const;
  // const float GetAngleInRadians() const;
  // const int GetAngleInDegrees() const;
  Vector3f& Normalize();

  float Dot(const Vector3f& other) const;
  Vector3f Cross(const Vector3f& other) const;

  Vector3f& RotateByDegrees(int degrees);
  Vector3f& RotateByRadians(float radians);

  void Print(const char* prefaceMsg = "");
};

#endif