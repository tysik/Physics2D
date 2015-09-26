#ifndef VEC_H
#define VEC_H

#include <cmath>
#include <ostream>
#include <cassert>

#include "Utilities/math_utils.h"

class Vec
{
public:
  Vec(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
  Vec(const Vec& v) : x(v.x), y(v.y) {}

  Vec& normalize()
  {
    float l = length();
    if (l > 0.0f)
      x /= l, y /= l;
    return *this;
  }
  float length()        const { return static_cast<float>(sqrt(pow(x, 2.0) + pow(y, 2.0))); }
  float lengthSquared() const { return static_cast<float>(pow(x, 2.0) + pow(y, 2.0)); }
  float angle()         const { return static_cast<float>(atan2(y, x)); }
  float angleDeg()      const { return static_cast<float>(180.0f * atan2(y, x) / M_PI); }
  float dot(const Vec& v)   const { return x * v.x + y * v.y; }
  float cross(const Vec& v) const { return x * v.y - y * v.x; }

  /*
   * Returns a vector rotated left by 90 deg.
   */
  Vec perpendicular() { return Vec(-y, x); }

  /*
   * Returns a vector as if it was reflected from the surface
   * which normal vector is given by parameter. normal is assumed
   * to be normalized.
   */
  Vec reflected(const Vec& normal) { return *this - 2.0f * normal * (normal.dot(*this)); }

  friend Vec operator+ (const Vec& v1, const Vec& v2) { return Vec(v1.x + v2.x, v1.y + v2.y); }
  friend Vec operator- (const Vec& v1, const Vec& v2) { return Vec(v1.x - v2.x, v1.y - v2.y); }
  friend Vec operator* (const float f, const Vec& v)  { return Vec(f * v.x, f * v.y); }
  friend Vec operator* (const Vec& v, const float f)  { return Vec(f * v.x, f * v.y); }
  friend Vec operator/ (const Vec& v, const float f)  { assert(f != 0.0f); return Vec(v.x / f, v.y / f); }

  Vec operator- () { return Vec(-x, -y); }
  Vec operator+ () { return Vec( x,  y); }

  Vec& operator= (const Vec& v) { if (this != &v) { x = v.x; y = v.y; } return *this; }
  Vec& operator+=(const Vec& v) { x += v.x; y += v.y; return *this; }
  Vec& operator-=(const Vec& v) { x -= v.x; y -= v.y; return *this; }

  friend bool operator==(const Vec& v1, const Vec& v2) { return (v1.x == v2.x && v1.y == v2.y); }
  friend bool operator!=(const Vec& v1, const Vec& v2) { return !(v1 == v2); }
  friend bool operator< (const Vec& v1, const Vec& v2) { return (v1.lengthSquared() < v2.lengthSquared()); }
  friend bool operator<=(const Vec& v1, const Vec& v2) { return (v1.lengthSquared() <= v2.lengthSquared()); }
  friend bool operator> (const Vec& v1, const Vec& v2) { return (v1.lengthSquared() > v2.lengthSquared()); }
  friend bool operator>=(const Vec& v1, const Vec& v2) { return (v1.lengthSquared() >= v2.lengthSquared()); }
  friend bool operator! (const Vec& v) { return (v.x == 0.0f && v.y == 0.0f); }

  friend std::ostream& operator<<(std::ostream& out, const Vec& v)
  { out << "(" << v.x << ", " << v.y << ")"; return out; }

  float x;
  float y;
};

#endif // VEC_H
