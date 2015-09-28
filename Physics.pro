TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

LIBS += -L/usr/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

SOURCES += \
    main.cpp

HEADERS += \
    Geometry/vec.h \
    Geometry/shape.h \
    Geometry/point.h \
    Geometry/segment.h \
    Geometry/circle.h \
    Geometry/rectangle.h \
    Geometry/polygon.h \
    Utilities/math_utils.h \
    Dynamics/body.h \
    Collisions/collision.h \
    Collisions/circle_circle_collision.h \
    Collisions/circle_point_collision.h \
    Collisions/circle_polygon_collision.h \
    Collisions/circle_segment_collision.h \
    Collisions/collision_factory.h
