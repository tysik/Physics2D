#ifndef SHAPE_H
#define SHAPE_H

#include "vec.h"
#include <iostream>

class Shape
{
public:
  virtual ~Shape() {}

  /*
   * Return the normal vector pointing towards given point
   */
  virtual Vec getNormal(const Vec& point) const = 0;

  /*
   * Returns the smallest distance between the shape border
   * and given point.
   */
  virtual float getSmallestDistance(const Vec& point) const = 0;

  /*
   * Returns the area of the shape.
   */
  virtual float getArea() const = 0;

  Vec origin() const { return *origin_; }

  void assignOrigin(Vec* origin) { origin_ = origin; }

protected:
  Shape(Vec* origin = nullptr) : origin_(origin) {}

  Vec* origin_;  // Points to position of shape in the world
};

#endif // SHAPE_H
