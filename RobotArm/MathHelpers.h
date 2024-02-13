#ifndef MATH_HELPERS_H
#define MATH_HELPERS_H

// TODO: make functions inline?
// TODO: turn into namespace
#include "Vector2f.h"
#include "Vector3f.h"

float ConvertDegreesToRadians(int angleInDegrees);
int ConvertRadiansToDegrees(float angleInRadians);
int SimplifyDegrees(int angleInDegrees);
float SimplifyRadians(float angleInRadians);

#endif