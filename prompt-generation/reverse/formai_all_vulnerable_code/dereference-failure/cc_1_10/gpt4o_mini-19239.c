//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAX_VERTICES 10
#define MAX_QUEUE_SIZE 100

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph {
    Node *adjLists[MAX_VERTICES];
    int numVertices;
} Graph;

typedef struct ThreadData {
    Graph *graph;
    int startVertex;
} ThreadData;

typedef struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void* bfs(void *threadData);
Queue* createQueue();
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
bool isEmpty(Queue *q);

int main() {
    Graph *graph = createGraph(MAX_VERTICES);
    
    // Sample edges to create a graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 8);
    
    pthread_t threads[MAX_VERTICES];
    ThreadData threadData[MAX_VERTICES];

    // Start BFS from multiple vertices
    for (int i = 0; i < MAX_VERTICES; i++) {
        threadData[i].graph = graph;
        threadData[i].startVertex = i;
        pthread_create(&threads[i], NULL, bfs, (void *)&threadData[i]);
    }

    // Join threads
    for (int i = 0; i < MAX_VERTICES; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free graph resources
    for (int i = 0; i < MAX_VERTICES; i++) {
        Node *temp = graph->adjLists[i];
        while (temp) {
            Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph);
    return 0;
}

Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode; // For undirected graph
}

void* bfs(void *threadData) {
    ThreadData *data = (ThreadData *)threadData;
    Graph *graph = data->graph;
    int startVertex = data->startVertex;

    bool visited[MAX_VERTICES] = {false};
    Queue *q = createQueue();
    
    visited[startVertex] = true;
    enqueue(q, startVertex);

    printf("BFS starting from vertex %d:\n", startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node *temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    
    printf("\n");
    free(q);
    return NULL;
}

Queue* createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        return; // Queue is full
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1; // Queue is empty
    }
    int item = q->items[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1; // Reset the queue
    }
    return item;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}