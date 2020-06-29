#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iterator>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
//#include <exception>

class Graph
{
    public:
        Graph(std::ifstream& inputFile, const int n);
        ~Graph();
        std::list<int> getList(int index) const;
        void debug();
        void printGraph() const;
        void sortGraph();
        //add edge
        //add vertex
        //remove edge
        //remove vertex
    private:
        int numNodes;
        std::vector<std::list<int>> table;
};

#endif // GRAPH_H
