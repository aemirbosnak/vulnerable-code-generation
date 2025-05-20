//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // Number of clusters
#define MAX_ITER 100 // Maximum iterations for convergence
#define THRESHOLD 0.01 // Convergence threshold

// Function to calculate the Euclidean distance between two points
double euclidean_distance(double* p1, double* p2, int dim) {
    double distance = 0;
    for(int i=0; i<dim; i++) {
        distance += pow((*p2++) - (*p1++), 2);
    }
    return sqrt(distance);
}

// Function to randomly initialize the centroids for the clusters
void initialize_centroids(double** data, int n, int dim, double** centroids) {
    for(int i=0; i<K; i++) {
        int idx = rand() % n;
        for(int j=0; j<dim; j++) {
            centroids[i][j] = data[idx][j];
        }
    }
}

// Function to assign each data point to one of the K clusters
void assign_clusters(double** data, int n, int dim, double** centroids, int* clusters) {
    for(int i=0; i<n; i++) {
        double min_distance = INFINITY;
        for(int j=0; j<K; j++) {
            double distance = euclidean_distance(data[i], centroids[j], dim);
            if(distance < min_distance) {
                min_distance = distance;
                clusters[i] = j;
            }
        }
    }
}

// Function to update the centroids for each cluster
void update_centroids(double** data, int n, int dim, double** centroids, int* clusters) {
    int* cluster_sizes = calloc(K, sizeof(int));
    for(int i=0; i<n; i++) {
        int cluster = clusters[i];
        cluster_sizes[cluster]++;
        for(int j=0; j<dim; j++) {
            centroids[cluster][j] += data[i][j];
        }
    }
    for(int i=0; i<K; i++) {
        if(cluster_sizes[i] > 0) {
            for(int j=0; j<dim; j++) {
                centroids[i][j] /= cluster_sizes[i];
            }
        }
    }
    free(cluster_sizes);
}

// Function to check for convergence
int check_convergence(double** old_centroids, double** new_centroids, int dim) {
    for(int i=0; i<K; i++) {
        for(int j=0; j<dim; j++) {
            if(fabs(old_centroids[i][j] - new_centroids[i][j]) > THRESHOLD) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n = 10; // Number of data points
    int dim = 2; // Dimensionality of data points
    double** data = malloc(n * sizeof(double*));
    for(int i=0; i<n; i++) {
        data[i] = malloc(dim * sizeof(double));
    }
    // Generate random data points
    for(int i=0; i<n; i++) {
        for(int j=0; j<dim; j++) {
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }

    double** centroids = malloc(K * sizeof(double*));
    for(int i=0; i<K; i++) {
        centroids[i] = malloc(dim * sizeof(double));
    }
    initialize_centroids(data, n, dim, centroids);

    int* clusters = calloc(n, sizeof(int));

    int iter = 0;
    double** old_centroids = malloc(K * sizeof(double*));
    for(int i=0; i<K; i++) {
        old_centroids[i] = malloc(dim * sizeof(double));
    }

    while(iter < MAX_ITER) {
        for(int i=0; i<K; i++) {
            for(int j=0; j<dim; j++) {
                old_centroids[i][j] = centroids[i][j];
                centroids[i][j] = 0;
            }
        }
        assign_clusters(data, n, dim, centroids, clusters);
        update_centroids(data, n, dim, centroids, clusters);
        if(check_convergence(old_centroids, centroids, dim)) {
            break;
        }
        iter++;
    }

    // Print the results
    printf("Final clustering:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", clusters[i]);
    }
    printf("\n");

    // Clean up memory
    for(int i=0; i<n; i++) {
        free(data[i]);
    }
    free(data);
    for(int i=0; i<K; i++) {
        free(centroids[i]);
        free(old_centroids[i]);
    }
    free(centroids);
    free(old_centroids);
    free(clusters);

    return 0;
}