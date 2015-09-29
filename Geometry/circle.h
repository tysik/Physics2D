#ifndef CIRCLE_H
#define CIRCLE_H

#include "Geometry/vec.h"
#include "Geometry/shape.h"

#include <cassert>

class Circle : public Shape
{
public:
  Circle(const float radius = 1.0f, Vec* origin = nullptr) : Shape(origin), radius_(radius) {
    assert(radius_ >= 0.0f);
  }

  Circle(const Circle& c) : Shape(), radius_(c.radius()) {
    origin_ = new Vec(c.origin());
  }

  virtual Vec getNormal(const Vec& point) const {
    Vec p = (point - origin());

    return signum(radius_ - p.length()) * p.normalize();
  }

  virtual float getSmallestDistance(const Vec& point) const {
    Vec p = (point - origin());

    return abs(p.length() - radius_);
  }

  virtual float getArea() const {
    return pi * pow(radius_, 2.0);
  }

  // Getters
  float radius() const { return radius_; }

private:
  float radius_;
};

#endif // CIRCLE_H
