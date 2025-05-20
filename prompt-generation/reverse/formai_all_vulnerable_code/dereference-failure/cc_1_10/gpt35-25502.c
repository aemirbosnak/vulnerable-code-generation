//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

struct Graph {
    int vertices;
    int **adj_matrix;
};

struct Graph* create_graph(int vertices)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adj_matrix = (int**) malloc(vertices * sizeof(int*));
    int i,j;
    for(i=0;i<vertices;i++)
    {
        graph->adj_matrix[i] = (int*) malloc(sizeof(int) * vertices);
        for(j=0;j<vertices;j++)
        {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(struct Graph* graph, int x, int y)
{
    graph->adj_matrix[x][y] = 1;
    graph->adj_matrix[y][x] = 1;
}

void print_graph(struct Graph* graph)
{
    int i,j;
    for(i=0;i<graph->vertices;i++)
    {
        for(j=0;j<graph->vertices;j++)
        {
            printf("%d ",graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    struct Graph* graph = create_graph(5);
    add_edge(graph,0,1);
    add_edge(graph,1,2);
    add_edge(graph,2,3);
    add_edge(graph,3,4);
    add_edge(graph,4,0);
    print_graph(graph);
    return 0;
}