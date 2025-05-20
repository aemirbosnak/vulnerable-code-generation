//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Point 
{
    int x;
    int y;
};

struct Point* createRandomPoints(int rows, int columns)
{
    struct Point* arr = (struct Point*)malloc((rows * columns) * sizeof(struct Point));

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            (arr + i * columns + j)->x = rand() % 10;
            (arr + i * columns + j)->y = rand() % 10;
        }
    }
    return arr;
}

float euclideanDistance(struct Point p1, struct Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
    int n = 4, m = 5, k = 2;

    struct Point* points = createRandomPoints(n, m);

    int* cluster = (int*)calloc(n * m, sizeof(int));

    // Randomly initialize centroids
    struct Point* centroids = (struct Point*)malloc(k * sizeof(struct Point));
    for(int i = 0; i < k; i++)
    {
        int index = rand() % (n * m);
        centroids[i].x = (points + index)->x;
        centroids[i].y = (points + index)->y;
    }

    int iterations = 0;

    while(iterations < 20)
    {
        // Assign each point to closest centroid
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int minIndex = 0;
                float minDistance = euclideanDistance(*(points + i * m + j), centroids[0]);

                for(int l = 1; l < k; l++)
                {
                    float distance = euclideanDistance(*(points + i * m + j), centroids[l]);
                    if(distance < minDistance)
                    {
                        minDistance = distance;
                        minIndex = l;
                    }
                }
                *(cluster + i * m + j) = minIndex;
            }
        }

        // Update centroids
        int* clusterSizes = (int*)calloc(k, sizeof(int));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int index = *(cluster + i * m + j);
                centroids[index].x += (points + i * m + j)->x;
                centroids[index].y += (points + i * m + j)->y;
                clusterSizes[index]++;
            }
        }
        for(int i = 0; i < k; i++)
        {
            if(clusterSizes[i] == 0)
            {
                int index = rand() % (n * m);
                centroids[i].x = (points + index)->x;
                centroids[i].y = (points + index)->y;
            }
            else
            {
                centroids[i].x /= clusterSizes[i];
                centroids[i].y /= clusterSizes[i];
            }
        }

        free(clusterSizes);

        iterations++;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("(%d, %d) belongs to cluster %d\n", (points + i * m + j)->x, (points + i * m + j)->y, *(cluster + i * m + j));
        }
    }

    free(points);
    free(centroids);
    free(cluster);

    return 0;
}