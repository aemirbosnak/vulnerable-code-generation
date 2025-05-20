//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_COLORS 4
#define MAX_VERTICES 5

struct Vertex {
    char name[MAX_NAME_LENGTH];
    int color;
    int degree;
    struct Vertex* neighbors[MAX_VERTICES];
};

struct Graph {
    struct Vertex* vertices[MAX_VERTICES];
    int num_vertices;
};

void add_vertex(struct Graph* graph, char* name) {
    if (graph->num_vertices == MAX_VERTICES) {
        printf("Error: graph is full\n");
        return;
    }
    
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    for (int i = 0; i < MAX_NAME_LENGTH; i++) {
        vertex->name[i] = name[i];
        if (name[i] == '\0') {
            break;
        }
    }
    vertex->color = -1;
    vertex->degree = 0;
    graph->vertices[graph->num_vertices] = vertex;
    graph->num_vertices++;
}

void add_edge(struct Graph* graph, char* vertex_name1, char* vertex_name2) {
    struct Vertex* vertex1 = NULL;
    struct Vertex* vertex2 = NULL;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (strcmp(graph->vertices[i]->name, vertex_name1) == 0) {
            vertex1 = graph->vertices[i];
        }
        if (strcmp(graph->vertices[i]->name, vertex_name2) == 0) {
            vertex2 = graph->vertices[i];
        }
    }
    if (vertex1 == NULL || vertex2 == NULL) {
        printf("Error: vertices not found\n");
        return;
    }
    
    if (vertex1->degree == MAX_VERTICES || vertex2->degree == MAX_VERTICES) {
        printf("Error: vertex degree is too high\n");
        return;
    }
    
    vertex1->neighbors[vertex1->degree] = vertex2;
    vertex1->degree++;
    vertex2->neighbors[vertex2->degree] = vertex1;
    vertex2->degree++;
}

int is_valid_color(struct Vertex* vertex, int color) {
    for (int i = 0; i < vertex->degree; i++) {
        if (vertex->neighbors[i]->color == color) {
            return 0;
        }
    }
    return 1;
}

void color_vertex(struct Vertex* vertex, int* available_colors) {
    for (int i = 0; i < MAX_COLORS; i++) {
        if (is_valid_color(vertex, available_colors[i])) {
            vertex->color = available_colors[i];
            return;
        }
    }
    printf("Error: vertex color could not be determined\n");
}

void color_graph(struct Graph* graph) {
    int available_colors[MAX_COLORS] = {0, 1, 2, 3};
    for (int i = 0; i < graph->num_vertices; i++) {
        color_vertex(graph->vertices[i], available_colors);
    }
}

void print_graph(struct Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        struct Vertex* vertex = graph->vertices[i];
        printf("Vertex: %s, Color: %d\n", vertex->name, vertex->color);
        printf("Neighbors: ");
        for (int j = 0; j < vertex->degree; j++) {
            printf("%s ", vertex->neighbors[j]->name);
        }
        printf("\n");
    }
}

int main() {
    struct Graph graph;
    graph.num_vertices = 0;
    
    // Add vertices
    add_vertex(&graph, "A");
    add_vertex(&graph, "B");
    add_vertex(&graph, "C");
    add_vertex(&graph, "D");
    add_vertex(&graph, "E");
    
    // Add edges
    add_edge(&graph, "A", "B");
    add_edge(&graph, "A", "C");
    add_edge(&graph, "B", "C");
    add_edge(&graph, "B", "D");
    add_edge(&graph, "C", "D");
    add_edge(&graph, "C", "E");
    add_edge(&graph, "D", "E");
    
    // Color graph
    color_graph(&graph);
    
    // Print results
    print_graph(&graph);
    
    return 0;
}