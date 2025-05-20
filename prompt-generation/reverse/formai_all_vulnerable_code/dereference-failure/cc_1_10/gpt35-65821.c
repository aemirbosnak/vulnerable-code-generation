//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 2 // Number of dimensions in data
#define CLUSTERS 2 // Number of clusters to create

// Function to generate random data
float** generate_data(int n) {
    float** data = (float**)malloc(n * sizeof(float*));
    for(int i = 0; i < n; i++) {
        data[i] = (float*)malloc(DIMENSIONS * sizeof(float));
        for(int j = 0; j < DIMENSIONS; j++) {
            data[i][j] = (float)rand() / RAND_MAX;
        }
    }
    return data;
}

// Function to get the euclidean distance between two points
float euclidean_distance(float* point1, float* point2) {
    float distance = 0;
    for(int i = 0; i < DIMENSIONS; i++) {
        distance += pow(point1[i] - point2[i], 2);
    }
    return sqrt(distance);
}

// Function to find the closest centroid for a point
int find_closest_centroid(float* point, float** centroids) {
    int closest_centroid = 0;
    float min_distance = euclidean_distance(point, centroids[0]);
    for(int i = 1; i < CLUSTERS; i++) {
        float distance = euclidean_distance(point, centroids[i]);
        if(distance < min_distance) {
            closest_centroid = i;
            min_distance = distance;
        }
    }
    return closest_centroid;
}

// Function to recompute the centroids for a cluster
void recompute_centroid(float** cluster, float* centroid) {
    for(int i = 0; i < DIMENSIONS; i++) {
        centroid[i] = 0;
        for(int j = 0; j < CLUSTERS; j++) {
            centroid[i] += cluster[j][i];
        }
        centroid[i] /= CLUSTERS;
    }
}

// Main function
int main() {
    // Generate random data
    float** data = generate_data(10);

    // Initialize centroids
    float** centroids = (float**)malloc(CLUSTERS * sizeof(float*));
    for(int i = 0; i < CLUSTERS; i++) {
        centroids[i] = (float*)malloc(DIMENSIONS * sizeof(float));
        for(int j = 0; j < DIMENSIONS; j++) {
            centroids[i][j] = (float)rand() / RAND_MAX;
        }
    }

    // Assign points to clusters
    int* assignments = (int*)malloc(10 * sizeof(int));
    for(int i = 0; i < 10; i++) {
        assignments[i] = find_closest_centroid(data[i], centroids);
    }

    // Initialize clusters
    float*** clusters = (float***)malloc(CLUSTERS * sizeof(float**));
    for(int i = 0; i < CLUSTERS; i++) {
        clusters[i] = (float**)malloc(10 * sizeof(float*));
        int count = 0;
        for(int j = 0; j < 10; j++) {
            if(assignments[j] == i) {
                clusters[i][count] = data[j];
                count++;
            }
        }
        // Recompute centroid for cluster
        recompute_centroid(clusters[i], centroids[i]);
    }

    // Print results
    printf("Data:\n");
    for(int i = 0; i < 10; i++) {
        printf("%f %f\n", data[i][0], data[i][1]);
    }
    printf("\nCentroids:\n");
    for(int i = 0; i < CLUSTERS; i++) {
        printf("%f %f\n", centroids[i][0], centroids[i][1]);
    }
    printf("\nClusters:\n");
    for(int i = 0; i < CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        for(int j = 0; j < 10; j++) {
            if(assignments[j] == i) {
                printf("%f %f\n", clusters[i][j][0], clusters[i][j][1]);
            }
        }
        printf("Centroid: %f %f\n", centroids[i][0], centroids[i][1]);
    }

    return 0;
}