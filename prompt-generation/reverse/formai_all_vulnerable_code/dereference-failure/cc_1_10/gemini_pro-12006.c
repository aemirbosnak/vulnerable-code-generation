//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
// C Clustering Algorithm Implementation

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data structures
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Cluster;

// Function prototypes
Cluster *create_cluster(int num_points);
void add_point_to_cluster(Cluster *cluster, Point point);
double distance_between_points(Point point1, Point point2);
void print_cluster(Cluster *cluster);

// Main function
int main() {
    // Create a cluster with 4 points
    Cluster *cluster = create_cluster(4);

    // Add points to the cluster
    add_point_to_cluster(cluster, (Point){0, 0});
    add_point_to_cluster(cluster, (Point){1, 0});
    add_point_to_cluster(cluster, (Point){0, 1});
    add_point_to_cluster(cluster, (Point){1, 1});

    // Print the cluster
    print_cluster(cluster);

    return 0;
}

// Function to create a cluster with a specified number of points
Cluster *create_cluster(int num_points) {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->points = malloc(sizeof(Point) * num_points);
    cluster->num_points = num_points;
    return cluster;
}

// Function to add a point to a cluster
void add_point_to_cluster(Cluster *cluster, Point point) {
    cluster->points[cluster->num_points] = point;
    cluster->num_points++;
}

// Function to calculate the distance between two points
double distance_between_points(Point point1, Point point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

// Function to print a cluster
void print_cluster(Cluster *cluster) {
    for (int i = 0; i < cluster->num_points; i++) {
        printf("(%d, %d)\n", cluster->points[i].x, cluster->points[i].y);
    }
}