//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 10    // number of data points
#define DIM 2   // dimension of data points
#define K 3     // number of clusters

typedef struct {
    double x[DIM];
} point;

typedef struct {
    int size;
    point centroid;
    point *points;
} cluster;

point data[N] = {{2, 3}, {5, 6}, {8, 9}, {1, 5}, {4, 7}, {7, 3}, {9, 1}, {3, 2}, {6, 5}, {8, 4}};

double distance(point p1, point p2) {
    double dist = 0.0;
    for (int i = 0; i < DIM; i++) {
        dist += (p1.x[i] - p2.x[i]) * (p1.x[i] - p2.x[i]);
    }
    return sqrt(dist);
}

point calculate_centroid(cluster *c) {
    point centroid = {{0}};
    for (int i = 0; i < c->size; i++) {
        for (int j = 0; j < DIM; j++) {
            centroid.x[j] += c->points[i].x[j];
        }
    }
    for (int j = 0; j < DIM; j++) {
        centroid.x[j] /= c->size;
    }
    return centroid;
}

int main() {
    // initialize clusters
    cluster clusters[K];
    for (int i = 0; i < K; i++) {
        clusters[i].size = 0;
        clusters[i].centroid = data[i];
        clusters[i].points = malloc(N * sizeof(point));
    }
    
    // perform clustering
    bool converged = false;
    while (!converged) {
        // assign each data point to the nearest cluster
        for (int i = 0; i < N; i++) {
            double min_dist = INFINITY;
            int min_index = 0;
            for (int j = 0; j < K; j++) {
                double dist = distance(data[i], clusters[j].centroid);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_index = j;
                }
            }
            clusters[min_index].points[clusters[min_index].size] = data[i];
            clusters[min_index].size++;
        }
        
        // calculate new centroids for each cluster
        converged = true;
        for (int i = 0; i < K; i++) {
            point old_centroid = clusters[i].centroid;
            clusters[i].centroid = calculate_centroid(&clusters[i]);
            if (distance(old_centroid, clusters[i].centroid) > 0.001) {
                converged = false;
            }
        }
    }
    
    // print final cluster centroids
    for (int i = 0; i < K; i++) {
        printf("Cluster %d centroid: ", i+1);
        for (int j = 0; j < DIM; j++) {
            printf("%.2f ", clusters[i].centroid.x[j]);
        }
        printf("\n");
    }
    
    return 0;
}