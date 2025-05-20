//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_VERTICES 100
#define EDGE_FILE "edges.txt"
#define VERTEX_FILE "vertices.txt"

typedef struct Vertex {
    char name[20];
    int id;
    int* adjacencies;
    int num_adj;
} Vertex;

void read_vertices_file(FILE* fp, Vertex** vertices) {
    int num_vertices;
    fscanf(fp, "%d", &num_vertices);
    *vertices = malloc(num_vertices * sizeof(Vertex));
    for (int i = 0; i < num_vertices; i++) {
        fscanf(fp, "%s%d", (*vertices)[i].name, &(*vertices)[i].id);
        (*vertices)[i].adjacencies = calloc(num_vertices, sizeof(int));
        (*vertices)[i].num_adj = 0;
    }
}

void read_edges_file(FILE* fp, Vertex* vertices) {
    int num_edges;
    fscanf(fp, "%d", &num_edges);
    for (int i = 0; i < num_edges; i++) {
        int src, dest, wt;
        fscanf(fp, "%d%d%d", &src, &dest, &wt);
        vertices[src].adjacencies[vertices[dest].id] = wt;
        vertices[src].num_adj++;
    }
}

void print_adjacency_list(Vertex* vertices) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%s: ", vertices[i].name);
        for (int j = 0; j < vertices[i].num_adj; j++) {
            printf("%s(%d) ", vertices[j].name, vertices[i].adjacencies[j]);
        }
        printf("\n");
    }
}

int main() {
    Vertex* vertices;
    FILE* vertex_file = fopen(VERTEX_FILE, "r");
    if (vertex_file == NULL) {
        perror("Error opening vertex file");
        return 1;
    }
    read_vertices_file(vertex_file, &vertices);
    FILE* edge_file = fopen(EDGE_FILE, "r");
    if (edge_file == NULL) {
        perror("Error opening edge file");
        free(vertices);
        return 1;
    }
    read_edges_file(edge_file, vertices);
    fclose(vertex_file);
    fclose(edge_file);
    print_adjacency_list(vertices);
    for (int i = 0; i < MAX_VERTICES; i++) {
        free(vertices[i].adjacencies);
    }
    free(vertices);
    return 0;
}