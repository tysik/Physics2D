#ifndef CIRCLE_SEGMENT_COLLISION_DETECTOR_H
#define CIRCLE_SEGMENT_COLLISION_DETECTOR_H

#include "Geometry/circle.h"
#include "Geometry/segment.h"
#include "Collisions/collision_detector.h"

class CircleSegmentCollisionDetector : public CollisionDetector
{
public:
  CircleSegmentCollisionDetector(const Circle& c, const Segment& s) : c_(c), s_(s) {}

  virtual bool detect() const {
    return (s_.getSmallestDistance(c_.origin()) <= c_.radius());
  }

private:
  Circle c_;
  Segment s_;
};

#endif // CIRCLE_SEGMENT_COLLISION_DETECTOR_H
