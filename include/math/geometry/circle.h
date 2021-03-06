//
// Created by jonas on 12/23/17.
//

#ifndef GAMEGEOMETRY_CIRCLE_H
#define GAMEGEOMETRY_CIRCLE_H

#include "shape2d.h"
#include "math/vector_types.h"

namespace GG {
    struct Circle : public Shape2D {
        Circle(const Vector2f& center, float radius):center(center),radius(radius){}

        ShapeType2D getShapeType() const override {return ShapeType2D::SHAPE_2D_CIRCLE;}

        Polygon2D toPolygon() const override;
        Bounding2D toBoundingBox() const override;

        Vector2f center;
        float radius;
    };
}


#endif //GAMEGEOMETRY_CIRCLE_H
