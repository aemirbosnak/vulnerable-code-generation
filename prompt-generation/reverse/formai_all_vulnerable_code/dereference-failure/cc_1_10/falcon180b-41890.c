//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF INT_MAX

//Structure to represent an edge
struct Edge {
    int src;
    int dest;
    int weight;
};

//Structure to represent a graph
struct Graph {
    int n;
    int e;
    struct Edge *edges;
};

//Function to create a new edge
struct Edge *newEdge(int src, int dest, int weight) {
    struct Edge *e = (struct Edge *)malloc(sizeof(struct Edge));
    e->src = src;
    e->dest = dest;
    e->weight = weight;
    return e;
}

//Function to create a new graph
struct Graph *newGraph(int n, int e) {
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->n = n;
    g->e = e;
    g->edges = (struct Edge *)malloc(sizeof(struct Edge) * e);
    return g;
}

//Function to add an edge to the graph
void addEdge(struct Graph *g, int src, int dest, int weight) {
    g->edges[g->e].src = src;
    g->edges[g->e].dest = dest;
    g->edges[g->e].weight = weight;
    g->e++;
}

//Function to find the shortest path using Dijkstra's algorithm
void dijkstra(struct Graph *g, int start) {
    int i, j, u, v;
    int dist[MAX_NODES], prev[MAX_NODES];

    //Initialize the distance array and the previous node array
    for (i = 0; i < g->n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    //Set the distance of the starting node to 0
    dist[start] = 0;

    //Relax all the edges in the graph
    for (i = 0; i < g->e; i++) {
        u = g->edges[i].src;
        v = g->edges[i].dest;
        if (dist[u]!= INF && dist[u] + g->edges[i].weight < dist[v]) {
            dist[v] = dist[u] + g->edges[i].weight;
            prev[v] = u;
        }
    }

    //Print the shortest path
    printf("Shortest path: ");
    for (i = 0; i < g->n; i++) {
        if (i == start)
            continue;
        if (dist[i] == INF)
            printf("- ");
        else
            printf("%d ", i);
    }
    printf("\n");
}

//Main function
int main() {
    int n, e, i, j, u, v, start;
    struct Graph *g;

    //Get the number of nodes and edges from the user
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    //Create a new graph
    g = newGraph(n, e);

    //Get the edges from the user
    printf("Enter the edges (src dest weight):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &g->edges[i].weight);
        addEdge(g, u, v, g->edges[i].weight);
    }

    //Get the starting node from the user
    printf("Enter the starting node: ");
    scanf("%d", &start);

    //Run Dijkstra's algorithm
    dijkstra(g, start);

    return 0;
}