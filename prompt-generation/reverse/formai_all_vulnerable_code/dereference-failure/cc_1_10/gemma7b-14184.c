//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_vertices = 10;
    int **adj_list = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++)
    {
        adj_list[i] = (int *)malloc(num_vertices * sizeof(int));
    }

    // Build the adjacency list
    adj_list[0] = malloc(num_vertices * sizeof(int));
    adj_list[0][1] = 1;
    adj_list[0][2] = 2;

    adj_list[1] = malloc(num_vertices * sizeof(int));
    adj_list[1][0] = 1;
    adj_list[1][2] = 3;

    adj_list[2] = malloc(num_vertices * sizeof(int));
    adj_list[2][0] = 2;
    adj_list[2][1] = 3;

    adj_list[3] = malloc(num_vertices * sizeof(int));
    adj_list[3][1] = 3;
    adj_list[3][2] = 4;

    adj_list[4] = malloc(num_vertices * sizeof(int));
    adj_list[4][3] = 4;
    adj_list[4][5] = 5;

    adj_list[5] = malloc(num_vertices * sizeof(int));
    adj_list[5][4] = 5;
    adj_list[5][6] = 6;

    adj_list[6] = malloc(num_vertices * sizeof(int));
    adj_list[6][5] = 6;
    adj_list[6][7] = 7;

    adj_list[7] = malloc(num_vertices * sizeof(int));
    adj_list[7][6] = 7;
    adj_list[7][8] = 8;

    adj_list[8] = malloc(num_vertices * sizeof(int));
    adj_list[8][7] = 8;
    adj_list[8][9] = 9;

    adj_list[9] = malloc(num_vertices * sizeof(int));
    adj_list[9][8] = 9;

    // Print the adjacency list
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (adj_list[i][j] != 0)
            {
                printf("%d ", adj_list[i][j]);
            }
        }
        printf("\n");
    }

    free(adj_list);

    return 0;
}