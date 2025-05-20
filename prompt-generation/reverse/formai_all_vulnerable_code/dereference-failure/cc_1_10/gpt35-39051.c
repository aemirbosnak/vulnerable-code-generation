//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 5
#define MAX_ITERATIONS 100

// Struct for holding point coordinates
typedef struct {
    double x;
    double y;
} Point;

// Struct for holding cluster data
typedef struct {
    Point centroid;
    Point* points;
    int num_points;
} Cluster;

// Function to calculate Euclidean distance between two points
double euclidean_distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to initialize clusters with random centroids
void initialize_clusters(Point* points, Cluster* clusters, int num_clusters, int num_points) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = (double)rand() / RAND_MAX * 10;
        clusters[i].centroid.y = (double)rand() / RAND_MAX * 10;
        clusters[i].points = (Point*)malloc(num_points * sizeof(Point));
        clusters[i].num_points = 0;
    }
    for (int i = 0; i < num_points; i++) {
        int random_cluster = rand() % num_clusters;
        clusters[random_cluster].points[clusters[random_cluster].num_points] = points[i];
        clusters[random_cluster].num_points++;
    }
}

// Function to update cluster centroids to average position of all points in the cluster
void update_centroids(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        double avg_x = 0;
        double avg_y = 0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            avg_x += clusters[i].points[j].x;
            avg_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = avg_x / clusters[i].num_points;
        clusters[i].centroid.y = avg_y / clusters[i].num_points;
    }
}

// Function to assign points to their nearest cluster
void assign_points(Point* points, Cluster* clusters, int num_clusters, int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster_index = 0;
        for (int j = 0; j < num_clusters; j++) {
            double distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster_index = j;
            }
        }
        clusters[closest_cluster_index].points[clusters[closest_cluster_index].num_points] = points[i];
        clusters[closest_cluster_index].num_points++;
    }
}

// Function to perform k-means clustering algorithm
void k_means_clustering(Point* points, Cluster* clusters, int num_clusters, int num_points) {
    int iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        assign_points(points, clusters, num_clusters, num_points);
        update_centroids(clusters, num_clusters);
        iteration++;
    }
}

int main() {
    Point points[MAX_POINTS] = {{2.0, 3.0}, {3.0, 2.0}, {3.0, 4.0}, {4.0, 3.0}, {10.0, 14.0}, {11.0, 13.0}, {12.0, 14.0}, {13.0, 13.0}, {14.0, 11.0}, {14.0, 13.0}};
    Cluster clusters[MAX_CLUSTERS];
    int num_points = 10;
    int num_clusters = 3;

    initialize_clusters(points, clusters, num_clusters, num_points);
    k_means_clustering(points, clusters, num_clusters, num_points);

    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%lf, %lf) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    return 0;
}