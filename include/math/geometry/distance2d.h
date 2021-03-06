//
// Created by Jonas on 04-01-2018.
//

#ifndef GAMEGEOMETRY_DISTANCE2D_H
#define GAMEGEOMETRY_DISTANCE2D_H

#include <algorithm>
#include "geometry_util.h"

namespace GG {
    inline Vector2f nearestPoint(const Vector2f &point, const LineSegment2D &lineSegment) {
        Vector2f projection = project(point, lineSegment.getLine());
        float pa = length2(lineSegment.a - point);
        float pb = length2(lineSegment.b - point);

        if (    projection.x <= std::max(lineSegment.a.x, lineSegment.b.x) &&
                projection.x >= std::min(lineSegment.a.x, lineSegment.b.x) &&
                projection.y <= std::max(lineSegment.a.y, lineSegment.b.y) &&
                projection.y >= std::min(lineSegment.a.y, lineSegment.b.y)) {
            return projection;
        }

        if (pa < pb) {
            return lineSegment.a;
        }

        return lineSegment.b;
    }

    //An invariance applies to all closestPoints functions:
    // point a of the returned item is a point on the first piece of geometry and point b is the point on the second.
    template<class T, class S,
            class = typename std::enable_if<std::is_base_of<Geometry2D, T>::value>::type,
            class = typename std::enable_if<std::is_base_of<Geometry2D, S>::value>::type
    >
    inline LineSegment2D nearestPoints(const T& geom1, const S& geom2) {
        LineSegment2D ls = nearestPoints(geom2, geom1);

        return LineSegment2D(ls.b, ls.a);
    };

    template<class T,
            class = typename std::enable_if<std::is_base_of<Geometry2D, T>::value>::type
    >
    LineSegment2D nearestPoints(const T& geom1, const Geometry2D& geom2);

    LineSegment2D nearestPoints(const Geometry2D& geom1, const Geometry2D& geom2);

    //Line segment
    inline LineSegment2D nearestPoints(const LineSegment2D& lineSegment1, const LineSegment2D& lineSegment2);
    inline LineSegment2D nearestPoints(const LineSegment2D& lineSegment, const Line2D& line);
    LineSegment2D nearestPoints(const LineSegment2D& lineSegment, const Polygon2D& poly);
    inline LineSegment2D nearestPoints(const LineSegment2D& lineSegment, const Bounding2D& bounding);
    inline LineSegment2D nearestPoints(const LineSegment2D& lineSegment, const Circle& circle);

    //Line
    inline LineSegment2D nearestPoints(const Line2D& line1, const Line2D& line2);
    LineSegment2D nearestPoints(const Line2D& line, const Polygon2D& poly);
    inline LineSegment2D nearestPoints(const Line2D& line, const Bounding2D& bounding);
    inline LineSegment2D nearestPoints(const Line2D& line, const Circle& circle);

    //Shape
    template<class T,
            class = typename std::enable_if<std::is_base_of<Geometry2D, T>::value>::type
    >
    LineSegment2D nearestPoints(const T& shape1, const Shape2D& shape2);

    LineSegment2D nearestPoints(const Shape2D& shape1, const Shape2D& shape2);

    //Polygon
    LineSegment2D nearestPoints(const Polygon2D &poly1, const Polygon2D &poly2);
    LineSegment2D nearestPoints(const Polygon2D& poly, const Circle& circle);
    inline LineSegment2D nearestPoints(const Polygon2D& poly, const Bounding2D& aabb);

    //Bounding box
    inline LineSegment2D nearestPoints(const Bounding2D& aabb, const Circle& circle);
    inline LineSegment2D nearestPoints(const Bounding2D& aabb1, const Bounding2D& aabb2);

    //Circle
    LineSegment2D nearestPoints(const Circle& circle1, const Circle& circle2);
}

#endif //GAMEGEOMETRY_DISTANCE2D_H
