//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point *points;
    int npoints;
} cluster;

double distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

cluster *create_cluster(point *points, int npoints) {
    cluster *c = malloc(sizeof(cluster));
    c->points = points;
    c->npoints = npoints;
    return c;
}

cluster *merge_clusters(cluster *a, cluster *b) {
    point *new_points = malloc((a->npoints + b->npoints) * sizeof(point));
    int i;
    for (i = 0; i < a->npoints; i++) {
        new_points[i] = a->points[i];
    }
    for (i = 0; i < b->npoints; i++) {
        new_points[a->npoints + i] = b->points[i];
    }
    cluster *c = create_cluster(new_points, a->npoints + b->npoints);
    free(a->points);
    free(a);
    free(b->points);
    free(b);
    return c;
}

cluster *kmeans(point *points, int npoints, int k) {
    cluster *clusters[k];
    int i, j;
    for (i = 0; i < k; i++) {
        clusters[i] = create_cluster(&points[i], 1);
    }
    while (1) {
        int changed = 0;
        for (i = 0; i < npoints; i++) {
            double min_dist = distance(points[i], clusters[0]->points[0]);
            int min_cluster = 0;
            for (j = 1; j < k; j++) {
                double dist = distance(points[i], clusters[j]->points[0]);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_cluster = j;
                }
            }
            if (min_cluster != clusters[i]->npoints) {
                clusters[min_cluster] = merge_clusters(clusters[min_cluster], clusters[i]);
                clusters[i] = create_cluster(&points[i], 1);
                changed = 1;
            }
        }
        if (!changed) {
            break;
        }
    }
    return clusters[0];
}

int main() {
    point points[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    int npoints = sizeof(points) / sizeof(point);
    int k = 3;
    cluster *c = kmeans(points, npoints, k);
    for (int i = 0; i < c->npoints; i++) {
        printf("(%f, %f)\n", c->points[i].x, c->points[i].y);
    }
    free(c->points);
    free(c);
    return 0;
}