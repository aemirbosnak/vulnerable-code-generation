//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int graph[MAX][MAX];
    int n, m;
    scanf("Enter the number of nodes and edges: ", &n);
    scanf("Enter the number of edges: ", &m);

    // Create the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Read the edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two nodes connected by the edge: ", &u);
        scanf("Enter the two nodes connected by the edge: ", &v);
        graph[u][v] = 1;
    }

    // Colour the graph
    int colours[n];
    for (int i = 0; i < n; i++)
    {
        colours[i] = -1;
    }

    int chromaticNumber = graphColouring(graph, colours);

    // Print the chromatic number
    printf("The chromatic number of the graph is: ", chromaticNumber);

    return 0;
}

int graphColouring(int graph[MAX][MAX], int colours[MAX])
{
    int n = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (graph[i][j] != 0)
            {
                n++;
            }
        }
    }

    int chromaticNumber = 0;
    for (int i = 0; i < n; i++)
    {
        int available = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != 0 && colours[j] == colours[i])
            {
                available = 0;
            }
        }

        if (available)
        {
            colours[i] = chromaticNumber;
            chromaticNumber++;
        }
    }

    return chromaticNumber;
}