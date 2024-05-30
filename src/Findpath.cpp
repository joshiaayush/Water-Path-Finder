#include"stdafx.h"
#include <cmath>
#include"Findpath.h"

Point3D Findpath::nextpoint(Point3D& currpoint, Triangulation& terrain)
{
	vector<Triangle> triangles = terrain.triangles();
	vector<Point3D> uniquepoints = terrain.uniquePoints();
	Point3D currentpoint = currpoint;
	vector<Point3D> connectedvertics;

	for (auto triangle : triangles)
	{
		Point3D P1, P2, P3;
		P1 = uniquepoints[triangle.v1()];
		P2 = uniquepoints[triangle.v2()];
		P3 = uniquepoints[triangle.v3()];

		if (P1 == currpoint)
		{
			connectedvertics.push_back(P2);
			connectedvertics.push_back(P3);
		}
		else if (P2 == currentpoint)
		{
			connectedvertics.push_back(P1);
			connectedvertics.push_back(P3);
		}
		else if (P3 == currentpoint)
		{
			connectedvertics.push_back(P1);
			connectedvertics.push_back(P2);
		}
	}

	Point3D final;
	//checking for slope with the current point and answer vertices
	double steepestpoint = mathUtility.slope(currentpoint, connectedvertics[0]);

	for (auto it : connectedvertics)
	{
		double currentslope;
		currentslope = mathUtility.slope(currentpoint, it);
		
		if (currentslope >= steepestpoint && currentpoint.z() > it.z())
		{
			final = it;
		}
	}
	return final;
}

vector<Point3D> Findpath::generatepath(Point3D& highestpoint, Triangulation& terrain)
{
	vector<Point3D> result;
	Point3D currentpoint = highestpoint;
	Point3D end = mathUtility.findlowestPoint(terrain);

	while (true)
	{
		Point3D newpoint = nextpoint(currentpoint, terrain);
		if (newpoint.z() <= end.z() )
		{
			break;
		}
		result.push_back(newpoint);
		currentpoint = newpoint;
		
	}
	return result;
}

vector<Point3D> Findpath::findpath(Triangulation& terrain)
{
	Point3D highestpoint = mathUtility.findHighestPoint(terrain);
	vector<Point3D> answer = generatepath(highestpoint, terrain);
	return answer;
}