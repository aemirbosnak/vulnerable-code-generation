//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
    int V;
    int** adj_matrix;
}Graph;

/**
 * Create a new graph with v vertices
 * @param  v The number of vertices in the graph
 * @return   The new graph
 */
Graph* create_graph(int v){
    Graph* graph = malloc(sizeof(Graph));
    graph->V = v;
    graph->adj_matrix = malloc(v * sizeof(int*));
    for(int i = 0; i < v; i++){
        graph->adj_matrix[i] = calloc(v, sizeof(int));
    }
    return graph;
}

/**
 * Add an edge to the graph
 * @param graph The graph to add the edge to
 * @param from  The vertex where the edge starts
 * @param to    The vertex where the edge ends
 * @param w     The weight of the edge
 */
void add_edge(Graph* graph, int from, int to, int w){
    graph->adj_matrix[from][to] = w;
}

/**
 * Print the graph
 * @param graph The graph to print
 */
void print_graph(Graph* graph){
    for(int i = 0; i < graph->V; i++){
        printf("%d: ", i);
        for(int j = 0; j < graph->V; j++){
            if(graph->adj_matrix[i][j]){
                printf("(%d, %d) - %d, ", i, j, graph->adj_matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1, 2);
    add_edge(graph, 0, 3, 5);
    add_edge(graph, 1, 0, 2);
    add_edge(graph, 1, 2, 3);
    add_edge(graph, 1, 3, 9);
    add_edge(graph, 2, 1, 3);
    add_edge(graph, 2, 4, 7);
    add_edge(graph, 3, 0, 5);
    add_edge(graph, 3, 1, 9);
    add_edge(graph, 3, 4, 1);
    add_edge(graph, 4, 2, 7);
    add_edge(graph, 4, 3, 1);
    print_graph(graph);
    return 0;
}