#ifndef CIRCLE_POLYGON_COLLISION_H
#define CIRCLE_POLYGON_COLLISION_H

#include "Geometry/circle.h"
#include "Geometry/polygon.h"
#include "Collisions/collision.h"
#include "Dynamics/body.h"

class CirclePolygonCollision : public Collision
{
public:
  CirclePolygonCollision(Body& b1, Body& b2) : b1_(b1), b2_(b2) {
    c_ = dynamic_cast<Circle*>(b1.shape());
    p_ = dynamic_cast<Polygon*>(b2.shape());
  }

  virtual bool detect() const {
    if (p_->getSmallestDistance(c_->origin()) <= c_->radius())
      return true;

    // Check if the circle is inside:
    uint N = p_->points().size();
    uint counter = 0;
    for (uint i = 0; i < N - 1; ++i) {
      Vec a = p_->points()[i+1] - p_->points()[i];
      Vec b = c_->origin() - p_->points()[i];

      if (a.cross(b) >= 0.0f)
        counter++;
    }

    if (counter == N - 1)
      return true;
    else
      return false;
  }

  virtual void apply() {}

private:
  Body& b1_;
  Body& b2_;

  Circle* c_;
  Polygon* p_;
};

#endif // CIRCLE_POLYGON_COLLISION_H
