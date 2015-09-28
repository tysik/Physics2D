#ifndef CIRCLE_POINT_COLLISION_H
#define CIRCLE_POINT_COLLISION_H

#include "Geometry/point.h"
#include "Geometry/circle.h"
#include "Collisions/collision.h"
#include "Dynamics/body.h"

class CirclePointCollision : public Collision
{
public:
  CirclePointCollision(Body& b1, Body& b2) : b1_(b1), b2_(b2) {
    c_ = dynamic_cast<Circle*>(b1.shape());
    p_ = dynamic_cast<Point*>(b2.shape());
  }

  virtual bool detect() const {
    return (p_->origin() - c_->origin()).length() <= c_->radius();
  }

  virtual void apply() {}

private:
  Body& b1_;
  Body& b2_;

  Circle* c_;
  Point* p_;
};

#endif // CIRCLE_POINT_COLLISION_H
