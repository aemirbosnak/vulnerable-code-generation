//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: futuristic
// Welcome to the Neon City of Clusters!

// In this futuristic metropolis of data, we harness the power of clustering algorithms to unveil hidden patterns lurking within the shadows.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
  double x;
  double y;
} Point;

typedef struct Cluster {
  Point centroid;
  int num_points;
  Point* points;
} Cluster;

// Function to calculate the Euclidean distance between two points
double distance(Point* p1, Point* p2) {
  return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

// Function to initialize a cluster with a given centroid
Cluster* create_cluster(Point* centroid) {
  Cluster* cluster = malloc(sizeof(Cluster));
  cluster->centroid = *centroid;
  cluster->num_points = 0;
  cluster->points = NULL;
  return cluster;
}

// Function to add a point to a cluster
void add_point_to_cluster(Cluster* cluster, Point* point) {
  // Resize the cluster's points array if necessary
  if (cluster->num_points == 0) {
    cluster->points = malloc(sizeof(Point));
  } else {
    cluster->points = realloc(cluster->points, (cluster->num_points + 1) * sizeof(Point));
  }

  // Add the point to the array
  cluster->points[cluster->num_points] = *point;
  cluster->num_points++;
}

// Function to calculate the centroid of a cluster
void calculate_centroid(Cluster* cluster) {
  double sum_x = 0;
  double sum_y = 0;

  for (int i = 0; i < cluster->num_points; i++) {
    sum_x += cluster->points[i].x;
    sum_y += cluster->points[i].y;
  }

  cluster->centroid.x = sum_x / cluster->num_points;
  cluster->centroid.y = sum_y / cluster->num_points;
}

// Function to perform k-means clustering on a set of points
Cluster** k_means(Point* points, int num_points, int k) {
  // Initialize k random centroids
  Cluster** clusters = malloc(k * sizeof(Cluster*));
  int idxs[k];
  for (int i = 0; i < k; i++) {
    idxs[i] = rand() % num_points;
    clusters[i] = create_cluster(&points[idxs[i]]);
  }

  // Iteratively assign points to clusters and update centroids
  int iter;
  int num_iters = 100;
  for (iter = 0; iter < num_iters; iter++) {
    // Assign each point to its closest cluster
    for (int i = 0; i < num_points; i++) {
      double min_distance = distance(&points[i], &clusters[0]->centroid);
      int closest_cluster = 0;

      for (int j = 1; j < k; j++) {
        double dist = distance(&points[i], &clusters[j]->centroid);
        if (dist < min_distance) {
          min_distance = dist;
          closest_cluster = j;
        }
      }

      add_point_to_cluster(clusters[closest_cluster], &points[i]);
    }

    // Update the centroids of each cluster
    for (int i = 0; i < k; i++) {
      calculate_centroid(clusters[i]);
    }
  }

  // Return the clusters
  return clusters;
}

// Function to print out the clusters
void print_clusters(Cluster** clusters, int k) {
  for (int i = 0; i < k; i++) {
    printf("Cluster %d:\n", i);
    printf("Centroid: (%lf, %lf)\n", clusters[i]->centroid.x, clusters[i]->centroid.y);
    printf("Number of points: %d\n", clusters[i]->num_points);
    printf("Points:\n");
    for (int j = 0; j < clusters[i]->num_points; j++) {
      printf("  (%lf, %lf)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
    }
    printf("\n");
  }
}

// Main function to test the k-means algorithm
int main() {
  // Generate a set of random points
  int num_points = 100;
  Point* points = malloc(num_points * sizeof(Point));
  for (int i = 0; i < num_points; i++) {
    points[i].x = rand() % 100;
    points[i].y = rand() % 100;
  }

  // Perform k-means clustering on the points
  int k = 3;
  Cluster** clusters = k_means(points, num_points, k);

  // Print out the clusters
  print_clusters(clusters, k);

  // Free the memory allocated for the clusters
  for (int i = 0; i < k; i++) {
    free(clusters[i]->points);
    free(clusters[i]);
  }
  free(clusters);

  // Free the memory allocated for the points
  free(points);

  return 0;
}