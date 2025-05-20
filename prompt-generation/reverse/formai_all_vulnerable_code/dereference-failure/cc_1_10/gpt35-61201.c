//FormAI DATASET v1.0 Category: Graph representation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node* next;
};

struct edge
{
    int start_vertex;
    int end_vertex;
};

struct Graph
{
    int vertex_count;
    struct node** adjacency_list;
};

struct Graph* create_graph(struct edge* edges, int edge_count)
{
    struct Graph* graph = malloc(sizeof(struct Graph));

    graph->vertex_count = 0;
    graph->adjacency_list = NULL;

    int i;
    for(i = 0; i < edge_count; i++)
    {
        if(edges[i].start_vertex > graph->vertex_count)
            graph->vertex_count = edges[i].start_vertex;
        if(edges[i].end_vertex > graph->vertex_count)
            graph->vertex_count = edges[i].end_vertex;
    }

    graph->vertex_count++;

    graph->adjacency_list = malloc(graph->vertex_count * sizeof(struct node*));

    for(i = 0; i < graph->vertex_count; i++)
    {
        graph->adjacency_list[i] = NULL;
    }

    int j;
    for(j = 0; j < edge_count; j++)
    {
        int start_vertex = edges[j].start_vertex;
        int end_vertex = edges[j].end_vertex;

        struct node* new_node = malloc(sizeof(struct node));
        new_node->value = end_vertex;
        new_node->next = graph->adjacency_list[start_vertex];

        graph->adjacency_list[start_vertex] = new_node;
    }

    return graph;
}

void print_graph(struct Graph* graph)
{
    int i;
    for(i = 0; i < graph->vertex_count; i++)
    {
        struct node* ptr = graph->adjacency_list[i];
        printf("\n Adjacency list of vertex %d\n head ", i);
        while(ptr != NULL)
        {
            printf("-> %d", ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    struct edge edges[] =
    {
        {0,1},
        {1,2},
        {2,0},
        {2,1},
        {3,2},
        {4,5},
        {5,4},
    };

    int edge_count = sizeof(edges)/sizeof(edges[0]);

    struct Graph *graph = create_graph(edges, edge_count);

    print_graph(graph);

    return 0;
}