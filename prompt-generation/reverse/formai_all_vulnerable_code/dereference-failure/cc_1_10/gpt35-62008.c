//FormAI DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>

// Function to print graph vertices
void print_vertices(int vertices, int graph[vertices][vertices])
{
   printf("The vertices are:\n");
   for(int i=0; i<vertices; i++)
   {
        printf("%d ", i);
   }
   printf("\n\n");
}

// Function to print graph edges
void print_edges(int vertices, int graph[vertices][vertices])
{
   printf("The edges are:\n");
   for(int i=0; i<vertices; i++)
   {
        for(int j=0; j<vertices; j++)
        {
            if(graph[i][j] == 1)
            {
                printf("(%d,%d) ", i, j);
            }
        }
    }
    printf("\n\n");
}

// Function to add edge to graph
void add_edge(int vertices, int graph[vertices][vertices], int src, int dest)
{
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

// Function to remove edge from graph
void remove_edge(int vertices, int graph[vertices][vertices], int src, int dest)
{
    graph[src][dest] = 0;
    graph[dest][src] = 0;
}

int main()
{
    int vertices = 5;
    int graph[5][5] = {{0, 1, 0, 1, 1},
                    {1, 0, 1, 0, 1},
                    {0, 1, 0, 1, 0},
                    {1, 0, 1, 0, 1},
                    {1, 1, 0, 1, 0}};

    print_vertices(vertices, graph);
    print_edges(vertices, graph);

    add_edge(vertices, graph, 1, 3);

    printf("Graph after adding edge (1,3):\n");
    print_edges(vertices, graph);

    remove_edge(vertices, graph, 2, 4);

    printf("Graph after removing edge (2,4):\n");
    print_edges(vertices, graph);

    return 0;
}