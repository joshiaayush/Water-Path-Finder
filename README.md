# Water Path Finder
## Description

Terrain Water Flow is a C++, OpenGL project aimed at simulating water flow over terrain surfaces. It provides tools to model various aspects of hydrology, including rainfall, surface runoff, and drainage patterns. The project utilizes STL (Stereolithography) files to represent terrain surfaces and employs a pathfinding algorithm to determine water flow paths.

## Classes

1. **FindPath**: Responsible for finding the path of water flow on the terrain surface using a pathfinding algorithm.
2. **MathUtility**: Contains utility functions for mathematical operations needed in the project.
3. **OpenGLWindow**: Manages the OpenGL window for visualization of the terrain and water flow.
4. **Point3D**: Represents a point in three-dimensional space.
5. **Reader**: Handles reading and parsing STL files to extract terrain data.
6. **Triangle**: Represents a triangle in three-dimensional space, used for triangulation of the terrain.
7. **Triangulation**: Performs triangulation of the terrain surface.
8. **stdafx**: Precompiled header file.

## Approach

The approach to finding the path of water flow is as follows:
1. Read the terrain surface data from an STL file using the Reader class.
2. Triangulate the terrain surface to form triangles using the Triangulation class.
3. Find the maximum point from the terrain surface.
4. Search for neighboring points with the lowest elevation from the current point, iteratively determining the path of water flow.
5. Store the path in a vector for later visualization and analysis.

```cpp
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

```
Clone this repository to your local machine.
```
git clone https://github.com/joshiaayush/Water-Path-Finder.git
```



