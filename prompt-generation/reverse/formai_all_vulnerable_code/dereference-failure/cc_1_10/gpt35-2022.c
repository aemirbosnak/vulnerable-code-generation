//FormAI DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// linked list node for adjacency list representation of graph
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// graph structure
typedef struct graph {
    Node* head[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    int num_vertices;
} Graph;

// function to create a new graph
Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        graph->head[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

// function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // create new node for adjacency list
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->vertex = dest;
    new_node->next = graph->head[src];
    graph->head[src] = new_node;
}

// function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        Node* current_node = graph->head[i];
        printf("%d: ", i);
        while (current_node != NULL) {
            printf("%d -> ", current_node->vertex);
            current_node = current_node->next;
        }
        printf("NULL\n");
    }
}

// main function
int main() {
    // create a graph with 5 vertices
    Graph* graph = createGraph(5);
    // add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    // print the graph
    printGraph(graph);
    // free memory
    free(graph);
    return 0;
}