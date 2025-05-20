//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//This is a function that checks if a graph has a valid coloring
int isValidColoring(int graph[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (graph[i] == i + 1)
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (graph[i] == graph[j] && graph[i]!= i + 1)
                return 0;
        }
    }

    return 1;
}

//This is a function that returns the number of colors needed to color a graph
int getNumColors(int graph[], int n)
{
    int colors = 0;
    for (int i = 0; i < n; i++)
    {
        if (graph[i] == i + 1)
            continue;

        colors++;
    }

    return colors;
}

//This is the main function that solves the graph coloring problem
int main()
{
    int n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    //Creating the adjacency matrix
    int graph[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }

    //Populating the adjacency matrix
    printf("Enter the edges of the graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    //Checking if the graph has a valid coloring
    if (isValidColoring(graph, n))
    {
        printf("The graph is not 2-colorable.\n");
    }
    else
    {
        //Finding the number of colors needed
        int numColors = getNumColors(graph, n);

        //Printing the result
        printf("The graph is %d-colorable.\n", numColors);
    }

    return 0;
}