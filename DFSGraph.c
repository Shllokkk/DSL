#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int V;
    int** adjacencyMatrix;
    bool* visited;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    
    graph->visited = (bool*)malloc(V * sizeof(bool));
    for (int i = 0; i < V; i++) {
        graph->visited[i] = false;
    }
    
    graph->adjacencyMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1; 
}

void DFS(struct Graph* graph, int vertex) {
    printf("%d ", vertex);
    graph->visited[vertex] = true;

    for (int i = 0; i < graph->V; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !graph->visited[i]) {
            DFS(graph, i);
        }
    }
}

int main() {
    int V = 6; 
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    printf("Depth First Traversal starting from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}
