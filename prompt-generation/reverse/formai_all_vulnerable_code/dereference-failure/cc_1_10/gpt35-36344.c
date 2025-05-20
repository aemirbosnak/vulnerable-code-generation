//FormAI DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct node {
    int vertex;
    struct node* next;
};

struct Graph {
    int num_vertices;
    struct node** adj_lists;
};

/* Function to create a new node in adjacency list */
struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/* Function to create a graph */
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertices = vertices;
    graph->adj_lists = (struct node**)calloc(vertices, sizeof(struct node*));
    return graph;
}

/* Function to add edge */
void add_edge(struct Graph* graph, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = graph->adj_lists[src];
    graph->adj_lists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = newNode;
}

/* Function to print the graph */
void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->num_vertices; v++) {
        struct node* temp = graph->adj_lists[v];
        printf("\nVertex %d: ", v+1);
        while (temp) {
            printf("%d -> ", temp->vertex+1);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

/* Main Function */
int main() {
    struct Graph* graph = createGraph(MAX);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    printf("\nGraph Representation:\n");
    printGraph(graph);

    return 0;
}