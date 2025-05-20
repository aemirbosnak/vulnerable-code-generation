//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare the structure of a point
typedef struct point {
  double x;
  double y;
} point;

// Declare the structure of a cluster
typedef struct cluster {
  point *points;
  int num_points;
} cluster;

// Create a new point
point *new_point(double x, double y) {
  point *p = (point *)malloc(sizeof(point));
  p->x = x;
  p->y = y;
  return p;
}

// Create a new cluster
cluster *new_cluster() {
  cluster *c = (cluster *)malloc(sizeof(cluster));
  c->points = NULL;
  c->num_points = 0;
  return c;
}

// Add a point to a cluster
void add_point_to_cluster(cluster *c, point *p) {
  c->points = (point *)realloc(c->points, (c->num_points + 1) * sizeof(point));
  c->points[c->num_points] = *p;
  c->num_points++;
}

// Calculate the distance between two points
double distance(point *p1, point *p2) {
  return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

// Find the closest cluster to a point
cluster *find_closest_cluster(point *p, cluster *clusters, int num_clusters) {
  double min_distance = INFINITY;
  cluster *closest_cluster = NULL;
  for (int i = 0; i < num_clusters; i++) {
    double distance_to_cluster = distance(p, &clusters[i].points[0]);
    if (distance_to_cluster < min_distance) {
      min_distance = distance_to_cluster;
      closest_cluster = &clusters[i];
    }
  }
  return closest_cluster;
}

// Assign points to clusters
void assign_points_to_clusters(point *points, int num_points, cluster *clusters, int num_clusters) {
  for (int i = 0; i < num_points; i++) {
    cluster *closest_cluster = find_closest_cluster(&points[i], clusters, num_clusters);
    add_point_to_cluster(closest_cluster, &points[i]);
  }
}

// Update the centroids of the clusters
void update_centroids(cluster *clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    double sum_x = 0;
    double sum_y = 0;
    for (int j = 0; j < clusters[i].num_points; j++) {
      sum_x += clusters[i].points[j].x;
      sum_y += clusters[i].points[j].y;
    }
    clusters[i].points[0].x = sum_x / clusters[i].num_points;
    clusters[i].points[0].y = sum_y / clusters[i].num_points;
  }
}

// Perform k-means clustering
void k_means(point *points, int num_points, int num_clusters) {
  // Initialize the clusters
  cluster *clusters = (cluster *)malloc(num_clusters * sizeof(cluster));
  for (int i = 0; i < num_clusters; i++) {
    clusters[i] = *new_cluster();
    clusters[i].points = (point *)malloc(sizeof(point));
    clusters[i].points[0] = points[i];
    clusters[i].num_points = 1;
  }

  // Assign points to clusters
  assign_points_to_clusters(points, num_points, clusters, num_clusters);

  // Update the centroids of the clusters
  update_centroids(clusters, num_clusters);

  // Repeat the previous two steps until the centroids no longer change
  int converged = 0;
  while (!converged) {
    // Assign points to clusters
    assign_points_to_clusters(points, num_points, clusters, num_clusters);

    // Update the centroids of the clusters
    update_centroids(clusters, num_clusters);

    // Check if the centroids have converged
    converged = 1;
    for (int i = 0; i < num_clusters; i++) {
      if (distance(&clusters[i].points[0], &clusters[i].points[0]) > 0.001) {
        converged = 0;
        break;
      }
    }
  }

  // Print the clusters
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i);
    for (int j = 0; j < clusters[i].num_points; j++) {
      printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
    }
    printf("\n");
  }

  // Free the memory allocated for the clusters
  for (int i = 0; i < num_clusters; i++) {
    free(clusters[i].points);
    free(&clusters[i]);
  }
  free(clusters);
}

int main() {
  // Define the points
  point points[] = {
    {0, 0},
    {1, 0},
    {2, 0},
    {3, 0},
    {4, 0},
    {0, 1},
    {1, 1},
    {2, 1},
    {3, 1},
    {4, 1},
    {0, 2},
    {1, 2},
    {2, 2},
    {3, 2},
    {4, 2},
    {0, 3},
    {1, 3},
    {2, 3},
    {3, 3},
    {4, 3}
  };
  int num_points = sizeof(points) / sizeof(points[0]);

  // Perform k-means clustering
  k_means(points, num_points, 5);

  return 0;
}