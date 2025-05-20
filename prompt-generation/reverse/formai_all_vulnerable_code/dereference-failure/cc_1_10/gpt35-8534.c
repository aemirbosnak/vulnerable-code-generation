//FormAI DATASET v1.0 Category: Graph representation ; Style: lively
#include<stdio.h>
#include<stdlib.h>

/* This program creates a graph and calculates the shortest path using Dijkstra's Algorithm */

typedef struct Edge { //Structure to represent edges in a graph
    int source, destination, weight;
} Edge;

typedef struct Graph { //Structure to represent a graph
    int V, E; //V is the number of vertices and E is the number of edges
    Edge* edge; //List of edges
} Graph;

Graph* createGraph(int V, int E) { //Function to create a graph
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*) malloc(E * sizeof(Edge));
    return graph;
}

void printDistance(int* distance, int V) { //Function to print the distance of each vertex from the source vertex
    printf("Vertex\tDistance from source\n");
    for(int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, distance[i]);
}

void dijkstra(Graph* graph, int source) { //Function to perform Dijkstra's Algorithm to find the shortest path
    int V = graph->V;
    int distance[V]; //Array to store the distance of each vertex from the source vertex
    int visited[V]; //Array to keep track of visited vertices

    for(int i = 0; i < V; i++) { //Initialize all distances to infinity and visited array to false
        distance[i] = __INT_MAX__;
        visited[i] = 0;
    }

    distance[source] = 0; //Distance of source vertex from itself is always 0

    for(int i = 0; i < V - 1; i++) { //Visit all vertices
        int u = -1;
        for(int j = 0; j < V; j++) { //Find the vertex with the minimum distance
            if(!visited[j] && (u == -1 || distance[j] < distance[u]))
                u = j;
        }

        visited[u] = 1; //Mark as visited

        for(int j = 0; j < graph->E; j++) { //Update the distance of adjacent vertices
            Edge* edge = &graph->edge[j];
            if(edge->source == u) {
                int v = edge->destination;
                int dist = distance[u] + edge->weight;
                if(dist < distance[v])
                    distance[v] = dist;
            }
        }
    }

    printDistance(distance, V); //Print the distance of each vertex from the source vertex
}

int main() {
    int V = 5;
    int E = 7;
    Graph* graph = createGraph(V, E);

    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = 4;

    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 5;

    graph->edge[2].source = 1;
    graph->edge[2].destination = 2;
    graph->edge[2].weight = 2;

    graph->edge[3].source = 1;
    graph->edge[3].destination = 3;
    graph->edge[3].weight = 6;

    graph->edge[4].source = 2;
    graph->edge[4].destination = 3;
    graph->edge[4].weight = 2;

    graph->edge[5].source = 2;
    graph->edge[5].destination = 4;
    graph->edge[5].weight = 4;

    graph->edge[6].source = 3;
    graph->edge[6].destination = 4;
    graph->edge[6].weight = 7;

    dijkstra(graph, 0); //Find the shortest path

    free(graph->edge);
    free(graph);
    return 0;
}