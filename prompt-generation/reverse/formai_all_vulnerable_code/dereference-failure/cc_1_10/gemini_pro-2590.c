//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data structure for a point
typedef struct {
  double x;
  double y;
} Point;

// Define the data structure for a cluster
typedef struct {
  Point centroid;
  int num_points;
  Point* points;
} Cluster;

// Function to create a new point
Point* create_point(double x, double y) {
  Point* point = malloc(sizeof(Point));
  point->x = x;
  point->y = y;
  return point;
}

// Function to create a new cluster
Cluster* create_cluster(Point centroid, int num_points, Point* points) {
  Cluster* cluster = malloc(sizeof(Cluster));
  cluster->centroid = centroid;
  cluster->num_points = num_points;
  cluster->points = points;
  return cluster;
}

// Function to calculate the distance between two points
double distance(Point a, Point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to assign a point to a cluster
void assign_point_to_cluster(Point* point, Cluster* cluster) {
  double min_distance = distance(*point, cluster->centroid);
  for (int i = 0; i < cluster->num_points; i++) {
    double distance_to_point = distance(*point, cluster->points[i]);
    if (distance_to_point < min_distance) {
      min_distance = distance_to_point;
      cluster->centroid = cluster->points[i];
    }
  }
  cluster->num_points++;
}

// Function to calculate the centroid of a cluster
Point calculate_centroid(Cluster* cluster) {
  Point centroid = {0, 0};
  for (int i = 0; i < cluster->num_points; i++) {
    centroid.x += cluster->points[i].x;
    centroid.y += cluster->points[i].y;
  }
  centroid.x /= cluster->num_points;
  centroid.y /= cluster->num_points;
  return centroid;
}

// Function to perform k-means clustering
void k_means(Point* points, int num_points, int num_clusters) {
  // Create the initial clusters
  Cluster* clusters[num_clusters];
  for (int i = 0; i < num_clusters; i++) {
    clusters[i] = create_cluster(points[i], 1, &points[i]);
  }

  // Iterate until the clusters are stable
  int stable = 0;
  while (!stable) {
    // Assign each point to the closest cluster
    for (int i = 0; i < num_points; i++) {
      assign_point_to_cluster(&points[i], clusters);
    }

    // Calculate the new centroids for each cluster
    for (int i = 0; i < num_clusters; i++) {
      clusters[i]->centroid = calculate_centroid(clusters[i]);
    }

    // Check if the clusters are stable
    stable = 1;
    for (int i = 0; i < num_clusters; i++) {
      if (distance(clusters[i]->centroid, clusters[i]->points[0]) > 0.01) {
        stable = 0;
        break;
      }
    }
  }

  // Print the final clusters
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i);
    for (int j = 0; j < clusters[i]->num_points; j++) {
      printf("  (%f, %f)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
    }
  }
}

// Main function
int main() {
  // Create the data points
  Point points[] = {
    {1, 2},
    {3, 4},
    {5, 6},
    {7, 8},
    {9, 10},
  };

  // Perform k-means clustering with 3 clusters
  k_means(points, 5, 3);

  return 0;
}