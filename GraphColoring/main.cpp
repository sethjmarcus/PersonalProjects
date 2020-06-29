#include "Graph.h"
#include "GraphColoring.h"
//"Graph.h" includes: fstream, iostram, list, exception

int main(int argc, char** argv)
{
    //Open file
    try
    {
        if(argc < 2)
        {
            throw(std::invalid_argument("No input file detected"));
        }
    }catch(std::invalid_argument &ex)
    {
        std::cout<<ex.what();
        std::cout<<"\nExiting program now"<<std::endl;
        return 0;
    }
    std::ifstream input;
    input.open(argv[1]);
    //Read in the first value, the number of nodes in the graph
    int numberOfNodes;
    input>>numberOfNodes;
    //create the graph
    Graph* g = new Graph(input, numberOfNodes);
    //g->printGraph();

    //create the Graph Coloring
    GraphColoring* gc = new GraphColoring(g);

    //gc->printColoring();
    std::cout<<"\n\n";
    //printTable(colorOfNodesAry, numberOfNodes);
    g->printGraph();
    //clean up and close files
    delete g;
    delete gc;
    input.close();
    return 0;
}

