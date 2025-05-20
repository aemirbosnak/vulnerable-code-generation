//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the maximum number of clusters and data points
#define MAX_CLUSTERS 10
#define MAX_DATA_POINTS 100

// Define the data point structure
typedef struct {
  double x;
  double y;
} data_point;

// Define the cluster structure
typedef struct {
  double centroid_x;
  double centroid_y;
  int num_points;
  data_point* points;
} cluster;

// Function to generate random data points
data_point* generate_data_points(int num_points) {
  data_point* points = malloc(num_points * sizeof(data_point));
  for (int i = 0; i < num_points; i++) {
    points[i].x = rand() / (double)RAND_MAX;
    points[i].y = rand() / (double)RAND_MAX;
  }
  return points;
}

// Function to initialize clusters
cluster* initialize_clusters(int num_clusters, data_point* points, int num_points) {
  cluster* clusters = malloc(num_clusters * sizeof(cluster));
  for (int i = 0; i < num_clusters; i++) {
    clusters[i].centroid_x = points[i].x;
    clusters[i].centroid_y = points[i].y;
    clusters[i].num_points = 1;
    clusters[i].points = malloc(sizeof(data_point));
    clusters[i].points[0] = points[i];
  }
  return clusters;
}

// Function to assign data points to clusters
void assign_data_points(cluster* clusters, int num_clusters, data_point* points, int num_points) {
  for (int i = 0; i < num_points; i++) {
    double min_distance = INFINITY;
    int closest_cluster = -1;
    for (int j = 0; j < num_clusters; j++) {
      double distance = sqrt(pow(points[i].x - clusters[j].centroid_x, 2) + pow(points[i].y - clusters[j].centroid_y, 2));
      if (distance < min_distance) {
        min_distance = distance;
        closest_cluster = j;
      }
    }
    clusters[closest_cluster].num_points++;
    clusters[closest_cluster].points = realloc(clusters[closest_cluster].points, clusters[closest_cluster].num_points * sizeof(data_point));
    clusters[closest_cluster].points[clusters[closest_cluster].num_points - 1] = points[i];
  }
}

// Function to update cluster centroids
void update_cluster_centroids(cluster* clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    double sum_x = 0;
    double sum_y = 0;
    for (int j = 0; j < clusters[i].num_points; j++) {
      sum_x += clusters[i].points[j].x;
      sum_y += clusters[i].points[j].y;
    }
    clusters[i].centroid_x = sum_x / clusters[i].num_points;
    clusters[i].centroid_y = sum_y / clusters[i].num_points;
  }
}

// Function to print clusters
void print_clusters(cluster* clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i + 1);
    printf("Centroid: (%f, %f)\n", clusters[i].centroid_x, clusters[i].centroid_y);
    printf("Number of points: %d\n", clusters[i].num_points);
    printf("Points:\n");
    for (int j = 0; j < clusters[i].num_points; j++) {
      printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
    }
    printf("\n");
  }
}

// Function to free memory
void free_memory(cluster* clusters, int num_clusters, data_point* points, int num_points) {
  for (int i = 0; i < num_clusters; i++) {
    free(clusters[i].points);
  }
  free(clusters);
  free(points);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate data points
  int num_data_points = 100;
  data_point* points = generate_data_points(num_data_points);

  // Initialize clusters
  int num_clusters = 3;
  cluster* clusters = initialize_clusters(num_clusters, points, num_data_points);

  // Assign data points to clusters
  assign_data_points(clusters, num_clusters, points, num_data_points);

  // Update cluster centroids
  update_cluster_centroids(clusters, num_clusters);

  // Print clusters
  print_clusters(clusters, num_clusters);

  // Free memory
  free_memory(clusters, num_clusters, points, num_data_points);

  return 0;
}