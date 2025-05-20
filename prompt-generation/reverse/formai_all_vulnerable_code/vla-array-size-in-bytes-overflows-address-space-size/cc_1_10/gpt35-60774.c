//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dist(float x1, float y1, float x2, float y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void main() {
    int n, c;
    float ans = 0;
    scanf("%d%d", &n, &c);
    float a[n][2];
    int cluster[n];
    for (int i = 0; i < n; i++) {
        scanf("%f%f", &a[i][0], &a[i][1]);
        cluster[i] = -1; // not assigned to any cluster yet
    }
    float centroid_x[c], centroid_y[c];
    for (int i = 0; i < c; i++) {
        centroid_x[i] = a[i][0];
        centroid_y[i] = a[i][1];
        cluster[i] = i; // assign first c points as initial clusters
    }
    while (1) {
        int change = 0;
        for (int i = 0; i < n; i++) {
            float min_distance = 1e9;
            int min_cluster = -1;
            for (int j = 0; j < c; j++) {
                if (dist(a[i][0], a[i][1], centroid_x[j], centroid_y[j]) < min_distance) {
                    min_distance = dist(a[i][0], a[i][1], centroid_x[j], centroid_y[j]);
                    min_cluster = j;
                }
            }
            if (cluster[i] != min_cluster) {
                cluster[i] = min_cluster;
                change = 1;
            }
        }
        if (!change) break; // no change in clustering
        for (int i = 0; i < c; i++) {
            float sum_x = 0, sum_y = 0, count = 0;
            for (int j = 0; j < n; j++) {
                if (cluster[j] == i) {
                    sum_x += a[j][0];
                    sum_y += a[j][1];
                    count++;
                }
            }
            centroid_x[i] = sum_x / count;
            centroid_y[i] = sum_y / count;
        }
    }
    for (int i = 0; i < n; i++) {
        ans += dist(a[i][0], a[i][1], centroid_x[cluster[i]], centroid_y[cluster[i]]);
    }
    printf("Minimum sum of distances from clusters' centroids = %f", ans);
}