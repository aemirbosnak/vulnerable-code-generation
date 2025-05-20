//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 2 // number of features

// data structure to represent a point in 2D space
typedef struct point {
    double features[DIM]; // features of the point
    int cluster; // cluster to which the point belongs
} point_t;

// compute the distance between two points
double distance(point_t* p1, point_t* p2) {
    double d = 0;
    for (int i = 0; i < DIM; i++) {
        d += pow(p1->features[i] - p2->features[i], 2);
    }
    return sqrt(d);
}

// compute the centroid of a set of points
void compute_centroid(point_t** points, int n, point_t* centroid) {
    for (int i = 0; i < DIM; i++) {
        centroid->features[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < DIM; j++) {
            centroid->features[j] += points[i]->features[j];
        }
    }
    for (int i = 0; i < DIM; i++) {
        centroid->features[i] /= n;
    }
}

// initialize centroids randomly
void init_centroids(point_t** points, int n, int k, point_t* centroids) {
    int* indexes = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        indexes[i] = i;
    }
    for (int i = 0; i < k; i++) {
        int index = rand() % n;
        centroids[i] = *points[indexes[index]];
        indexes[index] = indexes[n - 1];
        n--;
    }
    free(indexes);
}

// perform clustering
void kmeans(point_t** points, int n, int k) {
    point_t centroids[k];
    init_centroids(points, n, k, centroids);
    int changed;
    do {
        changed = 0;
        for (int i = 0; i < n; i++) {
            double min_distance = INFINITY;
            for (int j = 0; j < k; j++) {
                double d = distance(points[i], &centroids[j]);
                if (d < min_distance) {
                    min_distance = d;
                    points[i]->cluster = j;
                }
            }
        }
        for (int i = 0; i < k; i++) {
            point_t cluster_points[n];
            int cluster_size = 0;
            for (int j = 0; j < n; j++) {
                if (points[j]->cluster == i) {
                    cluster_points[cluster_size++] = *points[j];
                }
            }
            if (cluster_size > 0) {
                point_t centroid;
                compute_centroid(&cluster_points, cluster_size, &centroid);
                if (distance(&centroids[i], &centroid) > 0.0001) {
                    centroids[i] = centroid;
                    changed = 1;
                }
            }
        }
    } while (changed);
}

int main() {
    int n = 10; // number of points
    int k = 2; // number of clusters
    point_t* points[n];
    for (int i = 0; i < n; i++) {
        points[i] = (point_t*) malloc(sizeof(point_t));
        for (int j = 0; j < DIM; j++) {
            points[i]->features[j] = (double) (rand() % 100) / 100;
        }
    }
    kmeans(points, n, k);
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < n; j++) {
            if (points[j]->cluster == i) {
                printf("(%f,%f)\n", points[j]->features[0], points[j]->features[1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(points[i]);
    }
    return 0;
}