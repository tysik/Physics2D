#ifndef CIRCLE_POLYGON_COLLISION_DETECTION_H
#define CIRCLE_POLYGON_COLLISION_DETECTION_H

#include "Geometry/circle.h"
#include "Geometry/polygon.h"
#include "Collisions/collision_detector.h"

class CirclePolygonCollisionDetector : public CollisionDetector
{
public:
  CirclePolygonCollisionDetector(const Circle& c, const Polygon& p) : c_(c), p_(p) {}

  virtual bool detect() const {
    if (p_.getSmallestDistance(c_.origin()) <= c_.radius())
      return true;

    // Check if the circle is inside:
    uint N = p_.points().size();
    uint counter = 0;
    for (uint i = 0; i < N - 1; ++i) {
      Vec a = p_.points()[i+1] - p_.points()[i];
      Vec b = c_.origin() - p_.points()[i];

      if (a.cross(b) >= 0.0f)
        counter++;
    }

    if (counter == N - 1)
      return true;
    else
      return false;
  }

private:
  Circle c_;
  Polygon p_;
};

#endif // CIRCLE_POLYGON_COLLISION_DETECTION_H
