//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define surreal constants
#define PI 3.14159
#define E 2.71828
#define GOLDEN_RATIO 1.61803

// Define surreal variables
int n_clusters;
double tolerance = 0.0001;
int max_iterations = 1000;

// Define surreal functions
double distance(double *x, double *y) {
    double dist = 0.0;
    for(int i=0; i<sizeof(x)/sizeof(double); i++) {
        dist += pow(x[i]-y[i], 2);
    }
    return sqrt(dist);
}

double calculate_cost(double **data, int *assignments, double **centers) {
    double cost = 0.0;
    for(int i=0; i<sizeof(assignments)/sizeof(int); i++) {
        cost += distance(data[i], centers[assignments[i]]);
    }
    return cost;
}

void k_means(double **data, int n_features, int n_samples, double **centers) {
    int iteration = 0;
    double old_cost, new_cost = INFINITY;
    int *assignments = malloc(n_samples * sizeof(int));
    
    do {
        old_cost = new_cost;
        new_cost = 0.0;
        for(int i=0; i<n_samples; i++) {
            double min_dist = INFINITY;
            int closest_center = -1;
            for(int j=0; j<n_clusters; j++) {
                double dist = distance(data[i], centers[j]);
                if(dist < min_dist) {
                    min_dist = dist;
                    closest_center = j;
                }
            }
            new_cost += min_dist;
            assignments[i] = closest_center;
        }
        
        for(int j=0; j<n_clusters; j++) {
            int count = 0;
            double *sums = calloc(n_features, sizeof(double));
            for(int i=0; i<n_samples; i++) {
                if(assignments[i] == j) {
                    count += 1;
                    for(int k=0; k<n_features; k++) {
                        sums[k] += data[i][k];
                    }
                }
            }
            if(count > 0) {
                for(int k=0; k<n_features; k++) {
                    centers[j][k] = sums[k] / count;
                }
            }
            free(sums);
        }
        
        iteration += 1;
    } while(fabs(new_cost - old_cost) > tolerance && iteration < max_iterations);

    printf("Converged in %d iterations with a final cost of %f\n", iteration, new_cost);

    free(assignments);
}

int main() {
    // Define surreal data
    double data[10][2] = {{1.0, 1.0}, {2.0, 1.0}, {1.5, 2.0}, {7.0, 6.0}, {8.0, 6.0}, {7.5, 7.0}, {13.0, 12.0}, {14.0, 12.0}, {13.5, 13.0}, {19.0, 18.0}};
    int n_features = 2;
    int n_samples = 10;
    double *centers[3] = {calloc(n_features, sizeof(double)), calloc(n_features, sizeof(double)), calloc(n_features, sizeof(double))};

    // Define surreal parameters
    n_clusters = 3;

    // Set surreal centers randomly
    for(int i=0; i<n_clusters; i++) {
        for(int j=0; j<n_features; j++) {
            centers[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Surreal k-means algorithm
    k_means(data, n_features, n_samples, centers);

    // Free surreal memory
    for(int i=0; i<n_clusters; i++) {
        free(centers[i]);
    }

    return 0;
}