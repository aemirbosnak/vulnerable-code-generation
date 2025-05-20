//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void clustering(float *data, int size, int k, int *centroids, int *clusters) {
    int i, j, min_index;
    float min_dist, dist;

    // Initialize centroids randomly
    for (i = 0; i < k; i++) {
        centroids[i] = data[rand() % size];
    }

    while (1) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < k; j++) {
                dist = sqrtf((centroids[j] - data[i]) * (centroids[j] - data[i]));
                if (dist < min_dist) {
                    min_dist = dist;
                    min_index = j;
                }
            }
            clusters[i] = min_index;
        }

        // Check for convergence
        for (i = 0; i < size; i++) {
            if (clusters[i]!= clusters[i - 1]) {
                break;
            }
        }

        if (i == size) {
            break;
        }
    }
}

int main() {
    int size, k, i;
    float *data, *centroids, *clusters;

    // Input data
    printf("Enter the size of data: ");
    scanf("%d", &size);
    data = (float *)malloc(size * sizeof(float));
    for (i = 0; i < size; i++) {
        printf("Enter data element %d: ", i + 1);
        scanf("%f", &data[i]);
    }

    // Input number of clusters
    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    // Initialize clusters and centroids
    clusters = (int *)malloc(size * sizeof(int));
    centroids = (float *)malloc(k * sizeof(float));

    // Perform clustering
    clustering(data, size, k, centroids, clusters);

    // Print clusters
    for (i = 0; i < size; i++) {
        printf("Cluster %d: ", i + 1);
        for (int j = 0; j < k; j++) {
            if (clusters[i] == j) {
                printf("%.2f ", centroids[j]);
            }
        }
        printf("\n");
    }

    free(data);
    free(centroids);
    free(clusters);

    return 0;
}