//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A struct to represent a vertex in the graph
struct Vertex {
    char name[20];
    int color;
    int num_neighbors;
    struct Vertex** neighbors;
};

// Function to create a new vertex
struct Vertex* create_vertex(char name[]) {
    struct Vertex* v = (struct Vertex*) malloc(sizeof(struct Vertex));
    strcpy(v->name, name);
    v->color = -1;
    v->num_neighbors = 0;
    v->neighbors = NULL;
    return v;
}

// Function to add a neighbor to a vertex
void add_neighbor(struct Vertex* v, struct Vertex* neighbor) {
    v->num_neighbors++;
    v->neighbors = (struct Vertex**) realloc(v->neighbors, v->num_neighbors * sizeof(struct Vertex*));
    v->neighbors[v->num_neighbors-1] = neighbor;
}

// Function to check if a given color can be assigned to a given vertex
bool is_color_valid(struct Vertex* v, int color) {
    for (int i = 0; i < v->num_neighbors; i++) {
        if (v->neighbors[i]->color == color) {
            return false;
        }
    }
    return true;
}

// Function to assign colors to all vertices in the graph
void color_graph(struct Vertex** vertices, int num_vertices, int num_colors) {
    for (int i = 0; i < num_vertices; i++) {
        for (int color = 0; color < num_colors; color++) {
            if (is_color_valid(vertices[i], color)) {
                vertices[i]->color = color;
                break;
            }
        }
    }
}

int main() {
    // Create the vertices of the graph
    struct Vertex* a = create_vertex("Mr. Holmes");
    struct Vertex* b = create_vertex("Dr. Watson");
    struct Vertex* c = create_vertex("Inspector Lestrade");
    struct Vertex* d = create_vertex("Professor Moriarty");

    // Add edges to the graph
    add_neighbor(a, b);
    add_neighbor(b, c);
    add_neighbor(c, d);
    add_neighbor(d, a);

    // Color the graph using 3 colors
    color_graph((struct Vertex*[]){a, b, c, d}, 4, 3);

    // Print the colors of the vertices
    printf("Mr. Holmes is assigned color %d\n", a->color);
    printf("Dr. Watson is assigned color %d\n", b->color);
    printf("Inspector Lestrade is assigned color %d\n", c->color);
    printf("Professor Moriarty is assigned color %d\n", d->color);

    return 0;
}