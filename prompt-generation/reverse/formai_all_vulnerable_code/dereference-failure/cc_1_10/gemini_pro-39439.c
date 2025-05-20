//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    double x;
    double y;
} Point;

typedef struct {
    int id;
    int size;
    Point *points;
} Cluster;

typedef struct {
    int id;
    int size;
    Cluster *clusters;
} Hierarchy;

Hierarchy *create_hierarchy(int num_points, Point *points) {
    Hierarchy *hierarchy = malloc(sizeof(Hierarchy));
    hierarchy->id = 0;
    hierarchy->size = 1;
    hierarchy->clusters = malloc(sizeof(Cluster) * 1);
    hierarchy->clusters[0].id = 0;
    hierarchy->clusters[0].size = num_points;
    hierarchy->clusters[0].points = points;
    return hierarchy;
}

void destroy_hierarchy(Hierarchy *hierarchy) {
    for (int i = 0; i < hierarchy->size; i++) {
        free(hierarchy->clusters[i].points);
    }
    free(hierarchy->clusters);
    free(hierarchy);
}

Cluster *find_closest_clusters(Hierarchy *hierarchy, int num_clusters) {
    Cluster *closest_clusters = malloc(sizeof(Cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        closest_clusters[i].id = -1;
        closest_clusters[i].size = 0;
        closest_clusters[i].points = NULL;
    }
    for (int i = 0; i < hierarchy->size; i++) {
        Cluster *cluster = &hierarchy->clusters[i];
        if (cluster->size <= num_clusters) {
            for (int j = 0; j < num_clusters; j++) {
                if (closest_clusters[j].size < cluster->size) {
                    closest_clusters[j] = *cluster;
                    break;
                }
            }
        }
    }
    return closest_clusters;
}

Hierarchy *merge_clusters(Hierarchy *hierarchy, Cluster *clusters, int num_clusters) {
    Hierarchy *new_hierarchy = malloc(sizeof(Hierarchy));
    new_hierarchy->id = hierarchy->id + 1;
    new_hierarchy->size = hierarchy->size + num_clusters - 1;
    new_hierarchy->clusters = malloc(sizeof(Cluster) * new_hierarchy->size);
    int index = 0;
    for (int i = 0; i < hierarchy->size; i++) {
        if (clusters[i].id != -1) {
            for (int j = 0; j < num_clusters; j++) {
                if (clusters[j].id == hierarchy->clusters[i].id) {
                    new_hierarchy->clusters[index++] = hierarchy->clusters[i];
                    break;
                }
            }
        } else {
            new_hierarchy->clusters[index++] = hierarchy->clusters[i];
        }
    }
    destroy_hierarchy(hierarchy);
    return new_hierarchy;
}

int main(int argc, char **argv) {
    int num_points, num_clusters;
    if (argc < 3) {
        printf("Usage: %s <num_points> <num_clusters>\n", argv[0]);
        return 1;
    }
    num_points = atoi(argv[1]);
    num_clusters = atoi(argv[2]);
    Point *points = malloc(sizeof(Point) * num_points);
    for (int i = 0; i < num_points; i++) {
        points[i].id = i;
        points[i].x = rand() / (double)RAND_MAX;
        points[i].y = rand() / (double)RAND_MAX;
    }
    Hierarchy *hierarchy = create_hierarchy(num_points, points);
    while (hierarchy->size > num_clusters) {
        Cluster *closest_clusters = find_closest_clusters(hierarchy, num_clusters);
        hierarchy = merge_clusters(hierarchy, closest_clusters, num_clusters);
        free(closest_clusters);
    }
    for (int i = 0; i < hierarchy->size; i++) {
        Cluster *cluster = &hierarchy->clusters[i];
        printf("Cluster %d: ", cluster->id);
        for (int j = 0; j < cluster->size; j++) {
            printf("(%f, %f) ", cluster->points[j].x, cluster->points[j].y);
        }
        printf("\n");
    }
    destroy_hierarchy(hierarchy);
    free(points);
    return 0;
}