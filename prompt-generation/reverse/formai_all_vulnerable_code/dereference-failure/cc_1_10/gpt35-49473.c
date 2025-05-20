//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct edge
{
    int src;
    int dest;
}Edge;

typedef struct graph
{
    int V;
    int E;
    Edge edge[MAX_EDGES];
}Graph;

typedef struct node
{
    int id;
    int neighbours[MAX_NODES];
    int num_neighbours;
}Node;

void init_graph(Graph *g)
{
    g->V = 0;
    g->E = 0;
    memset(g->edge, -1, sizeof(Edge)*MAX_EDGES);
}

void init_node(Node *n)
{
    n->id = -1;
    memset(n->neighbours, -1, sizeof(int)*MAX_NODES);
    n->num_neighbours = 0;
}

int add_node(Graph *g, Node *n)
{
    if(g->V == MAX_NODES)
        return 0;

    n->id = g->V++;
    return 1;
}

int add_edge(Graph *g, int src, int dest)
{
    if(g->E == MAX_EDGES)
        return 0;

    g->edge[g->E].src = src;
    g->edge[g->E++].dest = dest;
    return 1;
}

void print_graph(Graph *g)
{
    int i,j;
    printf("Topology:\n");
    printf("Vertices: %d\n",g->V);
    printf("Edges: %d\n",g->E);

    for(i=0;i<g->V;i++)
    {
        Node *n = (Node *)malloc(sizeof(Node));
        init_node(n);
        n->id = i;
        for(j=0;j<g->E;j++)
        {
            if(g->edge[j].src == i)
            {
                n->neighbours[n->num_neighbours++] = g->edge[j].dest;
            }
        }
        printf("Node %d neighbours: ",n->id);
        for(j=0;j<n->num_neighbours;j++)
            printf("%d ",n->neighbours[j]);
        printf("\n");
    }
}

int main()
{
    Graph g;
    Node n1, n2, n3, n4;
    init_graph(&g);
    init_node(&n1);
    init_node(&n2);
    init_node(&n3);
    init_node(&n4);

    add_node(&g,&n1);
    add_node(&g,&n2);
    add_node(&g,&n3);
    add_node(&g,&n4);

    add_edge(&g,0,1);
    add_edge(&g,1,2);
    add_edge(&g,1,3);

    print_graph(&g);
    return 0;
}