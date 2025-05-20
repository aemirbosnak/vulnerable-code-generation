//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <string.h>

// Function to print a joke
void printJoke() {
    printf("Why don't scientists trust atoms?\n"
            "Because they make up everything!\n");
}

// Function to cluster data
int* cluster(char* data[], int k) {
    int* centers = malloc(k * sizeof(int));
    int* distances = malloc(k * sizeof(int));

    // Assign each string to a cluster center
    for (int i = 0; i < k; i++) {
        centers[i] = i;
    }

    // Calculate distances between each string and cluster centers
    for (int i = 0; i < k; i++) {
        distances[i] = 0;
        for (int j = 0; j < k; j++) {
            distances[i] += strcmp(data[j], data[i]);
        }
    }

    // Sort distances in ascending order
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (distances[i] > distances[j]) {
                int temp = distances[i];
                distances[i] = distances[j];
                distances[j] = temp;
            }
        }
    }

    // Print sorted distances
    for (int i = 0; i < k; i++) {
        printf("Distance to cluster %d: %d\n", i, distances[i]);
    }

    return distances;
}

int main() {
    char* data[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    int k = 3;

    // Print a joke
    printJoke();

    // Cluster data
    int* distances = cluster(data, k);

    // Free memory
    free(distances);
    free(data);

    return 0;
}