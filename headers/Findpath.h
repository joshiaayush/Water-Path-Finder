#pragma once

#include "Triangulation.h"
#include "Point3D.h"
#include "MathUtility.h"


class Findpath
{

public:
	vector<Point3D> findpath(Triangulation& terrain);

	Point3D nextpoint(Point3D& currentpoint, Triangulation& terrain);

	vector<Point3D> generatepath(Point3D& hghestpoint, Triangulation& terrain);
private:
	MathUtility mathUtility;
};