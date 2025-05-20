//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct graph
{
    int num_nodes;
    node *nodes[MAX_NODES];
} graph;

graph *create_graph()
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_nodes = 0;
    for (int i = 0; i < MAX_NODES; i++)
    {
        g->nodes[i] = NULL;
    }
    return g;
}

void add_node(graph *g, int value)
{
    if (g->num_nodes == MAX_NODES)
    {
        printf("Error: Graph is full.\n");
        return;
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    g->nodes[g->num_nodes++] = new_node;
}

void add_edge(graph *g, int from, int to)
{
    if (from < 0 || from >= g->num_nodes || to < 0 || to >= g->num_nodes)
    {
        printf("Error: Invalid node indices.\n");
        return;
    }
    node *new_edge = (node *)malloc(sizeof(node));
    new_edge->value = to;
    new_edge->next = g->nodes[from]->next;
    g->nodes[from]->next = new_edge;
}

void print_graph(graph *g)
{
    printf("Graph:\n");
    for (int i = 0; i < g->num_nodes; i++)
    {
        printf("Node %d: ", g->nodes[i]->value);
        node *current = g->nodes[i]->next;
        while (current != NULL)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

bool is_path(graph *g, int from, int to)
{
    if (from == to)
    {
        return true;
    }
    node *current = g->nodes[from]->next;
    while (current != NULL)
    {
        if (current->value == to)
        {
            return true;
        }
        if (is_path(g, current->value, to))
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main()
{
    graph *g = create_graph();

    add_node(g, 0);
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);

    print_graph(g);

    bool path_exists = is_path(g, 0, 3);
    printf("Is there a path from node 0 to node 3? %s\n", path_exists ? "Yes" : "No");

    return 0;
}