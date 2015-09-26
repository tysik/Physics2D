#ifndef CIRCLE_POINT_COLLISION_DETECTOR_H
#define CIRCLE_POINT_COLLISION_DETECTOR_H

#include "Geometry/point.h"
#include "Geometry/circle.h"
#include "Collisions/collision_detector.h"

class PointCircleCollisionDetector : public CollisionDetector
{
public:
  PointCircleCollisionDetector(const Point* p, const Circle* c) : p_(p), c_(c) {}

  virtual bool detect() const {
    return (p_->origin() - c_->origin()).length() <= c_->radius();
  }

private:
  Point* p_;
  Circle* c_;
};

#endif // CIRCLE_POINT_COLLISION_DETECTOR_H
