//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLUSTERS 3
#define MAX_ITERATIONS 100

typedef struct
{
    double x;
    double y;
} point_t;

typedef struct
{
    point_t centroid;
    point_t *points;
    int num_points;
} cluster_t;

double euclidean_distance(point_t a, point_t b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

void assign_points_to_clusters(cluster_t *clusters, int num_clusters, point_t *points, int num_points)
{
    int i, j;
    double distance;
    double min_distance;
    int closest_cluster;
    
    for(i = 0; i < num_points; i++)
    {
        min_distance = INFINITY;
        closest_cluster = 0;
        
        for(j = 0; j < num_clusters; j++)
        {
            distance = euclidean_distance(points[i], clusters[j].centroid);
            
            if(distance < min_distance)
            {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        
        clusters[closest_cluster].points[clusters[closest_cluster].num_points] = points[i];
        clusters[closest_cluster].num_points++;
    }
}

void update_centroids(cluster_t *clusters, int num_clusters)
{
    int i, j, k;
    
    for(i = 0; i < num_clusters; i++)
    {
        double sum_x = 0.0;
        double sum_y = 0.0;
        
        for(j = 0; j < clusters[i].num_points; j++)
        {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        
        clusters[i].centroid.x = sum_x / clusters[i].num_points;
        clusters[i].centroid.y = sum_y / clusters[i].num_points;
        
        for(k = 0; k < clusters[i].num_points; k++)
        {
            clusters[i].points[k] = (point_t){0.0, 0.0};
        }
        
        clusters[i].num_points = 0;
    }
}

void print_clusters(cluster_t *clusters, int num_clusters)
{
    int i, j;
    
    for(i = 0; i < num_clusters; i++)
    {
        printf("Cluster %d:\n", i+1);
        printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        
        printf("Points:\n");
        for(j = 0; j < clusters[i].num_points; j++)
        {
            printf("\t(%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        
        printf("\n");
    }
}

int main()
{
    point_t points[] = {
        {1.0, 2.0},
        {2.0, 1.0},
        {3.0, 2.0},
        {4.0, 3.0},
        {5.0, 5.0},
        {6.0, 6.0},
        {7.0, 5.0},
        {8.0, 6.0},
        {9.0, 7.0}
    };
    
    cluster_t clusters[] = {
        {.centroid = {2.0, 1.0}},
        {.centroid = {6.0, 6.0}},
        {.centroid = {9.0, 7.0}}
    };
    
    int i;
    int iteration_count = 0;
    
    while(iteration_count < MAX_ITERATIONS)
    {
        assign_points_to_clusters(clusters, NUM_CLUSTERS, points, sizeof(points)/sizeof(points[0]));
        update_centroids(clusters, NUM_CLUSTERS);
        iteration_count++;
    }
    
    print_clusters(clusters, NUM_CLUSTERS);
    
    return 0;
}