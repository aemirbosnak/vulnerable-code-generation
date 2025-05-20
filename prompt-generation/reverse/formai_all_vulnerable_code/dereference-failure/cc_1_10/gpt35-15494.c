//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define K 5
#define EPSILON 0.0001

typedef struct {
    double x, y;
} point_t;

typedef struct {
    int count;
    point_t center;
    point_t *points[N];
} cluster_t;

point_t random_point();
double distance(point_t a, point_t b);
double squared_distance(point_t a, point_t b);
int closest_cluster(point_t point, cluster_t *clusters, int k);
void recenter(cluster_t *cluster);
int update_clusters(cluster_t *clusters, point_t *points, int n, int k);
void print_clusters(cluster_t *clusters, int k);

int main() {
    srand(time(NULL));

    point_t *points = malloc(N * sizeof(point_t));
    for (int i = 0; i < N; i++) {
        points[i] = random_point();
    }

    cluster_t clusters[K];
    for (int i = 0; i < K; i++) {
        clusters[i].count = 0;
        clusters[i].center = random_point();
    }

    int n = N;
    while (update_clusters(clusters, points, n, K)) {
        for (int i = 0; i < K; i++) {
            recenter(&clusters[i]);
        }
    }

    print_clusters(clusters, K);

    return 0;
}

point_t random_point() {
    point_t point;
    point.x = (double) rand() / RAND_MAX;
    point.y = (double) rand() / RAND_MAX;
    return point;
}

double distance(point_t a, point_t b) {
    return sqrt(squared_distance(a, b));
}

double squared_distance(point_t a, point_t b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int closest_cluster(point_t point, cluster_t *clusters, int k) {
    int closest = 0;
    double min_distance = distance(point, clusters[0].center);
    for (int i = 1; i < k; i++) {
        double d = distance(point, clusters[i].center);
        if (d < min_distance) {
            closest = i;
            min_distance = d;
        }
    }
    return closest;
}

void recenter(cluster_t *cluster) {
    double x_sum = 0.0;
    double y_sum = 0.0;

    for (int i = 0; i < cluster->count; i++) {
        x_sum += cluster->points[i]->x;
        y_sum += cluster->points[i]->y;
    }

    cluster->center.x = x_sum / cluster->count;
    cluster->center.y = y_sum / cluster->count;
}

int update_clusters(cluster_t *clusters, point_t *points, int n, int k) {
    int changed = 0;

    for (int i = 0; i < k; i++) {
        clusters[i].count = 0;
    }

    for (int i = 0; i < n; i++) {
        int closest = closest_cluster(points[i], clusters, k);

        if (clusters[closest].count == N) {
            continue;
        }

        if (clusters[closest].count > 0) {
            point_t *last_point = clusters[closest].points[clusters[closest].count - 1];
            if (squared_distance(points[i], *last_point) < EPSILON) {
                continue;
            }
        }

        clusters[closest].points[clusters[closest].count++] = &points[i];
        changed = 1;
    }

    return changed;
}

void print_clusters(cluster_t *clusters, int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: (%lf, %lf)\n", i, clusters[i].center.x, clusters[i].center.y);
        for (int j = 0; j < clusters[i].count; j++) {
            printf("    (%lf, %lf)\n", clusters[i].points[j]->x, clusters[i].points[j]->y);
        }
    }
}