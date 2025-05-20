//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define INFINITY 99999

typedef struct {
    int edges[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

typedef struct {
    int vertex;
    int distance;
} MinHeapNode;

typedef struct {
    MinHeapNode *array;
    int size;
    int capacity;
} MinHeap;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph->edges[i][j] = (i == j) ? 0 : INFINITY;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->edges[src][dest] = weight;
    graph->edges[dest][src] = weight; // For undirected graph
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode*)malloc(capacity * sizeof(MinHeapNode));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode* a, MinHeapNode* b) {
    MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left].distance < minHeap->array[smallest].distance) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right].distance < minHeap->array[smallest].distance) {
        smallest = right;
    }

    if (smallest != index) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

int isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

MinHeapNode extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap)) {
        MinHeapNode emptyNode = { -1, -1 };
        return emptyNode; // Should not occur in valid cases
    }

    MinHeapNode root = minHeap->array[0];
    MinHeapNode lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(MinHeap* minHeap, int vertex, int distance) {
    int i;
    for (i = 0; i < minHeap->size; i++) {
        if (minHeap->array[i].vertex == vertex) {
            break;
        }
    }
    minHeap->array[i].distance = distance;

    while (i && minHeap->array[i].distance < minHeap->array[(i - 1) / 2].distance) {
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isPresentInMinHeap(MinHeap* minHeap, int vertex) {
    for (int i = 0; i < minHeap->size; i++) {
        if (minHeap->array[i].vertex == vertex) {
            return 1;
        }
    }
    return 0;
}

void dijkstra(Graph* graph, int start) {
    int vertices = graph->numVertices;
    int* distance = (int*)malloc(vertices * sizeof(int));
    MinHeap* minHeap = createMinHeap(vertices);

    for (int v = 0; v < vertices; v++) {
        distance[v] = INFINITY;
        minHeap->array[v] = (MinHeapNode){ v, distance[v] };
        minHeap->size++;
    }

    distance[start] = 0;
    minHeap->array[start].distance = distance[start];
    decreaseKey(minHeap, start, distance[start]);

    while (!isEmpty(minHeap)) {
        MinHeapNode minNode = extractMin(minHeap);
        int u = minNode.vertex;

        for (int v = 0; v < vertices; v++) {
            if (graph->edges[u][v] != INFINITY && isPresentInMinHeap(minHeap, v) && 
                distance[u] != INFINITY && distance[u] + graph->edges[u][v] < distance[v]) {
                distance[v] = distance[u] + graph->edges[u][v];
                decreaseKey(minHeap, v, distance[v]);
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }

    free(distance);
    free(minHeap->array);
    free(minHeap);
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    dijkstra(graph, 0);

    free(graph);
    return 0;
}