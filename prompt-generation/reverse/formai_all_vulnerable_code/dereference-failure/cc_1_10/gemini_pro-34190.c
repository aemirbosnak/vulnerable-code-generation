//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Generate random data
double *generate_data(int num_points, int num_features) {
  double *data = malloc(sizeof(double) * num_points * num_features);
  srand(time(NULL));
  for (int i = 0; i < num_points; i++) {
    for (int j = 0; j < num_features; j++) {
      data[i * num_features + j] = rand() / (double)RAND_MAX;
    }
  }
  return data;
}

// Perform k-means clustering
int *k_means(double *data, int num_points, int num_features, int num_clusters) {
  // Initialize cluster centroids
  double **centroids = malloc(sizeof(double *) * num_clusters);
  for (int i = 0; i < num_clusters; i++) {
    centroids[i] = malloc(sizeof(double) * num_features);
    for (int j = 0; j < num_features; j++) {
      centroids[i][j] = rand() / (double)RAND_MAX;
    }
  }

  // Assign data points to clusters
  int *cluster_assignments = malloc(sizeof(int) * num_points);
  int changed = 1;
  int iter = 0;
  while (changed) {
    changed = 0;
    for (int i = 0; i < num_points; i++) {
      // Find the closest centroid to the data point
      double min_distance = INFINITY;
      int min_cluster = -1;
      for (int j = 0; j < num_clusters; j++) {
        double distance = 0;
        for (int k = 0; k < num_features; k++) {
          distance += pow(data[i * num_features + k] - centroids[j][k], 2);
        }
        distance = sqrt(distance);
        if (distance < min_distance) {
          min_distance = distance;
          min_cluster = j;
        }
      }

      // Update the data point's cluster assignment
      if (cluster_assignments[i] != min_cluster) {
        cluster_assignments[i] = min_cluster;
        changed = 1;
      }
    }

    // Update the centroids
    for (int i = 0; i < num_clusters; i++) {
      for (int j = 0; j < num_features; j++) {
        double sum = 0;
        int num_points_in_cluster = 0;
        for (int k = 0; k < num_points; k++) {
          if (cluster_assignments[k] == i) {
            sum += data[k * num_features + j];
            num_points_in_cluster++;
          }
        }
        centroids[i][j] = sum / num_points_in_cluster;
      }
    }
    iter++;
  }

  // Free memory
  for (int i = 0; i < num_clusters; i++) {
    free(centroids[i]);
  }
  free(centroids);

  return cluster_assignments;
}

int main() {
  // Generate data
  int num_points = 1000;
  int num_features = 10;
  double *data = generate_data(num_points, num_features);

  // Perform k-means clustering
  int num_clusters = 3;
  int *cluster_assignments = k_means(data, num_points, num_features, num_clusters);

  // Print cluster assignments
  for (int i = 0; i < num_points; i++) {
    printf("Data point %d belongs to cluster %d\n", i, cluster_assignments[i]);
  }

  // Free memory
  free(data);
  free(cluster_assignments);

  return 0;
}