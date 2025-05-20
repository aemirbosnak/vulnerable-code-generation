//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct surreal_point {
   float x;
   float y;
   int z;
};

typedef struct surreal_point point;

void update_cluster(int* clusters, point pt, int cluster_num) {
    for (int i = 0; i < cluster_num; i++) {
        if (clusters[i] == -1) {
            clusters[i] = pt.z;
            return;
        }
        point mean = { 0, 0, 0 };
        int count = 0;
        for (int j = 0; j < cluster_num; j++) {
            if (clusters[j] == i) {
                mean.x += pt.x;
                mean.y += pt.y;
                mean.z += pt.z;
                count++;
            }
        }
        mean.x /= count;
        mean.y /= count;
        mean.z /= count;
        if (mean.x == pt.x && mean.y == pt.y && mean.z == pt.z) {
            clusters[i] = pt.z;
            return;
        }
    }
}

void surreal_cluster(point* pts, int size, int cluster_num) {
    int* clusters = malloc(sizeof(int) * cluster_num);
    for (int i = 0; i < cluster_num; i++) {
        clusters[i] = -1;
    }

    for (int i = 0; i < size; i++) {
        if (clusters[pts[i].z] == -1) {
            clusters[pts[i].z] = pts[i].z;
        } else {
            update_cluster(clusters, pts[i], cluster_num);
        }
    }

    for (int i = 0; i < cluster_num; i++) {
        printf("Cluster %d: ", i);
        for (int j = 0; j < size; j++) {
            if (clusters[pts[j].z] == i) {
                printf("(%f, %f, %d) ", pts[j].x, pts[j].y, pts[j].z);
            }
        }
        printf("\n");
    }

    free(clusters);
}

int main() {
    point pts[] = {
        {1.0f, 2.0f, 0},
        {3.0f, 4.0f, 1},
        {5.0f, 6.0f, 1},
        {7.0f, 8.0f, 2},
        {9.0f, 10.0f, 0},
        {11.0f, 12.0f, 2},
        {13.0f, 14.0f, 0},
        {15.0f, 16.0f, 1},
    };
    surreal_cluster(pts, 8, 3);
    return 0;
}