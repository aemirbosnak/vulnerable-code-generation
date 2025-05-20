//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_QUEUE_SIZE 100

// Node structure
typedef struct Node {
    int id;
    int distance;
} Node;

// Queue structure
typedef struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Graph structure
typedef struct Graph {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
} Graph;

// Function to create a new node
Node* createNode(int id, int distance) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->id = id;
    newNode->distance = distance;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

// Function to check if queue is empty
bool isEmpty(Queue* queue) {
    if(queue->rear == -1) {
        return true;
    } else {
        return false;
    }
}

// Function to add an item to the queue
void enqueue(Queue* queue, int value) { 
    if(queue->rear == MAX_QUEUE_SIZE-1) {
        printf("\nQueue is full");
    } else {
        if(queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    int item;
    if(isEmpty(queue)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if(queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Function to create a new graph
Graph* createGraph(int numNodes) {
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));
    newGraph->numNodes = numNodes;
    int i, j;
    for(i = 0; i < numNodes; i++) {
        for(j = 0; j < numNodes; j++) {
            newGraph->adjMatrix[i][j] = 0;
        }
    }
    return newGraph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int startNode, int endNode) {
    graph->adjMatrix[startNode][endNode] = 1;
}

// Function to print the graph
void printGraph(Graph* graph) {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < graph->numNodes; i++) {
        for(j = 0; j < graph->numNodes; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find shortest path
void shortestPath(Graph* graph, int startNode, int endNode) {
    // Create visited array to keep track of visited nodes
    bool* visited = (bool*) calloc(graph->numNodes, sizeof(bool));
    visited[startNode] = true;
    // Create distance array to keep track of distances from source
    int* distance = (int*) calloc(graph->numNodes, sizeof(int));
    int i;
    for(i = 0; i < graph->numNodes; i++) {
        distance[i] = -1;
    }
    distance[startNode] = 0;
    // Create queue for BFS traversal
    Queue* queue = createQueue();
    enqueue(queue, startNode);
    printf("\nShortest path from node %d to node %d:", startNode, endNode);
    while(!isEmpty(queue)) {
        int currentNode = dequeue(queue);
        int j;
        // Traverse all neighbours of current node
        for(j = 0; j < graph->numNodes; j++) {
            if(graph->adjMatrix[currentNode][j] == 1 && !visited[j]) {
                visited[j] = true;
                distance[j] = distance[currentNode] + 1;
                enqueue(queue, j);
                if(j == endNode) {
                    printf(" %d", distance[j]);
                    return;
                }
            }
        }
    }
}

int main() {
    Graph* graph = createGraph(5);
    printf("Adding edges to the graph...\n");
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    shortestPath(graph, 0, 4);
    return 0;
}