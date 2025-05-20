//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data structure to represent a point in n-dimensional space
typedef struct Point {
    double *coordinates;
    int n;
} Point;

// Data structure to represent a cluster
typedef struct Cluster {
    Point *centroid;
    int n;
    Point **points;
} Cluster;

// Function to create a new point
Point *new_point(int n) {
    Point *point = malloc(sizeof(Point));
    point->coordinates = malloc(n * sizeof(double));
    point->n = n;
    return point;
}

// Function to create a new cluster
Cluster *new_cluster(int n) {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->centroid = new_point(n);
    cluster->n = 0;
    cluster->points = malloc(100 * sizeof(Point *));
    return cluster;
}

// Function to add a point to a cluster
void add_point_to_cluster(Cluster *cluster, Point *point) {
    cluster->points[cluster->n] = point;
    cluster->n++;
}

// Function to calculate the distance between two points using euclidian distance formula
double distance(Point *point1, Point *point2) {
    double sum = 0;
    for (int i = 0; i < point1->n; i++) {
        sum += pow(point1->coordinates[i] - point2->coordinates[i], 2);
    }
    return sqrt(sum);
}

// Function to find the closest cluster to a point
Cluster *find_closest_cluster(Point *point, Cluster **clusters, int k) {
    double min_distance = INFINITY;
    Cluster *closest_cluster = NULL;
    for (int i = 0; i < k; i++) {
        double distance_to_cluster = distance(point, clusters[i]->centroid);
        if (distance_to_cluster < min_distance) {
            min_distance = distance_to_cluster;
            closest_cluster = clusters[i];
        }
    }
    return closest_cluster;
}

// Function to calculate the centroid of a cluster
void calculate_centroid(Cluster *cluster) {
    for (int i = 0; i < cluster->n; i++) {
        for (int j = 0; j < cluster->centroid->n; j++) {
            cluster->centroid->coordinates[j] += cluster->points[i]->coordinates[j];
        }
    }
    for (int j = 0; j < cluster->centroid->n; j++) {
        cluster->centroid->coordinates[j] /= cluster->n;
    }
}

// Function to perform k-means clustering
void k_means(Point **points, int n, int k) {
    // Initialize k clusters
    Cluster **clusters = malloc(k * sizeof(Cluster *));
    for (int i = 0; i < k; i++) {
        clusters[i] = new_cluster(points[0]->n);
        for (int j = 0; j < points[0]->n; j++) {
            clusters[i]->centroid->coordinates[j] = points[rand() % n]->coordinates[j];
        }
    }

    // Iterate until the clusters are stable
    int iterations = 0;
    while (iterations < 100) {
        // Assign each point to the closest cluster
        for (int i = 0; i < n; i++) {
            Cluster *closest_cluster = find_closest_cluster(points[i], clusters, k);
            add_point_to_cluster(closest_cluster, points[i]);
        }

        // Calculate the new centroids of the clusters
        for (int i = 0; i < k; i++) {
            calculate_centroid(clusters[i]);
        }

        iterations++;
    }

    // Print the clusters
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i]->n; j++) {
            for (int k = 0; k < clusters[i]->points[j]->n; k++) {
                printf("%f ", clusters[i]->points[j]->coordinates[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    // Initialize the points
    int n = 100;
    Point **points = malloc(n * sizeof(Point *));
    for (int i = 0; i < n; i++) {
        points[i] = new_point(2);
        for (int j = 0; j < 2; j++) {
            points[i]->coordinates[j] = rand() % 100;
        }
    }

    // Perform k-means clustering
    int k = 3;
    k_means(points, n, k);

    return 0;
}