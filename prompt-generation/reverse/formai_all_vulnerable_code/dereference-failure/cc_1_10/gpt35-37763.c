//FormAI DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to create and return adjacency list
int** create_adj_list(int num_vertices) {
    int** adj_list = (int**)malloc(num_vertices * sizeof(int*));
    for(int i = 0; i < num_vertices; i++) {
        adj_list[i] = (int*)malloc(num_vertices * sizeof(int));
        for(int j = 0; j < num_vertices; j++) {
            adj_list[i][j] = 0;
        }
    }
    return adj_list;
}

// Function to add edge to the graph
void add_edge(int** adj_list, int vertex1, int vertex2) {
    adj_list[vertex1][vertex2] = 1;
    adj_list[vertex2][vertex1] = 1;
}

// Function to display the adjacency matrix
void display_matrix(int** adj_list, int num_vertices) {
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < num_vertices; i++) {
        for(int j = 0; j < num_vertices; j++) {
            printf("%d ", adj_list[i][j]);
        }
        printf("\n");
    }
}

int main() {

    // Invasive style to create a graph
    printf("I am creating a graph with 5 vertices...\n\n");
    int num_vertices = 5;
    int** adj_list = create_adj_list(num_vertices);

    printf("I am adding edges to the vertices...\n");
    add_edge(adj_list, 0, 1);
    add_edge(adj_list, 0, 2);
    add_edge(adj_list, 1, 2);
    add_edge(adj_list, 1, 3);
    add_edge(adj_list, 3, 4);

    printf("I am displaying the adjacency matrix of the graph...\n");
    display_matrix(adj_list, num_vertices);

    printf("\nI have successfully created a graph and displayed its adjacency matrix!\n");

    return 0;
}