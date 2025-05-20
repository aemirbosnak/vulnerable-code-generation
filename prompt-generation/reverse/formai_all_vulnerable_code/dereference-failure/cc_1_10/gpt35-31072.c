//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100000

int color[MAX_VERTICES];

typedef struct node {
    int vertex;
    struct node *next;
} node;

node *adj_list[MAX_VERTICES];

node *create_node(int v) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

void add_edge(int a, int b) {
    node *new_node = create_node(b);
    new_node->next = adj_list[a];
    adj_list[a] = new_node;

    new_node = create_node(a);
    new_node->next = adj_list[b];
    adj_list[b] = new_node;
}

void color_vertices(int v, int num_colors) {
    // Initialize all vertices to have no color
    for (int i = 0; i < v; i++) {
        color[i] = -1;
    }

    // Start coloring vertices one by one
    for (int i = 0; i < v; i++) {
        // Check adjacent vertices and assign a color that is not used by any adjacent vertices
        int used_colors[num_colors];
        for (int j = 0; j < num_colors; j++) {
            used_colors[j] = 0;
        }
        node *adj_vertex = adj_list[i];
        while (adj_vertex != NULL) {
            if (color[adj_vertex->vertex] != -1) {
                used_colors[color[adj_vertex->vertex]] = 1;
            }
            adj_vertex = adj_vertex->next;
        }

        // Assign an available color to the vertex
        for (int j = 0; j < num_colors; j++) {
            if (used_colors[j] == 0) {
                color[i] = j;
                break;
            }
        }
    }
}

int main() {
    int v, e, a, b;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &v);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &e);

    printf("Enter the edges in the graph: \n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        add_edge(a, b);
    }

    int num_colors = 0;
    while (num_colors <= 0 || num_colors > v) {
        printf("Enter the number of colors to color the graph with (1 to %d): ", v);
        scanf("%d", &num_colors);
    }

    color_vertices(v, num_colors);

    printf("The vertices can be colored using %d colors as follows: \n", num_colors);
    for (int i = 0; i < v; i++) {
        printf("Vertex %d --> Color %d\n", i, color[i]);
    }

    return 0;
}