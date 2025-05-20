//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 15

void graph_coloring(int n, int m, int *colors, int *adj_mat[MAX_VERTICES], int vert_unprocessed, int *solution_found);

int main()
{
    int n, m, i, j, *colors, *adj_mat[MAX_VERTICES], vert_unprocessed = 0;
    int solution_found = 0;

    printf("Enter the number of vertices (max: %d): ", MAX_VERTICES);
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    colors = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        colors[i] = 0;
        adj_mat[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix (1 if there is an edge, 0 otherwise):\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj_mat[i][j]);
        }
    }

    graph_coloring(n, m, colors, adj_mat, vert_unprocessed, &solution_found);

    if (solution_found)
    {
        printf("\nSolution: \n");

        for (i = 0; i < n; i++)
        {
            printf("Vertex %d: Color %d\n", i + 1, colors[i]);
        }
    }
    else
    {
        printf("\nNo solution found with %d colors\n", m);
    }

    free(colors);

    for (i = 0; i < n; i++)
    {
        free(adj_mat[i]);
    }

    return 0;
}

void graph_coloring(int n, int m, int *colors, int *adj_mat[MAX_VERTICES], int vert_unprocessed, int *solution_found)
{
    int i, j, k, safe;

    if (vert_unprocessed == n)
    {
        *solution_found = 1;
        return;
    }

    for (k = 1; k <= m; k++)
    {
        safe = 1;

        for (i = 0; i < n; i++)
        {
            if (adj_mat[vert_unprocessed][i] == 1 && colors[i] == k)
            {
                safe = 0;
                break;
            }
        }

        if (safe)
        {
            colors[vert_unprocessed] = k;
            graph_coloring(n, m, colors, adj_mat, vert_unprocessed + 1, solution_found);

            if (*solution_found)
            {
                return;
            }

            colors[vert_unprocessed] = 0;
        }
    }
}