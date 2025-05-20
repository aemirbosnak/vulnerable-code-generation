//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define ROWS 10
#define COLS 2

float distance(float *a, float *b, int cols){   // function to calculate distance between points a and b
    float sum = 0.0;
    int i;
    for(i=0; i<cols; i++){
        sum += pow((b[i]-a[i]), 2.0);
    }
    return sqrt(sum);
}

int find_nearest(float *point, float **centroids, int k, int cols){   // function to find centroid nearest to the point
    int i, nearest;
    float d, min_d = 10000;   // initializing minimum distance to a large value
    for(i=0; i<k; i++){
        d = distance(point, centroids[i], cols);
        if(d < min_d){
            min_d = d;
            nearest = i;
        }
    }
    return nearest;
}

float** create_centroids(int k, int cols){   // function to create k random centroids in the range of 0 to 1
    int i, j;
    float **centroids = (float**)malloc(k*sizeof(float*));
    for(i=0; i<k; i++){
        centroids[i] = (float*)malloc(cols*sizeof(float));
        for(j=0; j<cols; j++){
            centroids[i][j] = (float)rand()/(float)RAND_MAX;
        }
    }
    return centroids;
}

int main(){
    srand(time(NULL));
    float data_points[ROWS][COLS] = {{0.1, 0.6}, {0.15, 0.71}, {0.08, 0.9}, {0.16, 0.85}, {0.2, 0.3}, {0.25, 0.5}, {0.24, 0.1}, {0.3, 0.2}, {0.35, 0.3}, {0.45, 0.2}};  // sample data points with 10 rows and 2 columns
    int k = 3, i, j, iter = 0;
    float **centroids = create_centroids(k, COLS);  // creating initial k random centroids
    int *cluster = (int*)malloc(ROWS*sizeof(int));   // array to store cluster assignments of each point
    int *old_cluster = (int*)malloc(ROWS*sizeof(int));  // array to store old cluster assignments for comparison
    while(1){                               // loop till the clusters no more change
        iter++;
        for(i=0; i<ROWS; i++){
            cluster[i] = find_nearest(data_points[i], centroids, k, COLS); // finding the nearest centroid for each point
        }
        if(iter != 1){
            int diff_count = 0;
            for(i=0; i<ROWS; i++){
                if(cluster[i] != old_cluster[i]){
                    diff_count++;
                }
            }
            if(diff_count == 0){         // if no point has changed cluster, break out of loop
                break;
            }
        }
        for(i=0; i<ROWS; i++){
            old_cluster[i] = cluster[i];
        }
        float **sum = (float**)malloc(k*sizeof(float*));
        int *count = (int*)malloc(k*sizeof(int));
        for(i=0; i<k; i++){
            sum[i] = (float*)calloc(COLS, sizeof(float));
            count[i] = 0;
        }
        for(i=0; i<ROWS; i++){          // calculating sum of points in each cluster
            int c = cluster[i];
            for(j=0; j<COLS; j++){
                sum[c][j] += data_points[i][j];
            }
            count[c]++;
        }
        for(i=0; i<k; i++){            // updating centroids
            for(j=0; j<COLS; j++){
                centroids[i][j] = sum[i][j]/count[i];
            }
        }
        for(i=0; i<k; i++){
            free(sum[i]);              // freeing memory
        }
        free(sum);
        free(count);
    }
    printf("Final clustering:\n");
    for(i=0; i<k; i++){
        printf("Cluster %d: ", i+1);
        for(j=0; j<ROWS; j++){
            if(cluster[j] == i){
                printf("(%f, %f) ", data_points[j][0], data_points[j][1]);
            }
        }
        printf("\n");
    }
    return 0;
}