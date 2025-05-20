//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_POINT_COUNT 100
#define MAX_CLUSTER_COUNT 10

struct point {
    double x;
    double y;
};

struct cluster {
    struct point centroid;
    int point_count;
    struct point points[MAX_POINT_COUNT];
};

struct cluster clusters[MAX_CLUSTER_COUNT];
int cluster_count = 0;
int point_count = 0;
struct point points[MAX_POINT_COUNT];

double distance(struct point p1, struct point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

bool are_points_equal(struct point p1, struct point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

void add_point(struct point p) {
    points[point_count++] = p;
}

void add_point_to_cluster(struct cluster* c, struct point p) {
    c->points[c->point_count++] = p;
}

void reset_clusters() {
    for (int i = 0; i < MAX_CLUSTER_COUNT; i++) {
        clusters[i].centroid.x = 0;
        clusters[i].centroid.y = 0;
        clusters[i].point_count = 0;
    }
    cluster_count = 0;
}

void print_cluster(struct cluster c) {
    printf("Cluster:\n");
    printf("Centroid: (%f, %f)\n", c.centroid.x, c.centroid.y);
    printf("Points:\n");
    for (int i = 0; i < c.point_count; i++) {
        printf("(%f, %f)\n", c.points[i].x, c.points[i].y);
    }
}

void print_clusters() {
    printf("Clusters\n");
    for (int i = 0; i < cluster_count; i++) {
        print_cluster(clusters[i]);
    }
}

void initialize_clusters() {
    for (int i = 0; i < cluster_count; i++) {
        clusters[i].centroid = points[i];
        add_point_to_cluster(&clusters[i], points[i]);
    }
}

void add_cluster(struct point p) {
    struct cluster c;
    c.centroid = p;
    add_point_to_cluster(&c, p);
    clusters[cluster_count++] = c;
}

void update_centroids() {
    for (int i = 0; i < cluster_count; i++) {
        double x_sum = 0;
        double y_sum = 0;
        for (int j = 0; j < clusters[i].point_count; j++) {
            x_sum += clusters[i].points[j].x;
            y_sum += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = x_sum / clusters[i].point_count;
        clusters[i].centroid.y = y_sum / clusters[i].point_count;
    }
}

void assign_points_to_clusters() {
    for (int i = 0; i < point_count; i++) {
        double min_distance = INFINITY;
        int closest_cluster_index = -1;
        for (int j = 0; j < cluster_count; j++) {
            double d = distance(points[i], clusters[j].centroid);
            if (d < min_distance) {
                min_distance = d;
                closest_cluster_index = j;
            }
        }
        add_point_to_cluster(&clusters[closest_cluster_index], points[i]);
    }
}

bool do_clusters_match(struct cluster* c1, struct cluster* c2) {
    if (c1->point_count != c2->point_count) {
        return false;
    }
    for (int i = 0; i < c1->point_count; i++) {
        if (!are_points_equal(c1->points[i], c2->points[i])) {
            return false;
        }
    }
    return true;
}

bool clusters_match(struct cluster* new_clusters) {
    for (int i = 0; i < cluster_count; i++) {
        if (!do_clusters_match(&clusters[i], &new_clusters[i])) {
            return false;
        }
    }
    return true;
}

void cluster() {
    reset_clusters();
    initialize_clusters();
    while (true) {
        struct cluster new_clusters[MAX_CLUSTER_COUNT];
        for (int i = 0; i < cluster_count; i++) {
            new_clusters[i] = clusters[i];
        }
        update_centroids();
        assign_points_to_clusters();
        if (clusters_match(new_clusters)) {
            break;
        }
    }
}

int main() {
    add_point((struct point){2, 10});
    add_point((struct point){2, 5});
    add_point((struct point){8, 4});
    add_point((struct point){5, 8});
    add_point((struct point){7, 5});
    add_point((struct point){6, 4});
    cluster();
    print_clusters();

    return 0;
}