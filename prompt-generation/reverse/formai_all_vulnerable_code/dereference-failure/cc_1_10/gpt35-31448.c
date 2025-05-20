//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare the number of clusters and data points
int num_clusters = 3;
int num_points = 100;
int max_iterations = 100;

// Define the structure for holding cluster information
typedef struct Cluster {
    double* center;
    int size;
    double** points;
} Cluster;

// Define a function to calculate the distance between two points
double distance(double* p1, double* p2, int num_features) {
    double result = 0;
    for (int i = 0; i < num_features; i++) {
        result += pow(p1[i] - p2[i], 2);
    }
    return sqrt(result);
}

int main() {
    // Declare an array to hold all the data points
    double** data_points = malloc(num_points * sizeof(double*));
    for (int i = 0; i < num_points; i++) {
        data_points[i] = malloc(2 * sizeof(double));
        data_points[i][0] = (double) rand() / RAND_MAX;
        data_points[i][1] = (double) rand() / RAND_MAX;
    }
    
    // Initialize the clusters with random points
    Cluster* clusters = malloc(num_clusters * sizeof(Cluster));
    for (int i = 0; i < num_clusters; i++) {
        int random_index = rand() % num_points;
        clusters[i].center = data_points[random_index];
        clusters[i].size = 0;
    }
    
    // Start iterating
    for (int iteration = 0; iteration < max_iterations; iteration++) {
        // Clear all the points from the clusters
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].size = 0;
            clusters[i].points = malloc(num_points * sizeof(double*));
        }
        
        // Assign each point to the nearest cluster
        for (int i = 0; i < num_points; i++) {
            double shortest_distance = INFINITY;
            int closest_cluster_index;
            for (int j = 0; j < num_clusters; j++) {
                double d = distance(data_points[i], clusters[j].center, 2);
                if (d < shortest_distance) {
                    shortest_distance = d;
                    closest_cluster_index = j;
                }
            }
            clusters[closest_cluster_index].points[clusters[closest_cluster_index].size] = data_points[i];
            clusters[closest_cluster_index].size++;
        }
        
        // Compute the mean of each cluster and update the clusters' centers
        for (int i = 0; i < num_clusters; i++) {
            double* sum = malloc(2 * sizeof(double));
            for (int j = 0; j < clusters[i].size; j++) {
                for (int k = 0; k < 2; k++) {
                    sum[k] += clusters[i].points[j][k];
                }
            }
            for (int k = 0; k < 2; k++) {
                clusters[i].center[k] = sum[k] / clusters[i].size;
            }
        }
    }
    
    // Print the final clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("Center: (%.2f, %.2f)\n", clusters[i].center[0], clusters[i].center[1]);
        printf("Size: %d\n", clusters[i].size);
        printf("Points:\n");
        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%.2f, %.2f)\n", clusters[i].points[j][0], clusters[i].points[j][1]);
        }
        printf("\n");
    }
    
    // Free memory
    for (int i = 0; i < num_points; i++) {
        free(data_points[i]);
    }
    free(data_points);
    for (int i = 0; i < num_clusters; i++) {
        for (int j = 0; j < clusters[i].size; j++) {
            free(clusters[i].points[j]);
        }
        free(clusters[i].points);
    }
    free(clusters);
    
    return 0;
}