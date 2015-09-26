#ifndef COLLISION_DETECTOR_FACTORY_H
#define COLLISION_DETECTOR_FACTORY_H

#include "Geometry/point.h"
#include "Geometry/circle.h"
#include "Geometry/segment.h"
#include "Geometry/rectangle.h"
#include "Geometry/polygon.h"

#include "Collisions/collision_detector_factory.h"
#include "Collisions/circle_circle_collision_detector.h"
#include "Collisions/circle_segment_collision_detector.h"
#include "Collisions/circle_polygon_collision_detector.h"

#include <cassert>
#include <typeinfo>

class CollisionDetectorFactory
{
public:
  static CollisionDetector* create(const Shape& s1, const Shape& s2) {
    assert(&s1 != &s2);

    if (typeid(s1) == typeid(const Circle&) && typeid(s2) == typeid(const Circle&)) {
      return new CircleCircleCollisionDetector(dynamic_cast<const Circle&>(s1), dynamic_cast<const Circle&>(s2));
    }
    else if (typeid(s1) == typeid(const Circle&) && typeid(s2) == typeid(const Segment&)) {
      return new CircleSegmentCollisionDetector(dynamic_cast<const Circle&>(s1), dynamic_cast<const Segment&>(s2));
    }
    else if (typeid(s1) == typeid(const Segment&) && typeid(s2) == typeid(const Circle&)) {
      return new CircleSegmentCollisionDetector(dynamic_cast<const Circle&>(s2), dynamic_cast<const Segment&>(s1));
    }
    else if (typeid(s1) == typeid(const Circle&) && typeid(s2) == typeid(const Polygon&)) {
      return new CirclePolygonCollisionDetector(dynamic_cast<const Circle&>(s1), dynamic_cast<const Polygon&>(s2));
    }
    else if (typeid(s1) == typeid(const Polygon&) && typeid(s2) == typeid(const Circle&)) {
      return new CirclePolygonCollisionDetector(dynamic_cast<const Circle&>(s2), dynamic_cast<const Polygon&>(s1));
    }
    else if (typeid(s1) == typeid(const Circle&) && typeid(s2) == typeid(const Rectangle&)) {
      return new CirclePolygonCollisionDetector(dynamic_cast<const Circle&>(s1), dynamic_cast<const Polygon&>(s2));
    }
    else if (typeid(s1) == typeid(const Rectangle&) && typeid(s2) == typeid(const Circle&)) {
      return new CirclePolygonCollisionDetector(dynamic_cast<const Circle&>(s2), dynamic_cast<const Polygon&>(s1));
    }
    else {
      return nullptr;
    }
  }
};

#endif // COLLISION_DETECTOR_FACTORY_H
