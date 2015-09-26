#ifndef CIRCLE_CIRCLE_COLLISION_DETECTOR_H
#define CIRCLE_CIRCLE_COLLISION_DETECTOR_H

#include "Collisions/collision_detector.h"
#include "Geometry/circle.h"

class CircleCircleCollisionDetector : public CollisionDetector
{
public:
  CircleCircleCollisionDetector(const Circle& c1, const Circle& c2) : c1_(c1), c2_(c2) {}

  virtual bool detect() const {
    return ((c1_.origin() - c2_.origin()).lengthSquared() <= pow(c1_.radius() + c2_.radius(), 2.0));
  }

private:
  Circle c1_;
  Circle c2_;
};

#endif // CIRCLE_CIRCLE_COLLISION_DETECTOR_H
