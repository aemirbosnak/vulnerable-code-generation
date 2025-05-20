//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void kmeans_clustering(int **data, int num_clusters, int num_points, double **centers)
{
    int i, j, k, l, nearest_center;
    double distance, min_distance, sum_distances = 0.0;
    centers = malloc(num_clusters * sizeof(double *));
    for (k = 0; k < num_clusters; k++)
    {
        centers[k] = malloc(num_points * sizeof(double));
    }

    for (i = 0; i < num_points; i++)
    {
        for (k = 0; k < num_clusters; k++)
        {
            min_distance = MAX;
            for (l = 0; l < num_clusters; l++)
            {
                distance = sqrt(pow(data[i][0] - centers[l][0], 2) + pow(data[i][1] - centers[l][1], 2));
                if (distance < min_distance)
                {
                    min_distance = distance;
                    nearest_center = l;
                }
            }

            centers[nearest_center][i] = data[i][0] + data[i][1] / 2.0;
            sum_distances += min_distance;
        }
    }

    printf("Total sum of distances: %.2lf\n", sum_distances);
}

int main()
{
    int **data = malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        data[i] = malloc(2 * sizeof(int));
    }

    data[0][0] = 10;
    data[0][1] = 20;
    data[1][0] = 15;
    data[1][1] = 25;
    data[2][0] = 20;
    data[2][1] = 30;
    data[3][0] = 25;
    data[3][1] = 35;
    data[4][0] = 30;
    data[4][1] = 40;
    data[5][0] = 35;
    data[5][1] = 45;
    data[6][0] = 40;
    data[6][1] = 50;
    data[7][0] = 45;
    data[7][1] = 55;
    data[8][0] = 50;
    data[8][1] = 60;
    data[9][0] = 55;
    data[9][1] = 65;

    int num_clusters = 3;
    kmeans_clustering(data, num_clusters, 10, NULL);

    return 0;
}