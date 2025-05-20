//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITER 1000 // max number of iterations

/* Function to calculate Euclidean distance between two data points */
double euclidean(double *a, double *b, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += pow((a[i] - b[i]), 2);
    }
    return sqrt(sum);
}

/* Function to randomly initialize centroids */
void init_centroids(double **X, int n, int d, int k, double **centroids) {
    int *indices = malloc(k * sizeof(int)); // randomly select k indices
    for (int i = 0; i < k; i++) {
        int index = rand() % n;
        for (int j = 0; j < i; j++) {
            if (indices[j] == index) {
                index = rand() % n;
                j = -1;
            }
        }
        indices[i] = index;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < d; j++) {
            centroids[i][j] = X[indices[i]][j]; // set centroids to randomly selected data points
        }
    }
    free(indices);
}

/* Function to assign data points to nearest centroid */
void assign_clusters(double **X, int n, int d, int k, double **centroids, int *clusters) {
    for (int i = 0; i < n; i++) {
        double min_dist = INFINITY;
        int cluster = 0;
        for (int j = 0; j < k; j++) {
            double dist = euclidean(X[i], centroids[j], d);
            if (dist < min_dist) {
                min_dist = dist;
                cluster = j;
            }
        }
        clusters[i] = cluster; // assign data points to nearest centroid
    }
}

/* Function to update centroids based on assigned data points */
void update_centroids(double **X, int n, int d, int k, double **centroids, int *clusters) {
    for (int i = 0; i < k; i++) {
        double *sum = calloc(d, sizeof(double));
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (clusters[j] == i) {
                for (int l = 0; l < d; l++) {
                    sum[l] += X[j][l];
                }
                count++;
            }
        }
        if (count > 0) {
            for (int l = 0; l < d; l++) {
                centroids[i][l] = sum[l] / count; // update centroids as average of assigned data points
            }
        }
        free(sum);
    }
}

/* Function to check if centroids have changed */
int centroids_changed(double **prev_centroids, double **centroids, int k, int d) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < d; j++) {
            if (prev_centroids[i][j] != centroids[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}

/* Main function to perform k-means clustering */
void kmeans(double **X, int n, int d, int k, int *clusters, double **centroids) {
    int iter = 0;
    double **prev_centroids = malloc(k * sizeof(double *));
    for (int i = 0; i < k; i++) {
        prev_centroids[i] = calloc(d, sizeof(double));
    }
    init_centroids(X, n, d, k, centroids);
    assign_clusters(X, n, d, k, centroids, clusters);
    update_centroids(X, n, d, k, centroids, clusters);
    while (centroids_changed(prev_centroids, centroids, k, d) && iter < MAX_ITER) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < d; j++) {
                prev_centroids[i][j] = centroids[i][j]; // set previous centroids to current centroids
            }
        }
        assign_clusters(X, n, d, k, centroids, clusters);
        update_centroids(X, n, d, k, centroids, clusters);
        iter++;
    }
    for (int i = 0; i < k; i++) {
        free(prev_centroids[i]);
    }
    free(prev_centroids);
}

/* Main function to test k-means clustering */
int main() {
    srand(time(NULL));
    int n = 1000; // number of data points
    int d = 2; // number of dimensions
    double **X = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        X[i] = calloc(d, sizeof(double));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            X[i][j] = rand() % 10; // generate random data points
        }
    }
    int k = 3; // number of clusters
    int *clusters = calloc(n, sizeof(int));
    double **centroids = malloc(k * sizeof(double *));
    for (int i = 0; i < k; i++) {
        centroids[i] = calloc(d, sizeof(double));
    }
    kmeans(X, n, d, k, clusters, centroids);
    for (int i = 0; i < n; i++) {
        printf("(%f,%f) belongs to cluster %d\n", X[i][0], X[i][1], clusters[i]); // print assigned clusters
    }
    for (int i = 0; i < n; i++) {
        free(X[i]);
    }
    free(X);
    for (int i = 0; i < k; i++) {
        free(centroids[i]);
    }
    free(centroids);
    free(clusters);
    return 0;
}