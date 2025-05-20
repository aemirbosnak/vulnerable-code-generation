//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.0001 // This is the convergence bound for clustering.

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  int num_points;
  Point *points;
  Point centroid;
} Cluster;

double distance(Point p1, Point p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx*dx + dy*dy);
}

Cluster *create_cluster(int num_points) {
  Cluster *cluster = malloc(sizeof(Cluster));
  cluster->num_points = num_points;
  cluster->points = malloc(num_points * sizeof(Point));
  return cluster;
}

void free_cluster(Cluster *cluster) {
  free(cluster->points);
  free(cluster);
}

void random_init_cluster(Cluster *cluster) {
  int i;
  for (i = 0; i < cluster->num_points; i++) {
    cluster->points[i].x = (double) rand() / RAND_MAX;
    cluster->points[i].y = (double) rand() / RAND_MAX;
  }
}

void compute_centroid(Cluster *cluster) {
  int i;
  double sum_x = 0;
  double sum_y = 0;
  for (i = 0; i < cluster->num_points; i++) {
    sum_x += cluster->points[i].x;
    sum_y += cluster->points[i].y;
  }
  cluster->centroid.x = sum_x / cluster->num_points;
  cluster->centroid.y = sum_y / cluster->num_points;
}

double update_cluster(Cluster *cluster, Cluster *clusters, int num_clusters) {
  int i, j;
  double min_distance = INFINITY;
  double sum_distance = 0;
  for (i = 0; i < num_clusters; i++) {
    double d = distance(cluster->centroid, clusters[i].centroid);
    if (d < min_distance) {
      min_distance = d;
    }
  }
  for (i = 0; i < cluster->num_points; i++) {
    double min_d = INFINITY;
    for (j = 0; j < num_clusters; j++) {
      double d = distance(cluster->points[i], clusters[j].centroid);
      if (d < min_d) {
        min_d = d;
      }
    }
    sum_distance += min_d;
  }
  compute_centroid(cluster);
  return sum_distance;
}

int main() {
  int num_points = 1000;
  int num_clusters = 10;
  int max_iterations = 100;
  int i, j;
  Cluster *clusters = malloc(num_clusters * sizeof(Cluster));
  for (i = 0; i < num_clusters; i++) {
    clusters[i] = *create_cluster(num_points / num_clusters);
    random_init_cluster(&clusters[i]);
  }
  double prev_distance;
  double curr_distance = INFINITY;
  for (i = 0; i < max_iterations && fabs(curr_distance - prev_distance) > EPSILON; i++) {
    prev_distance = curr_distance;
    curr_distance = 0;
    for (j = 0; j < num_clusters; j++) {
      curr_distance += update_cluster(&clusters[j], clusters, num_clusters);
    }
    printf("Iteration %d: distance = %lf\n", i, curr_distance);
  }
  for (i = 0; i < num_clusters; i++) {
    free_cluster(&clusters[i]);
  }
  free(clusters);
  return 0;
}