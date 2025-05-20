//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_DIMENSIONS 2
#define MAX_ITERATIONS 1000
#define THRESHOLD 0.01
#define NUM_CLUSTERS 3

typedef struct {
    double *coords;
    int cluster_id;
} DataPoint;

typedef struct {
    double *centroid;
    double *sums;
    int num_points;
    int *point_ids;
} Cluster;

void initialize_clusters(DataPoint *data_points, Cluster *clusters, int num_points) {
    // Select some random data points to be initial centroid positions
    int i, j, k, random_point_index;
    for (i = 0; i < NUM_CLUSTERS; i++) {
        random_point_index = rand() % num_points;
        for (j = 0; j < NUM_DIMENSIONS; j++) {
            clusters[i].centroid[j] = data_points[random_point_index].coords[j];
            clusters[i].sums[j] = 0;
        }
        clusters[i].num_points = 0;
        clusters[i].point_ids = malloc(num_points * sizeof(int));
    }

    // Assign each data point to the nearest centroid
    double distance, min_distance;
    int closest_cluster_id;
    for (i = 0; i < num_points; i++) {
        min_distance = INFINITY;
        for (j = 0; j < NUM_CLUSTERS; j++) {
            distance = 0;
            for (k = 0; k < NUM_DIMENSIONS; k++) {
                distance += pow(data_points[i].coords[k] - clusters[j].centroid[k], 2);
            }
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster_id = j;
            }
        }
        data_points[i].cluster_id = closest_cluster_id;
        clusters[closest_cluster_id].point_ids[clusters[closest_cluster_id].num_points] = i;
        clusters[closest_cluster_id].num_points++;
        for (k = 0; k < NUM_DIMENSIONS; k++) {
            clusters[closest_cluster_id].sums[k] += data_points[i].coords[k];
        }
    }
}

void update_clusters(DataPoint *data_points, Cluster *clusters, int num_points) {
    // Calculate new centroid positions and reset sums and point_ids
    int i, j, k, p;
    double new_centroid;
    for (i = 0; i < NUM_CLUSTERS; i++) {
        for (j = 0; j < NUM_DIMENSIONS; j++) {
            new_centroid = clusters[i].num_points == 0 ? 0 : clusters[i].sums[j] / clusters[i].num_points;
            if (fabs(clusters[i].centroid[j] - new_centroid) > THRESHOLD) {
                clusters[i].centroid[j] = new_centroid;
                for (p = 0; p < clusters[i].num_points; p++) {
                    data_points[clusters[i].point_ids[p]].cluster_id = -1;
                }
                clusters[i].num_points = 0;
                free(clusters[i].point_ids);
                clusters[i].point_ids = malloc(num_points * sizeof(int));
                break;
            }
            clusters[i].sums[j] = 0;
        }
    }

    // Reassign data points to the nearest centroid
    double distance, min_distance;
    int closest_cluster_id;
    for (i = 0; i < num_points; i++) {
        min_distance = INFINITY;
        for (j = 0; j < NUM_CLUSTERS; j++) {
            distance = 0;
            for (k = 0; k < NUM_DIMENSIONS; k++) {
                distance += pow(data_points[i].coords[k] - clusters[j].centroid[k], 2);
            }
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster_id = j;
            }
        }
        data_points[i].cluster_id = closest_cluster_id;
        clusters[closest_cluster_id].point_ids[clusters[closest_cluster_id].num_points] = i;
        clusters[closest_cluster_id].num_points++;
        for (k = 0; k < NUM_DIMENSIONS; k++) {
            clusters[closest_cluster_id].sums[k] += data_points[i].coords[k];
        }
    }
}

void print_clusters(Cluster *clusters) {
    int i, j;
    printf("Centroids: [");
    for (i = 0; i < NUM_CLUSTERS; i++) {
        printf("(");
        for (j = 0; j < NUM_DIMENSIONS; j++) {
            printf("%.2f", clusters[i].centroid[j]);
            if (j < NUM_DIMENSIONS - 1) printf(", ");
        }
        printf(")");
        if (i < NUM_CLUSTERS - 1) printf(", ");
    }
    printf("]\n");

    for (i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:", i);
        for (j = 0; j < clusters[i].num_points; j++) {
            printf(" %d", clusters[i].point_ids[j]);
        }
        printf("\n");
    }
}

int main() {
    int num_points = 10;
    DataPoint data_points[num_points];
    int i;
    for (i = 0; i < num_points; i++) {
        data_points[i].coords = malloc(NUM_DIMENSIONS * sizeof(double));
        data_points[i].coords[0] = rand() % 100;
        data_points[i].coords[1] = rand() % 100;
        data_points[i].cluster_id = -1;
    }

    Cluster clusters[NUM_CLUSTERS];
    for (i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].centroid = malloc(NUM_DIMENSIONS * sizeof(double));
        clusters[i].sums = malloc(NUM_DIMENSIONS * sizeof(double));
        clusters[i].num_points = 0;
        clusters[i].point_ids = NULL;
    }

    initialize_clusters(data_points, clusters, num_points);

    int iteration;
    for (iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        update_clusters(data_points, clusters, num_points);
        if (iteration % 10 == 0) {
            printf("Iteration %d:\n", iteration);
            print_clusters(clusters);
        }
    }

    for (i = 0; i < num_points; i++) {
        free(data_points[i].coords);
    }
    for (i = 0; i < NUM_CLUSTERS; i++) {
        free(clusters[i].centroid);
        free(clusters[i].sums);
        free(clusters[i].point_ids);
    }

    return 0;
}