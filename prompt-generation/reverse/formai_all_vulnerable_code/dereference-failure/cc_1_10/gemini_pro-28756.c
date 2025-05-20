//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data point struct
typedef struct point {
    double x;
    double y;
} point;

// Cluster struct
typedef struct cluster {
    point centroid;
    int num_points;
    point* points;
} cluster;

// Function to initialize a data point
point init_point(double x, double y) {
    point p;
    p.x = x;
    p.y = y;
    return p;
}

// Function to initialize a cluster
cluster init_cluster(point centroid, int num_points, point* points) {
    cluster c;
    c.centroid = centroid;
    c.num_points = num_points;
    c.points = points;
    return c;
}

// Function to calculate the distance between two points
double distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to assign a data point to a cluster
int assign_cluster(point p, cluster* clusters, int num_clusters) {
    int closest_cluster_index = -1;
    double closest_distance = INFINITY;
    for (int i = 0; i < num_clusters; i++) {
        double d = distance(p, clusters[i].centroid);
        if (d < closest_distance) {
            closest_distance = d;
            closest_cluster_index = i;
        }
    }
    return closest_cluster_index;
}

// Function to update the centroid of a cluster
void update_centroid(cluster* c) {
    double x_sum = 0;
    double y_sum = 0;
    for (int i = 0; i < c->num_points; i++) {
        x_sum += c->points[i].x;
        y_sum += c->points[i].y;
    }
    c->centroid.x = x_sum / c->num_points;
    c->centroid.y = y_sum / c->num_points;
}

// Function to perform k-means clustering
cluster* k_means(point* points, int num_points, int num_clusters) {
    // Initialize clusters
    cluster* clusters = malloc(num_clusters * sizeof(cluster));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = init_cluster(points[i], 0, NULL);
    }

    // Assign data points to clusters
    for (int i = 0; i < num_points; i++) {
        int cluster_index = assign_cluster(points[i], clusters, num_clusters);
        clusters[cluster_index].num_points++;
        clusters[cluster_index].points = realloc(clusters[cluster_index].points, clusters[cluster_index].num_points * sizeof(point));
        clusters[cluster_index].points[clusters[cluster_index].num_points - 1] = points[i];
    }

    // Update cluster centroids
    for (int i = 0; i < num_clusters; i++) {
        update_centroid(&clusters[i]);
    }

    // Repeat assignment and centroid update until convergence
    int converged = 0;
    while (!converged) {
        converged = 1;
        for (int i = 0; i < num_points; i++) {
            int old_cluster_index = assign_cluster(points[i], clusters, num_clusters);
            int new_cluster_index = assign_cluster(points[i], clusters, num_clusters);
            if (old_cluster_index != new_cluster_index) {
                converged = 0;
                break;
            }
        }
        if (!converged) {
            for (int i = 0; i < num_clusters; i++) {
                update_centroid(&clusters[i]);
            }
        }
    }

    return clusters;
}

// Function to print the clusters
void print_clusters(cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("  Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("  Number of points: %d\n", clusters[i].num_points);
        printf("  Points:\n");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("    (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

// Main function
int main() {
    // Initialize data points
    point points[] = {
        init_point(1, 2),
        init_point(3, 4),
        init_point(5, 6),
        init_point(7, 8),
        init_point(9, 10),
        init_point(11, 12),
        init_point(13, 14),
        init_point(15, 16),
        init_point(17, 18),
        init_point(19, 20)
    };

    // Perform k-means clustering
    cluster* clusters = k_means(points, 10, 3);

    // Print the clusters
    print_clusters(clusters, 3);

    // Free memory
    for (int i = 0; i < 3; i++) {
        free(clusters[i].points);
    }
    free(clusters);

    return 0;
}