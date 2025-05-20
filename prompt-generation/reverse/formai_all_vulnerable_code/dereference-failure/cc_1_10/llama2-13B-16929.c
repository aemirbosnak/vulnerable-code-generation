//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a vertex in the graph
typedef struct vertex {
    int label;    // Label of the vertex
    struct vertex* next;  // Next vertex in the graph
} Vertex;

// Function to create a new vertex
Vertex* new_vertex(int label) {
    Vertex* v = malloc(sizeof(Vertex));
    v->label = label;
    v->next = NULL;
    return v;
}

// Function to create a new edge between two vertices
void add_edge(Vertex* u, Vertex* v) {
    u->next = v;
    v->next = u;
}

// Function to traverse the graph in a recursive manner
void traverse(Vertex* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    traverse(root->next);

    // Visit the current vertex
    printf("%d ", root->label);

    // Traverse the right subtree
    traverse(root->next->next);
}

int main() {
    // Create the graph
    Vertex* root = new_vertex(1);
    Vertex* u = new_vertex(2);
    Vertex* v = new_vertex(3);
    Vertex* w = new_vertex(4);

    add_edge(root, u);
    add_edge(u, v);
    add_edge(v, w);

    // Traverse the graph
    traverse(root);

    return 0;
}