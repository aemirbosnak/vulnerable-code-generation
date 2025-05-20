//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define K 3 //The number of clusters
#define MAX_ITR 1000 //Maximum number of iterations allowed
#define THRESHOLD 0.0001 //Minimum change required in centroids to terminate iterations

//Function signatures
void initializeCentroids(double** data, int numPoints, int numFeatures, double** centroids);
int findCluster(double* dataPoint, double** centroids, int numFeatures);
void updateCentroids(double** data, int numPoints, int numFeatures, double** centroids, int* clusters);
double calculateDistance(double* dataPoint, double* centroid, int numFeatures);

int main(){

    //Generating some random data points
    srand(time(NULL));
    
    int numPoints = 100;
    int numFeatures = 2;
    double** data = (double**)malloc(numPoints*sizeof(double*));
    for(int i=0; i<numPoints; i++){
        data[i] = (double*)malloc(numFeatures*sizeof(double));
        data[i][0] = rand()%1000;
        data[i][1] = rand()%1000;
    }

    //Initialize centroids
    double** centroids = (double**)malloc(K*sizeof(double*));
    for(int i=0; i<K; i++)
        centroids[i] = (double*)malloc(numFeatures*sizeof(double));
    initializeCentroids(data, numPoints, numFeatures, centroids);

    //Clustering
    int* clusters = (int*)malloc(numPoints*sizeof(int));
    double prevCentroids[K][numFeatures];
    int itrCount = 0;
    while(itrCount<=MAX_ITR){
        //Assign points to clusters
        for(int i=0; i<numPoints; i++)
            clusters[i] = findCluster(data[i], centroids, numFeatures);

        //Backup previous centroids for threshold comparison
        for(int i=0; i<K; i++)
            for(int j=0; j<numFeatures; j++)
                prevCentroids[i][j] = centroids[i][j];

        //Update centroids
        updateCentroids(data, numPoints, numFeatures, centroids, clusters);

        //Check termination criterion
        int terminateFlag = 1;
        for(int i=0; i<K; i++){
            if(calculateDistance(centroids[i], prevCentroids[i], numFeatures) > THRESHOLD){
                terminateFlag = 0;
                break;
            }
        }
        if(terminateFlag==1) break;

        //Increment iteration counter
        itrCount++;
    }

    //Print results
    printf("\nFinal centroids:\n");
    for(int i=0; i<K; i++){
        for(int j=0; j<numFeatures; j++)
            printf("%lf ", centroids[i][j]);
        printf("\n");
    }

    //Free memory
    for(int i=0; i<numPoints; i++)
        free(data[i]);
    free(data);
    for(int i=0; i<K; i++)
        free(centroids[i]);
    free(centroids);
    free(clusters);

    return 0;
}

//Initializes centroids randomly
void initializeCentroids(double** data, int numPoints, int numFeatures, double** centroids){
    for(int i=0; i<K; i++){
        int randIndex = rand() % numPoints;
        for(int j=0; j<numFeatures; j++)
            centroids[i][j] = data[randIndex][j];
    }
}

//Finds the cluster to which the data point belongs
int findCluster(double* dataPoint, double** centroids, int numFeatures){
    int cluster = 0;
    double minDist = calculateDistance(dataPoint, centroids[0], numFeatures);
    for(int i=1; i<K; i++){
        double dist = calculateDistance(dataPoint, centroids[i], numFeatures);
        if(dist<minDist){
            cluster = i;
            minDist = dist;
        }
    }
    return cluster;
}

//Updates centroids based on the assigned cluster of each point
void updateCentroids(double** data, int numPoints, int numFeatures, double** centroids, int* clusters){
    for(int i=0; i<K; i++){
        double sum[numFeatures];
        int count = 0;
        for(int j=0; j<numFeatures; j++)
            sum[j] = 0.0;
        for(int j=0; j<numPoints; j++){
            if(clusters[j]==i){
                count++;
                for(int k=0; k<numFeatures; k++)
                    sum[k] += data[j][k];
            }
        }
        for(int j=0; j<numFeatures; j++){
            if(count==0) centroids[i][j] = 0.0;
            else centroids[i][j] = sum[j]/count;
        }
    }
}

//Calculates Euclidean distance between two points
double calculateDistance(double* dataPoint, double* centroid, int numFeatures){
    double dist = 0.0;
    for(int i=0; i<numFeatures; i++)
        dist += pow(dataPoint[i]-centroid[i], 2);
    return sqrt(dist);
}