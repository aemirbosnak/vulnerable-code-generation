//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
/*
 * This is a unique implementation of C Clustering Algorithm
 * It takes a set of data points and clusters them into k groups,
 * using an iterative algorithm that minimizes the total distance
 * between each point and its assigned cluster center.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    int num_points;
    point *points;
    point center;
} cluster;

void read_input_data(point **points, int *num_points)
{
    int i;
    printf("Enter the number of data points: ");
    scanf("%d", num_points);
    *points = (point*) malloc(*num_points * sizeof(point));
    for (i = 0; i < *num_points; ++i) {
        printf("Enter the x and y coordinates of point %d: ", i + 1);
        scanf("%lf%lf", &((*points)[i].x), &((*points)[i].y));
    }
}

void initialize_clusters(cluster **clusters, int num_clusters, point *points,
                          int num_points)
{
    int i, j;
    cluster *cl;
    *clusters = (cluster*) malloc(num_clusters * sizeof(cluster));
    for (i = 0; i < num_clusters; ++i) {
        cl = &((*clusters)[i]);
        cl->num_points = 0;
        cl->points = (point*) malloc(num_points * sizeof(point));
        cl->center.x = points[i].x;
        cl->center.y = points[i].y;
        for (j = 0; j < num_points; ++j) {
            if (i == j) {
                cl->points[cl->num_points++] = points[j];
            }
        }
    }
}

void update_clusters(cluster *clusters, int num_clusters, point *points,
                      int num_points)
{
    int i, j, k;
    double min_dist, dist;
    int min_cluster;
    point center;

    for (i = 0; i < num_clusters; ++i) {
        clusters[i].num_points = 0;
    }

    for (j = 0; j < num_points; ++j) {
        min_cluster = 0;
        min_dist = hypot(points[j].x - clusters[0].center.x,
                         points[j].y - clusters[0].center.y);
        for (i = 1; i < num_clusters; ++i) {
            dist = hypot(points[j].x - clusters[i].center.x,
                         points[j].y - clusters[i].center.y);
            if (dist < min_dist) {
                min_cluster = i;
                min_dist = dist;
            }
        }
        clusters[min_cluster].points[clusters[min_cluster].num_points++] =
                points[j];
    }

    for (i = 0; i < num_clusters; ++i) {
        center.x = 0.0;
        center.y = 0.0;
        for (j = 0; j < clusters[i].num_points; ++j) {
            center.x += clusters[i].points[j].x;
            center.y += clusters[i].points[j].y;
        }
        if (clusters[i].num_points > 0) {
            center.x /= clusters[i].num_points;
            center.y /= clusters[i].num_points;
        }
        clusters[i].center = center;
    }
}

int main()
{
    int i, j;
    int num_clusters, num_points;
    point *points;
    cluster *clusters;

    read_input_data(&points, &num_points);
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);

    initialize_clusters(&clusters, num_clusters, points, num_points);
    for (i = 0; i < MAX_ITERATIONS; ++i) {
        update_clusters(clusters, num_clusters, points, num_points);
    }

    printf("\nCluster centers:\n");
    for (i = 0; i < num_clusters; ++i) {
        printf("(%1.2lf, %1.2lf)\n", clusters[i].center.x, clusters[i].center.y);
        printf("Points in cluster %d:\n", i + 1);
        for (j = 0; j < clusters[i].num_points; ++j) {
            printf("(%1.2lf, %1.2lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);;
        }
    }

    for (i = 0; i < num_clusters; ++i) {
        free(clusters[i].points);
    }
    free(clusters);

    free(points);

    return 0;
}