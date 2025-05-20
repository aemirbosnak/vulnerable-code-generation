//FormAI DATASET v1.0 Category: Graph representation ; Style: random
#include<stdio.h>
#include<stdlib.h>

// Define a structure for graph node
struct GraphNode {
    int data;
    struct GraphNode* next;
};

// Define a structure for the graph
struct Graph {
    int num_vertices;
    struct GraphNode** adjacency_list;
};

// Create a new graph node with given data
struct GraphNode* createGraphNode(int data) {
    struct GraphNode* node = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Create a new graph with given number of vertices
struct Graph* createGraph(int num_vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_list = (struct GraphNode**)malloc(num_vertices * sizeof(struct GraphNode*));
    int i;
    for(i=0; i<num_vertices; i++) {
        graph->adjacency_list[i] = NULL;
    }
    return graph;
}

// Add a new edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct GraphNode* node = createGraphNode(dest);
    node->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = node;
}

// Print the graph representation
void printGraph(struct Graph* graph) {
    int i;
    for(i=0; i<graph->num_vertices; i++) {
        struct GraphNode* node = graph->adjacency_list[i];
        printf("Vertex %d: ", i);
        while(node != NULL) {
            printf("%d -> ", node->data);
            node = node->next;
        }
        printf("NULL\n");
    }
}

// Driver code
int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    printGraph(graph);
    return 0;
}