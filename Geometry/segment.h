#ifndef SEGMENT_H
#define SEGMENT_H

#include "Geometry/vec.h"
#include "Geometry/shape.h"

#include <cassert>

class Segment : public Shape
{
public:
  Segment(const Vec& p1 = Vec(), const Vec& p2 = Vec(1.0f, 0.0f), Vec* origin = nullptr)
    : Shape(origin), p1_(p1), p2_(p2) {
    assert(p1_ != p2_);
  }

  Segment(const Segment& segment)
    : Shape(), p1_(segment.first_point()), p2_(segment.last_point()) {
    origin_ = new Vec(segment.origin());
  }

  /*
   * If the point's projection on segment lays outside
   * the normal is obtained from the edge point.
   */
  virtual Vec getNormal(const Vec& point) const {
    Vec p = point - origin();

    Vec a = p2_ - p1_;
    Vec b = p - p1_;
    Vec c = p - p2_;

    float t = a.dot(b) / a.lengthSquared();

    if (t < 0.0f)
      return b.normalize();
    else if (t > 1.0f)
      return c.normalize();

    return signum(a.cross(b)) * a.perpendicular().normalize();
  }

  /*
   * The function projects point onto the line supporting
   * the segment and checks if its projection falls on the
   * segment or not. In the first case the distance between
   * point and segment is computed. In the latter case the
   * distance between point and one of the edge points is
   * computed. Projected point is obtained from equation:
   * p = p1 + t * (p2 - p1)
   */
  virtual float getSmallestDistance(const Vec& point) const {
    Vec p = point - origin();

    Vec a = p2_ - p1_;
    Vec b = p - p1_;
    Vec c = p - p2_;

    float t = a.dot(b) / a.lengthSquared();

    if (t < 0.0)
      return b.length();
    else if (t > 1.0)
      return c.length();

    Vec projection = p1_ + t * a;
    return (p - projection).length();
  }

  virtual float getArea() const {
    return 0.0f;
  }

  float getLength() const {
    return (p1_ - p2_).length();
  }

  // Getters
  Vec first_point() const { return p1_ + origin(); }
  Vec last_point() const { return p2_ + origin(); }

private:
  Vec p1_;
  Vec p2_;
};

#endif // SEGMENT_H
