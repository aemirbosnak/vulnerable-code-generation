//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x;
  double y;
} point;

typedef struct {
  point *points;
  int num_points;
} cluster;

double distance(point *a, point *b) {
  return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

cluster *new_cluster(point *points, int num_points) {
  cluster *c = malloc(sizeof(cluster));
  c->points = points;
  c->num_points = num_points;
  return c;
}

void free_cluster(cluster *c) {
  free(c->points);
  free(c);
}

cluster *kmeans(point *points, int num_points, int num_clusters) {
  // Initialize the clusters.
  cluster *clusters = malloc(sizeof(cluster) * num_clusters);
  for (int i = 0; i < num_clusters; i++) {
    clusters[i] = *new_cluster(&points[i * num_points / num_clusters], num_points / num_clusters);
  }

  // Iterate until the clusters converge.
  int converged = 0;
  while (!converged) {
    // Assign each point to the closest cluster.
    for (int i = 0; i < num_points; i++) {
      double min_distance = INFINITY;
      int min_cluster = -1;
      for (int j = 0; j < num_clusters; j++) {
        double distance_to_cluster = distance(&points[i], &clusters[j].points[0]);
        if (distance_to_cluster < min_distance) {
          min_distance = distance_to_cluster;
          min_cluster = j;
        }
      }
      clusters[min_cluster].points[clusters[min_cluster].num_points++] = points[i];
    }

    // Update the centroids of the clusters.
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

    // Check if the clusters have converged.
    converged = 1;
    for (int i = 0; i < num_clusters; i++) {
      if (distance(&clusters[i].points[0], &clusters[i].points[clusters[i].num_points - 1]) > 0.01) {
        converged = 0;
        break;
      }
    }
  }

  return clusters;
}

void print_clusters(cluster *clusters, int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d:\n", i);
    for (int j = 0; j < clusters[i].num_points; j++) {
      printf("  (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
    }
  }
}

int main() {
  // Generate some random points.
  int num_points = 100;
  point *points = malloc(sizeof(point) * num_points);
  for (int i = 0; i < num_points; i++) {
    points[i].x = rand() % 100;
    points[i].y = rand() % 100;
  }

  // Perform k-means clustering.
  int num_clusters = 3;
  cluster *clusters = kmeans(points, num_points, num_clusters);

  // Print the clusters.
  print_clusters(clusters, num_clusters);

  // Free the clusters.
  for (int i = 0; i < num_clusters; i++) {
    free_cluster(&clusters[i]);
  }
  free(clusters);

  // Free the points.
  free(points);

  return 0;
}