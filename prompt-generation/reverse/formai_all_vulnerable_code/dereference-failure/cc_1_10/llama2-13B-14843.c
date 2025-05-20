//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a vertex in the graph
typedef struct vertex {
    int x, y; // Coordinates of the vertex
    int label; // Label of the vertex
    struct vertex *next, *prev; // Next and previous vertices in the list
} vertex;

// Function to create a new vertex
vertex *new_vertex(int x, int y, int label) {
    vertex *v = malloc(sizeof(vertex));
    v->x = x;
    v->y = y;
    v->label = label;
    v->next = NULL;
    v->prev = NULL;
    return v;
}

// Function to draw the graph
void draw_graph(vertex *root) {
    if (root == NULL) {
        return;
    }

    // Zoom in and pan the graph
    if (root->x > 500) {
        root->x -= 100;
    } else if (root->x < 0) {
        root->x += 100;
    }

    if (root->y > 500) {
        root->y -= 100;
    } else if (root->y < 0) {
        root->y += 100;
    }

    // Draw the vertex
    printf("(%d, %d) - %d\n", root->x, root->y, root->label);

    // Recursively draw the children of the vertex
    draw_graph(root->next);
    draw_graph(root->prev);
}

int main() {
    // Create the root vertex
    vertex *root = new_vertex(200, 200, 1);

    // Create some child vertices
    vertex *child1 = new_vertex(300, 300, 2);
    vertex *child2 = new_vertex(400, 400, 3);
    vertex *child3 = new_vertex(500, 500, 4);

    // Add the child vertices to the root
    root->next = child1;
    root->prev = child2;
    child1->next = child2;
    child1->prev = root;
    child2->next = child3;
    child2->prev = child1;
    child3->next = NULL;
    child3->prev = child2;

    // Draw the graph
    draw_graph(root);

    return 0;
}