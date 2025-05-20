//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_ITERATIONS 100

typedef struct point {
    float x;
    float y;
} point_t;

typedef struct cluster {
    point_t centroid;
    int num_points;
    point_t *points;
} cluster_t;

float distance(point_t p1, point_t p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

void assign_to_cluster(cluster_t *clusters, point_t point, int k) {
    int i;
    float dist = distance(point, clusters[0].centroid);
    int cluster_index = 0;

    for(i = 1; i < k; i++) {
        float temp_dist = distance(point, clusters[i].centroid);
        if(temp_dist < dist) {
            dist = temp_dist;
            cluster_index = i;
        }
    }

    clusters[cluster_index].points[clusters[cluster_index].num_points++] = point;
}

point_t compute_new_centroid(cluster_t cluster) {
    int i;
    float x_sum = 0;
    float y_sum = 0;

    for(i = 0; i < cluster.num_points; i++) {
        x_sum += cluster.points[i].x;
        y_sum += cluster.points[i].y;
    }

    point_t new_centroid = {x_sum / cluster.num_points, y_sum / cluster.num_points};
    return new_centroid;
}

void k_means_clustering(point_t *points, int n, int k) {
    cluster_t *clusters = malloc(k * sizeof(cluster_t));
    int i, j, itr;

    srand(time(NULL));

    for(i = 0; i < k; i++) {
        clusters[i].centroid.x = ((float) rand() / RAND_MAX) * 10;
        clusters[i].centroid.y = ((float) rand() / RAND_MAX) * 10;
        clusters[i].num_points = 0;
        clusters[i].points = malloc(n * sizeof(point_t));
    }

    for(itr = 0; itr < MAX_ITERATIONS; itr++) {
        for(i = 0; i < k; i++) {
            clusters[i].num_points = 0;
        }

        for(i = 0; i < n; i++) {
            assign_to_cluster(clusters, points[i], k);
        }

        int convergence = 1;

        for(i = 0; i < k; i++) {
            point_t new_centroid = compute_new_centroid(clusters[i]);

            if(distance(new_centroid, clusters[i].centroid) > 0.001) {
                convergence = 0;
            }

            clusters[i].centroid = new_centroid;
        }

        if(convergence) {
            break;
        }
    }

    printf("Clusters:\n");
    for(i = 0; i < k; i++) {
        printf("Cluster %d: Centroid (%f, %f), Points: ", i+1, clusters[i].centroid.x, clusters[i].centroid.y);
        for(j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    for(i = 0; i < k; i++) {
        free(clusters[i].points);
    }

    free(clusters);
}

int main() {
    point_t points[MAX_POINTS] = {{1.0, 1.0},
                                     {2.0, 1.0},
                                     {4.0, 3.0},
                                     {5.0, 4.0},
                                     {6.0, 5.0},
                                     {10.0, 11.0},
                                     {11.0, 12.0},
                                     {12.0, 13.0},
                                     {15.0, 18.0},
                                     {16.0, 20.0}};

    int n = 10;
    int k = 3;

    k_means_clustering(points, n, k);

    return 0;
}