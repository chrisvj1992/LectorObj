#ifndef CARA_H
#define CARA_H

#pragma once

#include <vector>
using namespace std;

class cara
{
public:
	vector<unsigned int> verticesIndex;

	cara(vector<unsigned int> verticesIndex);
	void print();
};
#endif
