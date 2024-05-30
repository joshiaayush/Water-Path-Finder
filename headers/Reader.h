#pragma once
#include "stdafx.h"
#include "Triangulation.h"

class Reader
{
public:
    Reader();
    ~Reader();

    void readFile(Triangulation& triangulation);
};