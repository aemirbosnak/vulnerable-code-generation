//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define k 3 // Number of clusters
#define MAX_ITER 100 // Maximum number iterations

/* Generate random number within range */
double rand_range(double min, double max) {
    return (double) rand() / RAND_MAX * (max - min) + min;
}

/* Calculate Euclidean distance between two points */
double euclidean_distance(double *a, double *b, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        double diff = a[i] - b[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

/* Assign points to closest centroid */
int assign_cluster(double **points, double **centroids, int *labels, int num_points, int num_features) {
    int changed = 0;
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int min_cluster = 0;
        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(points[i], centroids[j], num_features);
            if (distance < min_distance) {
                min_distance = distance;
                min_cluster = j;
            }
        }
        if (labels[i] != min_cluster) {
            labels[i] = min_cluster;
            changed = 1;
        }
    }
    return changed;
}

/* Recalculate centroids based on cluster */
void calculate_centroids(double **points, double **centroids, int *labels, int num_points, int num_features) {
    int cluster_size[k];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < num_features; j++) {
            centroids[i][j] = 0.0;
        }
        cluster_size[i] = 0;
    }
    for (int i = 0; i < num_points; i++) {
        int cluster = labels[i];
        for (int j = 0; j < num_features; j++) {
            centroids[cluster][j] += points[i][j];
        }
        cluster_size[cluster]++;
    }
    for (int i = 0; i < k; i++) {
        if (cluster_size[i] > 0) {
            for (int j = 0; j < num_features; j++) {
                centroids[i][j] /= cluster_size[i];
            }
        }
    }
}

int main() {
    /* Generate random points for dataset */
    const int num_points = 50;
    const int num_features = 2;
    double **points = malloc(num_points * sizeof(double *));
    for (int i = 0; i < num_points; i++) {
        points[i] = malloc(num_features * sizeof(double));
        points[i][0] = rand_range(0.0, 10.0);
        points[i][1] = rand_range(0.0, 10.0);
    }

    /* Initialize centroids randomly */
    double **centroids = malloc(k * sizeof(double *));
    for (int i = 0; i < k; i++) {
        centroids[i] = malloc(num_features * sizeof(double));
        centroids[i][0] = rand_range(0.0, 10.0);
        centroids[i][1] = rand_range(0.0, 10.0);
    }

    /* Assign points to initial clusters */
    int *labels = malloc(num_points * sizeof(int));
    assign_cluster(points, centroids, labels, num_points, num_features);

    /* Run k-means clustering algorithm */
    int iter = 0;
    while (iter < MAX_ITER) {
        int changed = assign_cluster(points, centroids, labels, num_points, num_features);
        if (!changed) {
            break;
        }
        calculate_centroids(points, centroids, labels, num_points, num_features);
        iter++;
    }

    /* Print final clusters */
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < num_points; j++) {
            if (labels[j] == i) {
                printf("    (%lf, %lf)\n", points[j][0], points[j][1]);
            }
        }
    }

    /* Free memory */
    for (int i = 0; i < num_points; i++) {
        free(points[i]);
    }
    free(points);
    for (int i = 0; i < k; i++) {
        free(centroids[i]);
    }
    free(centroids);
    free(labels);

    return 0;
}