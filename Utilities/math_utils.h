#ifndef MATH_UTILS_H
#define MATH_UTILS_H

float signum(float x) { return (x >= 0.0f ? 1.0f : -1.0f); }
float abs(float x) { return (x >= 0.0f ? x : -x); }
const float pi = 3.141592;

#endif // MATH_UTILS_H
