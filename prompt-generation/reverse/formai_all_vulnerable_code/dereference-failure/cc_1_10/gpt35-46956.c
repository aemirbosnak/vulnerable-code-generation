//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helper function to initialize centers randomly
void init_centers(double* centers, int n_clusters, double* data, int n, int dim) {
    for(int i = 0; i < n_clusters; i++) {
        int r = rand() % n;
        for(int j = 0; j < dim; j++) {
            centers[i*dim+j] = data[r*dim+j];
        }
    }
}

// Helper function to calculate Euclidean distance
double dist(double* a, double* b, int dim) {
    double sum = 0;
    for(int i = 0; i < dim; i++) {
        sum += pow(a[i]-b[i], 2);
    }
    return sqrt(sum);
}

// Main clustering function
void cluster(double* data, int n, int dim, int n_clusters) {
    // Allocate memory for centers and clusters
    double* centers = (double*) malloc(sizeof(double) * n_clusters * dim);
    int* clusters = (int*) malloc(sizeof(int) * n);
    
    // Initialize centers randomly
    init_centers(centers, n_clusters, data, n, dim);
    
    // Perform clustering
    int max_iters = 10;
    for(int iters = 0; iters < max_iters; iters++) {
        // Assign points to clusters
        for(int i = 0; i < n; i++) {
            double min_dist = dist(&data[i*dim], &centers[0], dim);
            int min_cluster = 0;
            for(int j = 1; j < n_clusters; j++) {
                double d = dist(&data[i*dim], &centers[j*dim], dim);
                if(d < min_dist) {
                    min_dist = d;
                    min_cluster = j;
                }
            }
            clusters[i] = min_cluster;
        }
        
        // Compute new centers
        for(int i = 0; i < n_clusters; i++) {
            double sum[dim];
            for(int j = 0; j < dim; j++) {
                sum[j] = 0;
            }
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(clusters[j] == i) {
                    for(int k = 0; k < dim; k++) {
                        sum[k] += data[j*dim+k];
                    }
                    count++;
                }
            }
            if(count > 0) {
                for(int j = 0; j < dim; j++) {
                    centers[i*dim+j] = sum[j] / count;
                }
            }
        }
    }
    
    // Print cluster assignments
    printf("Cluster assignments:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", clusters[i]);
    }
    printf("\n");
    
    // Free memory
    free(centers);
    free(clusters);
}

int main() {
    // Generate some random data
    int n = 100;
    int dim = 2;
    double* data = (double*) malloc(sizeof(double) * n * dim);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < dim; j++) {
            data[i*dim+j] = (double) rand() / RAND_MAX * 10;
        }
    }
    
    // Cluster the data
    int n_clusters = 3;
    cluster(data, n, dim, n_clusters);
    
    // Free memory
    free(data);
    
    return 0;
}