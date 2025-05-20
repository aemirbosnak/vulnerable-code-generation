//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100

int num_nodes = 0;

typedef struct adjacency_matrix {
    int matrix[MAX_NODES][MAX_NODES];
} adj_matrix;

// Function to initialize adjacency matrix
void init(adj_matrix* graph) {
    for(int i = 0; i < MAX_NODES; i++) {
        for(int j = 0; j < MAX_NODES; j++) {
            graph->matrix[i][j] = 0;
        }
    }
}

// Function to add a new edge to the graph
void add_edge(adj_matrix* graph, int u, int v) {
    graph->matrix[u][v] = 1;
    graph->matrix[v][u] = 1;
}

// Function to print the adjacency matrix
void print_matrix(adj_matrix* graph) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to read input file and populate adjacency matrix
void read_file(adj_matrix* graph, char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file");
        exit(1);
    }
    int u, v;
    while(fscanf(fp, "%d %d", &u, &v) != EOF) {
        add_edge(graph, u, v);
    }
    fclose(fp);
}

// Function to do a depth-first search of the graph
void dfs(adj_matrix* graph, int cur_node, bool* visited) {
    visited[cur_node] = true;
    printf("%d ", cur_node);
    for (int i = 0; i < num_nodes; i++) {
        if (graph->matrix[cur_node][i] && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

// Function to find the shortest path between two nodes using Breadth-First-Search
int bfs(adj_matrix* graph, int start_node, int end_node) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    bool visited[MAX_NODES] = {false};
    int dist[MAX_NODES] = {0};
    visited[start_node] = true;
    queue[rear++] = start_node;
    while (front != rear) {
        int cur_node = queue[front++];
        for (int i = 0; i < num_nodes; i++) {
            if (graph->matrix[cur_node][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
                dist[i] = dist[cur_node] + 1;
                if (i == end_node) {
                    return dist[i];
                }
            }
        }
    }
    return -1;
}

// Main function
int main(int argc, char** argv) {
    adj_matrix graph;
    if(argc != 3) {
        printf("Usage: ./mapper <input_file> <num_nodes>\n");
        exit(1);
    }
    char* filename = argv[1];
    num_nodes = atoi(argv[2]);
    init(&graph);
    read_file(&graph, filename);
    printf("Adjacency Matrix:\n");
    print_matrix(&graph);
    printf("\nDFS Traversal:\n");
    bool visited[MAX_NODES] = {false};
    for (int i = 0; i < num_nodes; i++) {
        if(!visited[i]) {
            dfs(&graph, i, visited);
        }
    }
    printf("\n\nShortest Path between nodes 0 and 4: %d\n", bfs(&graph, 0, 4));
    return 0;
}