//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    int n;
    Point *points;
} Cluster;

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

void initialize_clusters(Cluster clusters[], int num_clusters, Point points[], int num_points) {
    int i, j, k;
    double max_distance = 0.0;
    double current_distance = 0.0;

    for (i = 0; i < num_clusters; i++) {
        clusters[i].n = 0;
        clusters[i].points = (Point*)malloc(sizeof(Point) * num_points);
        clusters[i].center.x = rand() % 100;
        clusters[i].center.y = rand() % 100;
        for (j = 0; j < i; j++) {
            current_distance = distance(clusters[i].center, clusters[j].center);
            if (current_distance > max_distance)
                max_distance = current_distance;
        }
    }

    for (i = 0; i < num_points; i++) {
        k = rand() % num_clusters;
        clusters[k].points[clusters[k].n] = points[i];
        clusters[k].n++;
    }
}

double update_cluster_center(Cluster *cluster) {
    int i;
    double x = 0.0, y = 0.0;

    for (i = 0; i < cluster->n; i++) {
        x += cluster->points[i].x;
        y += cluster->points[i].y;
    }

    cluster->center.x = x / cluster->n;
    cluster->center.y = y / cluster->n;

    return distance(cluster->center, (Point){x/cluster->n, y/cluster->n});
}

double update_cluster_centers(Cluster clusters[], int num_clusters) {
    int i;
    double max_shift = 0.0, shift = 0.0;
    for (i = 0; i < num_clusters; i++) {
        shift = update_cluster_center(&clusters[i]);
        if (shift > max_shift)
            max_shift = shift;
    }
    return max_shift;
}

void print_clusters(Cluster clusters[], int num_clusters) {
    int i, j;
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        printf("\tCenter: (%lf, %lf)\n", clusters[i].center.x, clusters[i].center.y);
        for (j = 0; j < clusters[i].n; j++) {
            printf("\tPoint: (%lf, %lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

int main() {
    int i, num_points = 100;
    Point *points = (Point*)malloc(sizeof(Point) * num_points);
    for (i = 0; i < num_points; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    int num_clusters = 5;
    Cluster *clusters = (Cluster*)malloc(sizeof(Cluster) * num_clusters);
    initialize_clusters(clusters, num_clusters, points, num_points);

    int max_iterations = 1000;
    double tolerance = 0.001;

    double shift = tolerance + 1.0;
    int iteration = 0;

    while (shift > tolerance && iteration < max_iterations) {
        shift = update_cluster_centers(clusters, num_clusters);
        printf("Iteration %d, max shift: %lf\n", iteration+1, shift);
        iteration++;
    }

    print_clusters(clusters, num_clusters);
}