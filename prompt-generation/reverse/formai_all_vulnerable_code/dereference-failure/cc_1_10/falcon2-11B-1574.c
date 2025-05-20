//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform k-means clustering
void kmeans(int *data, int n, int k, int *centroids, int *iterations) {
    // Initialize centroids randomly
    int i;
    for (i = 0; i < k; i++) {
        centroids[i] = (int)(rand() % 10000) + 1;
    }

    // Perform iterations of k-means
    int dist, min_dist;
    int cluster[k];
    int j;
    int *cluster_centers = (int *)malloc(k * sizeof(int));
    int *new_centers = (int *)malloc(k * sizeof(int));
    int *temp_centers = (int *)malloc(k * sizeof(int));
    int count = 0;

    // Loop until centroids stop changing
    do {
        for (j = 0; j < n; j++) {
            dist = 1000;
            min_dist = -1;
            for (i = 0; i < k; i++) {
                dist = abs(data[j] - centroids[i]);
                if (dist < min_dist) {
                    min_dist = dist;
                    cluster[j] = i;
                }
            }
            cluster_centers[cluster[j]] += data[j];
        }

        for (i = 0; i < k; i++) {
            new_centers[i] = 0;
            for (j = 0; j < n; j++) {
                if (cluster[j] == i) {
                    new_centers[i] += data[j];
                }
            }
            new_centers[i] /= cluster[j];
        }

        for (i = 0; i < k; i++) {
            temp_centers[i] = cluster_centers[i];
            cluster_centers[i] = new_centers[i];
        }
        free(cluster_centers);
        cluster_centers = temp_centers;
        count++;
    } while (count < *iterations);

    // Print the results
    printf("Clustered data:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Centroids:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", centroids[i]);
    }
    printf("\n");

    printf("Iterations: %d\n", *iterations);

    // Free memory
    free(cluster_centers);
    free(new_centers);
    free(temp_centers);
    free(cluster);
}

int main() {
    int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(data) / sizeof(data[0]);
    int k = 2;
    int iterations = 10;

    kmeans(data, n, k, NULL, &iterations);

    return 0;
}