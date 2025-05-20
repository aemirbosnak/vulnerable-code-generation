//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

// Function to add an edge between two nodes
void add_edge(int *graph, int n, int u, int v) {
    graph[n * 2] = u;
    graph[n * 2 + 1] = v;
    graph += n + 1;
}

// Function to print the graph
void print_graph(int *graph, int n) {
    printf("Graph:\n");
    for (int i = 0; i < n * 2; i += 2) {
        if (i % 2 == 0)
            printf("Node %d --> ", graph[i]);
        else
            printf("%d --> ", graph[i]);
    }
    printf("\n");
}

// Function to check if there is a path between two nodes
bool has_path(int *graph, int n, int u, int v) {
    if (u == v)
        return true;

    int *temp = graph;
    int *temp2 = graph;

    for (int i = 0; i < n * 2; i += 2) {
        if (temp[0] == u || temp[0] == v) {
            temp2 = temp + 2;
            if (temp2[0] == v)
                return true;
            else
                temp2 = temp;
        }
        temp += 2;
    }

    return false;
}

int main() {
    int graph[MAX_NODES * 2];
    int n = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the edges:\n");
    for (int i = 0; i < n * 2; i += 2) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(graph, n, u, v);
    }

    printf("Graph:\n");
    print_graph(graph, n);

    printf("Enter the source node: ");
    int src;
    scanf("%d", &src);

    printf("Enter the destination node: ");
    int dest;
    scanf("%d", &dest);

    if (has_path(graph, n, src, dest))
        printf("There is a path between %d and %d\n", src, dest);
    else
        printf("There is no path between %d and %d\n", src, dest);

    return 0;
}