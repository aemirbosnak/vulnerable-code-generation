//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 10 // number of points
#define NUM_CLUSTERS 2 // number of clusters
#define MAX_ITERATIONS 100 // maximum iterations

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct Cluster {
    int id;
    Point centroid;
    int num_points;
    Point *points;
} Cluster;

double euclidean_distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

Cluster *create_clusters(Point *points, int num_points, int num_clusters) {
    int i, j;
    Cluster *clusters = (Cluster*)malloc(num_clusters * sizeof(Cluster));
    for (i = 0; i < num_clusters; i++) {
        clusters[i].id = i;
        clusters[i].centroid = points[i];
        clusters[i].num_points = 0;
        clusters[i].points = (Point*)malloc(num_points * sizeof(Point));
    }
    for (i = 0; i < num_points; i++) {
        int cluster_id = i % num_clusters;
        clusters[cluster_id].points[clusters[cluster_id].num_points++] = points[i];
    }
    return clusters;
}

void plot_clusters(Cluster *clusters, int num_clusters) {
    int i, j;
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d: Centroid(%lf, %lf)\n", clusters[i].id, clusters[i].centroid.x, clusters[i].centroid.y);
        for (j = 0; j < clusters[i].num_points; j++) {
            printf("(%lf, %lf) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
    printf("\n");
}

void update_centroids(Cluster *clusters, int num_clusters) {
    int i, j;
    for (i = 0; i < num_clusters; i++) {
        double x_sum = 0.0, y_sum = 0.0;
        for (j = 0; j < clusters[i].num_points; j++) {
            x_sum += clusters[i].points[j].x;
            y_sum += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = x_sum / clusters[i].num_points;
        clusters[i].centroid.y = y_sum / clusters[i].num_points;
    }
}

void kmeans(Point *points, int num_points, int num_clusters) {
    Cluster *clusters = create_clusters(points, num_points, num_clusters);
    int i, j, iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        for (i = 0; i < num_clusters; i++) {
            for (j = 0; j < clusters[i].num_points; j++) {
                int k, nearest_cluster = i;
                double min_distance = euclidean_distance(clusters[i].points[j], clusters[i].centroid);
                for (k = 0; k < num_clusters; k++) {
                    if (k != i) {
                        double distance = euclidean_distance(clusters[i].points[j], clusters[k].centroid);
                        if (distance < min_distance) {
                            min_distance = distance;
                            nearest_cluster = k;
                        }
                    }
                }
                if (nearest_cluster != i) {
                    clusters[nearest_cluster].points[clusters[nearest_cluster].num_points++] = clusters[i].points[j];
                    clusters[i].points[j] = clusters[i].points[--clusters[i].num_points];
                    j--;
                }
            }
        }
        update_centroids(clusters, num_clusters);
        plot_clusters(clusters, num_clusters);
        iteration++;
    }
}

int main() {
    Point points[NUM_POINTS] = {
        {12.3, 15.2},
        {10.6, 22.1},
        {8.5, 17.8},
        {11.6, 19.2},
        {15.0, 17.4},
        {19.3, 21.7},
        {16.6, 15.5},
        {23.1, 12.3},
        {18.6, 19.4},
        {21.3, 14.2}
    };
    kmeans(points, NUM_POINTS, NUM_CLUSTERS);
    return 0;
}