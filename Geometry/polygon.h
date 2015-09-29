#ifndef POLYGON_H
#define POLYGON_H

#include "Geometry/vec.h"
#include "Geometry/shape.h"
#include "Geometry/segment.h"

#include <cassert>
#include <vector>

class Polygon : public Shape
{
public:
  /*
   * Points must be given in counter-clokwise direction.
   * The polygon must be convex.
   */
  Polygon(const std::vector<Vec>& points = std::vector<Vec>(), Vec* origin = nullptr)
    : Shape(origin),
      points_(points.begin(), points.end())
  {
    assert(points.size() >= 3);
    assert(checkConvexity());
    assert(getArea() > 0.0f);

    points_.push_back(points_.front()); // Add first point again to close the shape
  }

  Polygon(const Polygon& polygon)
    : Shape(),
      points_(polygon.points().begin(), polygon.points().end()) {
    origin_ = new Vec(polygon.origin());
  }

  virtual Vec getNormal(const Vec& point) const {
    Vec p = point - origin();

    Segment s = Segment(points_[0], points_[1]);
    float distance = s.getSmallestDistance(p);
    Vec normal = s.getNormal(p);

    float temp_d;
    for (uint i = 1; i < points_.size() - 1; ++i) {
      s = Segment(points_[i], points_[i+1]);

      if ((temp_d = s.getSmallestDistance(p)) <= distance) {
        distance = temp_d;
        normal = s.getNormal(p);
      }
    }

    return normal;
  }

  virtual float getSmallestDistance(const Vec& point) const {
    Vec p = point - origin();

    float distance = Segment(points_[0], points_[1]).getSmallestDistance(p);

    float temp_d;
    for (uint i = 1; i < points_.size() - 1; ++i) {
      Segment s = Segment(points_[i], points_[i+1]);

      if ((temp_d = s.getSmallestDistance(p)) <= distance)
        distance = temp_d;
    }

    return distance;
  }

  virtual float getArea() const {
    float area = 0.0f;

    for (uint i = 0; i < points_.size() - 1; ++i) {
      area += points_[i].cross(points_[i+1]);
    }

    return area / 2.0f;
  }

  // Getters
  const std::vector<Vec>& points() const { return points_; }

private:
  bool checkConvexity() const {
    uint N = points_.size();

    if (N == 2)
      return true;

    for (uint i = 0; i < N - 2; ++i) {
      Vec a = points_[i+1] - points_[i];
      Vec b = points_[i+2] - points_[i];

      if (a.cross(b) < 0.0f)
        return false;
    }

    // The last point is doubled
    if ((points_[N-1] - points_[N-2]).cross(points_[1] - points_[N-2]) < 0.0f)
      return false;

    return true;
  }

protected:
  std::vector<Vec> points_;
};

#endif // POLYGON_H
