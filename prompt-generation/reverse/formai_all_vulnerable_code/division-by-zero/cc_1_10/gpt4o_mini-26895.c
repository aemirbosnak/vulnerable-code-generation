//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    Point *points;
    int point_count;
} Cluster;

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initialize_clusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].point_count = 0;
        clusters[i].points = calloc(MAX_POINTS, sizeof(Point));
    }
}

void assign_points_to_clusters(Point *points, int n, Cluster *clusters, int k) {
    for (int i = 0; i < n; i++) {
        double min_distance = INFINITY;
        int cluster_index = 0;
        for (int j = 0; j < k; j++) {
            double dist = distance(points[i], clusters[j].centroid);
            if (dist < min_distance) {
                min_distance = dist;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points[clusters[cluster_index].point_count++] = points[i];
    }
}

void update_centroids(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        double sum_x = 0;
        double sum_y = 0;
        for (int j = 0; j < clusters[i].point_count; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        if (clusters[i].point_count > 0) {
            clusters[i].centroid.x = sum_x / clusters[i].point_count;
            clusters[i].centroid.y = sum_y / clusters[i].point_count;
        }
    }
}

int main() {
    int n, k;
    Cluster clusters[MAX_CLUSTERS];
    Point points[MAX_POINTS];

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the points (x y) in 2D space:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    printf("Enter the number of clusters (k): ");
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[rand() % n]; // Initialize centroids randomly
    }

    initialize_clusters(clusters, k);
    int iterations = 10;

    while (iterations--) {
        for (int i = 0; i < k; i++) {
            clusters[i].point_count = 0; // Reset point counts for this iteration
        }

        assign_points_to_clusters(points, n, clusters, k);
        update_centroids(clusters, k);
    }

    printf("\nClustering results:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf(" Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf(" Points:\n");
        for (int j = 0; j < clusters[i].point_count; j++) {
            printf("  (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    for (int i = 0; i < k; i++) {
        free(clusters[i].points);
    }

    return 0;
}