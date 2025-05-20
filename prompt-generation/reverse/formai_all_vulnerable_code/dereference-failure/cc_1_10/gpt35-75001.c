//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void printClusters(int clusters[], int size);
bool checkEqual(int a[], int b[], int size);
int* performClustering(int data[], int size);

int main() {
  int data[] = {1, 2, 4, 10, 11, 12, 16, 18, 19, 20, 22, 24, 30, 33};
  int size = sizeof(data) / sizeof(data[0]);

  int* clusters = performClustering(data, size);

  printf("Final Clusters: ");
  printClusters(clusters, size);

  free(clusters);
  return 0;
}

// Function to print the final clusters
void printClusters(int clusters[], int size) {
  printf("{ ");
  for (int i = 0; i < size; i++) {
    printf("%d ", clusters[i]);
  }
  printf("}\n");
}

// Function to check if two arrays are equal
bool checkEqual(int a[], int b[], int size) {
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

// Function to perform the clustering
int* performClustering(int data[], int size) {
  // Allocate memory for the clusters
  int* clusters = malloc(size * sizeof(int));

  // Initialize clusters as alternating values of 0 and 1
  for (int i = 0; i < size; i++) {
    clusters[i] = i % 2;
  }

  // Perform the clustering until convergence
  bool converged = false;
  while (!converged) {
    // Initialize the new clusters with all values set to -1
    int* newClusters = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
      newClusters[i] = -1;
    }

    // Determine the new clusters based on the old clusters
    int currentCluster = 0;
    int currentValue = data[0];
    for (int i = 1; i < size; i++) {
      if (clusters[i] == clusters[i - 1]) {
        currentValue += data[i];
      } else {
        newClusters[currentCluster] = currentValue;
        currentCluster++;
        currentValue = data[i];
      }
    }
    newClusters[currentCluster] = currentValue;

    // Check if the new clusters are equal to the old clusters
    if (checkEqual(clusters, newClusters, size)) {
      converged = true;
    } else {
      // Otherwise, update the old clusters with the new clusters
      for (int i = 0; i < size; i++) {
        clusters[i] = newClusters[i];
      }
    }

    // Free the memory for the new clusters
    free(newClusters);
  }

  return clusters;
}