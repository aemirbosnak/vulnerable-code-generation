//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

struct graph {
    int V;
    struct node** adj;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct graph* graph, int from, int to) {
    struct node* newNode = createNode(to);
    newNode->next = graph->adj[from];
    graph->adj[from] = newNode;
}

void printGraph(struct graph* graph) {
    for(int i = 0; i < graph->V; i++) {
        printf("%d->", i);
        struct node* curr = graph->adj[i];
        while(curr!= NULL) {
            printf("%d->", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

int dijkstra(struct graph* graph, int source) {
    int* distance = (int*)malloc(graph->V * sizeof(int));
    int* previous = (int*)malloc(graph->V * sizeof(int));
    for(int i = 0; i < graph->V; i++) {
        distance[i] = INT_MAX;
        previous[i] = -1;
    }
    distance[source] = 0;
    for(int iteration = 0; iteration < graph->V - 1; iteration++) {
        int min_distance = INT_MAX;
        int min_node = -1;
        for(int i = 0; i < graph->V; i++) {
            if(distance[i] < min_distance && distance[i]!= INT_MAX) {
                min_distance = distance[i];
                min_node = i;
            }
        }
        for(int i = 0; i < graph->V; i++) {
            if(distance[i] == min_distance && distance[i]!= INT_MAX) {
                if(previous[i]!= -1) {
                    distance[previous[i]] = distance[i] + 1;
                    previous[i] = previous[previous[i]];
                } else {
                    distance[i] = INT_MAX;
                }
            }
        }
    }
    printf("Shortest path: ");
    struct node* curr = graph->adj[source];
    while(curr!= NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return distance[source];
}

int main() {
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->V = 6;
    graph->adj = (struct node**)malloc(graph->V * sizeof(struct node*));
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    printf("Graph:\n");
    printGraph(graph);
    printf("Shortest path from node 0: %d\n", dijkstra(graph, 0));
    return 0;
}