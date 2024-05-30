#include"stdafx.h"

#include <cmath>

#include"MathUtility.h"

double MathUtility::slope(Point3D point1, Point3D point2)
{
	double dx = point2.x() - point1.x();
	double dy = point2.y() - point1.y();
	double dz = point2.z() - point1.z();
	double distance = std::sqrt(dx * dx + dy * dy + dz * dz);
	return std::abs(dz / distance);
}

Point3D MathUtility::findHighestPoint(Triangulation& triangulation)
{
	vector<Point3D> points = triangulation.uniquePoints();
	double highestpoint = std::numeric_limits<double>::lowest();
	Point3D answer;
	for (auto point : points)
	{
		double high = point.z();
		if (high > highestpoint)

		{
			highestpoint = high;
			answer = point;
		}
	}

	return answer;

}
Point3D MathUtility::findlowestPoint(Triangulation& triangulation)
{
	vector<Point3D> points = triangulation.uniquePoints();
	double lowestpoint = std::numeric_limits<double>::max();  //put highest value of z
	Point3D answer;
	for (auto point : points)
	{
		double low = point.z();
		if (low < lowestpoint)

		{
			lowestpoint = low;
			answer = point;
		}
	}

	return answer;

}

