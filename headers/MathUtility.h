#pragma once

#include "Triangulation.h"
#include "Point3D.h"


class MathUtility
{

public:
	double slope(Point3D P1, Point3D P2);

	Point3D findHighestPoint(Triangulation& triangulation);

	Point3D findlowestPoint(Triangulation& triangulation);

};