//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 20 
#define INF 999999

typedef struct {
    char name[50];
    char type[30];
} Node;

typedef struct {
    int edge[MAX_NODES][MAX_NODES];
    Node nodes[MAX_NODES];
    int nodeCount;
} Graph;

Graph *createGraph() {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->nodeCount = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            g->edge[i][j] = INF; // Initializing edges to "infinity"
        }
    }
    
    return g;
}

void addNode(Graph *g, const char *name, const char *type) {
    if (g->nodeCount < MAX_NODES) {
        strcpy(g->nodes[g->nodeCount].name, name);
        strcpy(g->nodes[g->nodeCount].type, type);
        g->nodeCount++;
    } else {
        printf("Max nodes limit reached.\n");
    }
}

void addEdge(Graph *g, int from, int to, int weight) {
    if (from < g->nodeCount && to < g->nodeCount) {
        g->edge[from][to] = weight;
        g->edge[to][from] = weight; // For undirected graph
    } else {
        printf("Invalid node indices.\n");
    }
}

void displayGraph(Graph *g) {
    printf("Cyberpunk Network Graph:\n");
    for (int i = 0; i < g->nodeCount; i++) {
        printf("%s (%s): ", g->nodes[i].name, g->nodes[i].type);
        for (int j = 0; j < g->nodeCount; j++) {
            if (g->edge[i][j] != INF) {
                printf("[to %s: %d] ", g->nodes[j].name, g->edge[i][j]);
            }
        }
        printf("\n");
    }
}

void dijkstra(Graph *g, int startIndex) {
    int distance[MAX_NODES];
    int visited[MAX_NODES] = {0};
    
    for (int i = 0; i < g->nodeCount; i++) {
        distance[i] = INF;
    }
    distance[startIndex] = 0;

    for (int count = 0; count < g->nodeCount - 1; count++) {
        int minIndex = -1, minDist = INF;

        for (int v = 0; v < g->nodeCount; v++) {
            if (!visited[v] && distance[v] <= minDist) {
                minDist = distance[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        for (int v = 0; v < g->nodeCount; v++) {
            if (!visited[v] && g->edge[minIndex][v] != INF &&
                distance[minIndex] + g->edge[minIndex][v] < distance[v]) {
                distance[v] = distance[minIndex] + g->edge[minIndex][v];
            }
        }
    }
    
    printf("\nDijkstra's Algorithm Results from %s:\n", g->nodes[startIndex].name);
    for (int i = 0; i < g->nodeCount; i++) {
        printf("Distance to %s: %d\n", g->nodes[i].name, distance[i]);
    }
}

int main() {
    Graph *g = createGraph();
    
    addNode(g, "The Neon Bazaar", "Market");
    addNode(g, "Elysium Data Vault", "Facility");
    addNode(g, "Cybernetic Clinic", "Medical");
    addNode(g, "Black Market Nexus", "Underground");
    addNode(g, "Hyperloop Station", "Transport");
    
    addEdge(g, 0, 1, 10);  
    addEdge(g, 0, 3, 5);   
    addEdge(g, 1, 2, 15);  
    addEdge(g, 1, 4, 20);  
    addEdge(g, 2, 4, 30);  
    addEdge(g, 3, 4, 10);  
    addEdge(g, 0, 2, 50);  

    displayGraph(g);
    
    dijkstra(g, 0); // Starting from "The Neon Bazaar"

    // Clean up the graph memory
    free(g);
    
    return 0;
}