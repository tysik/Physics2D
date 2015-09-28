#ifndef CIRCLE_SEGMENT_COLLISION_H
#define CIRCLE_SEGMENT_COLLISION_H

#include "Geometry/circle.h"
#include "Geometry/segment.h"
#include "Collisions/collision.h"
#include "Dynamics/body.h"

class CircleSegmentCollision : public Collision
{
public:
  CircleSegmentCollision(Body& b1, Body& b2) : b1_(b1), b2_(b2) {
    c_ = dynamic_cast<Circle*>(b1.shape());
    s_ = dynamic_cast<Segment*>(b2.shape());
  }

  virtual bool detect() const {
    return (s_->getSmallestDistance(c_->origin()) <= c_->radius());
  }

  virtual void apply() {}

private:
  Body& b1_;
  Body& b2_;

  Circle* c_;
  Segment* s_;
};

#endif // CIRCLE_SEGMENT_COLLISION_H
