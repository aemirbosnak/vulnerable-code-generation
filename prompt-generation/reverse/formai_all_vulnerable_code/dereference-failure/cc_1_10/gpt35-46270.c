//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Graph representation using adjacency list
struct Node {
    int id;
    int weight;
    struct Node* next;
};
struct Graph {
    int V;  // number of vertices
    struct Node** adjList; // array of adjacency lists
};
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    for(int i=0; i<V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}
void addEdge(struct Graph* graph, int v1, int v2, int weight) {
    // add edge from vertex v1 to vertex v2 with given weight
    struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
    newNode1->id = v2;
    newNode1->weight = weight;
    newNode1->next = graph->adjList[v1];
    graph->adjList[v1] = newNode1;

    // add edge from vertex v2 to vertex v1 with given weight
    struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
    newNode2->id = v1;
    newNode2->weight = weight;
    newNode2->next = graph->adjList[v2];
    graph->adjList[v2] = newNode2;
}

// Implementation of Dijkstra's Algorithm for finding shortest path
void dijkstra(struct Graph* graph, int src, int dest) {
    int visited[graph->V];  // array to keep track of visited vertices
    int distance[graph->V]; // array to store the distance of vertices from source vertex

    // initialize visited and distance arrays
    for(int i=0; i<graph->V; i++) {
        visited[i] = 0;
        distance[i] = INT_MAX;
    }
    distance[src] = 0; // distance of source vertex from itself is 0

    for(int i=0; i<graph->V-1; i++) {
        // find the vertex with minimum distance from source vertex
        int minDist = INT_MAX, minIndex = -1;
        for(int j=0; j<graph->V; j++) {
            if(!visited[j] && distance[j]<minDist) {
                minDist = distance[j];
                minIndex = j;
            }
        }

        if(minIndex == -1) {
            printf("No path found between %d and %d.", src, dest);
            return;
        }
        visited[minIndex] = 1; // mark the vertex as visited

        // update the distance of adjacent vertices of minIndex(vertex with minimum distance from src)
        struct Node* temp = graph->adjList[minIndex];
        while(temp != NULL) {
            if(!visited[temp->id] && distance[minIndex] != INT_MAX && 
                    distance[temp->id] > distance[minIndex] + temp->weight) {
                distance[temp->id] = distance[minIndex] + temp->weight;
            }
            temp = temp->next;
        }
    }
    // Print the shortest distance between src and dest
    printf("Shortest distance between %d and %d is %d", src, dest, distance[dest]);
}

int main() {
    // create example graph with 5 vertices and 7 edges
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1, 9);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 2, 4, 2);
    addEdge(graph, 3, 4, 10);
    addEdge(graph, 2, 3, 4);

    // find the shortest path between vertex 0 and vertex 4
    dijkstra(graph, 0, 4);

    return 0;
}