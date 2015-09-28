#ifndef CIRCLE_CIRCLE_COLLISION_H
#define CIRCLE_CIRCLE_COLLISION_H

#include "Geometry/circle.h"
#include "Collisions/collision.h"
#include "Dynamics/body.h"

class CircleCircleCollision : public Collision
{
public:
  CircleCircleCollision(Body& b1, Body& b2) : b1_(b1), b2_(b2) {
    c1_ = dynamic_cast<Circle*>(b1.shape());
    c2_ = dynamic_cast<Circle*>(b2.shape());
  }

  virtual bool detect() const {
    return ((c1_->origin() - c2_->origin()).lengthSquared() <= pow(c1_->radius() + c2_->radius(), 2.0));
  }

  virtual void apply() {}

private:
  Body& b1_;
  Body& b2_;

  Circle* c1_;
  Circle* c2_;
};

#endif // CIRCLE_CIRCLE_COLLISION_H
