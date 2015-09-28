#ifndef COLLISION_H
#define COLLISION_H

class Collision
{
public:
  /*
   * Returns true if two shapes collide. The detector
   * assumes that if one of the figures is inside of the
   * other - they collide.
   */
  virtual bool detect() const = 0;

  /*
   * Applies appropriate impulses to the colliding
   * bodies.
   */
  virtual void apply() {} // const = 0;
};

#endif // COLLISION_H
