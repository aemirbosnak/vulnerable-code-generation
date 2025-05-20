//FormAI DATASET v1.0 Category: Graph representation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node {
    int dest;
    int weight;
    struct node* next;
};

struct Graph {
    struct node* head[MAX];
};

struct node* createNode(int dest, int weight) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct node* newNode = createNode(dest, weight);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
}

void printGraph(struct Graph* graph) {
    printf("Graph Representation using Adjacency List:\n");
    for(int i=0; i<MAX; i++) {
        struct node* temp = graph->head[i];
        if(temp != NULL) {
            printf("Vertex %d:\n", i);
            while(temp != NULL) {
                printf(" -> %d (weight: %d)", temp->dest, temp->weight);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for(int i=0; i<MAX; i++)
        graph->head[i] = NULL;

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 20);
    addEdge(graph, 1, 2, 30);
    addEdge(graph, 1, 3, 40);
    addEdge(graph, 1, 4, 50);
    addEdge(graph, 2, 3, 60);
    addEdge(graph, 3, 4, 70);

    printGraph(graph);
    return 0;
}