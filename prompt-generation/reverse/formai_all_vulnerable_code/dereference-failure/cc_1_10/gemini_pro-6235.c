//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point struct
typedef struct {
  double x;
  double y;
} DataPoint;

// Define the cluster struct
typedef struct {
  DataPoint* points;
  int num_points;
} Cluster;

// Create a new data point
DataPoint* create_data_point(double x, double y) {
  DataPoint* point = malloc(sizeof(DataPoint));
  point->x = x;
  point->y = y;
  return point;
}

// Create a new cluster
Cluster* create_cluster() {
  Cluster* cluster = malloc(sizeof(Cluster));
  cluster->points = NULL;
  cluster->num_points = 0;
  return cluster;
}

// Add a data point to a cluster
void add_data_point_to_cluster(Cluster* cluster, DataPoint* point) {
  cluster->points = realloc(cluster->points, (cluster->num_points + 1) * sizeof(DataPoint));
  cluster->points[cluster->num_points] = *point;
  cluster->num_points++;
}

// Calculate the distance between two data points
double distance_between_points(DataPoint* point1, DataPoint* point2) {
  return sqrt(pow(point1->x - point2->x, 2) + pow(point1->y - point2->y, 2));
}

// Calculate the centroid of a cluster
DataPoint* calculate_centroid(Cluster* cluster) {
  double sum_x = 0;
  double sum_y = 0;
  for (int i = 0; i < cluster->num_points; i++) {
    sum_x += cluster->points[i].x;
    sum_y += cluster->points[i].y;
  }
  return create_data_point(sum_x / cluster->num_points, sum_y / cluster->num_points);
}

// Assign a data point to the closest cluster
Cluster* assign_data_point_to_cluster(DataPoint* point, Cluster** clusters, int num_clusters) {
  double min_distance = INFINITY;
  Cluster* closest_cluster = NULL;
  for (int i = 0; i < num_clusters; i++) {
    double distance = distance_between_points(point, calculate_centroid(clusters[i]));
    if (distance < min_distance) {
      min_distance = distance;
      closest_cluster = clusters[i];
    }
  }
  return closest_cluster;
}

// Perform k-means clustering
Cluster** k_means_clustering(DataPoint* points, int num_points, int num_clusters) {
  // Initialize the clusters
  Cluster** clusters = malloc(num_clusters * sizeof(Cluster*));
  for (int i = 0; i < num_clusters; i++) {
    clusters[i] = create_cluster();
  }

  // Assign the data points to the clusters
  for (int i = 0; i < num_points; i++) {
    Cluster* closest_cluster = assign_data_point_to_cluster(points + i, clusters, num_clusters);
    add_data_point_to_cluster(closest_cluster, points + i);
  }

  // Update the cluster centroids
  for (int i = 0; i < num_clusters; i++) {
    free(clusters[i]->points);
    clusters[i]->points = calculate_centroid(clusters[i]);
  }

  // Repeat the assignment and update steps until the clusters no longer change
  int converged = 0;
  while (!converged) {
    converged = 1;
    for (int i = 0; i < num_points; i++) {
      Cluster* closest_cluster = assign_data_point_to_cluster(points + i, clusters, num_clusters);
      if (closest_cluster != assign_data_point_to_cluster(points + i, clusters, num_clusters)) {
        converged = 0;
      }
    }
    if (!converged) {
      for (int i = 0; i < num_clusters; i++) {
        free(clusters[i]->points);
        clusters[i]->points = calculate_centroid(clusters[i]);
      }
    }
  }

  return clusters;
}

// Print the clusters
void print_clusters(Cluster** clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i + 1);
    for (int j = 0; j < clusters[i]->num_points; j++) {
      printf("  (%f, %f)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
    }
  }
}

int main() {
  // Generate some data points
  DataPoint points[] = {
    {1, 2},
    {3, 4},
    {5, 6},
    {7, 8},
    {9, 10},
    {11, 12},
    {13, 14},
    {15, 16},
    {17, 18},
    {19, 20},
  };
  int num_points = sizeof(points) / sizeof(points[0]);

  // Perform k-means clustering with k = 3
  int num_clusters = 3;
  Cluster** clusters = k_means_clustering(points, num_points, num_clusters);

  // Print the clusters
  print_clusters(clusters, num_clusters);

  // Free the clusters
  for (int i = 0; i < num_clusters; i++) {
    free(clusters[i]->points);
    free(clusters[i]);
  }
  free(clusters);

  return 0;
}