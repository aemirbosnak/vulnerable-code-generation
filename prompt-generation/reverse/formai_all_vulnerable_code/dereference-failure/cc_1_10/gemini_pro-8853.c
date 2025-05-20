//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point structure
typedef struct {
    double x;
    double y;
} Point;

// Define the cluster structure
typedef struct {
    Point *points;
    int num_points;
} Cluster;

// Function to create a new cluster
Cluster *create_cluster(void) {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->points = NULL;
    cluster->num_points = 0;
    return cluster;
}

// Function to add a point to a cluster
void add_point_to_cluster(Cluster *cluster, Point point) {
    cluster->points = realloc(cluster->points, (cluster->num_points + 1) * sizeof(Point));
    cluster->points[cluster->num_points] = point;
    cluster->num_points++;
}

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to calculate the centroid of a cluster
Point centroid(Cluster *cluster) {
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
void assign_points_to_clusters(Cluster *clusters, Point *points, int num_points, int num_clusters) {
    // Calculate the centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].points = realloc(clusters[i].points, num_points * sizeof(Point));
        clusters[i].num_points = 0;
    }
    for (int i = 0; i < num_points; i++) {
        // Find the cluster with the closest centroid
        int closest_cluster = 0;
        double closest_distance = distance(points[i], centroid(&clusters[0]));
        for (int j = 1; j < num_clusters; j++) {
            double distance_to_centroid = distance(points[i], centroid(&clusters[j]));
            if (distance_to_centroid < closest_distance) {
                closest_cluster = j;
                closest_distance = distance_to_centroid;
            }
        }
        // Add the point to the closest cluster
        add_point_to_cluster(&clusters[closest_cluster], points[i]);
    }
}

// Function to update the centroids of the clusters
void update_centroids(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].points = realloc(clusters[i].points, clusters[i].num_points * sizeof(Point));
        clusters[i].num_points = 0;
    }
    for (int i = 0; i < num_clusters; i++) {
        // Calculate the new centroid of the cluster
        Point new_centroid = centroid(&clusters[i]);
        // Update the centroid of the cluster
        clusters[i].points[0] = new_centroid;
    }
}

// Function to print the clusters
void print_clusters(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

// Main function
int main(void) {
    // Create a set of points
    Point points[] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10}
    };
    int num_points = sizeof(points) / sizeof(points[0]);

    // Create a set of clusters
    Cluster clusters[] = {
        create_cluster(),
        create_cluster(),
        create_cluster()
    };
    int num_clusters = sizeof(clusters) / sizeof(clusters[0]);

    // Assign points to clusters
    assign_points_to_clusters(clusters, points, num_points, num_clusters);

    // Update the centroids of the clusters
    update_centroids(clusters, num_clusters);

    // Print the clusters
    print_clusters(clusters, num_clusters);

    return 0;
}