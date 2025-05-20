//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Define a struct for our cluster
typedef struct Cluster {
    double *center;
    int size;
} Cluster;

// Define a function to calculate distance between two points
double calculate_distance(double *point1, double *point2, int dim) {
    double distance = 0;
    for (int i=0; i<dim; i++) {
        distance += pow(point1[i] - point2[i], 2);
    }
    return sqrt(distance);
}

// Define our clustering function
Cluster *clustering(double **points, int num_points, int dim, int num_clusters, double threshold) {
    
    // Initialize our clusters randomly
    Cluster *clusters = (Cluster *)malloc(num_clusters * sizeof(Cluster));
    
    for (int i=0; i<num_clusters; i++) {
        clusters[i].center = points[rand() % num_points];
        clusters[i].size = 0;
    }
    
    // Initialize our old_centers array for checking convergence
    double **old_centers = (double **)malloc(num_clusters * sizeof(double *));
    
    // Initialize our convergence flag
    bool converged = false;
    
    while (!converged) {
        
        // Assign points to clusters
        for (int i=0; i<num_points; i++) {
            double min_distance = INFINITY;
            int closest_cluster = 0;
            for (int j=0; j<num_clusters; j++) {
                double distance = calculate_distance(points[i], clusters[j].center, dim);
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_cluster = j;
                }
            }
            clusters[closest_cluster].size++;
        }
        
        // Update cluster centers
        for (int i=0; i<num_clusters; i++) {
            old_centers[i] = clusters[i].center;
            if (clusters[i].size > 0) {
                double *new_center = (double *)malloc(dim * sizeof(double));
                for (int j=0; j<dim; j++) {
                    new_center[j] = 0;
                    for (int k=0; k<num_points; k++) {
                        if (calculate_distance(points[k], clusters[i].center, dim) <= threshold) {
                            new_center[j] += points[k][j];
                        }
                    }
                    new_center[j] /= clusters[i].size;
                }
                clusters[i].center = new_center;
            }
        }
        
        // Check for convergence
        converged = true;
        for (int i=0; i<num_clusters; i++) {
            if (calculate_distance(clusters[i].center, old_centers[i], dim) > threshold) {
                converged = false;
                break;
            }
        }
        
    }
    
    return clusters;
}

// Main function to test our clustering algorithm
int main() {
    // Create an array of points
    const int NUM_POINTS = 1000;
    const int DIMENSIONS = 2;
    
    double **points = (double **)malloc(NUM_POINTS * sizeof(double *));
    for (int i=0; i<NUM_POINTS; i++) {
        points[i] = (double *)malloc(DIMENSIONS * sizeof(double));
        points[i][0] = ((double)rand() / RAND_MAX) * 10;
        points[i][1] = ((double)rand() / RAND_MAX) * 10;
    }
    
    Cluster *clusters = clustering(points, NUM_POINTS, DIMENSIONS, 5, 0.01);
    
    // Print our clusters
    for (int i=0; i<5; i++) {
        printf("Cluster %d (%d points):\n", i+1, clusters[i].size);
        for (int j=0; j<DIMENSIONS; j++) {
            printf("%f ", clusters[i].center[j]);
        }
        printf("\n\n");
    }
    
    return 0;
}