//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Struct for a vertex in the graph
typedef struct {
    int id;
    int color;
    int num_adj;
    int* adj_list;
} vertex;

// Function to initialize a vertex
vertex* init_vertex(int id, int num_adj) {
    vertex* v = (vertex*) malloc(sizeof(vertex));
    v -> id = id;
    v -> color = -1; // initialize color to -1
    v -> num_adj = num_adj;
    v -> adj_list = (int*) malloc(sizeof(int) * num_adj);
    return v;
}

// Function to print the graph
void print_graph(int num_vertices, vertex** graph) {
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d (Color %d) is connected to: ", graph[i]->id, graph[i]->color);
        for (int j = 0; j < graph[i]->num_adj; j++) {
            printf("%d ", graph[i]->adj_list[j]);
        }
        printf("\n");
    }
}

// Function to color the graph
void color_graph(int num_vertices, vertex** graph, int num_colors) {
    // Initialize the first vertex with color 0
    graph[0] -> color = 0;
    
    // Loop through all the vertices
    for (int i = 1; i < num_vertices; i++) {
        // Array to keep track of the available colors
        int available_colors[num_colors];
        for (int j = 0; j < num_colors; j++) {
            available_colors[j] = 1; // initialize all colors to be available
        }
        
        // Loop through the adjacent vertices
        for (int j = 0; j < graph[i]->num_adj; j++) {
            int adj_vertex_color = graph[graph[i]->adj_list[j]]->color;
            if (adj_vertex_color != -1) {
                available_colors[adj_vertex_color] = 0; // mark the adjacent vertex's color as unavailable
            }
        }
        
        // Set the vertex's color to the first available color
        for (int j = 0; j < num_colors; j++) {
            if (available_colors[j] == 1) {
                graph[i] -> color = j;
                break;
            }
        }
    }
}

int main() {
    // Initialize a graph with 7 vertices
    vertex* graph[7];
    graph[0] = init_vertex(0, 3);
    graph[0] -> adj_list[0] = 1;
    graph[0] -> adj_list[1] = 2;
    graph[0] -> adj_list[2] = 3;
    graph[1] = init_vertex(1, 3);
    graph[1] -> adj_list[0] = 0;
    graph[1] -> adj_list[1] = 2;
    graph[1] -> adj_list[2] = 5;
    graph[2] = init_vertex(2, 3);
    graph[2] -> adj_list[0] = 0;
    graph[2] -> adj_list[1] = 1;
    graph[2] -> adj_list[2] = 4;
    graph[3] = init_vertex(3, 2);
    graph[3] -> adj_list[0] = 0;
    graph[3] -> adj_list[1] = 4;
    graph[4] = init_vertex(4, 3);
    graph[4] -> adj_list[0] = 2;
    graph[4] -> adj_list[1] = 3;
    graph[4] -> adj_list[2] = 5;
    graph[5] = init_vertex(5, 3);
    graph[5] -> adj_list[0] = 1;
    graph[5] -> adj_list[1] = 4;
    graph[5] -> adj_list[2] = 6;
    graph[6] = init_vertex(6, 2);
    graph[6] -> adj_list[0] = 5;
    graph[6] -> adj_list[1] = 7;

    // Color the graph with 3 colors
    color_graph(7, graph, 3);

    // Print the graph after coloring
    print_graph(7, graph);

    return 0;
}