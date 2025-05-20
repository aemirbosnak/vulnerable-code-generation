//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct Cluster {
    Point centroid;
    int num_points;
    Point* points;
} Cluster;

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    // Generate some random points
    int num_points = 100;
    Point* points = malloc(sizeof(Point) * num_points);
    for (int i = 0; i < num_points; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    // Initialize the clusters
    int num_clusters = 3;
    Cluster* clusters = malloc(sizeof(Cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = rand() % 100;
        clusters[i].centroid.y = rand() % 100;
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }

    // Assign each point to its closest cluster
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            int closest_cluster = -1;
            for (int j = 0; j < num_clusters; j++) {
                double d = distance(points[i], clusters[j].centroid);
                if (d < min_distance) {
                    min_distance = d;
                    closest_cluster = j;
                }
            }

            if (closest_cluster != -1) {
                // Reassign the point to the closest cluster
                clusters[closest_cluster].num_points++;
                clusters[closest_cluster].points = realloc(clusters[closest_cluster].points, sizeof(Point) * clusters[closest_cluster].num_points);
                clusters[closest_cluster].points[clusters[closest_cluster].num_points - 1] = points[i];
                changed = true;
            }
        }

        // Update the centroids of the clusters
        for (int i = 0; i < num_clusters; i++) {
            double sum_x = 0;
            double sum_y = 0;
            for (int j = 0; j < clusters[i].num_points; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            clusters[i].centroid.x = sum_x / clusters[i].num_points;
            clusters[i].centroid.y = sum_y / clusters[i].num_points;
        }
    }

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("  (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    // Free the memory
    free(points);
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
    return 0;
}