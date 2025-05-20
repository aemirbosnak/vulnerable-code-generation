//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTERS 10
#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    int num_points;
    Point *points;
} Cluster;

// Function to create a new cluster
Cluster *create_cluster(int num_points) {
    Cluster *cluster = (Cluster *)malloc(sizeof(Cluster));
    cluster->num_points = num_points;
    cluster->points = (Point *)malloc(num_points * sizeof(Point));
    return cluster;
}

// Function to free a cluster
void free_cluster(Cluster *cluster) {
    free(cluster->points);
    free(cluster);
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

// Function to find the closest cluster to a point
Cluster *find_closest_cluster(Point point, Cluster *clusters, int num_clusters) {
    double min_distance = INFINITY;
    Cluster *closest_cluster = NULL;
    for (int i = 0; i < num_clusters; i++) {
        double distance = distance_between_points(point, clusters[i].points[0]);
        if (distance < min_distance) {
            min_distance = distance;
            closest_cluster = &clusters[i];
        }
    }
    return closest_cluster;
}

// Function to perform k-means clustering
Cluster *k_means_clustering(Point *points, int num_points, int num_clusters) {
    // Create clusters
    Cluster *clusters = (Cluster *)malloc(num_clusters * sizeof(Cluster));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *create_cluster(1);
        clusters[i].points[0] = points[i];
    }

    // Assign points to clusters
    for (int i = 0; i < num_points; i++) {
        Cluster *closest_cluster = find_closest_cluster(points[i], clusters, num_clusters);
        add_point_to_cluster(closest_cluster, points[i]);
    }

    // Update cluster centroids
    for (int i = 0; i < num_clusters; i++) {
        double sum_x = 0;
        double sum_y = 0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].points[0].x = sum_x / clusters[i].num_points;
        clusters[i].points[0].y = sum_y / clusters[i].num_points;
    }

    // Repeat until convergence
    int num_iterations = 0;
    while (num_iterations < 100) {
        // Assign points to clusters
        for (int i = 0; i < num_points; i++) {
            Cluster *closest_cluster = find_closest_cluster(points[i], clusters, num_clusters);
            add_point_to_cluster(closest_cluster, points[i]);
        }

        // Update cluster centroids
        for (int i = 0; i < num_clusters; i++) {
            double sum_x = 0;
            double sum_y = 0;
            for (int j = 0; j < clusters[i].num_points; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            clusters[i].points[0].x = sum_x / clusters[i].num_points;
            clusters[i].points[0].y = sum_y / clusters[i].num_points;
        }

        num_iterations++;
    }

    return clusters;
}

// Function to print a cluster
void print_cluster(Cluster cluster) {
    printf("Cluster: ");
    for (int i = 0; i < cluster.num_points; i++) {
        printf("(%.2f, %.2f) ", cluster.points[i].x, cluster.points[i].y);
    }
    printf("\n");
}

// Function to print all clusters
void print_clusters(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        print_cluster(clusters[i]);
    }
}

int main() {
    // Create points
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
        {19, 20},
    };
    int num_points = 10;

    // Perform k-means clustering
    int num_clusters = 3;
    Cluster *clusters = k_means_clustering(points, num_points, num_clusters);

    // Print clusters
    print_clusters(clusters, num_clusters);

    // Free clusters
    for (int i = 0; i < num_clusters; i++) {
        free_cluster(&clusters[i]);
    }
    free(clusters);

    return 0;
}