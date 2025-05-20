//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A point in the 2D plane
typedef struct Point {
    double x;
    double y;
} Point;

// A cluster of points
typedef struct Cluster {
    int size;
    Point* points;
    Point centroid;
} Cluster;

// Function to create a new point
Point* create_point(double x, double y) {
    Point* point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

// Function to create a new cluster
Cluster* create_cluster(int size) {
    Cluster* cluster = malloc(sizeof(Cluster));
    cluster->size = size;
    cluster->points = malloc(size * sizeof(Point));
    return cluster;
}

// Function to calculate the distance between two points
double distance(Point* point1, Point* point2) {
    return sqrt(pow(point1->x - point2->x, 2) + pow(point1->y - point2->y, 2));
}

// Function to assign a point to a cluster
void assign_point_to_cluster(Point* point, Cluster* cluster) {
    cluster->points[cluster->size++] = *point;
}

// Function to calculate the centroid of a cluster
void calculate_centroid(Cluster* cluster) {
    for (int i = 0; i < cluster->size; i++) {
        cluster->centroid.x += cluster->points[i].x;
        cluster->centroid.y += cluster->points[i].y;
    }
    cluster->centroid.x /= cluster->size;
    cluster->centroid.y /= cluster->size;
}

// Function to perform k-means clustering
Cluster** k_means(Point* points, int num_points, int num_clusters) {
    // Create an array of clusters
    Cluster** clusters = malloc(num_clusters * sizeof(Cluster*));

    // Initialize the clusters
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = create_cluster(num_points);
    }

    // Assign the points to the clusters
    for (int i = 0; i < num_points; i++) {
        // Find the closest cluster
        double min_distance = INFINITY;
        int min_cluster_index = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance_to_cluster = distance(&points[i], &clusters[j]->centroid);
            if (distance_to_cluster < min_distance) {
                min_distance = distance_to_cluster;
                min_cluster_index = j;
            }
        }

        // Assign the point to the closest cluster
        assign_point_to_cluster(&points[i], clusters[min_cluster_index]);
    }

    // Calculate the centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
        calculate_centroid(clusters[i]);
    }

    return clusters;
}

// Function to print the results of the clustering
void print_clusters(Cluster** clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i]->size; j++) {
            printf("(%f, %f)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create an array of points
    Point points[] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10}
    };
    int num_points = sizeof(points) / sizeof(Point);

    // Perform k-means clustering
    Cluster** clusters = k_means(points, num_points, 2);

    // Print the results of the clustering
    print_clusters(clusters, 2);

    // Free the memory allocated for the clusters
    for (int i = 0; i < 2; i++) {
        free(clusters[i]->points);
        free(clusters[i]);
    }
    free(clusters);

    return 0;
}