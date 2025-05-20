//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a graph node
typedef struct graph_node {
    int vertex;
    int color;
    int edges;
    struct graph_node *next;
} GraphNode;

// Define the structure for a graph
typedef struct graph {
    GraphNode *head;
    int num_vertices;
    int num_edges;
} Graph;

// Function to initialize a graph
Graph *init_graph(int num_vertices, int num_edges) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->head = NULL;
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    return graph;
}

// Function to add an edge to a graph
void add_edge(Graph *graph, int vertex1, int vertex2) {
    GraphNode *node1 = NULL, *node2 = NULL;
    
    // Find the first node with the given vertex
    for (node1 = graph->head; node1!= NULL; node1 = node1->next) {
        if (node1->vertex == vertex1)
            break;
    }
    
    // Find the second node with the given vertex
    for (node2 = graph->head; node2!= NULL; node2 = node2->next) {
        if (node2->vertex == vertex2)
            break;
    }
    
    // Add a new node to the graph
    GraphNode *new_node = (GraphNode *)malloc(sizeof(GraphNode));
    new_node->vertex = vertex2;
    new_node->edges = 0;
    new_node->color = 0;
    new_node->next = NULL;
    
    // Connect the nodes to each other
    new_node->next = node1;
    node1->next = new_node;
    
    // Increment the number of edges in the graph
    graph->num_edges++;
}

// Function to print a graph
void print_graph(Graph *graph) {
    GraphNode *node = graph->head;
    while (node!= NULL) {
        printf("%d: ", node->vertex);
        for (node = node->next; node!= NULL; node = node->next) {
            printf("%d ", node->vertex);
        }
        printf("\n");
        node = node->next;
    }
}

// Function to perform graph coloring
int color_graph(Graph *graph) {
    int num_colors = 0;
    
    // Find the first node with a color of 0
    GraphNode *node = graph->head;
    while (node!= NULL) {
        if (node->color == 0) {
            node->color = num_colors;
            num_colors++;
            break;
        }
        node = node->next;
    }
    
    // Recursively color the remaining nodes
    if (node!= NULL) {
        color_graph(node->next);
    }
    
    // Return the number of colors used
    return num_colors;
}

// Main function
int main() {
    // Create a graph with 3 vertices and 4 edges
    Graph *graph = init_graph(3, 4);
    
    // Add edges to the graph
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    
    // Print the graph
    print_graph(graph);
    
    // Perform graph coloring
    int num_colors = color_graph(graph);
    
    // Print the number of colors used
    printf("Number of colors used: %d\n", num_colors);
    
    return 0;
}