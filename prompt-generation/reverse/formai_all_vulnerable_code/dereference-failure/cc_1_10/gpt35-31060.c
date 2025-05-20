//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5

// Function to calculate euclidean distance
double euclidean_distance(double point1[], double point2[]) {
    double distance = 0.0;
    for (int i = 0; i < N; i++) {
        distance += pow((point1[i] - point2[i]), 2);
    }
    return sqrt(distance);
}

// Function to calculate the centroid of a cluster
void calculate_centroid(double** data_points, int num_observations, int num_dimensions, int cluster_num, double *centroid) {
    for (int i = 0; i < num_dimensions; i++) {
        double dimension_total = 0.0;
        for (int j = 0; j < num_observations; j++) {
            if (data_points[j][cluster_num] == 1) {
                dimension_total += data_points[j][i];
            }
        }
        centroid[i] = dimension_total / num_observations;
    }
}

int main() {
    // Create some random data points
    double data_points[5][N] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    
    // Define the number of clusters
    int k = 2;

    // Initialize the cluster assignments randomly
    double **cluster_assignments = (double **) malloc(sizeof(double *) * N);
    for (int i = 0; i < N; i++) {
        cluster_assignments[i] = (double *) malloc(sizeof(double) * k);
        for (int j = 0; j < k; j++) {
            cluster_assignments[i][j] = rand() % 2;
        }
    }

    // Initialize the centroids
    double **centroids = (double **) malloc(sizeof(double *) * k);
    for (int i = 0; i < k; i++) {
        centroids[i] = (double *) malloc(sizeof(double) * N);
        calculate_centroid(data_points, N, N, i, centroids[i]);
    }

    // Run the algorithm until convergence
    int max_iterations = 1000;
    int iteration_num = 0;
    double tolerance = 0.000001;
    double objective_function = 0.0;
    while (iteration_num < max_iterations) {
        // Assign each point to the cluster with the closest centroid
        for (int i = 0; i < N; i++) {
            double min_distance = INFINITY;
            int min_cluster = -1;
            for (int j = 0; j < k; j++) {
                double distance = euclidean_distance(data_points[i], centroids[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_cluster = j;
                }
            }
            for (int j = 0; j < k; j++) {
                if (j == min_cluster) {
                    cluster_assignments[i][j] = 1;
                } else {
                    cluster_assignments[i][j] = 0;
                }
            }
        }
        
        // Update the centroids
        for (int i = 0; i < k; i++) {
            calculate_centroid(cluster_assignments, N, k, i, centroids[i]);
        }
        
        // Calculate the objective function
        double new_objective_function = 0.0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < k; j++) {
                new_objective_function += cluster_assignments[i][j] * pow(euclidean_distance(data_points[i], centroids[j]), 2);
            }
        }
        
        // Check for convergence
        if (fabs(new_objective_function - objective_function) < tolerance) {
            break;
        }
        objective_function = new_objective_function;
        iteration_num++;
    }

    // Print the results
    printf("Cluster assignments:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < k; j++) {
            printf("%f ", cluster_assignments[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    printf("Cluster centroids:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", centroids[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < N; i++) {
        free(cluster_assignments[i]);
    }
    free(cluster_assignments);
    for (int i = 0; i < k; i++) {
        free(centroids[i]);
    }
    free(centroids);

    return 0;
}