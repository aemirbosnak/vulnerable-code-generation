//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\nWelcome to the most cheerful C Graph representation program ever!\n\n");

    int n, i, j, k;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    int **graph;
    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nYour graph is represented as follows:\n\n");

    for (i = 0; i < n; i++)
    {
        printf("\t%d", i + 1);
    }
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", i + 1);
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                printf("🌟\t");
            }
            else
            {
                printf("💭\t");
            }
        }
        printf("\n\n");
    }

    for (k = 0; k < n; k++)
    {
        free(graph[k]);
    }
    free(graph);

    printf("Thank you for using our cheerful C Graph representation program!\n\n");

    return 0;
}