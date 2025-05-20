//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 26

typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

GraphNode* createNode(int v);
void addEdge(GraphNode** nodes, int u, int v);
void printGraph(GraphNode** nodes);
void breadthFirstSearch(GraphNode** nodes, int startVertex);

Queue* createQueue();
QueueNode* createQueueNode(int data);
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
bool isEmpty(Queue* queue);

int main() {
    // initialize all vertices to null
    GraphNode* nodes[MAX_VERTICES] = { NULL };

    // create edges between vertices 
    addEdge(nodes, 0, 1);
    addEdge(nodes, 0, 4);
    addEdge(nodes, 1, 3);
    addEdge(nodes, 1, 4);
    addEdge(nodes, 2, 1);
    addEdge(nodes, 3, 2);
    addEdge(nodes, 3, 4);
    addEdge(nodes, 4, 2);

    // print graph to verify edges were added correctly
    printf("Graph:\n");
    printGraph(nodes);

    // perform breadth-first search starting at vertex 0
    printf("\nBreadth-First Search:\n");
    breadthFirstSearch(nodes, 0);

    return 0;
}

// creates a new GraphNode
GraphNode* createNode(int v) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->next = NULL;
    return node;
}

// adds an edge between two vertices
void addEdge(GraphNode** nodes, int u, int v) {
    GraphNode* node = createNode(v);
    node->next = nodes[u];
    nodes[u] = node;
}

// prints the graph's adjacency list
void printGraph(GraphNode** nodes) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        GraphNode* curr = nodes[i];
        printf("Node %d: ", i);

        while (curr) {
            printf("%d -> ", curr->vertex);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

// performs breadth-first search starting at a given vertex
void breadthFirstSearch(GraphNode** nodes, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    Queue* queue = createQueue();

    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while(!isEmpty(queue)) {
        int curr = dequeue(queue);
        printf("%d -> ", curr);

        GraphNode* adj = nodes[curr];
        while (adj) {
            int vertex = adj->vertex;
            if (!visited[vertex]) {
                visited[vertex] = true;
                enqueue(queue, vertex);
            }
            adj = adj->next;
        }
    }

    printf("NULL\n");
}

// creates a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// creates a new queue node
QueueNode* createQueueNode(int data) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// adds data to the rear of the queue
void enqueue(Queue* queue, int data) {
    QueueNode* node = createQueueNode(data);

    if (isEmpty(queue)) {
        queue->front = queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// removes and returns data from the front of the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    QueueNode* front = queue->front;
    int data = front->data;

    queue->front = front->next;
    free(front);

    return data;
}

// returns true if the queue is empty, false otherwise
bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}