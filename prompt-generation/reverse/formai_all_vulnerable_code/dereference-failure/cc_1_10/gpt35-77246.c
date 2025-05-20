//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLUSTERS 10
#define MAX_POINTS 50

typedef struct point {
    int x;
    int y;
} Point;

typedef struct cluster {
    Point centroid;
    Point points[MAX_POINTS];
    int num_points;
} Cluster;

int distance(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
    // Initialize clusters and points
    Cluster clusters[MAX_CLUSTERS];
    Point points[MAX_POINTS];
    int num_clusters = 0;
    int num_points = 0;

    // Read in input
    FILE *fp = fopen("input.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, ",");
        Point p;
        p.x = atoi(token);
        token = strtok(NULL, ",");
        p.y = atoi(token);
        points[num_points] = p;
        num_points++;
    }

    // Randomly assign initial centroids
    for (int i = 0; i < MAX_CLUSTERS; i++) {
        int rand_index = rand() % num_points;
        clusters[i].centroid = points[rand_index];
        num_clusters++;
    }

    // Cluster points
    int num_iterations = 0;
    while (num_iterations < 10) {
        // Reset points in each cluster
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].num_points = 0;
        }

        // Assign points to cluster with closest centroid
        for (int i = 0; i < num_points; i++) {
            int min_distance = distance(points[i], clusters[0].centroid);
            int cluster_index = 0;
            for (int j = 1; j < num_clusters; j++) {
                int d = distance(points[i], clusters[j].centroid);
                if (d < min_distance) {
                    min_distance = d;
                    cluster_index = j;
                }
            }
            clusters[cluster_index].points[clusters[cluster_index].num_points] = points[i];
            clusters[cluster_index].num_points++;
        }

        // Recalculate centroid of each cluster
        for (int i = 0; i < num_clusters; i++) {
            int sum_x = 0;
            int sum_y = 0;
            for (int j = 0; j < clusters[i].num_points; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            clusters[i].centroid.x = sum_x / clusters[i].num_points;
            clusters[i].centroid.y = sum_y / clusters[i].num_points;
        }

        num_iterations++;
    }

    // Print results
    printf("Clusters:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%d,%d) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    return 0;
}