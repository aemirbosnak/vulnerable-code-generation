//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point structure
typedef struct {
  double x;
  double y;
} point;

// Define the cluster structure
typedef struct {
  point centroid;
  int num_points;
  point* points;
} cluster;

// Function to initialize a cluster
cluster* init_cluster(point centroid, int num_points) {
  cluster* c = malloc(sizeof(cluster));
  c->centroid = centroid;
  c->num_points = num_points;
  c->points = malloc(sizeof(point) * num_points);
  return c;
}

// Function to free a cluster
void free_cluster(cluster* c) {
  free(c->points);
  free(c);
}

// Function to calculate the distance between two points
double distance(point p1, point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to assign a point to a cluster
void assign_point(point p, cluster* c) {
  double min_distance = distance(p, c->centroid);
  int min_cluster = -1;
  for (int i = 0; i < c->num_points; i++) {
    double distance_to_point = distance(p, c->points[i]);
    if (distance_to_point < min_distance) {
      min_distance = distance_to_point;
      min_cluster = i;
    }
  }
  c->points[min_cluster] = p;
}

// Function to update the centroid of a cluster
void update_centroid(cluster* c) {
  double x = 0;
  double y = 0;
  for (int i = 0; i < c->num_points; i++) {
    x += c->points[i].x;
    y += c->points[i].y;
  }
  c->centroid.x = x / c->num_points;
  c->centroid.y = y / c->num_points;
}

// Function to perform k-means clustering
cluster** k_means(point* points, int num_points, int num_clusters) {
  // Initialize the clusters
  cluster** clusters = malloc(sizeof(cluster*) * num_clusters);
  for (int i = 0; i < num_clusters; i++) {
    clusters[i] = init_cluster(points[i], 0);
  }

  // Assign the points to the clusters
  for (int i = 0; i < num_points; i++) {
    assign_point(points[i], clusters[0]);
  }

  // Update the centroids of the clusters
  for (int i = 0; i < num_clusters; i++) {
    update_centroid(clusters[i]);
  }

  // Repeat the previous two steps until the centroids no longer change
  int num_iterations = 0;
  while (num_iterations < 100) {
    // Assign the points to the clusters
    for (int i = 0; i < num_points; i++) {
      assign_point(points[i], clusters[0]);
    }

    // Update the centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
      update_centroid(clusters[i]);
    }

    num_iterations++;
  }

  return clusters;
}

// Function to print the clusters
void print_clusters(cluster** clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i);
    for (int j = 0; j < clusters[i]->num_points; j++) {
      printf("(%f, %f)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
    }
  }
}

// Main function
int main() {
  // Create a set of data points
  point points[] = {
    {0.0, 0.0},
    {1.0, 1.0},
    {2.0, 2.0},
    {3.0, 3.0},
    {4.0, 4.0},
    {5.0, 5.0}
  };
  int num_points = sizeof(points) / sizeof(points[0]);

  // Perform k-means clustering
  cluster** clusters = k_means(points, num_points, 2);

  // Print the clusters
  print_clusters(clusters, 2);

  // Free the clusters
  for (int i = 0; i < 2; i++) {
    free_cluster(clusters[i]);
  }
  free(clusters);

  return 0;
}