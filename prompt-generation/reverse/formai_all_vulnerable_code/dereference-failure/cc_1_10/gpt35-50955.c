//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void initialize(int rows, int cols, float data[rows][cols]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            data[i][j] = rand()%10;
        }
    }
}

void kmeans(int k, int rows, int cols, float data[rows][cols]){
    int clusters[rows], oldClusters[rows];
    float centroids[k][cols], distance, minDistance;
    int iterations = 0;
    int counter[k];
    float sum[k][cols];
    int flag = 0;

    // initialize random centroids
    for(int i=0; i<k; i++){
        for(int j=0; j<cols; j++){
            centroids[i][j] = data[rand()%rows][j];
        }
    }

    while(!flag){
        // initialize cluster counts and sums
        for(int i=0; i<k; i++){
            counter[i] = 0;

            for(int j=0; j<cols; j++){
                sum[i][j] = 0;
            }
        }

        // assign nearest centroid to each point
        for(int i=0; i<rows; i++){
            minDistance = INFINITY;

            for(int j=0; j<k; j++){
                distance = 0;

                for(int l=0; l<cols; l++){
                    distance += pow(data[i][l] - centroids[j][l], 2);
                }

                distance = sqrt(distance);

                if(distance < minDistance){
                    clusters[i] = j;
                    minDistance = distance;
                }
            }
        }

        // check if clusters have changed
        if(iterations > 0){
            flag = 1;

            for(int i=0; i<rows; i++){
                if(clusters[i] != oldClusters[i]){
                    flag = 0;
                    break;
                }
            }
        }

        if(!flag){
            iterations++;

            // update centroids 
            for(int i=0; i<rows; i++){
                counter[clusters[i]]++;

                for(int j=0; j<cols; j++){
                    sum[clusters[i]][j] += data[i][j];
                }
            }

            for(int i=0; i<k; i++){
                for(int j=0; j<cols; j++){
                    centroids[i][j] = sum[i][j] / counter[i];
                }
            }

            // store old clusters
            for(int i=0; i<rows; i++){
                oldClusters[i] = clusters[i];
            }
        }
    }

    // print final clusters and centroids
    printf("Final Clusters:\n");

    for(int i=0; i<k; i++){
        printf("Cluster %d: ", i);

        for(int j=0; j<rows; j++){
            if(clusters[j] == i){
                printf("%d ", j);
            }
        }

        printf("\n");
    }
    printf("Final Centroids:\n");

    for(int i=0; i<k; i++){
        printf("Centroid %d: ", i);

        for(int j=0; j<cols; j++){
            printf("%f ", centroids[i][j]);
        }

        printf("\n");
    }
}

int main(){
    srand(time(0));

    int k = 2; // number of clusters
    int rows = 10; // number of data points
    int cols = 2; // number of features

    float data[rows][cols];

    initialize(rows, cols, data);

    kmeans(k, rows, cols, data);

    return 0;
}