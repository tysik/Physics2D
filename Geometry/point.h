#ifndef POINT_H
#define POINT_H

#include "Geometry/vec.h"
#include "Geometry/shape.h"

class Point : public Shape
{
public:
  Point(Vec* origin = nullptr) : Shape(origin) {}

  Point(const Point& point) : Shape() {
    origin_ = new Vec(point.origin());
  }

  virtual Vec getNormal(const Vec& point) const {
    Vec p = point - origin();

    return p.normalize();
  }

  virtual float getSmallestDistance(const Vec& point) const {
    Vec p = point - origin();

    return p.length();
  }

  virtual float getArea() const {
    return 0.0f;
  }
};

#endif // POINT_H
