//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point structure
typedef struct {
    double x;
    double y;
} point;

// Define the cluster structure
typedef struct {
    point centroid;
    int num_points;
    point* points;
} cluster;

// Function to initialize a cluster
cluster* init_cluster(point centroid, int num_points) {
    cluster* c = (cluster*)malloc(sizeof(cluster));
    c->centroid = centroid;
    c->num_points = num_points;
    c->points = (point*)malloc(num_points * sizeof(point));
    return c;
}

// Function to free a cluster
void free_cluster(cluster* c) {
    free(c->points);
    free(c);
}

// Function to add a point to a cluster
void add_point_to_cluster(cluster* c, point p) {
    c->points[c->num_points] = p;
    c->num_points++;
}

// Function to calculate the distance between two points
double distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to calculate the centroid of a cluster
point calculate_centroid(cluster* c) {
    point centroid;
    centroid.x = 0;
    centroid.y = 0;
    for (int i = 0; i < c->num_points; i++) {
        centroid.x += c->points[i].x;
        centroid.y += c->points[i].y;
    }
    centroid.x /= c->num_points;
    centroid.y /= c->num_points;
    return centroid;
}

// Function to assign points to clusters
void assign_points_to_clusters(cluster* clusters, int num_clusters, point* points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance_to_cluster = distance(points[i], clusters[j].centroid);
            if (distance_to_cluster < min_distance) {
                min_distance = distance_to_cluster;
                closest_cluster = j;
            }
        }
        add_point_to_cluster(&clusters[closest_cluster], points[i]);
    }
}

// Function to update the centroids of the clusters
void update_centroids(cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid = calculate_centroid(&clusters[i]);
    }
}

// Function to perform k-means clustering
cluster* k_means(point* points, int num_points, int num_clusters) {
    // Initialize the clusters
    cluster* clusters = (cluster*)malloc(num_clusters * sizeof(cluster));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *init_cluster(points[i], 0);
    }

    // Assign points to clusters
    assign_points_to_clusters(clusters, num_clusters, points, num_points);

    // Update the centroids of the clusters
    update_centroids(clusters, num_clusters);

    // Repeat the previous two steps until the centroids no longer change
    int num_iterations = 0;
    while (num_iterations < 100) {
        assign_points_to_clusters(clusters, num_clusters, points, num_points);
        update_centroids(clusters, num_clusters);
        num_iterations++;
    }

    return clusters;
}

// Function to print the clusters
void print_clusters(cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the data points
    point points[] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12},
        {13, 14},
        {15, 16},
        {17, 18},
        {19, 20}
    };
    int num_points = sizeof(points) / sizeof(points[0]);

    // Perform k-means clustering
    cluster* clusters = k_means(points, num_points, 3);

    // Print the clusters
    print_clusters(clusters, 3);

    // Free the clusters
    for (int i = 0; i < 3; i++) {
        free_cluster(&clusters[i]);
    }
    free(clusters);

    return 0;
}