//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 1000 // maximum number of data points allowed
#define K 5 // number of clusters to be formed
#define D 2 // number of dimensions of data points

// compute euclidean distance between two points
double euclideanDistance(double *point1, double *point2) {
    double distance = 0;
    for(int i=0; i<D; i++) {
        distance += pow((point1[i]-point2[i]), 2);
    }
    return sqrt(distance);
}

// randomly initialize centroids for K clusters
void randomInitCentroids(double **dataset, double **centroids, int n_data) {
    int *indices = malloc(K * sizeof(int));
    for(int i=0; i<K; i++) {
        int index = rand() % n_data;
        for(int j=0; j<i; j++) {
            if(indices[j] == index) {
                index = rand() % n_data;
                j = -1;
            }
        }
        indices[i] = index;
        for(int j=0; j<D; j++) {
            centroids[i][j] = dataset[index][j];
        }
    }
    free(indices);
}

// assign each data point to the closest centroid
void assignCentroids(double **dataset, double **centroids, int *labels, int n_data) {
    for(int i=0; i<n_data; i++) {
        double min_distance = INFINITY;
        int min_index = -1;
        for(int j=0; j<K; j++) {
            double distance = euclideanDistance(dataset[i], centroids[j]);
            if(distance < min_distance) {
                min_distance = distance;
                min_index = j;
            }
        }
        labels[i] = min_index;
    }
}

// update centroid values for each cluster
int updateCentroids(double **dataset, double **old_centroids, double **new_centroids, int *labels, int n_data) {
    int convergence = 1;
    int *members = calloc(K, sizeof(int));
    for(int i=0; i<K; i++) {
        for(int j=0; j<D; j++) {
            new_centroids[i][j] = 0;
        }
    }
    for(int i=0; i<n_data; i++) {
        int label = labels[i];
        members[label]++;
        for(int j=0; j<D; j++) {
            new_centroids[label][j] += dataset[i][j];
        }
    }
    for(int i=0; i<K; i++) {
        if(members[i] != 0) {
            for(int j=0; j<D; j++) {
                new_centroids[i][j] /= members[i];
            }
            if(euclideanDistance(new_centroids[i], old_centroids[i]) > 0.01) {
                convergence = 0;
            }
        }
        else {
            randomInitCentroids(dataset, new_centroids, n_data);
        }
    }
    free(members);
    return convergence;
}

// print final cluster assignments
void printClusterAssignments(int *labels, int n_data) {
    printf("Final cluster assignments:\n");
    for(int i=0; i<n_data; i++) {
        printf("Data Point %d: Cluster %d\n", i+1, labels[i]+1);
    }
}

// main function
int main() {
    // read dataset from file
    double **dataset = malloc(N * sizeof(double *));
    for(int i=0; i<N; i++) {
        dataset[i] = malloc(D * sizeof(double));
    }
    FILE *fp = fopen("data.txt", "r");
    int n_data = 0;
    while(fscanf(fp, "%lf,%lf", &dataset[n_data][0], &dataset[n_data][1]) == 2) {
        n_data++;
    }
    fclose(fp);

    // randomly initialize centroids
    double **old_centroids = malloc(K * sizeof(double *));
    double **new_centroids = malloc(K * sizeof(double *));
    for(int i=0; i<K; i++) {
        old_centroids[i] = malloc(D * sizeof(double));
        new_centroids[i] = malloc(D * sizeof(double));
    }
    randomInitCentroids(dataset, old_centroids, n_data);

    // assign data points to initial cluster centroids
    int *labels = malloc(n_data * sizeof(int));
    assignCentroids(dataset, old_centroids, labels, n_data);

    // iteratively update centroids until convergence
    int iterations = 0;
    int max_iterations = 100;
    while(iterations < max_iterations) {
        iterations++;
        int convergence = updateCentroids(dataset, old_centroids, new_centroids, labels, n_data);
        if(convergence) {
            break;
        }
        double **temp = old_centroids;
        old_centroids = new_centroids;
        new_centroids = temp;

        if(iterations == max_iterations) {
            printf("Clustering did not converge in %d iterations.\n", max_iterations);
        }
    }

    // print final cluster assignments
    printClusterAssignments(labels, n_data);

    // free memory
    for(int i=0; i<N; i++) {
        free(dataset[i]);
    }
    free(dataset);
    for(int i=0; i<K; i++) {
        free(old_centroids[i]);
        free(new_centroids[i]);
    }
    free(old_centroids);
    free(new_centroids);
    free(labels);

    return 0;
}