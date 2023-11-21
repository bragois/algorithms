#include "Graph.hpp"
#include <map>
#include <algorithm>

graphAlgorithms::Graph::Graph(bool directed)
{
    isDirected = directed;
}

graphAlgorithms::Graph::~Graph()
{
}

void graphAlgorithms::Graph::addEdge(int source, int destination)
{
    adjacencyList[source].push_back(destination);

    if (!isDirected){
        adjacencyList[destination].push_back(source);
    }
}

const std::vector<int>& graphAlgorithms::Graph::getAdjacentNodes(int node) const
{
    if (adjacencyList.find(node) != adjacencyList.end()){
        return adjacencyList.at(node);
    }
    static const std::vector<int> emptyVector;
    return std::move(emptyVector);
}

bool graphAlgorithms::Graph::hasEdge(int source, int destination) const
{
    if (adjacencyList.find(source) != adjacencyList.end()){
        const std::vector<int>& destinationNodes = adjacencyList.at(source);
        return std::find(destinationNodes.begin(), destinationNodes.end(), destination) != destinationNodes.end();

    }
    return false;
}

int graphAlgorithms::Graph::getNumNodes() const
{
    return static_cast<int>(adjacencyList.size());
}

int graphAlgorithms::Graph::getNumEdges() const
{
    int numEdges = 0;
    for (auto& entry : adjacencyList) {
        numEdges += static_cast<int>(entry.second.size());
    }
    
    if(!isDirected){
        numEdges /= 2;
    }

    return numEdges;
}

graphAlgorithms::GraphAlgorithms::GraphAlgorithms(Graph &g)
{
    graph = std::move(g);
}

graphAlgorithms::GraphAlgorithms::~GraphAlgorithms()
{
}

void graphAlgorithms::GraphAlgorithms::DFS(int startNode)
{
    std::map<int, bool> visited;
    visited[startNode] = true;
    
    for(auto node : graph.adjacencyList){
        if(!visited[node.first]){
            this->DFS(node.first);
        }
    }
}

// Driver code
int main()
{
    using namespace graphAlgorithms;
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    GraphAlgorithms grAlg(g);
    std::cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";

    // Function call
    grAlg.DFS(2);

    return 0;
}

