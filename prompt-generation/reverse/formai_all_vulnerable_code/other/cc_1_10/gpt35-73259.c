//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<assert.h>

#define WHITE 0
#define GRAY  1
#define BLACK 2

/* Create a custom structure type to represent a node in the graph */
typedef struct node_t {
    int id;
    int color;
    struct node_t** neighbors;
    size_t num_neighbors;
} node_t;

/* Function to initialize a node */
node_t* init_node(int id) {
    node_t* node = calloc(1, sizeof(node_t));
    node->id = id;
    node->color = WHITE;
    node->neighbors = NULL;
    node->num_neighbors = 0;
    return node;
}

/* Function to free a node */
void free_node(node_t* node) {
    assert(node != NULL);
    if (node->neighbors != NULL)
        free(node->neighbors);
    free(node);
}

/* Function to add a neighbor to a node */
void add_neighbor(node_t* node, node_t* neighbor) {
    assert(node != NULL && neighbor != NULL);
    node->neighbors = realloc(node->neighbors, (node->num_neighbors + 1) * sizeof(node_t*));
    node->neighbors[node->num_neighbors] = neighbor;
    node->num_neighbors++;
}

/* Function to color a graph using the greedy algorithm */
void color_graph(node_t** graph, size_t num_nodes, size_t num_colors) {
    assert(graph != NULL && num_nodes > 0 && num_colors > 0);
    /* Assign a unique color to the first node */
    graph[0]->color = 1; 
    /* Color all the remaining nodes using the greedy algorithm */
    for (size_t i = 1; i < num_nodes; i++) {
        int available_colors[num_colors+1]; /* Array containing the available colors */
        for (size_t j = 1; j <= num_colors; j++) /* Initialize all colors as available */
            available_colors[j] = 1;
        /* Iterate over all neighbors of the current node */
        for (size_t j = 0; j < graph[i]->num_neighbors; j++) {
            node_t* neighbor = graph[i]->neighbors[j];
            if (neighbor->color != WHITE) /* If the neighbor is already colored */
                available_colors[neighbor->color] = 0; /* Mark the color as unavailable */
        }
        /* Find the first available color */
        for (size_t j = 1; j <= num_colors; j++) {
            if (available_colors[j] == 1) {
                graph[i]->color = j; /* Color the node with that color */
                break;
            }
        }
    }
}

int main() {
    
    /* Post-apocalyptic graph consisting of 7 nodes and 4 colors */
    node_t* node0 = init_node(0);
    node_t* node1 = init_node(1);
    node_t* node2 = init_node(2);
    node_t* node3 = init_node(3);
    node_t* node4 = init_node(4);
    node_t* node5 = init_node(5);
    node_t* node6 = init_node(6);

    add_neighbor(node0, node1);
    add_neighbor(node0, node2);
    add_neighbor(node0, node3);
    add_neighbor(node1, node2);
    add_neighbor(node1, node4);
    add_neighbor(node1, node5);
    add_neighbor(node2, node4);
    add_neighbor(node2, node5);
    add_neighbor(node3, node5);
    add_neighbor(node5, node6);
    
    node_t* graph[] = {node0, node1, node2, node3, node4, node5, node6};
    size_t num_nodes = sizeof(graph) / sizeof(node_t*);
    size_t num_colors = 4;

    color_graph(graph, num_nodes, num_colors);

    /* Print the colors of the nodes */
    for (size_t i = 0; i < num_nodes; i++) {
        printf("Node %d is colored with %d\n", graph[i]->id, graph[i]->color);
    }

    /* Free the memory allocated for the nodes and the graph */
    for (size_t i = 0; i < num_nodes; i++) {
        free_node(graph[i]);
    }

    return 0;
}