#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100


struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}


struct Graph {
    int V;
    int** adjacencyMatrix;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
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

void BFS(struct Graph* graph, int startVertex) {
    int V = graph->V;
    bool* visited = (bool*)malloc(V * sizeof(bool));
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    struct Queue* queue = createQueue(MAX_VERTICES);

    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < V; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(queue, i);
            }
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

    printf("Breadth First Traversal starting from vertex 0:\n");
    BFS(graph, 0);

    return 0;
}
