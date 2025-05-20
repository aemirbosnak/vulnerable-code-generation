//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char name[20];
    int degree;
    int *adj_list;
} Node;

typedef struct {
    int src;
    int dest;
} Edge;

void add_edge(Node *graph, int src, int dest) {
    graph[src].degree++;
    graph[dest].degree++;
    graph[src].adj_list = (int *)realloc(graph[src].adj_list, sizeof(int) * graph[src].degree);
    graph[src].adj_list[graph[src].degree - 1] = dest;
}

void print_graph(Node *graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("Node %d: %s, Degree: %d\n", graph[i].id, graph[i].name, graph[i].degree);
        printf("Adjacent Nodes: ");
        for (int j = 0; j < graph[i].degree; j++) {
            printf("%d ", graph[i].adj_list[j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    Node *graph = (Node *)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++) {
        printf("Enter the name of node %d: ", i+1);
        scanf("%s", graph[i].name);
        graph[i].id = i+1;
        graph[i].degree = 0;
        graph[i].adj_list = (int *)malloc(sizeof(int));
        graph[i].adj_list[0] = -1;
    }

    for (int i = 0; i < m; i++) {
        printf("Enter the source node id: ");
        int src;
        scanf("%d", &src);
        printf("Enter the destination node id: ");
        int dest;
        scanf("%d", &dest);
        add_edge(graph, src, dest);
    }

    print_graph(graph, n);

    return 0;
}