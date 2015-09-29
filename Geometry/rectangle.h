#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Geometry/polygon.h"

class Rectangle : public Polygon
{
public:
  /*
   * Parameter lb stands from left-bottom corner position
   */
  Rectangle(const Vec& lb = Vec(), const Vec& size = Vec(1.0f, 1.0f), Vec* origin = nullptr)
    : Polygon(std::vector<Vec>{lb, lb + Vec(size.x, 0.0f), lb + size, lb + Vec(0.0f, size.y)}, origin)
  {
    assert(checkRightAngles());
  }

  Rectangle(const std::vector<Vec>& points = std::vector<Vec>(), Vec* origin = nullptr)
    : Polygon(points, origin)
  {
    assert(points.size() == 4);
    assert(checkRightAngles());
  }

  Rectangle(const Rectangle& rectangle) : Polygon(rectangle) {}

private:
  bool checkRightAngles() const {
    if (((points_[0] - points_[3]).dot(points_[1] - points_[0]) == 0.0f) &&
        ((points_[1] - points_[0]).dot(points_[2] - points_[1]) == 0.0f) &&
        ((points_[2] - points_[1]).dot(points_[3] - points_[2]) == 0.0f) &&
        ((points_[3] - points_[2]).dot(points_[0] - points_[3]) == 0.0f))
      return true;
    else
      return false;
  }
};

#endif // RECTANGLE_H
