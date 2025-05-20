//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point {
    double x;
    double y;
};

struct centroid {
    double x;
    double y;
};

void kmeans(struct point *points, int n, int k, int max_iter, struct centroid *centroids, int *clusters) {
    double *distances = malloc(sizeof(double)*n);
    double *temp_centroids = malloc(sizeof(double)*k*2);
    int *cluster_indices = malloc(sizeof(int)*n);
    for (int i=0; i<n; i++) {
        distances[i] = 100000000000000;
    }
    for (int j=0; j<k; j++) {
        for (int i=0; i<n; i++) {
            distances[i] = sqrt(pow((points[i].x-centroids[j].x), 2) + pow((points[i].y-centroids[j].y), 2));
        }
        cluster_indices[0] = 0;
        for (int i=0; i<n; i++) {
            if (distances[i] < distances[cluster_indices[i]]) {
                cluster_indices[i] = i;
            }
        }
        for (int i=0; i<n; i++) {
            centroids[j].x = centroids[j].x + points[cluster_indices[i]].x/n;
            centroids[j].y = centroids[j].y + points[cluster_indices[i]].y/n;
        }
        for (int i=0; i<n; i++) {
            distances[i] = 100000000000000;
        }
    }
    printf("Clusters:\n");
    for (int i=0; i<k; i++) {
        printf("Cluster %d : (%f, %f)\n", i, centroids[i].x, centroids[i].y);
    }
}

int main() {
    int n = 100;
    int k = 3;
    int max_iter = 1000;
    int i, j;
    double x, y;
    struct point *points = malloc(sizeof(struct point)*n);
    struct centroid *centroids = malloc(sizeof(struct centroid)*k);
    int *clusters = malloc(sizeof(int)*n);
    for (i=0; i<n; i++) {
        points[i].x = (double)rand()/RAND_MAX;
        points[i].y = (double)rand()/RAND_MAX;
    }
    for (i=0; i<k; i++) {
        centroids[i].x = (double)rand()/RAND_MAX;
        centroids[i].y = (double)rand()/RAND_MAX;
    }
    for (i=0; i<n; i++) {
        clusters[i] = 0;
    }
    kmeans(points, n, k, max_iter, centroids, clusters);
    return 0;
}