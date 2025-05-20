//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//define a structure for each data point
struct dataPoint {
    int id; //unique identifier for each point
    double *features; //the features of the point in n-dimensional space
    int cluster; //the cluster to which the point belongs
};

//define a structure for each cluster
struct cluster {
    int id; //unique identifier for each cluster
    double *centroid; //the centroid of the cluster in n-dimensional space
    struct dataPoint **points; //an array of pointers to data points in the cluster
    int num_points; //the number of points in the cluster
};

//define a function to calculate the Euclidean distance between two data points
double euclidean_distance(double *p1, double *p2, int dim) {
    double sum = 0;
    for (int i = 0; i < dim; i++) {
        sum += pow(p1[i] - p2[i], 2);
    }
    return sqrt(sum);
}

//define a function to initialize the centroids randomly
void initialize_centroids(struct cluster *clusters, int k, int dim, int num_points) {
    for (int i = 0; i < k; i++) {
        //generate a random index for a data point
        int index = rand() % num_points;
        //copy the features of the data point to the centroid
        for (int j = 0; j < dim; j++) {
            clusters[i].centroid[j] = clusters[i].points[index]->features[j];
        }
    }
}

//define a function to assign each data point to its nearest cluster
bool assign_points_to_clusters(struct cluster *clusters, int k, int dim, int num_points) {
    bool changed = false;
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int cluster_id = -1;
        //calculate the Euclidean distance between the data point and each centroid
        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(clusters[j].centroid, clusters[j].points[i]->features, dim);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_id = j;
            }
        }
        //assign the data point to the nearest cluster
        if (clusters[cluster_id].points[i]->cluster != cluster_id) {
            changed = true;
        }
        clusters[cluster_id].points[i]->cluster = cluster_id;
        clusters[cluster_id].points[clusters[cluster_id].num_points++] = clusters[0].points[i];
    }
    return changed;
}

//define a function to update the centroids based on the mean of the points in each cluster
void update_centroids(struct cluster *clusters, int k, int dim) {
    for (int i = 0; i < k; i++) {
        //initialize the centroid to 0
        for (int j = 0; j < dim; j++) {
            clusters[i].centroid[j] = 0;
        }
        //calculate the mean of the points in the cluster
        for (int j = 0; j < clusters[i].num_points; j++) {
            for (int l = 0; l < dim; l++) {
                clusters[i].centroid[l] += clusters[i].points[j]->features[l];
            }
        }
        for (int l = 0; l < dim; l++) {
            clusters[i].centroid[l] /= clusters[i].num_points;
        }
    }
}

int main() {
    //define the number of data points, the dimensionality of the space, and the number of clusters
    int num_points = 1000;
    int dim = 2;
    int k = 5;
    
    //allocate space for the data points and the clusters
    struct dataPoint *points = malloc(num_points * sizeof(struct dataPoint));
    struct cluster *clusters = malloc(k * sizeof(struct cluster));
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = malloc(dim * sizeof(double));
        clusters[i].points = malloc(num_points * sizeof(struct dataPoint *));
    }
    
    //initialize the data points with random features
    for (int i = 0; i < num_points; i++) {
        points[i].id = i;
        points[i].features = malloc(dim * sizeof(double));
        for (int j = 0; j < dim; j++) {
            points[i].features[j] = ((double) rand() / RAND_MAX) * 10;
        }
    }
    
    //initialize the clusters with random centroids
    initialize_centroids(clusters, k, dim, num_points);
    
    //iterate until convergence
    int iter = 0;
    while (true) {
        bool changed = assign_points_to_clusters(clusters, k, dim, num_points);
        update_centroids(clusters, k, dim);
        iter++;
        if (!changed) {
            break;
        }
    }
    
    //print the final cluster assignments
    printf("Final cluster assignments:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < num_points; j++) {
            if (points[j].cluster == i) {
                printf("Point %d (%f, %f)\n", points[j].id, points[j].features[0], points[j].features[1]);
            }
        }
    }
    
    //free the memory allocated for the data points and the clusters
    for (int i = 0; i < num_points; i++) {
        free(points[i].features);
    }
    free(points);
    for (int i = 0; i < k; i++) {
        free(clusters[i].centroid);
        free(clusters[i].points);
    }
    free(clusters);
    
    return 0;
}