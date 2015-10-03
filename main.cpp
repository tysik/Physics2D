#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include "Geometry/point.h"
#include "Geometry/segment.h"
#include "Geometry/rectangle.h"
#include "Geometry/polygon.h"
#include "Geometry/circle.h"

#include "Dynamics/body.h"

#include "Collisions/collision.h"
#include "Collisions/collision_factory.h"
#include "Collisions/circle_point_collision.h"
#include "Collisions/circle_segment_collision.h"
#include "Collisions/circle_polygon_collision.h"
#include "Collisions/circle_circle_collision.h"

#include <iostream>
#include <vector>
#include <typeinfo>

const sf::Vector2f SCREEN_SIZE(1366.0f, 768.0f);

int key_pressed[1024];

double calculateScreenSize(double size) {
  return size * 100.0;
}

sf::Vector2f calculateScreenCoords(Vec position) {
  // Y|_X, (0,0) at center, (1,1) at top right
  sf::Vector2f screen_coords;

  screen_coords.x = (position.x + 1.0f) * SCREEN_SIZE.x / 2.0f;
  screen_coords.y = (1.0f - position.y) * SCREEN_SIZE.y / 2.0f;

  return screen_coords;
}

sf::Vector2f calculateWorldCoords(sf::Vector2f screen_coords) {
  sf::Vector2f world_coords;

  world_coords.x = 2.0f * screen_coords.x / SCREEN_SIZE.x - 1.0f;
  world_coords.y = 1.0f - 2.0f * screen_coords.y / SCREEN_SIZE.y;

  return world_coords;
}

void drawBody(const Body& b, sf::RenderWindow& window) {
  static int i = 0;
  Circle* c = dynamic_cast<Circle*>(b.shape());
  sf::CircleShape cs(calculateScreenSize(c->radius()));
  if (i++ % 2)
    cs.setFillColor(sf::Color::Cyan);
  else
    cs.setFillColor(sf::Color::Red);

  cs.setPosition(calculateScreenCoords(c->origin()));
  window.draw(cs);
}

int main()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode::getFullscreenModes().front(), "Physics Tests", sf::Style::Fullscreen, settings);
  window.setFramerateLimit(60);
  window.setMouseCursorVisible(true);

  // Add bodies:
  Body b1(3.0f, Vec(-1.0f, 0.0f));
  b1.assignShape(new Circle(0.1f));
  b1.applyImpulse(Vec(1.0f, 0.0f));

  Body b2(3.0f, Vec(1.0f, 0.0f));
  b2.assignShape(new Circle(0.1f));
  b2.applyImpulse(Vec(-1.0f, 0.0f));

//  bool collided = false;

  sf::Clock clock;
  while (window.isOpen())
  {
    float dt = clock.restart().asSeconds();
    b1.applyMotion(dt);
    b2.applyMotion(dt);

    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::MouseMoved)
      {}
      if (event.type == sf::Event::MouseButtonPressed)
      {}
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed)
        key_pressed[event.key.code] = 1;
      if (event.type == sf::Event::KeyReleased)
        key_pressed[event.key.code] = 0;
    }
    if (key_pressed[sf::Keyboard::Escape])
      window.close();

//    float fx = 5.0f * (key_pressed[sf::Keyboard::D] - key_pressed[sf::Keyboard::A]);
//    float fy = 5.0f * (key_pressed[sf::Keyboard::W] - key_pressed[sf::Keyboard::S]);

//    if (!collided) {
//      Collision* cd = CollisionFactory::create(b1, b2);

//      if (cd->detect()) {
//        cd->apply();
//        collided = false;
//      }
//    }

    window.clear();
    drawBody(b1, window);
    drawBody(b2, window);
    window.display();
  }

  return 0;

//  Vec p1(1.0f, 0.0f);
//  Vec p2(2.0f, 1.0f);
//  Vec p3(1.0f, 2.0f);
//  Vec p4(0.0f, 1.0f);

//  vector<Vec> rectangle_points;
//  rectangle_points.push_back(p1);
//  rectangle_points.push_back(p2);
//  rectangle_points.push_back(p3);
//  rectangle_points.push_back(p4);

//  Vec t1(-10.0f, -10.0f);
//  Vec t2( 10.0f, -10.0f);
//  Vec t3(  0.0f,  10.0f);

//  vector<Vec> triangle_points;
//  triangle_points.push_back(t1);
//  triangle_points.push_back(t2);
//  triangle_points.push_back(t3);

//  Point point;
//  Circle circle(3.0f);
//  Segment segment(Vec(-10.0f, 0.0f), Vec(10.0f, 0.0f));
//  Rectangle rectangle(rectangle_points);
//  Polygon triangle(triangle_points);

//  Body b1(1.0f, Vec(0.0f, 0.5f));
//  b1.assignShape(new Circle);
//  b1.applyImpulse(Vec(1.0f, -1.0f));

//  Body b2(1.0f, Vec(0.5f, 0.0f));
//  b2.assignShape(new Circle);
//  b2.applyImpulse(Vec(-1.0f, 1.0f));

//  cout << "B1 vel: " << b1.velocity() << endl;
//  cout << "B2 vel: " << b2.velocity() << endl;

//  Collision* cd = CollisionFactory::create(b1, b2);

//  if (cd->detect()) {
//    cout << "collide!" << endl << endl;
//    cd->apply();
//  }

//  cout << "B1 vel: " << b1.velocity() << endl;
//  cout << "B2 vel: " << b2.velocity() << endl;
}

