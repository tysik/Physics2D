#ifndef BODY_H
#define BODY_H

#include "Geometry/vec.h"
#include "Geometry/point.h"
#include "Geometry/segment.h"
#include "Geometry/rectangle.h"
#include "Geometry/polygon.h"
#include "Geometry/circle.h"

#include <typeinfo>

class Body
{
public:
  Body(float mass = 1.0f, Vec position = Vec()) : mass_(mass), position_(position) {
    if (mass_ <= 0.0f)
      mass = 0.0f, mass_inv_ = 0.0f;
    else
      mass_inv_ = 1.0f / mass_;

    velocity_ = Vec();
    acceleration_ = Vec();
  }

  void assignShape(Shape* shape) {
    shape_ = shape;
    shape_->assignOrigin(&position_);
  }

  void applyForce(Vec f) {
    acceleration_ = mass_inv_ * f;
  }

  void applyImpulse(Vec i) {
    velocity_ += mass_inv_ * i;
  }

  void applyMotion(float dt) {
    velocity_ += acceleration_ * dt / 2.0f;
    position_ += velocity_ * dt;
    velocity_ += acceleration_ * dt / 2.0f;
  }

  // Getters:
  Shape* shape() const { return shape_; }
  float mass() const { return mass_; }
  float mass_inv() const { return mass_inv_; }

  Vec position() const { return position_; }
  Vec velocity() const { return velocity_; }
  Vec acceleration() const { return acceleration_; }

private:
  float mass_;
  float mass_inv_;

  Vec position_;
  Vec velocity_;
  Vec acceleration_;

  Shape* shape_;
};

#endif // BODY_H
