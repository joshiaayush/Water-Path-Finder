#include "stdafx.h"
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include "Point3D.h"
#include "Reader.h"
#include "Triangle.h"
#include "Triangulation.h"

using namespace std;

Reader::Reader()
{
}
Reader ::~Reader()
{
}

void Reader::readFile(Triangulation& triangualtion)
{
    std::ifstream readFromFile("Terrain.stl");

    map<Point3D, int> mapppedPoint3D;
    map<Point3D, int> mappedNormals;
    string line;

    bool ans = readFromFile.is_open();
    if (ans)
    {

        int numberOfVertex = 1;
        int normalIndex = 1;
        int v1;
        int v2;
        int v3;
        int Normal;
        while (getline(readFromFile, line))
        {
            

            if (line.find("vertex") != string::npos)
            {
                istringstream vertexStream(line);
                string token;
                double x, y, z;

                vertexStream >> token >> x >> y >> z;
                // Stored Coordinates x,y,z into object of Point3D
                Point3D point(x, y, z);


                auto it = mapppedPoint3D.find(point);

                if (it == mapppedPoint3D.end())
                {
                    triangualtion.uniquePoints().push_back(point);

                    mapppedPoint3D[point] = triangualtion.uniquePoints().size();
                }
                if (numberOfVertex == 1)
                {
                    v1 = mapppedPoint3D[point];
                    numberOfVertex++;
                }
                else if (numberOfVertex == 2)
                {
                    v2 = mapppedPoint3D[point];
                    numberOfVertex++;
                }
                else if (numberOfVertex == 3)
                {

                    v3 = mapppedPoint3D[point];
                    numberOfVertex++;
                }
            }
            if (numberOfVertex == 4)
            {

                Triangle T(v1 - 1, v2 - 1, v3 - 1);
                triangualtion.triangles().push_back(T);
                numberOfVertex = 1;
            }
        }

        // copied all data of different vector into uniquePoints
        cout << "file close successfully" << endl;
        readFromFile.close();
    }
}