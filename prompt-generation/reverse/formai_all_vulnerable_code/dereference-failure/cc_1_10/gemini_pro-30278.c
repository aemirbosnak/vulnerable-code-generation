//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point struct
typedef struct {
    double x;
    double y;
} Point;

// Define the cluster struct
typedef struct {
    Point centroid;
    int num_points;
    Point* points;
} Cluster;

// Create a new point
Point* new_point(double x, double y) {
    Point* point = (Point*)malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

// Create a new cluster
Cluster* new_cluster(Point centroid) {
    Cluster* cluster = (Cluster*)malloc(sizeof(Cluster));
    cluster->centroid = centroid;
    cluster->num_points = 0;
    cluster->points = NULL;
    return cluster;
}

// Add a point to a cluster
void add_point_to_cluster(Cluster* cluster, Point* point) {
    cluster->num_points++;
    cluster->points = (Point*)realloc(cluster->points, cluster->num_points * sizeof(Point));
    cluster->points[cluster->num_points - 1] = *point;
}

// Calculate the distance between two points
double distance(Point* point1, Point* point2) {
    return sqrt(pow(point1->x - point2->x, 2) + pow(point1->y - point2->y, 2));
}

// Calculate the centroid of a cluster
Point calculate_centroid(Cluster* cluster) {
    Point centroid;
    centroid.x = 0;
    centroid.y = 0;
    for (int i = 0; i < cluster->num_points; i++) {
        centroid.x += cluster->points[i].x;
        centroid.y += cluster->points[i].y;
    }
    centroid.x /= cluster->num_points;
    centroid.y /= cluster->num_points;
    return centroid;
}

// Assign points to clusters
void assign_points_to_clusters(Cluster* clusters, int num_clusters, Point* points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance_to_centroid = distance(&points[i], &clusters[j].centroid);
            if (distance_to_centroid < min_distance) {
                min_distance = distance_to_centroid;
                closest_cluster = j;
            }
        }
        add_point_to_cluster(&clusters[closest_cluster], &points[i]);
    }
}

// Update the centroids of the clusters
void update_centroids(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid = calculate_centroid(&clusters[i]);
    }
}

// Perform k-means clustering
void k_means(Point* points, int num_points, int num_clusters, int max_iterations) {
    // Initialize the clusters
    Cluster* clusters = (Cluster*)malloc(num_clusters * sizeof(Cluster));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *new_cluster(*new_point(rand() % 100, rand() % 100));
    }

    // Assign points to clusters
    assign_points_to_clusters(clusters, num_clusters, points, num_points);

    // Update the centroids of the clusters
    update_centroids(clusters, num_clusters);

    // Repeat until convergence
    int iteration = 0;
    while (iteration < max_iterations) {
        // Assign points to clusters
        assign_points_to_clusters(clusters, num_clusters, points, num_points);

        // Update the centroids of the clusters
        update_centroids(clusters, num_clusters);

        iteration++;
    }

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf(" (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
        free(&clusters[i]);
    }
    free(clusters);
}

int main() {
    // Generate some random points
    int num_points = 100;
    Point* points = (Point*)malloc(num_points * sizeof(Point));
    for (int i = 0; i < num_points; i++) {
        points[i] = *new_point(rand() % 100, rand() % 100);
    }

    // Perform k-means clustering
    int num_clusters = 3;
    int max_iterations = 10;
    k_means(points, num_points, num_clusters, max_iterations);

    // Free the memory
    free(points);

    return 0;
}