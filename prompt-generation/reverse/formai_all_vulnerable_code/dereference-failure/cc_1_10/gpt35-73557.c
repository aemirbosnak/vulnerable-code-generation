//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

typedef struct point{
    double x;
    double y;
} Point;

typedef struct cluster{
    Point centroid;
    Point* points;
    int num_points;
} Cluster;

double euclidean_distance(Point a, Point b){
    double distance = sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
    return distance;
}

Point random_point(Point min, Point max){
    Point random;
    random.x = ((double)rand() / RAND_MAX) * (max.x - min.x) + min.x;
    random.y = ((double)rand() / RAND_MAX) * (max.y - min.y) + min.y;
    return random;
}

double calculate_angle(Point a, Point b){
    double angle = atan2(b.y-a.y, b.x-a.x);
    if (angle < 0){
        angle = 2*PI + angle;
    }
    return angle;
}

void calculate_centroids(Cluster* clusters, int num_clusters){
    for(int i=0; i<num_clusters; i++){
        double x_sum = 0.0;
        double y_sum = 0.0;
        for(int j=0; j<clusters[i].num_points; j++){
            x_sum += clusters[i].points[j].x;
            y_sum += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = x_sum / clusters[i].num_points;
        clusters[i].centroid.y = y_sum / clusters[i].num_points;
    }
}

void assign_points_to_clusters(Point* points, int num_points, Cluster* clusters, int num_clusters){
    for(int i=0; i<num_points; i++){
        double min_distance = INFINITY;
        int cluster_index = -1;
        for(int j=0; j<num_clusters; j++){
            double distance = euclidean_distance(points[i], clusters[j].centroid);
            if(distance < min_distance){
                min_distance = distance;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points = realloc(clusters[cluster_index].points, (clusters[cluster_index].num_points+1) * sizeof(Point));
        clusters[cluster_index].points[clusters[cluster_index].num_points] = points[i];
        clusters[cluster_index].num_points++;
    }
}

void print_clusters(Cluster* clusters, int num_clusters){
    for(int i=0; i<num_clusters; i++){
        printf("Cluster %d:\nCentroid: (%lf, %lf)\nPoints: ", i+1, clusters[i].centroid.x, clusters[i].centroid.y);
        for(int j=0; j<clusters[i].num_points; j++){
            printf("(%lf, %lf) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n\n");
    }
}

int main(){
    srand(123);

    int num_points = 100;
    Point min = {0, 0};
    Point max = {10, 10};

    Point* points = malloc(num_points * sizeof(Point));
    for(int i=0; i<num_points; i++){
        points[i] = random_point(min, max);
    }

    int num_clusters = 5;

    Cluster* clusters = malloc(num_clusters * sizeof(Cluster));
    for(int i=0; i<num_clusters; i++){
        clusters[i].centroid = random_point(min, max);
        clusters[i].points = NULL;
        clusters[i].num_points = 0;
    }

    int num_iterations = 10;

    for(int i=0; i<num_iterations; i++){
        assign_points_to_clusters(points, num_points, clusters, num_clusters);
        calculate_centroids(clusters, num_clusters);
        for(int j=0; j<num_clusters; j++){
            free(clusters[j].points);
            clusters[j].points = NULL;
            clusters[j].num_points = 0;
        }
    }

    print_clusters(clusters, num_clusters);

    free(points);
    free(clusters);

    return 0;
}