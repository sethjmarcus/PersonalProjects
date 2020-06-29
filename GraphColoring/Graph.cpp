#include "Graph.h"

Graph::Graph(std::ifstream& inputFile, const int n) : numNodes(n)
{
    //define the edge by 2 end nodes
    int startNode, endNode;
    //initialize table
    table.resize(numNodes+1);
    //fill in table from input file. Input is directed graph. We need an undirected graph
    while(inputFile>>startNode>>endNode)
    {
        table[startNode].push_back(endNode);
        table[endNode].push_back(startNode);
    }
    //The first node of each list will tell us which node this list is associated with.
    //Allows us to rearrange the ordering of the lists without 'forgetting' which list is
    //associated with which node
    for(int i = 0; i <= numNodes; i++)
    {
        table[i].push_front(i);
    }


}

void Graph::sortGraph()
{
    //sort the lists in descending order based on size of list
    std::sort(this->table.begin(), this->table.end(), []
        (const std::list<int>& a, const std::list<int> b) -> bool
        {
            return a.size() > b.size();
        }
    );
}

std::list<int> Graph::getList(int index) const
{
    //Ensures list requested is a valid list
    if(index < 0 || index >= this->numNodes)
    {
        throw(std::range_error("Trying to access list/node that does not have meaning and/or doesn't exist"));
    }
    //returns requested list. Enables data checking and whole graph isn't a public memeber
    return this->table[index];
}

void Graph::debug()
{
    std::list<int> temp;
    std::cout<<"Table\n";
    for(unsigned int i = 0; i < table.size(); i++)
    {
        temp = table[i];
        std::list<int>::iterator buffer = temp.begin();
        std::list<int>::iterator it;
        for(it = ++buffer; it != temp.end(); it++){
            std::cout<<(*it)<<" ";
        }
        std::cout<<std::endl;
    }
}
Graph::~Graph()
{
    std::cout<<"Graph has been destructed\n"<<std::endl;
}
void Graph::printGraph() const
{
    std::list<int>::const_iterator buffer;
    std::list<int>::const_iterator it;
    std::cout<<"Contents of graph printed";
    for(int i = 0; i < this->table.size(); i++)
    {
        buffer = table[i].begin();
        for(it = ++buffer; it != table[i].end(); it++)
        {
            std::cout<<(*it)<<" ";
        }
        std::cout<<std::endl;
    }
}
