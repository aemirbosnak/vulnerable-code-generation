//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point structure
typedef struct {
  double x;
  double y;
} Point;

// Define the cluster structure
typedef struct {
  Point centroid;
  int num_points;
  Point *points;
} Cluster;

// Create a new cluster
Cluster *create_cluster(Point centroid) {
  Cluster *cluster = malloc(sizeof(Cluster));
  cluster->centroid = centroid;
  cluster->num_points = 0;
  cluster->points = NULL;
  return cluster;
}

// Free a cluster
void free_cluster(Cluster *cluster) {
  free(cluster->points);
  free(cluster);
}

// Add a point to a cluster
void add_point_to_cluster(Cluster *cluster, Point point) {
  cluster->num_points++;
  cluster->points = realloc(cluster->points, cluster->num_points * sizeof(Point));
  cluster->points[cluster->num_points - 1] = point;
}

// Calculate the centroid of a cluster
Point calculate_centroid(Cluster *cluster) {
  Point centroid = {0, 0};
  for (int i = 0; i < cluster->num_points; i++) {
    centroid.x += cluster->points[i].x;
    centroid.y += cluster->points[i].y;
  }
  centroid.x /= cluster->num_points;
  centroid.y /= cluster->num_points;
  return centroid;
}

// Assign a point to the closest cluster
Cluster *assign_point_to_cluster(Point point, Cluster *clusters, int num_clusters) {
  double min_distance = INFINITY;
  Cluster *closest_cluster = NULL;
  for (int i = 0; i < num_clusters; i++) {
    double distance = sqrt(pow(point.x - clusters[i].centroid.x, 2) + pow(point.y - clusters[i].centroid.y, 2));
    if (distance < min_distance) {
      min_distance = distance;
      closest_cluster = &clusters[i];
    }
  }
  return closest_cluster;
}

// Perform k-means clustering
Cluster *k_means_clustering(Point *points, int num_points, int num_clusters) {
  // Create the clusters
  Cluster *clusters = malloc(num_clusters * sizeof(Cluster));
  for (int i = 0; i < num_clusters; i++) {
    clusters[i] = *create_cluster((Point){rand() % 100, rand() % 100});
  }

  // Assign the points to the clusters
  for (int i = 0; i < num_points; i++) {
    Cluster *closest_cluster = assign_point_to_cluster(points[i], clusters, num_clusters);
    add_point_to_cluster(closest_cluster, points[i]);
  }

  // Update the centroids of the clusters
  for (int i = 0; i < num_clusters; i++) {
    clusters[i].centroid = calculate_centroid(&clusters[i]);
  }

  // Repeat the previous two steps until the clusters no longer change
  int num_iterations = 0;
  while (num_iterations < 100) {
    // Assign the points to the clusters
    for (int i = 0; i < num_points; i++) {
      Cluster *closest_cluster = assign_point_to_cluster(points[i], clusters, num_clusters);
      add_point_to_cluster(closest_cluster, points[i]);
    }

    // Update the centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
      clusters[i].centroid = calculate_centroid(&clusters[i]);
    }

    num_iterations++;
  }

  return clusters;
}

// Print the clusters
void print_clusters(Cluster *clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i);
    for (int j = 0; j < clusters[i].num_points; j++) {
      printf("  (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
    }
  }
}

// Free the clusters
void free_clusters(Cluster *clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    free_cluster(&clusters[i]);
  }
  free(clusters);
}

int main() {
  // Create the data points
  Point *points = malloc(100 * sizeof(Point));
  for (int i = 0; i < 100; i++) {
    points[i] = (Point){rand() % 100, rand() % 100};
  }

  // Perform k-means clustering
  Cluster *clusters = k_means_clustering(points, 100, 3);

  // Print the clusters
  print_clusters(clusters, 3);

  // Free the clusters
  free_clusters(clusters, 3);

  // Free the data points
  free(points);

  return 0;
}