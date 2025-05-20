//FormAI DATASET v1.0 Category: Graph representation ; Style: protected
// Protected style C program to showcase graph representation
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

// Define struct for node
typedef struct node {
    int vertex;
    struct node* next;
} node_t;

// Define struct for graph
typedef struct graph {
    node_t* head[MAX_VERTICES];
} graph_t;

// Function to create a new node
node_t* create_node(int v) {
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
graph_t* create_graph() {
    graph_t* graph = (graph_t*) malloc(sizeof(graph_t));
    
    for(int i=0;i<MAX_VERTICES;++i)
        graph->head[i] = NULL;
    
    return graph;
}

// Function to add edge to the graph for given source and destination vertices
void add_edge(graph_t* graph, int source, int destination) {
    // Add edge from source to destination
    node_t* newNode = create_node(destination);
    newNode->next = graph->head[source];
    graph->head[source] = newNode;
    
    // Add edge from destination to source since the graph is undirected
    newNode = create_node(source);
    newNode->next = graph->head[destination];
    graph->head[destination] = newNode;
}

// Function to print the graph representation
void print_graph(graph_t* graph) {
    for(int i=0;i<MAX_VERTICES;++i) {
        node_t* temp = graph->head[i];
        printf("\n Adjacency list of vertex %d:", i);
        while(temp) {
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    graph_t* graph = create_graph();
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    print_graph(graph);

    return 0;
}