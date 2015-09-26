#include "Geometry/point.h"
#include "Geometry/circle.h"
#include "Geometry/segment.h"
#include "Geometry/polygon.h"
#include "Geometry/rectangle.h"

#include "Collisions/collision_detector.h"
#include "Collisions/collision_detector_factory.h"
#include "Collisions/circle_circle_collision_detector.h"
#include "Collisions/circle_segment_collision_detector.h"

#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

int main()
{
//  Vec p1(-1.0f, -1.0f);
//  Vec p2( 1.0f, -1.0f);
//  Vec p3( 1.0f,  1.0f);
//  Vec p4(-1.0f,  1.0f);

  Vec p1(1.0f, 0.0f);
  Vec p2(2.0f, 1.0f);
  Vec p3(1.0f, 2.0f);
  Vec p4(0.0f, 1.0f);

  vector<Vec> rectangle_points;
  rectangle_points.push_back(p1);
  rectangle_points.push_back(p2);
  rectangle_points.push_back(p3);
  rectangle_points.push_back(p4);

  Vec t1(-10.0f, -10.0f);
  Vec t2( 10.0f, -10.0f);
  Vec t3(  0.0f,  10.0f);

//  Vec t1(1.0f, 0.0f);
//  Vec t2(1.0f, 1.0f);
//  Vec t3(0.0f, 0.0f);

  vector<Vec> triangle_points;
  triangle_points.push_back(t1);
  triangle_points.push_back(t2);
  triangle_points.push_back(t3);

  Point point;
  Circle circle(3.0f);
  Segment segment(Vec(-10.0f, 0.0f), Vec(10.0f, 0.0f));
  Rectangle rectangle(rectangle_points);
  Polygon triangle(triangle_points);

  cout << "Area of:" << endl;
  cout << "- point: " << point.getArea() << endl;
  cout << "- circle: " << circle.getArea() << endl;
  cout << "- segment: " << segment.getArea() << endl;
  cout << "- rectangle: " << rectangle.getArea() << endl;
  cout << "- triangle: " << triangle.getArea() << endl << endl;

  Vec pt(5.0f, 5.0f);
  cout << "Normal vector to point: " << pt << endl;
  cout << "- point: " << point.getNormal(pt) << endl;
  cout << "- circle: " << circle.getNormal(pt) << endl;
  cout << "- segment: " << segment.getNormal(pt) << endl;
  cout << "- rectangle: " << rectangle.getNormal(pt) << endl;
  cout << "- triangle: " << triangle.getNormal(pt) << endl << endl;

  cout << "Smallest distance to point: " << pt << endl;
  cout << "- point: " << point.getSmallestDistance(pt) << endl;
  cout << "- circle: " << circle.getSmallestDistance(pt) << endl;
  cout << "- segment: " << segment.getSmallestDistance(pt) << endl;
  cout << "- rectangle: " << rectangle.getSmallestDistance(pt) << endl;
  cout << "- triangle: " << triangle.getSmallestDistance(pt) << endl << endl;

  Circle c1(1.0f, Vec(1.0f, 1.0f));
  Circle c2(10.0f, Vec(10.0f, 0.0f));
  Segment s(Vec(-10.0f, 0.0f), Vec(10.0f, 0.0f));

  CollisionDetector* cd = CollisionDetectorFactory::create(rectangle, c1);

  if (cd->detect())
    cout << "collide!" << endl << endl;

  return 0;
}

