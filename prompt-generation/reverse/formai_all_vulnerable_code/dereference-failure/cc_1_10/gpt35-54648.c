//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
    int vertex;
    struct edge *next;
}Edge;

typedef struct adj_list{
    Edge *head;
}Adj_list;

typedef struct graph_struct{
    int vertices;
    Adj_list* adj_list;
}Graph;

Graph *create_graph(int v){
    Graph *new_graph = (Graph*)malloc(sizeof(Graph));
    new_graph->vertices = v;

    new_graph->adj_list = (Adj_list*)malloc(sizeof(Adj_list)*v);

    int i;
    for(i=0;i<v;i++){
        new_graph->adj_list[i].head = NULL;
    }
    return new_graph;
}

Edge *new_edge(int v){
    Edge *new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->vertex = v;
    new_edge->next = NULL;
    return new_edge;
}

void add_edge(Graph *graph, int s, int d){
    Edge *new_Edge = new_edge(d);
    new_Edge->next = graph->adj_list[s].head;
    graph->adj_list[s].head = new_Edge;

    new_Edge = new_edge(s);
    new_Edge->next = graph->adj_list[d].head;
    graph->adj_list[d].head = new_Edge;
}

void print_graph(Graph *graph){
    int i;
    for(i=0;i<graph->vertices;i++){
        Edge *temp = graph->adj_list[i].head;
        printf("\nAdjacency list of vertex %d \n head", i);
        while(temp){
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    Graph *graph = create_graph(5);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    print_graph(graph);

    return 0;

}