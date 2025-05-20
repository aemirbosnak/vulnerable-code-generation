//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// define the maximum number of vertices and edges
#define MAX_VERTICES 1000
#define MAX_EDGES 2000

// define the structure for the edge
typedef struct Edge {
    int src;        // source vertex
    int dest;       // destination vertex
    int weight;     // weight of the edge
} Edge;

// define the structure for the graph
typedef struct Graph {
    int V;          // number of vertices
    int E;          // number of edges
    Edge edges[MAX_EDGES];  // array of edges
} Graph;

// define the structure for the minimum heap node
typedef struct MinHeapNode {
    int vertex;     // vertex number
    int key;        // minimum distance from the source vertex to the vertex
} MinHeapNode;

// define the structure for the minimum heap
typedef struct MinHeap {
    int size;       // size of the heap
    int capacity;   // max capacity of the heap
    int *pos;       // position of the node in the heap
    MinHeapNode **array;    // array of heap nodes
} MinHeap;

// function to create a new graph
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));     // allocate memory for the graph
    graph->V = V;       // set the number of vertices
    graph->E = E;       // set the number of edges
    return graph;
}

// function to create a new minimum heap node
MinHeapNode* newMinHeapNode(int vertex, int key) {
    MinHeapNode* node = (MinHeapNode*) malloc(sizeof(MinHeapNode));      // allocate memory for the node
    node->vertex = vertex;      // set the vertex of the node
    node->key = key;        // set the key (minimum distance from the source vertex to the vertex)
    return node;
}

// function to create a new minimum heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));       // allocate memory for the heap
    heap->pos = (int*) malloc(capacity * sizeof(int));        // allocate memory for the position array
    heap->size = 0;         // set the size to 0
    heap->capacity = capacity;      // set the max capacity
    heap->array = (MinHeapNode**) malloc(capacity * sizeof(MinHeapNode*));     // allocate memory for the node array
    return heap;
}

// function to swap two minimum heap nodes
void swap(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// function to heapify a minimum heap
void minHeapify(MinHeap* heap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->key < heap->array[smallest]->key)
        smallest = left;
    if (right < heap->size && heap->array[right]->key < heap->array[smallest]->key)
        smallest = right;
    if (smallest != idx) {
        MinHeapNode *smallestNode = heap->array[smallest];
        MinHeapNode *idxNode = heap->array[idx];
        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;
        swap(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// function to check if the minimum heap is empty
int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

// function to extract the minimum node from the minimum heap
MinHeapNode* extractMin(MinHeap* heap) {
    if (isEmpty(heap)) 
        return NULL;
    MinHeapNode* root = heap->array[0];
    MinHeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;
    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;
    --heap->size;
    minHeapify(heap, 0);
    return root;
}

// function to decrease the key value of a given vertex
void decreaseKey(MinHeap* heap, int vertex, int key) {
    int i = heap->pos[vertex];
    heap->array[i]->key = key;
    while (i && heap->array[i]->key < heap->array[(i - 1) / 2]->key) {
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// function to check if a given vertex is in the minimum heap
int isInMinHeap(MinHeap* heap, int vertex) {
    return heap->pos[vertex] < heap->size;
}

// function to print the solution
void printSolution(int dist[], int n) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t %d\n", i, dist[i]);
}

// function to perform Dijkstra's algorithm on the given graph and source vertex
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[V];
    MinHeap* heap = createMinHeap(V);
    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
        heap->array[i] = newMinHeapNode(i, dist[i]);
        heap->pos[i] = i;
    }
    heap->array[src] = newMinHeapNode(src, dist[src]);
    heap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(heap, src, dist[src]);
    heap->size = V;
    while (!isEmpty(heap)) {
        MinHeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;
        for (int i = 0; i < graph->E; ++i) {
            int v = graph->edges[i].dest;
            if (graph->edges[i].src == u && isInMinHeap(heap, v) && dist[u] != INT_MAX && 
                    graph->edges[i].weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + graph->edges[i].weight;
                decreaseKey(heap, v, dist[v]);
            }
        }
    }
    printSolution(dist, V);
}

// main function
int main() {
    int V = 9;
    int E = 14;
    Graph* graph = createGraph(V, E);
    graph->edges[0].src = 0; graph->edges[0].dest = 1; graph->edges[0].weight = 4;
    graph->edges[1].src = 0; graph->edges[1].dest = 7; graph->edges[1].weight = 8;
    graph->edges[2].src = 1; graph->edges[2].dest = 2; graph->edges[2].weight = 8;
    graph->edges[3].src = 1; graph->edges[3].dest = 7; graph->edges[3].weight = 11;
    graph->edges[4].src = 2; graph->edges[4].dest = 3; graph->edges[4].weight = 7;
    graph->edges[5].src = 2; graph->edges[5].dest = 8; graph->edges[5].weight = 2;
    graph->edges[6].src = 2; graph->edges[6].dest = 5; graph->edges[6].weight = 4;
    graph->edges[7].src = 3; graph->edges[7].dest = 4; graph->edges[7].weight = 9;
    graph->edges[8].src = 3; graph->edges[8].dest = 5; graph->edges[8].weight = 14;
    graph->edges[9].src = 4; graph->edges[9].dest = 5; graph->edges[9].weight = 10;
    graph->edges[10].src = 5; graph->edges[10].dest = 6; graph->edges[10].weight = 2;
    graph->edges[11].src = 6; graph->edges[11].dest = 7; graph->edges[11].weight = 1;
    graph->edges[12].src = 6; graph->edges[12].dest = 8; graph->edges[12].weight = 6;
    graph->edges[13].src = 7; graph->edges[13].dest = 8; graph->edges[13].weight = 7;
    dijkstra(graph, 0);
    return 0;
}