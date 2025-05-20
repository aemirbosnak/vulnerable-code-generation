//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_POINTS 100
#define DIMENSIONS 2

typedef struct {
    double *coords;
    int cluster;
} Point;

typedef struct {
    int num_clusters;
    Point *points;
} ClusterData;

double euclidean_distance(Point *p1, Point *p2) {
    double sum = 0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += (p1->coords[i] - p2->coords[i]) * (p1->coords[i] - p2->coords[i]);
    }
    return sqrt(sum);
}

int choose_random_point(ClusterData *data) {
    return rand() % NUM_POINTS;
}

int choose_furthest_point(ClusterData *data, bool *chosen_points) {
    int furthest = -1;
    double max_distance = -1;
    for (int i = 0; i < NUM_POINTS; i++) {
        if (!chosen_points[i]) {
            double min_distance = -1;
            for (int j = 0; j < NUM_POINTS; j++) {
                if (chosen_points[j] && (min_distance == -1 || euclidean_distance(&data->points[i], &data->points[j]) < min_distance)) {
                    min_distance = euclidean_distance(&data->points[i], &data->points[j]);
                }
            }
            if (min_distance > max_distance) {
                furthest = i;
                max_distance = min_distance;
            }
        }
    }
    return furthest;
}

ClusterData *init_cluster_data() {
    ClusterData *data = malloc(sizeof(ClusterData));
    data->num_clusters = 3;
    data->points = malloc(NUM_POINTS * sizeof(Point));
    for (int i = 0; i < NUM_POINTS; i++) {
        data->points[i].cluster = -1;
        data->points[i].coords = malloc(DIMENSIONS * sizeof(double));
        for (int j = 0; j < DIMENSIONS; j++) {
            data->points[i].coords[j] = (double) rand() / RAND_MAX;
        }
    }
    return data;
}

void kmeans(ClusterData *data) {
    srand(time(NULL));
    bool *chosen_points = calloc(NUM_POINTS, sizeof(bool));
    int first_centroid = choose_random_point(data);
    data->points[first_centroid].cluster = 0;
    chosen_points[first_centroid] = true;
    for (int i = 1; i < data->num_clusters; i++) {
        int furthest_point = choose_furthest_point(data, chosen_points);
        data->points[furthest_point].cluster = i;
        chosen_points[furthest_point] = true;
    }

    bool changed = true;
    while (changed) {
        changed = false;
        int num_points_in_cluster[data->num_clusters];
        Point new_centroids[data->num_clusters];
        for (int i = 0; i < data->num_clusters; i++) {
            num_points_in_cluster[i] = 0;
            new_centroids[i].coords = calloc(DIMENSIONS, sizeof(double));
            for (int j = 0; j < DIMENSIONS; j++) {
                new_centroids[i].coords[j] = 0;
            }
        }

        for (int i = 0; i < NUM_POINTS; i++) {
            Point *p = &data->points[i];
            double min_distance = -1;
            int old_cluster = p->cluster;
            for (int j = 0; j < data->num_clusters; j++) {
                double distance = euclidean_distance(p, &new_centroids[j]);
                if (min_distance == -1 || distance < min_distance) {
                    min_distance = distance;
                    p->cluster = j;
                }
            }
            if (old_cluster != p->cluster) {
                changed = true;
            }
            num_points_in_cluster[p->cluster]++;
            for (int j = 0; j < DIMENSIONS; j++) {
                new_centroids[p->cluster].coords[j] += p->coords[j];
            }
        }

        for (int i = 0; i < data->num_clusters; i++) {
            if (num_points_in_cluster[i] == 0) {
                continue;
            }
            for (int j = 0; j < DIMENSIONS; j++) {
                new_centroids[i].coords[j] /= num_points_in_cluster[i];
            }
        }
    }
}

int main() {
    ClusterData *data = init_cluster_data();
    kmeans(data);
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("Point %d is in cluster %d\n", i, data->points[i].cluster);
    }
    return 0;
}