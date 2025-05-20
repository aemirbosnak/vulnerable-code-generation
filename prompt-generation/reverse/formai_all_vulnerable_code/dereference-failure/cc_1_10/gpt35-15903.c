//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct cluster_cluster {
    size_t size;
    double *center;
    double *points;
} cluster;

double euclidean_distance(double *p1, double *p2, size_t size) {
    double distance = 0;
    for (int i = 0; i < size; i++) {
        distance += pow((p2[i] - p1[i]), 2);
    }
    return sqrt(distance);
}

void update_centers(cluster *clusters, size_t num_clusters, size_t dim) {
    for (int i = 0; i < num_clusters; i++) {
        if (clusters[i].size > 0) {
            for (int j = 0; j < dim; j++) {
                double mean = 0;
                for (int k = 0; k < clusters[i].size; k++) {
                    mean += clusters[i].points[k * dim + j];
                }
                clusters[i].center[j] = mean / clusters[i].size;
            }
        }
    }
}

bool assign_points(double *points, size_t num_points, cluster *clusters, size_t num_clusters, size_t dim) {
    bool converged = true;
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int assigned_cluster = -1;
        
        for (int j = 0; j < num_clusters; j++) {
            double distance = euclidean_distance(points + i * dim, clusters[j].center, dim);
            if (distance < min_distance) {
                min_distance = distance;
                assigned_cluster = j;
            }
        }
        
        if (clusters[assigned_cluster].size == 0 || \
            memcmp(clusters[assigned_cluster].points + (clusters[assigned_cluster].size - 1) * dim, points + i * dim, dim * sizeof(double)) != 0) {
            converged = false;
        }
        
        clusters[assigned_cluster].points = realloc(clusters[assigned_cluster].points, (clusters[assigned_cluster].size + 1) * dim * sizeof(double));
        if (!clusters[assigned_cluster].points) {
            fprintf(stderr, "Error: realloc failed\n");
            exit(EXIT_FAILURE);
        }
        memcpy(clusters[assigned_cluster].points + clusters[assigned_cluster].size * dim, points + i * dim, dim * sizeof(double));
        clusters[assigned_cluster].size += 1;
    }
    return converged;
}

cluster *k_means_clustering(double *points, size_t num_points, size_t num_clusters, size_t dim, size_t max_iterations) {
    cluster *clusters = calloc(num_clusters, sizeof(cluster));
    if (!clusters) {
        fprintf(stderr, "Error: calloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].center = calloc(dim, sizeof(double));
        if (!clusters[i].center) {
            fprintf(stderr, "Error: calloc failed\n");
            exit(EXIT_FAILURE);
        }
        memcpy(clusters[i].center, points + (i * num_points / num_clusters) * dim, dim * sizeof(double));
        clusters[i].size = 0;
        clusters[i].points = NULL;
    }
    
    for (int i = 0; i < max_iterations; i++) {
        printf("Iteration %d\n", i + 1);
        bool converged = assign_points(points, num_points, clusters, num_clusters, dim);
        if (converged) {
            break;
        }
        update_centers(clusters, num_clusters, dim);
    }
    
    return clusters;
}

int main() {
    double points[] = {
        1.0, 1.0,
        1.5, 2.0,
        3.0, 4.0,
        5.0, 7.0,
        3.5, 5.0,
        4.5, 5.0,
        3.5, 4.5
    };
    size_t num_points = 7;
    size_t num_clusters = 2;
    size_t dim = 2;
    size_t max_iterations = 10;
    
    cluster *clusters = k_means_clustering(points, num_points, num_clusters, dim, max_iterations);
    
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d center: (%f, %f)\n", i, clusters[i].center[0], clusters[i].center[1]);
        printf("Points in Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%f, %f)\n", clusters[i].points[j * dim], clusters[i].points[j * dim + 1]);
        }
    }
    
    return 0;
}