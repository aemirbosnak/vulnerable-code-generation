//FormAI DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct graph
{
    int vertex, weight;
    struct graph* next;
};

struct graph* create_node(int v, int w)
{
    struct graph* node = (struct graph*)malloc(sizeof(struct graph));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

void add_edge(struct graph** graph, int u, int v, int w)
{
    struct graph* node = create_node(v, w);
    node->next = graph[u];
    graph[u] = node;
}

void print_graph(struct graph** graph, int vertices)
{
    for(int i=0;i<vertices;i++)
    {
        printf("Node %d connected to:\n",i);
        struct graph* vertex = graph[i];
        while(vertex!=NULL)
        {
            printf("(%d, %d) ",vertex->vertex,vertex->weight);
            vertex=vertex->next;
            printf("\n");
        }
    }
}

int main()
{
    int vertices = 4;
    struct graph *graph[vertices];
    for(int i=0;i<vertices;i++)
    {
        graph[i]=NULL;
    }
    add_edge(graph, 0, 1, 2);
    add_edge(graph, 0, 2, 4);
    add_edge(graph, 1, 2, 1);
    add_edge(graph, 2, 3, 3);
    add_edge(graph, 3, 3, 5);
    print_graph(graph, vertices);
    return 0;
}