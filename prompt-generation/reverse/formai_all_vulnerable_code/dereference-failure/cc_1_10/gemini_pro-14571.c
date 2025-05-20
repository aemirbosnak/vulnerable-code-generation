//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data point structure
typedef struct {
  double x;
  double y;
} Point;

// Cluster structure
typedef struct {
  Point centroid;
  int num_points;
  Point* points;
} Cluster;

// Function to initialize a cluster
Cluster* init_cluster(Point centroid) {
  Cluster* cluster = malloc(sizeof(Cluster));
  cluster->centroid = centroid;
  cluster->num_points = 0;
  cluster->points = NULL;
  return cluster;
}

// Function to free a cluster
void free_cluster(Cluster* cluster) {
  free(cluster->points);
  free(cluster);
}

// Function to add a point to a cluster
void add_point_to_cluster(Cluster* cluster, Point point) {
  cluster->num_points++;
  cluster->points = realloc(cluster->points, cluster->num_points * sizeof(Point));
  cluster->points[cluster->num_points - 1] = point;
}

// Function to calculate the centroid of a cluster
Point calculate_centroid(Cluster* cluster) {
  double sum_x = 0;
  double sum_y = 0;
  for (int i = 0; i < cluster->num_points; i++) {
    sum_x += cluster->points[i].x;
    sum_y += cluster->points[i].y;
  }
  Point centroid = {sum_x / cluster->num_points, sum_y / cluster->num_points};
  return centroid;
}

// Function to assign points to clusters
void assign_points_to_clusters(Cluster* clusters, int num_clusters, Point* points, int num_points) {
  for (int i = 0; i < num_points; i++) {
    double min_distance = INFINITY;
    int closest_cluster_index = -1;
    for (int j = 0; j < num_clusters; j++) {
      double distance = sqrt(pow(points[i].x - clusters[j].centroid.x, 2) + pow(points[i].y - clusters[j].centroid.y, 2));
      if (distance < min_distance) {
        min_distance = distance;
        closest_cluster_index = j;
      }
    }
    add_point_to_cluster(&clusters[closest_cluster_index], points[i]);
  }
}

// Function to update the centroids of clusters
void update_centroids(Cluster* clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    clusters[i].centroid = calculate_centroid(&clusters[i]);
  }
}

// Function to perform k-means clustering
Cluster* k_means_clustering(Point* points, int num_points, int num_clusters) {
  // Initialize clusters
  Cluster* clusters = malloc(num_clusters * sizeof(Cluster));
  for (int i = 0; i < num_clusters; i++) {
    clusters[i] = *init_cluster(points[i]);
  }

  // Assign points to clusters
  assign_points_to_clusters(clusters, num_clusters, points, num_points);

  // Update centroids
  update_centroids(clusters, num_clusters);

  // Repeat until convergence
  int max_iterations = 100;
  int iteration = 0;
  while (iteration < max_iterations) {
    // Assign points to clusters
    assign_points_to_clusters(clusters, num_clusters, points, num_points);

    // Update centroids
    update_centroids(clusters, num_clusters);

    iteration++;
  }

  return clusters;
}

// Function to print the clusters
void print_clusters(Cluster* clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i);
    for (int j = 0; j < clusters[i].num_points; j++) {
      printf("(%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
    }
    printf("\n");
  }
}

int main() {
  // Data points
  Point points[] = {{1.0, 1.0}, {1.5, 2.0}, {3.0, 4.0}, {5.0, 7.0}, {3.5, 5.0}, {4.5, 6.0}, {2.0, 3.0}};
  int num_points = sizeof(points) / sizeof(points[0]);

  // Number of clusters
  int num_clusters = 3;

  // Perform k-means clustering
  Cluster* clusters = k_means_clustering(points, num_points, num_clusters);

  // Print the clusters
  print_clusters(clusters, num_clusters);

  // Free the clusters
  for (int i = 0; i < num_clusters; i++) {
    free_cluster(&clusters[i]);
  }
  free(clusters);

  return 0;
}