#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>


namespace graphAlgorithms{
    // Class forward declaration

    //Node representation
    class Node {
        public:
        int data;
        explicit Node(int value) : data(value) {}
    };
// TO DO: template to support adjiacency Lists with weights.
    class Graph{
    public:
        Graph(bool directed = false);
        ~Graph();

        void addEdge(int source, int destination);
        const std::vector<int>& getAdjacentNodes(int node) const;
        bool hasEdge(int source, int destination) const;
        int getNumNodes() const;
        int getNumEdges() const;

    
        std::unordered_map<int, std::vector<int>> adjacencyList;
    
    private:
        bool isDirected;
    };

    class GraphAlgorithms{
    public:
        GraphAlgorithms(Graph& g);
        ~GraphAlgorithms();

        void DFS(int startNode);
        void BFS(int startNode);
        std::unordered_map<int, int>  DijkstrasAlgorithm(int startNode);
        std::unordered_map<int, int> BellmanFordAlgorithm(int startNode);
        std::vector<std::vector<int>> FloysWarshallAlgorithm(void);
    
    private:
        // Helper function for Dijkstra's Algorithm
        int getMinDistanceVertex(const std::vector<int>& distances, const std::vector<bool>& visited);

        // Helper function for Bellman-Ford Algorithm
        bool relaxEdge(int u, int v, int weight, std::vector<int>& distance);

    public:
        Graph graph;
    };
}

#endif // END OF GRAPH.HPP