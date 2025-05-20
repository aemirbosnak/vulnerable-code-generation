//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point;

typedef struct cluster {
    point centroid;
    int size;
    point* points;
} cluster;

cluster* create_cluster(point centroid, int size, point* points) {
    cluster* c = (cluster*)malloc(sizeof(cluster));
    c->centroid = centroid;
    c->size = size;
    c->points = points;
    return c;
}

void free_cluster(cluster* c) {
    free(c->points);
    free(c);
}

double distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

point calculate_centroid(cluster* c) {
    point centroid = {0, 0};
    for (int i = 0; i < c->size; i++) {
        centroid.x += c->points[i].x;
        centroid.y += c->points[i].y;
    }
    centroid.x /= c->size;
    centroid.y /= c->size;
    return centroid;
}

void reassign_points(cluster* clusters, int num_clusters, point* points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        int min_cluster = 0;
        double min_distance = distance(points[i], clusters[0].centroid);
        for (int j = 1; j < num_clusters; j++) {
            double d = distance(points[i], clusters[j].centroid);
            if (d < min_distance) {
                min_cluster = j;
                min_distance = d;
            }
        }
        clusters[min_cluster].points[clusters[min_cluster].size++] = points[i];
    }
}

void kmeans(point* points, int num_points, int num_clusters) {
    // Initialize clusters with random centroids
    cluster* clusters = (cluster*)malloc(sizeof(cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *create_cluster((point){(double)rand() / RAND_MAX, (double)rand() / RAND_MAX}, 0, NULL);
    }

    int max_iter = 100;
    int iter = 0;
    while (iter < max_iter) {
        // Reassign points to clusters
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].size = 0;
        }
        reassign_points(clusters, num_clusters, points, num_points);

        // Calculate new centroids
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].centroid = calculate_centroid(&clusters[i]);
        }

        iter++;
    }

    // Print cluster centroids
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: (%f, %f)\n", i, clusters[i].centroid.x, clusters[i].centroid.y);
    }

    // Free memory
    for (int i = 0; i < num_clusters; i++) {
        free_cluster(&clusters[i]);
    }
    free(clusters);
}

int main() {
    // Generate some random points
    int num_points = 100;
    point* points = (point*)malloc(sizeof(point) * num_points);
    for (int i = 0; i < num_points; i++) {
        points[i] = (point){(double)rand() / RAND_MAX, (double)rand() / RAND_MAX};
    }

    // Perform K-Means clustering
    int num_clusters = 3;
    kmeans(points, num_points, num_clusters);

    // Free memory
    free(points);
    return 0;
}