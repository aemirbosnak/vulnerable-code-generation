//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Dataset;

typedef struct {
    Point centroid;
    int num_points;
} Cluster;

Dataset* create_dataset(int num_points) {
    Dataset *dataset = malloc(sizeof(Dataset));
    dataset->points = malloc(sizeof(Point) * num_points);
    dataset->num_points = num_points;
    for (int i = 0; i < num_points; i++) {
        dataset->points[i].x = (double) rand() / RAND_MAX;
        dataset->points[i].y = (double) rand() / RAND_MAX;
    }
    return dataset;
}

void free_dataset(Dataset *dataset) {
    free(dataset->points);
    free(dataset);
}

Cluster* create_cluster(int num_points) {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->centroid.x = 0.0;
    cluster->centroid.y = 0.0;
    cluster->num_points = num_points;
    return cluster;
}

void free_cluster(Cluster *cluster) {
    free(cluster);
}

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void assign_points_to_clusters(Dataset *dataset, Cluster *clusters, int num_clusters) {
    for (int i = 0; i < dataset->num_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance_to_centroid = distance(dataset->points[i], clusters[j].centroid);
            if (distance_to_centroid < min_distance) {
                min_distance = distance_to_centroid;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].num_points++;
    }
}

void update_centroids(Dataset *dataset, Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = 0.0;
        clusters[i].centroid.y = 0.0;
        for (int j = 0; j < dataset->num_points; j++) {
            if (distance(dataset->points[j], clusters[i].centroid) < INFINITY) {
                clusters[i].centroid.x += dataset->points[j].x;
                clusters[i].centroid.y += dataset->points[j].y;
            }
        }
        clusters[i].centroid.x /= clusters[i].num_points;
        clusters[i].centroid.y /= clusters[i].num_points;
    }
}

int main() {
    int num_points = 1000;
    int num_clusters = 3;

    Dataset *dataset = create_dataset(num_points);
    Cluster *clusters = malloc(sizeof(Cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *create_cluster(0);
    }

    int max_iterations = 100;
    for (int i = 0; i < max_iterations; i++) {
        assign_points_to_clusters(dataset, clusters, num_clusters);
        update_centroids(dataset, clusters, num_clusters);
    }

    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Number of points: %d\n", clusters[i].num_points);
        printf("\n");
    }

    free_dataset(dataset);
    for (int i = 0; i < num_clusters; i++) {
        free_cluster(&clusters[i]);
    }
    free(clusters);

    return 0;
}