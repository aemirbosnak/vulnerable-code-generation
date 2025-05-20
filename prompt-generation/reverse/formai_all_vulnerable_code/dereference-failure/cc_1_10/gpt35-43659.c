//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

typedef struct Edge {
    int dest;
    struct Edge* next;
}Edge;

typedef struct Graph {
    int V;
    Edge** adj_list;
}Graph;

Graph* create_graph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj_list = (Edge**)calloc(V, sizeof(Edge*));
    return graph;
}

void add_edge(Graph* graph, int src, int dest) {
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->dest = dest;
    new_edge->next = graph->adj_list[src];
    graph->adj_list[src] = new_edge;

    new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->dest = src;
    new_edge->next = graph->adj_list[dest];
    graph->adj_list[dest] = new_edge;
}

void print_graph(Graph* graph) {
    int v;
    for(v=0; v<graph->V; v++) {
        Edge* current = graph->adj_list[v];
        printf("\nAdjacency list of vertex %d\n", v);
        while(current) {
            printf("%d ", current->dest);
            current = current->next;
        }
    }
}

int main() {
    int V = 6;
    Graph* graph = create_graph(V);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    print_graph(graph);
    return 0;
}