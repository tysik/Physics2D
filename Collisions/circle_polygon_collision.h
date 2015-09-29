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

  virtual void apply() const {
    float m1 = b1_.mass();
    float m2 = b2_.mass();

    Vec normal = p_->getNormal(c_->origin());
    if (normal.dot(b2_.velocity() - b1_.velocity()) <= 0.0f)
      return;
//    Vec tangent = normal.perpendicular();

    float v1_n = b1_.velocity().dot(normal);
//    float v1_t = b1_.velocity().dot(tangent);

    float v2_n = b2_.velocity().dot(normal);
//    float v2_t = b2_.velocity().dot(tangent);

    float new_v1_n = (v1_n * (m1 - m2) + 2.0f * m2 * v2_n) / (m1 + m2);
    float new_v2_n = (v2_n * (m2 - m1) + 2.0f * m1 * v1_n) / (m1 + m2);

    b1_.applyImpulse((new_v1_n - v1_n) * normal * m1);
    b2_.applyImpulse((new_v2_n - v2_n) * normal * m2);
  }

private:
  Body& b1_;
  Body& b2_;

  Circle* c_;
  Polygon* p_;
};

#endif // CIRCLE_POLYGON_COLLISION_H
