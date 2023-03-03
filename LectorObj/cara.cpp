#include "cara.hpp"
#include <iostream>

using std::cout;

cara::cara(vector<unsigned int> verticesIndex) {
	this->verticesIndex = verticesIndex;
}

void cara::print()
{
	printf("caras:\n\n");
	for (auto const& i : verticesIndex)
	{
		std::cout << i << " ";
		printf("\n\n");
	}
}