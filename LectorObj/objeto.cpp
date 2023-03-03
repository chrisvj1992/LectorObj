#include <fstream>
#include "objeto.hpp"
#include "vertice.hpp"

objeto::objeto(string objFile, vector<unsigned int> &indices)
{
    this->vertices = {};
    string line;
    ifstream archivoOBJ(objFile);
    while (getline(archivoOBJ, line))
    {
        if (line.length() > 0)
        {
            vector<string> tokens = this->split(line, " ");
            if (!tokens.empty())
            {
                if (tokens[0] == "v")
                {
                    float x = stof(tokens[1]);
                    float y = stof(tokens[2]);
                    float z = stof(tokens[3]);
                    vertice v(x, y, z);
                    this->vertices.push_back(v);
                }
                if (tokens[0] == "f")
                {
                    for (unsigned int i = 1; i <= tokens.size() - 1; i++)
                    {
                        unsigned int ind = stoi(this->split(tokens[i], "/")[0]) - 1;
                        indices.push_back(ind);
                    }
                    cara f(indices);
                    this->faces.push_back(f);
                }
            }
        }
    }
}

vector<string> objeto::split(string str, string delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);

        if (pos == string::npos ) pos = str.length();
        string token = str.substr( prev, pos - prev);

        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();

    } while (pos < str.length() && prev < str.length());
    return tokens;
}
