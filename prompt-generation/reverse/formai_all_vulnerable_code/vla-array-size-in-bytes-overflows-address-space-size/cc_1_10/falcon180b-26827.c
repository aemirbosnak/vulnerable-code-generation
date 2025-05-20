//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAX 100
#define INF 9999

struct Point
{
    int x, y;
};

int euclidean_distance(struct Point p1, struct Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void swap(struct Point *a, struct Point *b)
{
    struct Point temp = *a;
    *a = *b;
    *b = temp;
}

void k_means(struct Point data[], int k, int iter)
{
    int i, j;
    struct Point centroids[k];
    for(i=0; i<k; i++)
    {
        centroids[i].x = rand() % MAX;
        centroids[i].y = rand() % MAX;
    }
    for(i=0; i<iter; i++)
    {
        for(j=0; j<k; j++)
        {
            int count = 0;
            struct Point temp = centroids[j];
            centroids[j].x = 0;
            centroids[j].y = 0;
            for(int l=0; l<MAX; l++)
            {
                if(euclidean_distance(data[l], temp) <= 50)
                {
                    centroids[j].x += data[l].x;
                    centroids[j].y += data[l].y;
                    count++;
                }
            }
            if(count > 0)
            {
                centroids[j].x /= count;
                centroids[j].y /= count;
            }
        }
    }
}

int main()
{
    struct Point data[MAX];
    int k, iter;
    printf("Enter the number of data points: ");
    scanf("%d", &k);
    printf("Enter the number of iterations: ");
    scanf("%d", &iter);
    srand(time(NULL));
    for(int i=0; i<k; i++)
    {
        data[i].x = rand() % MAX;
        data[i].y = rand() % MAX;
    }
    k_means(data, k, iter);
    return 0;
}