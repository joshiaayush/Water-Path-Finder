#pragma once
#include "stdafx.h"
class Point3D
{
public:
    Point3D();
    Point3D(float inX, float inY, float inZ);
    ~Point3D();
    float x();
    float y();
    float z();
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    bool operator<(const Point3D& other) const;
    Point3D& operator=(const Point3D& other);
    bool operator==(const Point3D& other) const;


private:
    float mX;
    float mY;
    float mZ;
};