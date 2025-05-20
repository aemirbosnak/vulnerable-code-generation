//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: complete
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
    int num_points;
    Point *points;
    Point centroid;
} Cluster;

// Function to create a new point
Point *new_point(double x, double y) {
    Point *p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

// Function to create a new cluster
Cluster *new_cluster(int num_points, Point *points) {
    Cluster *c = malloc(sizeof(Cluster));
    c->num_points = num_points;
    c->points = points;
    c->centroid.x = 0;
    c->centroid.y = 0;
    return c;
}

// Function to calculate the distance between two points
double distance(Point *a, Point *b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

// Function to calculate the centroid of a cluster
void calculate_centroid(Cluster *c) {
    for (int i = 0; i < c->num_points; i++) {
        c->centroid.x += c->points[i].x;
        c->centroid.y += c->points[i].y;
    }
    c->centroid.x /= c->num_points;
    c->centroid.y /= c->num_points;
}

// Function to assign points to clusters
void assign_points(Cluster *clusters, int num_clusters, int num_points, Point *points) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int min_cluster_index = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance_to_centroid = distance(&points[i], &clusters[j].centroid);
            if (distance_to_centroid < min_distance) {
                min_distance = distance_to_centroid;
                min_cluster_index = j;
            }
        }
        clusters[min_cluster_index].points[clusters[min_cluster_index].num_points++] = points[i];
    }
}

// Function to perform k-means clustering
void k_means(int num_clusters, int num_points, Point *points) {
    // Create clusters
    Cluster *clusters = malloc(sizeof(Cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *new_cluster(0, NULL);
    }

    // Randomly assign points to clusters
    for (int i = 0; i < num_points; i++) {
        int cluster_index = rand() % num_clusters;
        clusters[cluster_index].points[clusters[cluster_index].num_points++] = points[i];
    }

    // Iterate until clusters do not change
    int iterations = 0;
    while (iterations < 100) {
        // Calculate centroids
        for (int i = 0; i < num_clusters; i++) {
            calculate_centroid(&clusters[i]);
        }

        // Assign points to clusters
        assign_points(clusters, num_clusters, num_points, points);

        // Check if clusters have changed
        int changed = 0;
        for (int i = 0; i < num_clusters; i++) {
            if (clusters[i].num_points != clusters[i].num_points) {
                changed = 1;
                break;
            }
        }

        if (!changed) {
            break;
        }

        iterations++;
    }

    // Print clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("  (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    // Free memory
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
        free(&clusters[i]);
    }
    free(clusters);
}

int main() {
    // Create points
    int num_points = 10;
    Point points[] = {
        *new_point(1, 2),
        *new_point(3, 4),
        *new_point(5, 6),
        *new_point(7, 8),
        *new_point(9, 10),
        *new_point(11, 12),
        *new_point(13, 14),
        *new_point(15, 16),
        *new_point(17, 18),
        *new_point(19, 20)
    };

    // Perform k-means clustering
    int num_clusters = 3;
    k_means(num_clusters, num_points, points);

    return 0;
}