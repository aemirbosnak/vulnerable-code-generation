//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A node in the graph
typedef struct node {
    int color;
    int index;
    int degree;
    struct node *neighbors[10];
} node;

// A graph
typedef struct graph {
    int num_nodes;
    node **nodes;
} graph;

// Function to initialize the graph
graph* init_graph(int num_nodes) {
    graph* g = malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->nodes = malloc(num_nodes * sizeof(node*));
    
    for (int i = 0; i < num_nodes; i++) {
        g->nodes[i] = malloc(sizeof(node));
        g->nodes[i]->color = INT_MIN;
        g->nodes[i]->index = i;
        g->nodes[i]->degree = 0;
        g->nodes[i]->neighbors[0] = NULL;
    }
    
    return g;
}

// Function to add an edge to the graph
void add_edge(graph* g, int node_a, int node_b) {
    if (g->nodes[node_a]->degree < 10) {
        g->nodes[node_a]->degree++;
        g->nodes[node_a]->neighbors[g->nodes[node_a]->degree - 1] = g->nodes[node_b];
    }
    if (g->nodes[node_b]->degree < 10) {
        g->nodes[node_b]->degree++;
        g->nodes[node_b]->neighbors[g->nodes[node_b]->degree - 1] = g->nodes[node_a];
    }
}

// Function to color the graph
void color_graph(graph* g) {
    int color_count[10];
    for (int i = 0; i < g->num_nodes; i++) {
        color_count[0] = 0;
        int temp_color = 1;
        while (temp_color <= 9) {
            if (g->nodes[i]->color!= temp_color) {
                g->nodes[i]->color = temp_color;
                color_count[temp_color - 1]++;
                for (int j = 0; j < g->nodes[i]->degree; j++) {
                    if (g->nodes[i]->neighbors[j]->color == g->nodes[i]->color) {
                        color_count[temp_color - 1]--;
                        break;
                    }
                }
                if (color_count[temp_color - 1] == g->nodes[i]->degree) {
                    break;
                }
                temp_color++;
            }
        }
    }
}

// Function to print the graph
void print_graph(graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < g->nodes[i]->degree; j++) {
            printf("%d ", g->nodes[i]->neighbors[j]->index);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int num_nodes = 5;
    graph* g = init_graph(num_nodes);
    
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    
    color_graph(g);
    
    print_graph(g);
    
    return 0;
}