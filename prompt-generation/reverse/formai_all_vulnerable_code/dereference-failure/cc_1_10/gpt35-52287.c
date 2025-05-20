//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100

double euclid_distance(double *a, double *b, int dim)
{
    double distance = 0;
    for(int i=0; i<dim; i++)
    {
        distance += pow(a[i]-b[i], 2);
    }
    distance = sqrt(distance);
    return distance;
}

void clustering(double **data, int n, int dim, int k, double **centers, int *clusters)
{
    double *distances = malloc(sizeof(double)*k);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            distances[j] = euclid_distance(data[i], centers[j], dim);
        }
        int min_index = 0;
        double min_distance = distances[0];
        for(int j=1; j<k; j++)
        {
            if(distances[j] < min_distance)
            {
                min_index = j;
                min_distance = distances[j];
            }
        }
        clusters[i] = min_index;
    }
    free(distances);
}

void update_centers(double **data, int n, int dim, int k, double **centers, int *clusters)
{
    int *cluster_size = calloc(k, sizeof(int));
    for(int i=0; i<n; i++)
    {
        int cluster_index = clusters[i];
        cluster_size[cluster_index]++;
        for(int j=0; j<dim; j++)
        {
            centers[cluster_index][j] += data[i][j];
        }
    }
    for(int i=0; i<k; i++)
    {
        if(cluster_size[i] > 0)
        {
            for(int j=0; j<dim; j++)
            {
                centers[i][j] /= cluster_size[i];
            }
        }
    }
    free(cluster_size);
}

void kmeans(double **data, int n, int dim, int k, double **centers, int *clusters)
{
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<dim; j++)
        {
            centers[i][j] = data[rand()%n][j];
        }
    }
    for(int iter=0; iter<MAX_ITER; iter++)
    {
        clustering(data, n, dim, k, centers, clusters);
        update_centers(data, n, dim, k, centers, clusters);
    }
}

int main()
{
    int n = 1000;
    int dim = 2;
    int k = 3;
    double **data = malloc(sizeof(double*)*n);
    double **centers = malloc(sizeof(double*)*k);
    int *clusters = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
    {
        data[i] = malloc(sizeof(double)*dim);
        for(int j=0; j<dim; j++)
        {
            data[i][j] = (double)rand()/RAND_MAX*10.0;
        }
    }
    for(int i=0; i<k; i++)
    {
        centers[i] = malloc(sizeof(double)*dim);
    }
    kmeans(data, n, dim, k, centers, clusters);
    for(int i=0; i<n; i++)
    {
        printf("(%f, %f) belongs to cluster %d\n", data[i][0], data[i][1], clusters[i]);
    }
    for(int i=0; i<n; i++)
    {
        free(data[i]);
    }
    free(data);
    for(int i=0; i<k; i++)
    {
        free(centers[i]);
    }
    free(centers);
    free(clusters);
    return 0;
}