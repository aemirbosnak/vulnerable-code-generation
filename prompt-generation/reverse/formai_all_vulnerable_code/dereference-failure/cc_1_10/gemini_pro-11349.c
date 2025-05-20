//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data point structure
typedef struct {
    double x;
    double y;
} Point;

// Cluster structure
typedef struct {
    Point centroid;
    int num_points;
    Point* points;
} Cluster;

// Function to create a new cluster
Cluster* create_cluster(Point centroid) {
    Cluster* cluster = (Cluster*)malloc(sizeof(Cluster));
    cluster->centroid = centroid;
    cluster->num_points = 0;
    cluster->points = NULL;
    return cluster;
}

// Function to add a point to a cluster
void add_point_to_cluster(Cluster* cluster, Point point) {
    cluster->num_points++;
    cluster->points = (Point*)realloc(cluster->points, cluster->num_points * sizeof(Point));
    cluster->points[cluster->num_points - 1] = point;
}

// Function to calculate the distance between two points
double distance(Point point1, Point point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

// Function to calculate the centroid of a cluster
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

// Function to assign points to clusters
void assign_points_to_clusters(Cluster** clusters, int num_clusters, Point* points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance_to_cluster = distance(points[i], clusters[j]->centroid);
            if (distance_to_cluster < min_distance) {
                min_distance = distance_to_cluster;
                closest_cluster = j;
            }
        }
        add_point_to_cluster(clusters[closest_cluster], points[i]);
    }
}

// Function to update the centroids of clusters
void update_centroids(Cluster** clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i]->centroid = calculate_centroid(clusters[i]);
    }
}

// Function to perform clustering
void clustering(Point* points, int num_points, int num_clusters) {
    // Create clusters
    Cluster** clusters = (Cluster**)malloc(num_clusters * sizeof(Cluster*));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = create_cluster(points[i]);
    }

    // Assign points to clusters
    assign_points_to_clusters(clusters, num_clusters, points, num_points);

    // Update centroids of clusters
    update_centroids(clusters, num_clusters);

    // Repeat steps 2 and 3 until convergence
    int num_iterations = 0;
    while (num_iterations < 100) {
        // Assign points to clusters
        assign_points_to_clusters(clusters, num_clusters, points, num_points);

        // Update centroids of clusters
        update_centroids(clusters, num_clusters);

        num_iterations++;
    }

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        for (int j = 0; j < clusters[i]->num_points; j++) {
            printf("(%f, %f)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i]->points);
        free(clusters[i]);
    }
    free(clusters);
}

int main() {
    // Define the points
    Point points[] = {
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

    // Define the number of points
    int num_points = sizeof(points) / sizeof(points[0]);

    // Define the number of clusters
    int num_clusters = 3;

    // Perform clustering
    clustering(points, num_points, num_clusters);

    return 0;
}