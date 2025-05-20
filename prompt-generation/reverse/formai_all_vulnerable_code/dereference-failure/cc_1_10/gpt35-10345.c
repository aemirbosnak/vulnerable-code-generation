//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main(){

    int n, num_clusters, i, j, k, l, m, o, min_distance, min_cluster;
    float **data_points, **centroids, *cluster_distances;

    printf("How many data points do you have: ");
    scanf("%d", &n);

    data_points = (float**)malloc(n*sizeof(float*));

    for(i=0;i<n;i++){
        printf("Enter data point %d: ", i+1);
        data_points[i] = (float*)malloc(2*sizeof(float));
        scanf("%f %f", &data_points[i][0], &data_points[i][1]);
    }

    printf("How many clusters do you want: ");
    scanf("%d", &num_clusters);

    centroids = (float**)malloc(num_clusters*sizeof(float*));
    cluster_distances = (float*)malloc(num_clusters*sizeof(float));

    for(i=0;i<num_clusters;i++){
        centroids[i] = (float*)malloc(2*sizeof(float));
        centroids[i][0] = rand()%10; 
        centroids[i][1] = rand()%10; 
    }

    for(i=0;i<10;i++){  // Run 10 iterations
        for(j=0;j<n;j++){  // For each data point
            min_distance = 1000; 
            for(k=0;k<num_clusters;k++){  // Find the nearest cluster
                cluster_distances[k] = (data_points[j][0] - centroids[k][0])*(data_points[j][0] - centroids[k][0]) +
                                        (data_points[j][1] - centroids[k][1])*(data_points[j][1] - centroids[k][1]);
                if(cluster_distances[k] < min_distance){
                    min_distance = cluster_distances[k];
                    min_cluster = k;  
                }
            }

            // Update the centroid of the nearest cluster
            centroids[min_cluster][0] = (centroids[min_cluster][0]+data_points[j][0])/(float)2;
            centroids[min_cluster][1] = (centroids[min_cluster][1]+data_points[j][1])/(float)2;
        }
    }

    // Print the final centroids
    printf("Final Centroids:\n");
    for(i=0;i<num_clusters;i++){
        printf("%d => (%.2f, %.2f)\n", i+1, centroids[i][0], centroids[i][1]);
    }

    return 0;
}