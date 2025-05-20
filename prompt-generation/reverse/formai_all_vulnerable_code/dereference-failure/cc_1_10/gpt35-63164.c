//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double euclidean_distance(double *v1, double *v2, int size){
    double sum = 0.0;
    for(int i=0; i<size; i++){
        sum += pow((v2[i] - v1[i]), 2);
    }
    return sqrt(sum);
}

void print_clusters(double ***clusters, int *cluster_sizes, int k, int feature_size){
    for(int i=0; i<k; i++){
        printf("Cluster %d:\n", i+1);
        for(int j=0; j<cluster_sizes[i]; j++){
            printf("[ ");
            for(int f=0; f<feature_size; f++){
                printf("%f ", *(*(*(clusters+i)+j)+f));
            }
            printf("]\n");
        }
        printf("\n");
    }
}

void k_means_cluster(double **dataset, int dataset_size, int feature_size, int k, int max_iterations){
    double **centroid = (double **)malloc(sizeof(double *) * k);
    double ***clusters = (double ***)malloc(sizeof(double **) * k);
    int *assignments = (int *)malloc(sizeof(int) * dataset_size);
    int *cluster_sizes = (int *)calloc(k, sizeof(int));
    int converged = 0;

    //initialize centroid randomly
    for(int i=0; i<k; i++){
        centroid[i] = (double *)malloc(sizeof(double) * feature_size);
        for(int f=0; f<feature_size; f++){
            centroid[i][f] = (double)(rand() % 1000) / 1000;
        }
    }

    //initialize clusters array
    for(int i=0; i<k; i++){
        clusters[i] = (double **)malloc(sizeof(double *) * dataset_size);
        for(int j=0; j<dataset_size; j++){
            clusters[i][j] = (double *)malloc(sizeof(double) * feature_size);
        }
    }

    //run k-means algorithm
    int iterations = 0;
    while(iterations < max_iterations && !converged){
        //clear cluster sizes and cluster assignments
        for(int i=0; i<k; i++){
            cluster_sizes[i] = 0;
        }
        for(int i=0; i<dataset_size; i++){
            assignments[i] = -1;
        }

        //assign each datapoint to nearest centroid
        for(int i=0; i<dataset_size; i++){
            double min_distance = INFINITY;
            int min_index = -1;
            for(int j=0; j<k; j++){
                double dist = euclidean_distance(dataset[i], centroid[j], feature_size);
                if(dist < min_distance){
                    min_distance = dist;
                    min_index = j;
                }
            }
            assignments[i] = min_index;
            for(int f=0; f<feature_size; f++){
                clusters[min_index][cluster_sizes[min_index]][f] = dataset[i][f];
            }
            cluster_sizes[min_index] += 1;
        }

        //recompute centroid location
        converged = 1;
        for(int i=0; i<k; i++){
            for(int f=0; f<feature_size; f++){
                double sum = 0.0;
                for(int j=0; j<cluster_sizes[i]; j++){
                    sum += clusters[i][j][f];
                }
                double new_centroid = sum / (double)cluster_sizes[i];
                if(new_centroid != centroid[i][f]){
                    converged = 0;
                }
                centroid[i][f] = new_centroid;
            }
        }
        iterations++;
    }

    //print final clusters
    print_clusters(clusters, cluster_sizes, k, feature_size);

    //free memory
    for(int i=0; i<k; i++){
        free(centroid[i]);
    }
    free(centroid);
    for(int i=0; i<k; i++){
        for(int j=0; j<dataset_size; j++){
            free(clusters[i][j]);
        }
        free(clusters[i]);
    }
    free(clusters);
    free(assignments);
    free(cluster_sizes);
}

int main(){
    //sample dataset
    double dataset[][2] = {{1.0, 2.0}, {1.5, 1.8}, {5.0, 8.0}, {8.0, 8.0}, {1.0, 0.6}, {9.0, 11.0}, {1.5, 2.5}, {7.0, 9.0}, {2.0, 1.0}, {3.0, 3.0}, {9.0, 10.0}};
    int dataset_size = sizeof(dataset)/sizeof(dataset[0]);
    int feature_size = sizeof(dataset[0])/sizeof(double);

    //run k-means clustering
    k_means_cluster(dataset, dataset_size, feature_size, 3, 100);

    return 0;
}