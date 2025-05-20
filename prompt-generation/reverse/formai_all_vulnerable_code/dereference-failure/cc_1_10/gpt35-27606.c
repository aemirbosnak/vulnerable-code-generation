//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* define number of clusters and number of attributes for input data */
#define K 3
#define ATTRIBUTES 4

/* define a structure for representing data points */
typedef struct datapoint_t {
    double attributes[ATTRIBUTES];
    int cluster_id;
} datapoint;

/* define a structure for storing cluster centroid */
typedef struct centroid_t {
    double attributes[ATTRIBUTES];
} centroid;

/* define a function to calculate distance between two data points */
double distance(datapoint* d1, datapoint* d2) {
    double dist = 0;
    for(int i=0; i<ATTRIBUTES; i++) {
        dist += pow((d1->attributes[i] - d2->attributes[i]), 2);
    }
    return sqrt(dist);
}

/* define a function to update cluster centroids */
void update_centroids(datapoint** data, int n, centroid* centroids) {
    for(int i=0; i<K; i++) {
        int count = 0;
        double attr_sum[ATTRIBUTES] = {0};
        for(int j=0; j<n; j++) {
            if(data[j]->cluster_id == i) {
                count++;
                for(int k=0; k<ATTRIBUTES; k++) {
                    attr_sum[k] += data[j]->attributes[k];
                }
            }
        }
        if(count == 0) continue;
        for(int k=0; k<ATTRIBUTES; k++) {
            centroids[i].attributes[k] = attr_sum[k] / count;
        }
    }
}

/* define a function to assign data points to clusters */
void assign_clusters(datapoint** data, int n, centroid* centroids) {
    for(int i=0; i<n; i++) {
        double min_dist = INFINITY;
        int min_cluster_id = -1;
        for(int j=0; j<K; j++) {
            double dist = distance(data[i], &centroids[j]);
            if(dist < min_dist) {
                min_dist = dist;
                min_cluster_id = j;
            }
        }
        if(data[i]->cluster_id != min_cluster_id) {
            data[i]->cluster_id = min_cluster_id;
        }
    }
}

int main() {
    /* read input data */
    int n;
    printf("Enter number of data points: ");
    scanf("%d", &n);
    datapoint** data = (datapoint**) malloc(n * sizeof(datapoint*));
    printf("Enter attributes for each data point:\n");
    for(int i=0; i<n; i++) {
        data[i] = (datapoint*) malloc(sizeof(datapoint));
        printf("Data Point %d: ", i+1);
        for(int j=0; j<ATTRIBUTES; j++) {
            scanf("%lf", &data[i]->attributes[j]);
        }
        data[i]->cluster_id = -1; //initialize cluster id to be assigned later
    }
    
    /* initialize centroids */
    centroid centroids[K];
    printf("Initial Centroids:\n");
    for(int i=0; i<K; i++) {
        printf("Centroid %d: ", i+1);
        for(int j=0; j<ATTRIBUTES; j++) {
            centroids[i].attributes[j] = data[i]->attributes[j];
            printf("%lf ", centroids[i].attributes[j]);
        }
        printf("\n");
    }
    
    /* assign clusters and update centroids */
    int max_iterations = 100;
    int iter = 0;
    while(iter < max_iterations) {
        assign_clusters(data, n, centroids);
        update_centroids(data, n, centroids);
        iter++;
    }
    
    /* print final cluster assignments and centroid values */
    printf("Final Clusters and Centroids:\n");
    for(int i=0; i<K; i++) {
        printf("Cluster %d Centroid: ", i+1);
        for(int j=0; j<ATTRIBUTES; j++) {
            printf("%lf ", centroids[i].attributes[j]);
        }
        printf("\n");
    }
    for(int i=0; i<n; i++) {
        printf("Data Point %d Cluster: %d\n", i+1, data[i]->cluster_id+1);
    }
    
    /* cleanup */
    for(int i=0; i<n; i++) {
        free(data[i]);
    }
    free(data);
    
    return 0;
}