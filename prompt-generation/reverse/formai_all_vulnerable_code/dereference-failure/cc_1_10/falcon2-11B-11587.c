//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

typedef struct vertex_t {
    int color;
    struct vertex_t *next;
} vertex_t;

vertex_t *head = NULL;
int num_vertices = 0;
int max_colors = 0;

void add_vertex(int color) {
    vertex_t *new_vertex = (vertex_t*)malloc(sizeof(vertex_t));
    new_vertex->color = color;
    new_vertex->next = NULL;
    
    if (head == NULL) {
        head = new_vertex;
    } else {
        vertex_t *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_vertex;
    }
    num_vertices++;
}

int get_num_colors() {
    return num_vertices + 1;
}

void color_graph(int num_colors) {
    max_colors = num_colors;
    vertex_t *current = head;
    while (current!= NULL) {
        current->color = 1;
        current = current->next;
    }
}

int is_valid_color(int color, vertex_t *current) {
    while (current!= NULL) {
        if (current->color == color) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

int main() {
    int num_vertices, num_colors;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);
    
    for (int i = 0; i < num_vertices; i++) {
        add_vertex(i + 1);
    }
    
    color_graph(num_colors);
    
    printf("Graph is colored with %d colors.\n", max_colors);
    
    return 0;
}