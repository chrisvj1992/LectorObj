#ifndef OBJETO_H
#define OBJETO_H

#pragma once

#include <string>
#include "vertice.hpp"
#include "cara.hpp"

class objeto
{

public:
    objeto(string objFile, vector<unsigned int> &indices);
    vector<vertice> vertices;
    vector<cara> faces;
    vector<string> split(string str, string delim);
};

#endif // !OBJETO_H