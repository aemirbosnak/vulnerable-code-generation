//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100 // Maximum number of data points
#define D 3   // Number of dimensions

// Definition of a point in D-dimensional space
typedef struct {
    double coords[D];
} Point;

// Definition of a cluster
typedef struct {
    Point centroid;
    int size;
    Point points[N];
} Cluster;

// Initialize a cluster with a random centroid
void initialize_cluster(Cluster *c, Point *data, int n) {
    int index = rand() % n;
    c->centroid = data[index];
    c->size = 0;
}

// Compute the distance between two points in D-dimensional space
double distance(Point *a, Point *b) {
    double sum = 0.0;
    int i;
    for (i = 0; i < D; i++) {
        sum += pow(a->coords[i] - b->coords[i], 2);
    }
    return sqrt(sum);
}

// Compute the mean coordinates of all points in a cluster
Point compute_mean(Cluster *c) {
    Point mean;
    int i, j;
    for (i = 0; i < D; i++) {
        mean.coords[i] = 0.0;
    }
    for (i = 0; i < c->size; i++) {
        for (j = 0; j < D; j++) {
            mean.coords[j] += c->points[i].coords[j];
        }
    }
    for (i = 0; i < D; i++) {
        mean.coords[i] /= c->size;
    }
    return mean;
}

// Assign each data point to the closest cluster
void assign_points(Cluster *clusters, Point *data, int n, int num_clusters) {
    int i, j,closest_cluster;
    double dist, min_dist;
    for (i = 0; i < n; i++) {
        min_dist = INFINITY;
        for (j = 0; j < num_clusters; j++) {
            dist = distance(&data[i], &clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].points[clusters[closest_cluster].size++] = data[i];
    }
}

// Run the clustering algorithm
void k_means(Point *data, int n, int num_clusters) {
    Cluster clusters[num_clusters];
    int i, j;
    // Initialize each cluster with a random centroid
    for (i = 0; i < num_clusters; i++) {
        initialize_cluster(&clusters[i], data, n);
    }
    int iterations = 0;
    while (1) {
        iterations++;
        // Assign each data point to the closest cluster
        assign_points(clusters, data, n, num_clusters);
        // Compute the mean coordinates of each cluster
        for (i = 0; i < num_clusters; i++) {
            if (clusters[i].size > 0) {
                clusters[i].centroid = compute_mean(&clusters[i]);
            }
        }
        // Check if the clusters have converged
        int converged = 1;
        for (i = 0; i < num_clusters; i++) {
            for (j = 0; j < clusters[i].size; j++) {
                if (distance(&clusters[i].points[j], &clusters[i].centroid) > 0.001) {
                    converged = 0;
                    break;
                }
            }
        }
        if (converged) {
            break;
        }
        // Reset the clusters for the next iteration
        for (i = 0; i < num_clusters; i++) {
            clusters[i].size = 0;
        }
    }
    printf("Algorithm converged after %d iterations.\n", iterations);
}

int main() {
    Point data[N];
    int n, num_clusters;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);
    printf("Enter the data points (one per line):\n");
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < D; j++) {
            scanf("%lf", &data[i].coords[j]);
        }
    }
    k_means(data, n, num_clusters);
    return 0;
}