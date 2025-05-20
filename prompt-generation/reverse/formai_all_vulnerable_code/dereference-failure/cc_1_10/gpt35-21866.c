//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLOR 4 // maximum number of colors that can be used to color the graph

/* Struct to represent the vertices of the graph */
typedef struct Vertex {
    int id;
    int color;
    struct Vertex* next;
} Vertex;

/* Function to create a new vertex */
Vertex* create_vertex(int id) {
    Vertex* new_vertex = (Vertex*) malloc(sizeof(Vertex));
    new_vertex->id = id;
    new_vertex->color = -1; // initialize vertex color to -1
    new_vertex->next = NULL;
    return new_vertex;
}

/* Function to add a new vertex to the list of vertices */
void add_vertex(Vertex** vertices, int id) {
    Vertex* new_vertex = create_vertex(id);
    new_vertex->next = *vertices;
    *vertices = new_vertex;
}

/* Function to print the list of vertices */
void print_vertices(Vertex* vertices) {
    while (vertices != NULL) {
        printf("%d ", vertices->id);
        vertices = vertices->next;
    }
    printf("\n");
}

/* Function to add an edge between two vertices */
void add_edge(Vertex** vertices, int id1, int id2) {
    Vertex* vertex1 = NULL;
    Vertex* vertex2 = NULL;

    // find the two vertices that need to be connected by an edge
    while (*vertices != NULL) {
        if ((*vertices)->id == id1) {
            vertex1 = *vertices;
        }
        if ((*vertices)->id == id2) {
            vertex2 = *vertices;
        }
        if (vertex1 != NULL && vertex2 != NULL) {
            break;
        }
        *vertices = (*vertices)->next;
    }

    // add edges to the adjacency list of both vertices
    Vertex* temp1 = vertex1->next;
    while (temp1 != NULL) {
        if (temp1->id == id2) {
            return; // edge already exists
        }
        temp1 = temp1->next;
    }
    Vertex* temp2 = vertex2->next;
    while (temp2 != NULL) {
        if (temp2->id == id1) {
            return; // edge already exists
        }
        temp2 = temp2->next;
    }
    Vertex* new_edge1 = create_vertex(id2);
    Vertex* new_edge2 = create_vertex(id1);
    new_edge1->next = vertex1->next;
    new_edge2->next = vertex2->next;
    vertex1->next = new_edge1;
    vertex2->next = new_edge2;
}

/* Function to print the adjacency list of the graph */
void print_graph(Vertex* vertices) {
    while (vertices != NULL) {
        printf("Vertex %d:", vertices->id);
        Vertex* temp = vertices->next;
        while (temp != NULL) {
            printf(" %d", temp->id);
            temp = temp->next;
        }
        printf("\n");
        vertices = vertices->next;
    }
}

/* Function to check if a vertex can be colored with a given color */
bool can_color_vertex(Vertex* vertex, int color) {
    Vertex* temp = vertex->next;
    while (temp != NULL) {
        if (temp->color == color) {
            return false; // vertex already has the given color
        }
        temp = temp->next;
    }
    return true; // vertex can be colored with the given color
}

/* Function to color the vertices of the graph */
bool color_vertices(Vertex* vertices, int num_vertices) {
    // color the first vertex with the first available color
    vertices->color = 0;
    for (int i = 1; i < num_vertices; i++) {
        bool is_colored = false;
        Vertex* temp = vertices;
        while (temp != NULL) {
            if (temp->color == -1) {
                // check if the vertex can be colored with any of the available colors
                for (int j = 0; j < MAX_COLOR; j++) {
                    if (can_color_vertex(temp, j)) {
                        temp->color = j;
                        is_colored = true;
                        break;
                    }
                }
                if (!is_colored) {
                    // no available color for the vertex
                    return false;
                }
            }
            temp = temp->next;
        }
    }
    return true;
}

int main() {
    Vertex* vertices = NULL;

    // create vertices
    add_vertex(&vertices, 1);
    add_vertex(&vertices, 2);
    add_vertex(&vertices, 3);
    add_vertex(&vertices, 4);

    // add edges
    add_edge(&vertices, 1, 2);
    add_edge(&vertices, 1, 3);
    add_edge(&vertices, 2, 3);
    add_edge(&vertices, 3, 4);

    // print vertices and adjacency list
    printf("Vertices: ");
    print_vertices(vertices);
    printf("Adjacency list:\n");
    print_graph(vertices);

    // color the vertices of the graph and print the result
    if (color_vertices(vertices, 4)) {
        printf("The vertices of the graph can be colored with %d colors.\n", MAX_COLOR);
    } else {
        printf("The vertices of the graph cannot be colored with %d colors.\n", MAX_COLOR);
    }

    return 0;
}