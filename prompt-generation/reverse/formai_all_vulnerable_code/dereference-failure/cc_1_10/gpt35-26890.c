//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// maximum number of vertices in the graph
#define MAX_VERTICES 50

// maximum number of colors
#define MAX_COLORS 10

// structure to represent the graph
struct graph
{
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
};

// function declarations
void create_graph(struct graph *g);
void color_graph(struct graph g, int color[]);
void print_colors(int color[], int num_vertices);

// main function
int main()
{
    struct graph g;
    int color[MAX_VERTICES];

    create_graph(&g);

    color_graph(g, color);

    print_colors(color, g.num_vertices);

    return 0;
}

// function to create the graph
void create_graph(struct graph *g)
{
    int i, j, num_edges, edge_start, edge_end;

    // initialize the graph
    printf("Enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);
    scanf("%d", &g->num_vertices);

    // initialize the adjacency matrix
    for (i = 0; i < g->num_vertices; i++)
    {
        for (j = 0; j < g->num_vertices; j++)
        {
            g->adj_matrix[i][j] = 0;
        }
    }

    // get the number of edges and their endpoints
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    printf("Enter the endpoints of each edge (separated by a space):\n");
    for (i = 0; i < num_edges; i++)
    {
        scanf("%d %d", &edge_start, &edge_end);
        g->adj_matrix[edge_start][edge_end] = 1;
        g->adj_matrix[edge_end][edge_start] = 1;
    }
}

// function to color the graph
void color_graph(struct graph g, int color[])
{
    int i, j, c;

    // initialize all colors to -1
    for (i = 0; i < g.num_vertices; i++)
    {
        color[i] = -1;
    }

    // assign the first color to the first vertex
    color[0] = 0;

    // assign colors to the remaining vertices
    for (i = 1; i < g.num_vertices; i++)
    {
        // initialize the color array for this vertex to all available colors
        int available_colors[MAX_COLORS];
        for (j = 0; j < MAX_COLORS; j++)
        {
            available_colors[j] = 1;
        }

        // mark the colors that are already used by adjacent vertices
        for (j = 0; j < i; j++)
        {
            if (g.adj_matrix[i][j] && color[j] != -1)
            {
                available_colors[color[j]] = 0;
            }
        }

        // find the first available color for this vertex
        for (c = 0; c < MAX_COLORS; c++)
        {
            if (available_colors[c])
            {
                color[i] = c;
                break;
            }
        }
    }
}

// function to print the colors of each vertex
void print_colors(int color[], int num_vertices)
{
    int i;

    printf("The colors of the vertices are:\n");
    for (i = 0; i < num_vertices; i++)
    {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}