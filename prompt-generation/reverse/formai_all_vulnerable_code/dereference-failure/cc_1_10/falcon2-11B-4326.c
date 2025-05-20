//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CLUSTERS 10
#define MAX_DATA_POINTS 100

typedef struct {
    int data[3];
} DataPoint;

typedef struct {
    int cluster;
    int data_points_count;
    double centroid[3];
} Cluster;

void initialize_clusters(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].cluster = i;
        clusters[i].data_points_count = 0;
        clusters[i].centroid[0] = 0.0;
        clusters[i].centroid[1] = 0.0;
        clusters[i].centroid[2] = 0.0;
    }
}

void initialize_data_points(DataPoint *data_points, int num_data_points) {
    for (int i = 0; i < num_data_points; i++) {
        data_points[i].data[0] = (int)(rand() % 100);
        data_points[i].data[1] = (int)(rand() % 100);
        data_points[i].data[2] = (int)(rand() % 100);
    }
}

double calculate_distance(DataPoint *point1, DataPoint *point2) {
    double distance = 0.0;
    for (int i = 0; i < 3; i++) {
        distance += pow(point1->data[i] - point2->data[i], 2);
    }
    return sqrt(distance);
}

void assign_clusters(Cluster *clusters, DataPoint *data_points, int num_clusters, int num_data_points) {
    for (int i = 0; i < num_data_points; i++) {
        int min_distance = 0;
        int min_cluster = 0;
        for (int j = 0; j < num_clusters; j++) {
            double distance = calculate_distance(&data_points[i], &clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                min_cluster = j;
            }
        }
        clusters[min_cluster].data_points_count++;
        clusters[min_cluster].centroid[0] += data_points[i].data[0];
        clusters[min_cluster].centroid[1] += data_points[i].data[1];
        clusters[min_cluster].centroid[2] += data_points[i].data[2];
    }
}

void print_clusters(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: %d data points\n", i, clusters[i].data_points_count);
        printf("Centroid: (%d, %d, %d)\n", clusters[i].centroid[0], clusters[i].centroid[1], clusters[i].centroid[2]);
        printf("===============================\n");
    }
}

int main() {
    int num_clusters = MAX_CLUSTERS;
    int num_data_points = MAX_DATA_POINTS;
    int *data_points = (int*)malloc(num_data_points * sizeof(int));
    Cluster *clusters = (Cluster*)malloc(num_clusters * sizeof(Cluster));
    initialize_clusters(clusters, num_clusters);
    initialize_data_points(data_points, num_data_points);
    assign_clusters(clusters, data_points, num_clusters, num_data_points);
    print_clusters(clusters, num_clusters);
    free(data_points);
    free(clusters);
    return 0;
}