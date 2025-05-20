//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the number of data points and the number of clusters
#define NUM_POINTS 100
#define NUM_CLUSTERS 3

// Define the data structure for a data point
typedef struct point {
  double x;
  double y;
} point;

// Define the data structure for a cluster
typedef struct cluster {
  point centroid;
  int num_points;
  point *points;
} cluster;

// Function to generate random data points
void generate_data(point *points, int num_points) {
  // Set the random seed
  srand(time(NULL));

  // Generate the data points
  for (int i = 0; i < num_points; i++) {
    points[i].x = (double)rand() / (double)RAND_MAX;
    points[i].y = (double)rand() / (double)RAND_MAX;
  }
}

// Function to initialize the clusters
void initialize_clusters(cluster *clusters, int num_clusters, point *points, int num_points) {
  // Randomly select the centroids of the clusters
  for (int i = 0; i < num_clusters; i++) {
    int index = rand() % num_points;
    clusters[i].centroid = points[index];
    clusters[i].num_points = 0;
    clusters[i].points = NULL;
  }
}

// Function to assign data points to clusters
void assign_points_to_clusters(cluster *clusters, int num_clusters, point *points, int num_points) {
  // For each data point
  for (int i = 0; i < num_points; i++) {
    // Find the closest cluster
    int closest_cluster = 0;
    double min_distance = INFINITY;
    for (int j = 0; j < num_clusters; j++) {
      double distance = sqrt(pow(points[i].x - clusters[j].centroid.x, 2) + pow(points[i].y - clusters[j].centroid.y, 2));
      if (distance < min_distance) {
        min_distance = distance;
        closest_cluster = j;
      }
    }

    // Assign the data point to the closest cluster
    clusters[closest_cluster].points = realloc(clusters[closest_cluster].points, (clusters[closest_cluster].num_points + 1) * sizeof(point));
    clusters[closest_cluster].points[clusters[closest_cluster].num_points] = points[i];
    clusters[closest_cluster].num_points++;
  }
}

// Function to update the centroids of the clusters
void update_centroids(cluster *clusters, int num_clusters) {
  // For each cluster
  for (int i = 0; i < num_clusters; i++) {
    // Calculate the new centroid
    double sum_x = 0.0;
    double sum_y = 0.0;
    for (int j = 0; j < clusters[i].num_points; j++) {
      sum_x += clusters[i].points[j].x;
      sum_y += clusters[i].points[j].y;
    }
    clusters[i].centroid.x = sum_x / clusters[i].num_points;
    clusters[i].centroid.y = sum_y / clusters[i].num_points;
  }
}

// Function to print the clusters
void print_clusters(cluster *clusters, int num_clusters) {
  // For each cluster
  for (int i = 0; i < num_clusters; i++) {
    // Print the cluster's centroid
    printf("Cluster %d:\n", i);
    printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);

    // Print the cluster's points
    for (int j = 0; j < clusters[i].num_points; j++) {
      printf("Point %d: (%.2f, %.2f)\n", j, clusters[i].points[j].x, clusters[i].points[j].y);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Generate the data points
  point *points = malloc(NUM_POINTS * sizeof(point));
  generate_data(points, NUM_POINTS);

  // Initialize the clusters
  cluster *clusters = malloc(NUM_CLUSTERS * sizeof(cluster));
  initialize_clusters(clusters, NUM_CLUSTERS, points, NUM_POINTS);

  // Assign the data points to the clusters
  assign_points_to_clusters(clusters, NUM_CLUSTERS, points, NUM_POINTS);

  // Update the centroids of the clusters
  update_centroids(clusters, NUM_CLUSTERS);

  // Print the clusters
  print_clusters(clusters, NUM_CLUSTERS);

  // Free the memory
  free(points);
  for (int i = 0; i < NUM_CLUSTERS; i++) {
    free(clusters[i].points);
  }
  free(clusters);

  return 0;
}