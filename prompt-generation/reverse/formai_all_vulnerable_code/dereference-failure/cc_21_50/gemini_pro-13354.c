//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x;
  double y;
} point;

typedef struct {
  double centroid_x;
  double centroid_y;
  int num_points;
} cluster;

int main() {
  // Generate some random points
  int num_points = 100;
  point *points = malloc(num_points * sizeof(point));
  for (int i = 0; i < num_points; i++) {
    points[i].x = (double)rand() / RAND_MAX;
    points[i].y = (double)rand() / RAND_MAX;
  }

  // Initialize the clusters
  int num_clusters = 3;
  cluster *clusters = malloc(num_clusters * sizeof(cluster));
  for (int i = 0; i < num_clusters; i++) {
    clusters[i].centroid_x = (double)rand() / RAND_MAX;
    clusters[i].centroid_y = (double)rand() / RAND_MAX;
    clusters[i].num_points = 0;
  }

  // Assign each point to a cluster
  for (int i = 0; i < num_points; i++) {
    double min_distance = INFINITY;
    int min_cluster = -1;
    for (int j = 0; j < num_clusters; j++) {
      double distance = sqrt(pow(points[i].x - clusters[j].centroid_x, 2) +
                              pow(points[i].y - clusters[j].centroid_y, 2));
      if (distance < min_distance) {
        min_distance = distance;
        min_cluster = j;
      }
    }
    clusters[min_cluster].num_points++;
  }

  // Update the centroids of the clusters
  for (int i = 0; i < num_clusters; i++) {
    clusters[i].centroid_x = 0;
    clusters[i].centroid_y = 0;
    for (int j = 0; j < num_points; j++) {
      if (points[j].x == clusters[i].centroid_x &&
          points[j].y == clusters[i].centroid_y) {
        clusters[i].centroid_x += points[j].x;
        clusters[i].centroid_y += points[j].y;
      }
    }
    clusters[i].centroid_x /= clusters[i].num_points;
    clusters[i].centroid_y /= clusters[i].num_points;
  }

  // Repeat the previous two steps until the centroids no longer change
  int num_iterations = 0;
  while (1) {
    int changed = 0;
    for (int i = 0; i < num_points; i++) {
      double min_distance = INFINITY;
      int min_cluster = -1;
      for (int j = 0; j < num_clusters; j++) {
        double distance = sqrt(pow(points[i].x - clusters[j].centroid_x, 2) +
                                pow(points[i].y - clusters[j].centroid_y, 2));
        if (distance < min_distance) {
          min_distance = distance;
          min_cluster = j;
        }
      }
      if (min_cluster != clusters[i].num_points) {
        changed = 1;
        break;
      }
    }
    if (!changed) {
      break;
    }

    for (int i = 0; i < num_clusters; i++) {
      clusters[i].centroid_x = 0;
      clusters[i].centroid_y = 0;
      clusters[i].num_points = 0;
    }

    for (int i = 0; i < num_points; i++) {
      double min_distance = INFINITY;
      int min_cluster = -1;
      for (int j = 0; j < num_clusters; j++) {
        double distance = sqrt(pow(points[i].x - clusters[j].centroid_x, 2) +
                                pow(points[i].y - clusters[j].centroid_y, 2));
        if (distance < min_distance) {
          min_distance = distance;
          min_cluster = j;
        }
      }
      clusters[min_cluster].num_points++;
    }

    for (int i = 0; i < num_clusters; i++) {
      clusters[i].centroid_x = 0;
      clusters[i].centroid_y = 0;
      for (int j = 0; j < num_points; j++) {
        if (points[j].x == clusters[i].centroid_x &&
            points[j].y == clusters[i].centroid_y) {
          clusters[i].centroid_x += points[j].x;
          clusters[i].centroid_y += points[j].y;
        }
      }
      clusters[i].centroid_x /= clusters[i].num_points;
      clusters[i].centroid_y /= clusters[i].num_points;
    }

    num_iterations++;
  }

  // Print the final clusters
  for (int i = 0; i < num_clusters; i++) {
    printf("Cluster %d: %d points, centroid (%f, %f)\n", i, clusters[i].num_points,
           clusters[i].centroid_x, clusters[i].centroid_y);
  }

  // Free the allocated memory
  free(points);
  free(clusters);

  return 0;
}