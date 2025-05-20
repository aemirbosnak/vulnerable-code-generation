//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: recursive
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Define the maximum number of clusters
#define MAX_CLUSTERS 10

// Define the maximum number of data points
#define MAX_DATA_POINTS 100

// Define the data type for a data point
typedef struct data_point {
  double x;
  double y;
} data_point;

// Define the data type for a cluster
typedef struct cluster {
  data_point centroid;
  int num_points;
  data_point* points;
} cluster;

// Function to initialize a data point
data_point init_data_point(double x, double y) {
  data_point point;
  point.x = x;
  point.y = y;
  return point;
}

// Function to initialize a cluster
cluster init_cluster(data_point centroid) {
  cluster cluster;
  cluster.centroid = centroid;
  cluster.num_points = 0;
  cluster.points = NULL;
  return cluster;
}

// Function to calculate the distance between two data points
double distance(data_point p1, data_point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to find the closest cluster to a data point
cluster* find_closest_cluster(data_point point, cluster* clusters, int num_clusters) {
  double min_distance = INFINITY;
  cluster* closest_cluster = NULL;
  for (int i = 0; i < num_clusters; i++) {
    double distance_to_centroid = distance(point, clusters[i].centroid);
    if (distance_to_centroid < min_distance) {
      min_distance = distance_to_centroid;
      closest_cluster = &clusters[i];
    }
  }
  return closest_cluster;
}

// Function to update the centroid of a cluster
void update_centroid(cluster* cluster) {
  double sum_x = 0;
  double sum_y = 0;
  for (int i = 0; i < cluster->num_points; i++) {
    sum_x += cluster->points[i].x;
    sum_y += cluster->points[i].y;
  }
  cluster->centroid.x = sum_x / cluster->num_points;
  cluster->centroid.y = sum_y / cluster->num_points;
}

// Function to perform k-means clustering
cluster* k_means(data_point* data_points, int num_data_points, int num_clusters) {
  // Initialize the clusters
  cluster* clusters = malloc(sizeof(cluster) * num_clusters);
  for (int i = 0; i < num_clusters; i++) {
    clusters[i] = init_cluster(data_points[i]);
  }

  // Assign each data point to the closest cluster
  for (int i = 0; i < num_data_points; i++) {
    cluster* closest_cluster = find_closest_cluster(data_points[i], clusters, num_clusters);
    closest_cluster->points = realloc(closest_cluster->points, sizeof(data_point) * (closest_cluster->num_points + 1));
    closest_cluster->points[closest_cluster->num_points] = data_points[i];
    closest_cluster->num_points++;
  }

  // Update the centroids of the clusters
  for (int i = 0; i < num_clusters; i++) {
    update_centroid(&clusters[i]);
  }

  // Repeat the previous two steps until the centroids no longer change
  int num_iterations = 0;
  int max_iterations = 100;
  while (num_iterations < max_iterations) {
    int num_changes = 0;
    for (int i = 0; i < num_data_points; i++) {
      cluster* closest_cluster = find_closest_cluster(data_points[i], clusters, num_clusters);
      if (closest_cluster != find_closest_cluster(data_points[i], clusters, num_clusters)) {
        num_changes++;
      }
    }

    if (num_changes == 0) {
      break;
    }

    for (int i = 0; i < num_clusters; i++) {
      update_centroid(&clusters[i]);
    }

    num_iterations++;
  }

  return clusters;
}

// Function to print the clusters
void print_clusters(cluster* clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i);
    printf("  Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
    printf("  Number of points: %d\n", clusters[i].num_points);
    for (int j = 0; j < clusters[i].num_points; j++) {
      printf("    Point: (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
    }
  }
}

// Main function
int main() {
  // Initialize the data points
  data_point data_points[] = {
    init_data_point(1, 1),
    init_data_point(1, 2),
    init_data_point(1, 3),
    init_data_point(2, 1),
    init_data_point(2, 2),
    init_data_point(2, 3),
    init_data_point(3, 1),
    init_data_point(3, 2),
    init_data_point(3, 3)
  };
  int num_data_points = sizeof(data_points) / sizeof(data_points[0]);

  // Initialize the number of clusters
  int num_clusters = 3;

  // Perform k-means clustering
  cluster* clusters = k_means(data_points, num_data_points, num_clusters);

  // Print the clusters
  print_clusters(clusters, num_clusters);

  // Free the allocated memory
  for (int i = 0; i < num_clusters; i++) {
    free(clusters[i].points);
  }
  free(clusters);

  return 0;
}