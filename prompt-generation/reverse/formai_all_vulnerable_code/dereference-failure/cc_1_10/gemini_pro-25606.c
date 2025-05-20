//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
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
    point* points;
} cluster;

// Function to calculate the distance between two points
double distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to create a new cluster
cluster* create_cluster(point centroid) {
    cluster* new_cluster = malloc(sizeof(cluster));
    new_cluster->centroid = centroid;
    new_cluster->num_points = 0;
    new_cluster->points = NULL;
    return new_cluster;
}

// Function to add a point to a cluster
void add_point_to_cluster(cluster* c, point p) {
    c->num_points++;
    c->points = realloc(c->points, c->num_points * sizeof(point));
    c->points[c->num_points - 1] = p;
}

// Function to calculate the centroid of a cluster
point calculate_centroid(cluster* c) {
    point centroid = {0, 0};
    for (int i = 0; i < c->num_points; i++) {
        centroid.x += c->points[i].x;
        centroid.y += c->points[i].y;
    }
    centroid.x /= c->num_points;
    centroid.y /= c->num_points;
    return centroid;
}

// Function to perform k-means clustering
void k_means(point* points, int num_points, int num_clusters) {
    // Create k clusters
    cluster** clusters = malloc(num_clusters * sizeof(cluster*));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = create_cluster(points[i]);
    }

    // Assign each point to the nearest cluster
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double dist = distance(points[i], clusters[j]->centroid);
            if (dist < min_distance) {
                min_distance = dist;
                closest_cluster = j;
            }
        }
        add_point_to_cluster(clusters[closest_cluster], points[i]);
    }

    // Update the centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
        clusters[i]->centroid = calculate_centroid(clusters[i]);
    }

    // Repeat the previous two steps until the centroids no longer change
    int num_iterations = 0;
    while (1) {
        int changed = 0;
        for (int i = 0; i < num_clusters; i++) {
            point old_centroid = clusters[i]->centroid;
            clusters[i]->centroid = calculate_centroid(clusters[i]);
            if (distance(old_centroid, clusters[i]->centroid) > 0.001) {
                changed = 1;
            }
        }
        num_iterations++;
        if (!changed) {
            break;
        }
    }

    // Print the final clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i]->num_points; j++) {
            printf("(%f, %f)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i]);
    }
    free(clusters);
}

int main() {
    // Create a set of data points
    point points[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    int num_points = sizeof(points) / sizeof(points[0]);

    // Perform k-means clustering with k = 2
    k_means(points, num_points, 2);

    return 0;
}