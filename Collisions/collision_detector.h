#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

class CollisionDetector
{
public:
  /*
   * Returns true if two shapes collide. The detector
   * assumes that if one of the figures is inside of the
   * other - they collide.
   */
  virtual bool detect() const = 0;
};

#endif // COLLISION_DETECTOR_H
