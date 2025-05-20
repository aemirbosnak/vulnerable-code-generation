//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_cases = 0;
    scanf("Number of test cases:", &num_cases);

    for (int i = 0; i < num_cases; i++)
    {
        int n = 0;
        scanf("Number of nodes:", &n);

        int **graph = (int **)malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++)
        {
            graph[j] = (int *)malloc(n * sizeof(int));
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                graph[j][k] = 0;
            }
        }

        int m = 0;
        scanf("Number of edges:", &m);

        for (int l = 0; l < m; l++)
        {
            int u = 0;
            int v = 0;
            scanf("Edge (%d, %d):", &u, &v);
            graph[u][v] = 1;
        }

        int query = 0;
        scanf("Number of queries:", &query);

        for (int q = 0; q < query; q++)
        {
            int u = 0;
            int v = 0;
            scanf("Query (%d, %d):", &u, &v);
            if (graph[u][v] == 1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }

        free(graph);
    }

    return 0;
}