#ifndef COLLISION_FACTORY_H
#define COLLISION_FACTORY_H

#include "Geometry/point.h"
#include "Geometry/segment.h"
#include "Geometry/rectangle.h"
#include "Geometry/polygon.h"
#include "Geometry/circle.h"

#include "Collisions/circle_point_collision.h"
#include "Collisions/circle_segment_collision.h"
#include "Collisions/circle_polygon_collision.h"
#include "Collisions/circle_circle_collision.h"

#include "Dynamics/body.h"

#include <cassert>
#include <typeinfo>

class CollisionFactory
{
public:
  static Collision* create(Body& b1, Body& b2) {
    assert(&b1 != &b2);

    Shape* s1 = b1.shape();
    Shape* s2 = b2.shape();

    if (typeid(*s1) == typeid(Circle) && typeid(*s2) == typeid(Point)) {
      return new CirclePointCollision(b1, b2);
    }
    else if (typeid(*s1) == typeid(Point) && typeid(*s2) == typeid(Circle)) {
      return new CirclePointCollision(b2, b1);
    }
    else if (typeid(*s1) == typeid(Circle) && typeid(*s2) == typeid(Segment)) {
      return new CircleSegmentCollision(b1, b2);
    }
    else if (typeid(*s1) == typeid(Segment) && typeid(*s2) == typeid(Circle)) {
      return new CirclePointCollision(b2, b1);
    }
    else if (typeid(*s1) == typeid(Circle) && typeid(*s2) == typeid(Polygon)) {
      return new CirclePolygonCollision(b1, b2);
    }
    else if (typeid(*s1) == typeid(Polygon) && typeid(*s2) == typeid(Circle)) {
      return new CirclePolygonCollision(b2, b1);
    }
    else if (typeid(*s1) == typeid(Circle) && typeid(*s2) == typeid(Rectangle)) {
      std::cout << "circ rect" << std::endl;
      return new CirclePolygonCollision(b1, b2);
    }
    else if (typeid(*s1) == typeid(Rectangle) && typeid(*s2) == typeid(Circle)) {
      std::cout << "rect circ" << std::endl;
      return new CirclePolygonCollision(b2, b1);
    }
    else if (typeid(*s1) == typeid(Circle) && typeid(*s2) == typeid(Circle)) {
      return new CircleCircleCollision(b1, b2);
    }
    else {
      return nullptr;
    }
  }
};

#endif // COLLISION_FACTORY_H
