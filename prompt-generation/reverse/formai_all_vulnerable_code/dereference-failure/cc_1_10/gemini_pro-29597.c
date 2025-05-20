//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of clusters and data points
#define MAX_CLUSTERS 10
#define MAX_DATA_POINTS 100

// Define the data structure for a data point
typedef struct {
  double x;
  double y;
} data_point;

// Define the data structure for a cluster
typedef struct {
  data_point centroid;
  int num_points;
  data_point* points;
} cluster;

// Function to initialize the clusters
void initialize_clusters(cluster* clusters, int num_clusters, data_point* data_points, int num_data_points) {
  // Randomly select the centroids of the clusters
  for (int i = 0; i < num_clusters; i++) {
    int index = rand() % num_data_points;
    clusters[i].centroid = data_points[index];
    clusters[i].num_points = 0;
    clusters[i].points = malloc(sizeof(data_point) * num_data_points);
  }
}

// Function to assign data points to clusters
void assign_data_points(cluster* clusters, int num_clusters, data_point* data_points, int num_data_points) {
  // For each data point, find the closest cluster and assign it to that cluster
  for (int i = 0; i < num_data_points; i++) {
    double min_distance = INFINITY;
    int closest_cluster = -1;
    for (int j = 0; j < num_clusters; j++) {
      double distance = sqrt(pow(data_points[i].x - clusters[j].centroid.x, 2) + pow(data_points[i].y - clusters[j].centroid.y, 2));
      if (distance < min_distance) {
        min_distance = distance;
        closest_cluster = j;
      }
    }
    clusters[closest_cluster].points[clusters[closest_cluster].num_points] = data_points[i];
    clusters[closest_cluster].num_points++;
  }
}

// Function to update the centroids of the clusters
void update_centroids(cluster* clusters, int num_clusters) {
  // For each cluster, calculate the new centroid as the average of the points in the cluster
  for (int i = 0; i < num_clusters; i++) {
    double sum_x = 0;
    double sum_y = 0;
    for (int j = 0; j < clusters[i].num_points; j++) {
      sum_x += clusters[i].points[j].x;
      sum_y += clusters[i].points[j].y;
    }
    clusters[i].centroid.x = sum_x / clusters[i].num_points;
    clusters[i].centroid.y = sum_y / clusters[i].num_points;
  }
}

// Function to print the clusters
void print_clusters(cluster* clusters, int num_clusters) {
  // For each cluster, print the centroid and the points in the cluster
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i);
    printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
    for (int j = 0; j < clusters[i].num_points; j++) {
      printf("Point: (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Set the number of clusters and data points
  int num_clusters = 3;
  int num_data_points = 100;

  // Generate the data points
  data_point* data_points = malloc(sizeof(data_point) * num_data_points);
  for (int i = 0; i < num_data_points; i++) {
    data_points[i].x = rand() % 100;
    data_points[i].y = rand() % 100;
  }

  // Initialize the clusters
  cluster* clusters = malloc(sizeof(cluster) * num_clusters);
  initialize_clusters(clusters, num_clusters, data_points, num_data_points);

  // Assign data points to clusters
  assign_data_points(clusters, num_clusters, data_points, num_data_points);

  // Update the centroids of the clusters
  update_centroids(clusters, num_clusters);

  // Print the clusters
  print_clusters(clusters, num_clusters);

  // Free the memory allocated for the data points and clusters
  free(data_points);
  for (int i = 0; i < num_clusters; i++) {
    free(clusters[i].points);
  }
  free(clusters);

  return 0;
}