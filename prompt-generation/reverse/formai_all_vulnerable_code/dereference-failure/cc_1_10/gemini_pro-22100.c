//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The data point structure
typedef struct {
    int n;  // number of dimensions
    double *x;  // the coordinates of the point
} data_point;

// The cluster structure
typedef struct {
    int n;  // number of data points in the cluster
    data_point *x;  // the centroid of the cluster
} cluster;

// The clustering algorithm
int cluster_data(data_point *x, int n, int k, cluster *c) {
    // Initialize the clusters
    for (int i = 0; i < k; i++) {
        c[i].n = 0;
        c[i].x = (data_point *)malloc(sizeof(data_point));
        c[i].x->n = n;
        c[i].x->x = (double *)malloc(n * sizeof(double));
    }

    // Assign each data point to the nearest cluster
    for (int i = 0; i < n; i++) {
        double min_dist = 1e9;
        int min_cluster = 0;
        for (int j = 0; j < k; j++) {
            double dist = 0;
            for (int l = 0; l < n; l++) {
                dist += pow(x[i].x[l] - c[j].x->x[l], 2);
            }
            if (dist < min_dist) {
                min_dist = dist;
                min_cluster = j;
            }
        }
        c[min_cluster].n++;
        for (int l = 0; l < n; l++) {
            c[min_cluster].x->x[l] += x[i].x[l];
        }
    }

    // Update the centroids of the clusters
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            c[i].x->x[j] /= c[i].n;
        }
    }

    // Repeat the process until the clusters converge
    int converged = 0;
    while (!converged) {
        int num_changed = 0;
        // Assign each data point to the nearest cluster
        for (int i = 0; i < n; i++) {
            double min_dist = 1e9;
            int min_cluster = 0;
            for (int j = 0; j < k; j++) {
                double dist = 0;
                for (int l = 0; l < n; l++) {
                    dist += pow(x[i].x[l] - c[j].x->x[l], 2);
                }
                if (dist < min_dist) {
                    min_dist = dist;
                    min_cluster = j;
                }
            }
            if (min_cluster != min_cluster) {
                num_changed++;
                c[min_cluster].n++;
                for (int l = 0; l < n; l++) {
                    c[min_cluster].x->x[l] += x[i].x[l];
                    c[min_cluster].x->x[l] -= x[i].x[l];
                }
            }
        }
        // Update the centroids of the clusters
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                c[i].x->x[j] /= c[i].n;
            }
        }
        if (num_changed == 0) {
            converged = 1;
        }
    }

    return 0;
}

// Print the clusters
void print_clusters(cluster *c, int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < c[i].n; j++) {
            printf("  %f ", c[i].x->x[j]);
        }
        printf("\n");
    }
}

// Free the memory allocated for the clusters
void free_clusters(cluster *c, int k) {
    for (int i = 0; i < k; i++) {
        free(c[i].x->x);
        free(c[i].x);
    }
}

// Main function
int main() {
    // Generate some random data
    int n = 100;
    int k = 3;
    data_point *x = (data_point *)malloc(n * sizeof(data_point));
    for (int i = 0; i < n; i++) {
        x[i].n = 2;
        x[i].x = (double *)malloc(2 * sizeof(double));
        x[i].x[0] = rand() / (double)RAND_MAX;
        x[i].x[1] = rand() / (double)RAND_MAX;
    }

    // Cluster the data
    cluster *c = (cluster *)malloc(k * sizeof(cluster));
    cluster_data(x, n, k, c);

    // Print the clusters
    print_clusters(c, k);

    // Free the memory allocated for the data and the clusters
    free_clusters(c, k);
    for (int i = 0; i < n; i++) {
        free(x[i].x);
    }
    free(x);

    return 0;
}