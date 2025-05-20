//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: satisfied
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
} Cluster;

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

Cluster* create_cluster(Point *points, int num_points) {
    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->points = points;
    cluster->num_points = num_points;
    return cluster;
}

void free_cluster(Cluster *cluster) {
    free(cluster->points);
    free(cluster);
}

Cluster* merge_clusters(Cluster *a, Cluster *b) {
    Point *new_points = malloc(sizeof(Point) * (a->num_points + b->num_points));
    memcpy(new_points, a->points, sizeof(Point) * a->num_points);
    memcpy(new_points + a->num_points, b->points, sizeof(Point) * b->num_points);

    Cluster *new_cluster = create_cluster(new_points, a->num_points + b->num_points);
    free_cluster(a);
    free_cluster(b);
    return new_cluster;
}

double cluster_distance(Cluster *a, Cluster *b) {
    double min_distance = INFINITY;
    for (int i = 0; i < a->num_points; i++) {
        for (int j = 0; j < b->num_points; j++) {
            double dist = distance(a->points[i], b->points[j]);
            if (dist < min_distance) {
                min_distance = dist;
            }
        }
    }
    return min_distance;
}

Cluster* hierarchical_clustering(Point *points, int num_points) {
    Cluster **clusters = malloc(sizeof(Cluster*) * num_points);
    for (int i = 0; i < num_points; i++) {
        clusters[i] = create_cluster(&points[i], 1);
    }

    int num_clusters = num_points;
    while (num_clusters > 1) {
        double min_distance = INFINITY;
        int a = -1, b = -1;
        for (int i = 0; i < num_clusters; i++) {
            for (int j = i + 1; j < num_clusters; j++) {
                double dist = cluster_distance(clusters[i], clusters[j]);
                if (dist < min_distance) {
                    min_distance = dist;
                    a = i;
                    b = j;
                }
            }
        }

        Cluster *new_cluster = merge_clusters(clusters[a], clusters[b]);
        free(clusters[a]);
        free(clusters[b]);
        clusters[a] = new_cluster;
        clusters[b] = NULL;
        num_clusters--;
    }

    Cluster *final_cluster = clusters[0];
    free(clusters);
    return final_cluster;
}

int main() {
    Point points[] = {
        {0, 0},
        {1, 0},
        {2, 0},
        {0, 1},
        {1, 1},
        {2, 1},
        {0, 2},
        {1, 2},
        {2, 2}
    };
    int num_points = sizeof(points) / sizeof(points[0]);

    Cluster *cluster = hierarchical_clustering(points, num_points);

    for (int i = 0; i < cluster->num_points; i++) {
        printf("(%f, %f)\n", cluster->points[i].x, cluster->points[i].y);
    }

    free_cluster(cluster);
    return 0;
}