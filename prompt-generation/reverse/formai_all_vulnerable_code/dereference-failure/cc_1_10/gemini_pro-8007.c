//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Define the data structure for a cluster
typedef struct {
  int size;
  double* centroid;
  int* points;
} Cluster;

// Define the data structure for the clustering algorithm
typedef struct {
  int num_clusters;
  Cluster* clusters;
} ClusteringAlgorithm;

// Create a new clustering algorithm
ClusteringAlgorithm* create_clustering_algorithm(int num_clusters) {
  ClusteringAlgorithm* algorithm = malloc(sizeof(ClusteringAlgorithm));
  algorithm->num_clusters = num_clusters;
  algorithm->clusters = malloc(num_clusters * sizeof(Cluster));
  for (int i = 0; i < num_clusters; i++) {
    algorithm->clusters[i].size = 0;
    algorithm->clusters[i].centroid = NULL;
    algorithm->clusters[i].points = NULL;
  }
  return algorithm;
}

// Destroy a clustering algorithm
void destroy_clustering_algorithm(ClusteringAlgorithm* algorithm) {
  for (int i = 0; i < algorithm->num_clusters; i++) {
    free(algorithm->clusters[i].centroid);
    free(algorithm->clusters[i].points);
  }
  free(algorithm->clusters);
  free(algorithm);
}

// Fit the clustering algorithm to a set of data
void fit_clustering_algorithm(ClusteringAlgorithm* algorithm, double** data, int num_data) {
  // Initialize the clusters
  for (int i = 0; i < algorithm->num_clusters; i++) {
    algorithm->clusters[i].size = 1;
    algorithm->clusters[i].centroid = malloc(sizeof(double) * num_data);
    for (int j = 0; j < num_data; j++) {
      algorithm->clusters[i].centroid[j] = data[i][j];
    }
    algorithm->clusters[i].points = malloc(sizeof(int) * 1);
    algorithm->clusters[i].points[0] = i;
  }

  // Iterate until the clusters converge
  int converged = 0;
  while (!converged) {
    // Assign each point to the closest cluster
    for (int i = 0; i < num_data; i++) {
      int closest_cluster = -1;
      double closest_distance = -1;
      for (int j = 0; j < algorithm->num_clusters; j++) {
        double distance = 0;
        for (int k = 0; k < num_data; k++) {
          distance += pow(data[i][k] - algorithm->clusters[j].centroid[k], 2);
        }
        distance = sqrt(distance);
        if (closest_cluster == -1 || distance < closest_distance) {
          closest_cluster = j;
          closest_distance = distance;
        }
      }
      algorithm->clusters[closest_cluster].points[algorithm->clusters[closest_cluster].size] = i;
      algorithm->clusters[closest_cluster].size++;
    }

    // Recalculate the centroids of the clusters
    for (int i = 0; i < algorithm->num_clusters; i++) {
      for (int j = 0; j < num_data; j++) {
        algorithm->clusters[i].centroid[j] = 0;
      }
      for (int k = 0; k < algorithm->clusters[i].size; k++) {
        for (int j = 0; j < num_data; j++) {
          algorithm->clusters[i].centroid[j] += data[algorithm->clusters[i].points[k]][j];
        }
      }
      for (int j = 0; j < num_data; j++) {
        algorithm->clusters[i].centroid[j] /= algorithm->clusters[i].size;
      }
    }

    // Check if the clusters have converged
    converged = 1;
    for (int i = 0; i < algorithm->num_clusters; i++) {
      for (int j = 0; j < num_data; j++) {
        if (fabs(algorithm->clusters[i].centroid[j] - algorithm->clusters[i].centroid[j]) > 0.001) {
          converged = 0;
          break;
        }
      }
    }
  }
}

// Print the clusters
void print_clusters(ClusteringAlgorithm* algorithm) {
  for (int i = 0; i < algorithm->num_clusters; i++) {
    printf("Cluster %d: ", i);
    for (int j = 0; j < algorithm->clusters[i].size; j++) {
      printf("%d ", algorithm->clusters[i].points[j]);
    }
    printf("\n");
  }
}

int main() {
  // Create a data set
  double** data = malloc(100 * sizeof(double*));
  for (int i = 0; i < 100; i++) {
    data[i] = malloc(100 * sizeof(double));
    for (int j = 0; j < 100; j++) {
      data[i][j] = rand() / (double)RAND_MAX;
    }
  }

  // Create a clustering algorithm
  ClusteringAlgorithm* algorithm = create_clustering_algorithm(5);

  // Fit the clustering algorithm to the data
  fit_clustering_algorithm(algorithm, data, 100);

  // Print the clusters
  print_clusters(algorithm);

  // Destroy the clustering algorithm
  destroy_clustering_algorithm(algorithm);

  // Free the data
  for (int i = 0; i < 100; i++) {
    free(data[i]);
  }
  free(data);

  return 0;
}