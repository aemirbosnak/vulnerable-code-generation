//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data structure to represent a point in n-dimensional space
typedef struct Point {
    int n;
    double *coords;
} Point;

// Data structure to represent a cluster
typedef struct Cluster {
    int n_points;
    Point *points;
    Point centroid;
} Cluster;

// Function to create a new point
Point *new_point(int n) {
    Point *point = malloc(sizeof(Point));
    point->n = n;
    point->coords = malloc(sizeof(double) * n);
    return point;
}

// Function to create a new cluster
Cluster *new_cluster(int n) {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->n_points = 0;
    cluster->points = NULL;
    cluster->centroid = *new_point(n);
    return cluster;
}

// Function to add a point to a cluster
void add_point(Cluster *cluster, Point *point) {
    cluster->n_points++;
    cluster->points = realloc(cluster->points, sizeof(Point) * cluster->n_points);
    cluster->points[cluster->n_points - 1] = *point;
}

// Function to calculate the distance between two points
double distance(Point *p1, Point *p2) {
    double sum = 0;
    for (int i = 0; i < p1->n; i++) {
        sum += pow(p1->coords[i] - p2->coords[i], 2);
    }
    return sqrt(sum);
}

// Function to calculate the centroid of a cluster
void calculate_centroid(Cluster *cluster) {
    for (int i = 0; i < cluster->centroid.n; i++) {
        cluster->centroid.coords[i] = 0;
        for (int j = 0; j < cluster->n_points; j++) {
            cluster->centroid.coords[i] += cluster->points[j].coords[i];
        }
        cluster->centroid.coords[i] /= cluster->n_points;
    }
}

// Function to assign points to clusters
void assign_points(Cluster *clusters, Point *points, int n_points, int n_clusters) {
    for (int i = 0; i < n_points; i++) {
        double min_distance = INFINITY;
        int min_cluster = -1;
        for (int j = 0; j < n_clusters; j++) {
            double distance_to_centroid = distance(&points[i], &clusters[j].centroid);
            if (distance_to_centroid < min_distance) {
                min_distance = distance_to_centroid;
                min_cluster = j;
            }
        }
        add_point(&clusters[min_cluster], &points[i]);
    }
}

// Function to perform k-means clustering
void k_means(Point *points, int n_points, int n_clusters) {
    // Create clusters
    Cluster *clusters = malloc(sizeof(Cluster) * n_clusters);
    for (int i = 0; i < n_clusters; i++) {
        clusters[i] = *new_cluster(points[i].n);
    }

    // Initialize clusters with random points
    for (int i = 0; i < n_clusters; i++) {
        add_point(&clusters[i], &points[rand() % n_points]);
    }

    // Iterate until convergence
    int max_iterations = 100;
    int iteration = 0;
    while (iteration < max_iterations) {
        // Assign points to clusters
        assign_points(clusters, points, n_points, n_clusters);

        // Calculate centroids of clusters
        for (int i = 0; i < n_clusters; i++) {
            calculate_centroid(&clusters[i]);
        }

        iteration++;
    }

    // Print clusters
    for (int i = 0; i < n_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        for (int j = 0; j < clusters[i].n_points; j++) {
            for (int k = 0; k < clusters[i].points[j].n; k++) {
                printf("%lf ", clusters[i].points[j].coords[k]);
            }
            printf("\n");
        }
    }

    // Free memory
    for (int i = 0; i < n_clusters; i++) {
        free(clusters[i].points);
        free(&clusters[i]);
    }
    free(clusters);
}

int main() {
    // Generate some random points
    int n_points = 100;
    int n_clusters = 3;
    int n_dimensions = 2;
    Point *points = malloc(sizeof(Point) * n_points);
    for (int i = 0; i < n_points; i++) {
        points[i] = *new_point(n_dimensions);
        for (int j = 0; j < n_dimensions; j++) {
            points[i].coords[j] = rand() % 100;
        }
    }

    // Perform k-means clustering
    k_means(points, n_points, n_clusters);

    // Free memory
    for (int i = 0; i < n_points; i++) {
        free(points[i].coords);
        free(&points[i]);
    }
    free(points);

    return 0;
}