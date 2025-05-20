//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int numVertices;
int **graph;
int *colors;

void initGraph()
{
    int i, j;
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            graph[i][j] = rand() % 2;
        }
    }
}

void printGraph()
{
    int i, j;
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            if (graph[i][j] == 1)
            {
                printf("%d ", colors[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int isValid(int vertex, int color)
{
    int i;
    for (i = 0; i < numVertices; i++)
    {
        if (graph[vertex][i] == 1 && colors[i] == color)
        {
            return 0;
        }
    }
    return 1;
}

int colorGraph()
{
    int i, j, k;
    for (i = 0; i < numVertices; i++)
    {
        colors[i] = rand() % MAX_COLORS;
    }
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            if (graph[i][j] == 1)
            {
                for (k = 0; k < MAX_COLORS; k++)
                {
                    if (isValid(i, k) && isValid(j, k))
                    {
                        colors[i] = k;
                        colors[j] = k;
                        break;
                    }
                }
            }
        }
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
    }
    colors = (int *)malloc(numVertices * sizeof(int));
    initGraph();
    if (colorGraph())
    {
        printf("Graph colored successfully!\n");
    }
    else
    {
        printf("Graph cannot be colored with %d colors.\n", MAX_COLORS);
    }
    printGraph();
    return 0;
}