//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helpers
#define sqr(x) ((x) * (x))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

// Data structure to represent a point
typedef struct Point {
  double x;
  double y;
} Point;

// Data structure to represent a cluster
typedef struct Cluster {
  Point centroid;
  int num_points;
  Point* points;
} Cluster;

// Function to initialize a point
Point point(double x, double y) {
  Point p = {x, y};
  return p;
}

// Function to initialize a cluster
Cluster cluster(Point centroid, int num_points, Point* points) {
  Cluster c = {centroid, num_points, points};
  return c;
}

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
  return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

// Function to assign a point to the nearest cluster
Cluster* assign_point(Point p, Cluster* clusters, int num_clusters) {
  double min_dist = INFINITY;
  Cluster* min_cluster = NULL;
  for (int i = 0; i < num_clusters; i++) {
    double dist = distance(p, clusters[i].centroid);
    if (dist < min_dist) {
      min_dist = dist;
      min_cluster = &clusters[i];
    }
  }
  return min_cluster;
}

// Function to update the centroid of a cluster
void update_centroid(Cluster* cluster) {
  double x = 0, y = 0;
  for (int i = 0; i < cluster->num_points; i++) {
    x += cluster->points[i].x;
    y += cluster->points[i].y;
  }
  cluster->centroid.x = x / cluster->num_points;
  cluster->centroid.y = y / cluster->num_points;
}

// Function to perform k-means clustering
Cluster* k_means(Point* points, int num_points, int num_clusters) {
  // Initialize clusters
  Cluster* clusters = (Cluster*)malloc(sizeof(Cluster) * num_clusters);
  for (int i = 0; i < num_clusters; i++) {
    clusters[i] = cluster(points[i], 1, &points[i]);
  }

  // Iterate until convergence
  int converged = 0;
  while (!converged) {
    converged = 1;

    // Assign points to clusters
    for (int i = 0; i < num_points; i++) {
      Cluster* cluster = assign_point(points[i], clusters, num_clusters);
      if (cluster != NULL) {
        converged = 0;
        cluster->num_points++;
        cluster->points = (Point*)realloc(cluster->points, sizeof(Point) * cluster->num_points);
        cluster->points[cluster->num_points - 1] = points[i];
      }
    }

    // Update cluster centroids
    for (int i = 0; i < num_clusters; i++) {
      update_centroid(&clusters[i]);
    }
  }

  // Return clusters
  return clusters;
}

// Function to print clusters
void print_clusters(Cluster* clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i + 1);
    printf("  Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
    printf("  Number of points: %d\n", clusters[i].num_points);
    printf("  Points:\n");
    for (int j = 0; j < clusters[i].num_points; j++) {
      printf("    (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Initialize points
  Point points[] = {
    point(1, 2),
    point(3, 4),
    point(5, 6),
    point(7, 8),
    point(9, 10),
    point(11, 12),
    point(13, 14),
    point(15, 16),
    point(17, 18),
    point(19, 20),
  };
  int num_points = sizeof(points) / sizeof(points[0]);

  // Perform k-means clustering
  int num_clusters = 3;
  Cluster* clusters = k_means(points, num_points, num_clusters);

  // Print clusters
  print_clusters(clusters, num_clusters);

  // Free memory
  for (int i = 0; i < num_clusters; i++) {
    free(clusters[i].points);
  }
  free(clusters);

  return 0;
}