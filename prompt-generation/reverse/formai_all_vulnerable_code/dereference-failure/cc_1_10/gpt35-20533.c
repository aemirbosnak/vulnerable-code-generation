//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* cluster struct to hold centroid and cluster points */
typedef struct cluster_t{
    double *centroid;
    int count;
    double **points;
}Cluster;

/* function to compute euclidean distance between two points */
double euclidean_distance(double *point1, double *point2, int num_dimensions){
    double distance = 0;
    for(int i=0; i<num_dimensions; i++){
        distance += (point1[i] - point2[i]) * (point1[i] - point2[i]);
    }
    return sqrt(distance);
}

/* function to initialize random centroids */
double **initialize_centroids(double **points, int num_points, int num_dimensions, int num_clusters){
    double **centroids = (double **)malloc(num_clusters * sizeof(double *));
    for(int i=0; i<num_clusters; i++){
        centroids[i] = (double *)malloc(num_dimensions * sizeof(double));
        int random_index = rand() % num_points;
        for(int j=0; j<num_dimensions; j++){
            centroids[i][j] = points[random_index][j];
        }
    }
    return centroids;
}

/* function to assign points to nearest centroid */
int assign_clusters(double **points, int num_points, int num_dimensions, double **centroids, Cluster *clusters, int num_clusters){
    int num_changes = 0;
    for(int i=0; i<num_points; i++){
        double min_distance = INFINITY;
        int cluster_index = -1;
        for(int j=0; j<num_clusters; j++){
            double distance = euclidean_distance(points[i], centroids[j], num_dimensions);
            if(distance < min_distance){
                min_distance = distance;
                cluster_index = j;
            }
        }
        if(cluster_index != clusters[i].count){
            num_changes++;
        }
        clusters[i].count = cluster_index;
        clusters[i].centroid = centroids[cluster_index];
        clusters[i].points = (double **)realloc(clusters[i].points, (clusters[i].count+1) * sizeof(double *));
        clusters[i].points[clusters[i].count] = points[i];
    }
    return num_changes;
}

/* function to recompute centroids based on cluster points */
double **recompute_centroids(Cluster *clusters, int num_clusters, int num_dimensions){
    double **centroids = (double **)malloc(num_clusters * sizeof(double *));
    for(int i=0; i<num_clusters; i++){
        centroids[i] = (double *)calloc(num_dimensions, sizeof(double));
        for(int j=0; j<clusters[i].count; j++){
            for(int k=0; k<num_dimensions; k++){
                centroids[i][k] += clusters[i].points[j][k];
            }
        }
        for(int k=0; k<num_dimensions; k++){
            centroids[i][k] /= clusters[i].count;
        }
    }
    return centroids;
}

/* main function */
int main(){
    /* initialize data set */
    double points[8][2] = {{1.0, 3.0}, {1.5, 5.0}, {3.0, 4.0}, {5.0, 6.0}, {5.5, 6.5}, {6.0, 4.0}, {7.0, 7.0}, {8.0, 5.0}};
    int num_points = 8;
    int num_dimensions = 2;
    int num_clusters = 2;

    /* initialize random centroids */
    double **centroids = initialize_centroids(points, num_points, num_dimensions, num_clusters);

    /* initialize clusters */
    Cluster *clusters = (Cluster *)malloc(num_points * sizeof(Cluster));
    for(int i=0; i<num_points; i++){
        clusters[i].count = -1;
        clusters[i].points = (double **)malloc(sizeof(double *));
    }

    /* assign points to nearest centroid */
    int num_changes = 1;
    int max_iterations = 10;
    int num_iterations = 0;
    while(num_changes != 0 && num_iterations < max_iterations){
        num_changes = assign_clusters(points, num_points, num_dimensions, centroids, clusters, num_clusters);
        centroids = recompute_centroids(clusters, num_clusters, num_dimensions);
        num_iterations++;
    }

    /* print results */
    printf("Final Clusters:\n");
    for(int i=0; i<num_clusters; i++){
        printf("Cluster %d:\n", i+1);
        for(int j=0; j<clusters[i].count; j++){
            printf("(%lf, %lf)\n", clusters[i].points[j][0], clusters[i].points[j][1]);
        }
        printf("Centroid: (%lf, %lf)\n", centroids[i][0], centroids[i][1]);
    }

    /* free memory */
    for(int i=0; i<num_clusters; i++){
        free(centroids[i]);
    }
    free(centroids);
    for(int i=0; i<num_points; i++){
        free(clusters[i].points);
    }
    free(clusters);

    return 0;
}