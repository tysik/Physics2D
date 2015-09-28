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
    Collisions/collision_detector.h \
    Collisions/circle_point_collision_detector.h \
    Collisions/circle_circle_collision_detector.h \
    Collisions/circle_segment_collision_detector.h \
    Collisions/circle_polygon_collision_detector.h \
    Collisions/collision_detector_factory.h \
    Utilities/math_utils.h \
    Dynamics/body.h
b
