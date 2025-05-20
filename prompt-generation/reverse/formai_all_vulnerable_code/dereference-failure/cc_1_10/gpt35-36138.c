//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_POINTS 10
#define NUM_CLUSTERS 2
#define DEBUG_MODE 1
#define THRESHOLD 0.001

typedef struct point {
    double x;
    double y;
    int cluster;
} point_t;

double distance(point_t p1, point_t p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    point_t *points;
    int i, j, k, l, m;
    double min_distance;
    int min_distance_cluster;
    double old_centroids_x[NUM_CLUSTERS];
    double old_centroids_y[NUM_CLUSTERS];
    double new_centroids_x[NUM_CLUSTERS];
    double new_centroids_y[NUM_CLUSTERS];
    int num_points_in_cluster[NUM_CLUSTERS];
    int num_iterations = 0;
    int num_points_changed_clusters;
    
    srand(time(NULL));

    points = (point_t *) malloc(MAX_NUM_POINTS * sizeof(point_t));

    printf("Initializing points...\n");
    for (i = 0; i < MAX_NUM_POINTS; i++) {
        points[i].x = (double) rand() / RAND_MAX;
        points[i].y = (double) rand() / RAND_MAX;
        points[i].cluster = rand() % NUM_CLUSTERS;
        if (DEBUG_MODE) {
            printf("Point %d: (%f, %f), Cluster %d\n", i, points[i].x, points[i].y, points[i].cluster);
        }
    }

    printf("\nBeginning clustering...\n\n");

    // Calculate initial centroids
    for (i = 0; i < NUM_CLUSTERS; i++) {
        new_centroids_x[i] = 0;
        new_centroids_y[i] = 0;
        num_points_in_cluster[i] = 0;
        for (j = 0; j < MAX_NUM_POINTS; j++) {
            if (points[j].cluster == i) {
                new_centroids_x[i] += points[j].x;
                new_centroids_y[i] += points[j].y;
                num_points_in_cluster[i]++;
            }
        }
        new_centroids_x[i] /= num_points_in_cluster[i];
        new_centroids_y[i] /= num_points_in_cluster[i];
    }

    // Run clustering iterations
    do {
        num_iterations++;
        num_points_changed_clusters = 0;

        // Save old centroids for comparison
        for (i = 0; i < NUM_CLUSTERS; i++) {
            old_centroids_x[i] = new_centroids_x[i];
            old_centroids_y[i] = new_centroids_y[i];
        }

        // Assign points to clusters
        for (i = 0; i < MAX_NUM_POINTS; i++) {
            min_distance = distance(points[i], (point_t) {new_centroids_x[0], new_centroids_y[0]});
            min_distance_cluster = 0;
            for (j = 1; j < NUM_CLUSTERS; j++) {
                if (distance(points[i], (point_t) {new_centroids_x[j], new_centroids_y[j]}) < min_distance) {
                    min_distance = distance(points[i], (point_t) {new_centroids_x[j], new_centroids_y[j]});
                    min_distance_cluster = j;
                }
            }
            if (points[i].cluster != min_distance_cluster) {
                points[i].cluster = min_distance_cluster;
                num_points_changed_clusters++;
            }
        }

        // Recalculate centroids
        for (i = 0; i < NUM_CLUSTERS; i++) {
            new_centroids_x[i] = 0;
            new_centroids_y[i] = 0;
            num_points_in_cluster[i] = 0;
            for (j = 0; j < MAX_NUM_POINTS; j++) {
                if (points[j].cluster == i) {
                    new_centroids_x[i] += points[j].x;
                    new_centroids_y[i] += points[j].y;
                    num_points_in_cluster[i]++;
                }
            }
            new_centroids_x[i] /= num_points_in_cluster[i];
            new_centroids_y[i] /= num_points_in_cluster[i];
        }

        if (DEBUG_MODE) {
            printf("Centroids after iteration %d:\n", num_iterations);
            for (i = 0; i < NUM_CLUSTERS; i++) {
                printf("Cluster %d: (%f, %f)\n", i, new_centroids_x[i], new_centroids_y[i]);
            }
            printf("\n");
        }
    } while (num_points_changed_clusters / (double) MAX_NUM_POINTS > THRESHOLD);

    printf("\nClustering complete after %d iterations.\n", num_iterations);

    if (DEBUG_MODE) {
        printf("\nFinal points:\n");
        for (i = 0; i < MAX_NUM_POINTS; i++) {
            printf("Point %d: (%f, %f), Cluster %d\n", i, points[i].x, points[i].y, points[i].cluster);
        }
    }

    free(points);

    return 0;
}