//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data point structure
typedef struct point {
    double x;
    double y;
} point;

// Cluster structure
typedef struct cluster {
    point centroid;
    int num_points;
    point *points;
} cluster;

// Function to initialize a data point
point init_point(double x, double y) {
    point p;
    p.x = x;
    p.y = y;
    return p;
}

// Function to initialize a cluster
cluster init_cluster(point centroid, int num_points, point *points) {
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
int assign_cluster(point p, cluster *clusters, int num_clusters) {
    int min_cluster = 0;
    double min_distance = distance(p, clusters[0].centroid);
    for (int i = 1; i < num_clusters; i++) {
        double dist = distance(p, clusters[i].centroid);
        if (dist < min_distance) {
            min_cluster = i;
            min_distance = dist;
        }
    }
    return min_cluster;
}

// Function to update the centroid of a cluster
point update_centroid(cluster *c) {
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 0; i < c->num_points; i++) {
        sum_x += c->points[i].x;
        sum_y += c->points[i].y;
    }
    point new_centroid;
    new_centroid.x = sum_x / c->num_points;
    new_centroid.y = sum_y / c->num_points;
    return new_centroid;
}

// Function to perform k-means clustering
void k_means(point *data, int num_data, int num_clusters) {
    // Initialize clusters
    cluster *clusters = malloc(num_clusters * sizeof(cluster));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = init_cluster(data[i], 0, NULL);
    }

    // Iterate until convergence
    int converged = 0;
    while (!converged) {
        // Assign data points to clusters
        for (int i = 0; i < num_data; i++) {
            int cluster_index = assign_cluster(data[i], clusters, num_clusters);
            clusters[cluster_index].num_points++;
            clusters[cluster_index].points = realloc(clusters[cluster_index].points, clusters[cluster_index].num_points * sizeof(point));
            clusters[cluster_index].points[clusters[cluster_index].num_points - 1] = data[i];
        }

        // Update cluster centroids
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].centroid = update_centroid(&clusters[i]);
        }

        // Check for convergence
        converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            if (distance(clusters[i].centroid, update_centroid(&clusters[i])) > 0.001) {
                converged = 0;
            }
        }
    }

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
}

int main() {
    // Sample data
    point data[] = {
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
    int num_data = sizeof(data) / sizeof(data[0]);

    // Number of clusters
    int num_clusters = 3;

    // Perform k-means clustering
    k_means(data, num_data, num_clusters);

    return 0;
}