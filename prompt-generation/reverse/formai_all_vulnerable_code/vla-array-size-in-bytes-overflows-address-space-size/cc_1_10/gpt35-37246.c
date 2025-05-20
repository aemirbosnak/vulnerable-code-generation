//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: random
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define K 2
#define MAX_ITERATIONS 100

struct Point {
    double x[K];
    int cluster;
};
typedef struct Point Point;

double distance(Point p, Point q){
    double result = 0.0;
    for(int i=0; i<K; i++){
        result += ((p.x[i]-q.x[i])*(p.x[i]-q.x[i]));
    }
    return sqrt(result);
}

int main(){
    int n;
    printf("Enter the number of data points: ");
    scanf("%d",&n);

    Point points[n];
    for(int i=0; i<n; i++){
        printf("Enter the two coordinates for Point %d: ", i+1);
        scanf("%lf",&points[i].x[0]);
        scanf("%lf",&points[i].x[1]);

        points[i].cluster = 0;
    }

    Point centroids[K];
    for(int i=0; i<K; i++){
        centroids[i].x[0] = (rand() % 100)/100.0;
        centroids[i].x[1] = (rand() % 100)/100.0;
        centroids[i].cluster = i+1;
    }

    int iterations = 0;
    while(iterations < MAX_ITERATIONS){
        // Assign points to clusters
        for(int i=0; i<n; i++){
            double min_distance = distance(points[i],centroids[0]);
            int closest_cluster = 1;
            for(int j=1; j<K; j++){
                double dist = distance(points[i],centroids[j]);
                if(dist < min_distance){
                    min_distance = dist;
                    closest_cluster = j+1;
                }
            }
            points[i].cluster = closest_cluster;
        }

        // Update centroids
        int num_points[K] = {0};
        double total[K][K] = {{0.0}};
        for(int i=0; i<n; i++){
            num_points[points[i].cluster-1]++;
            for(int j=0; j<K; j++){
                total[points[i].cluster-1][j] += points[i].x[j];
            }
        }
        for(int i=0; i<K; i++){
            for(int j=0; j<K; j++){
                if(num_points[i] > 0){
                    centroids[i].x[j] = total[i][j] / num_points[i];
                }
            }
        }

        iterations++;
    }

    // Print results
    printf("\n\nFinal clustering:\n");
    for(int i=0; i<K; i++){
        printf("Cluster %d:\n", i+1);
        for(int j=0; j<n; j++){
            if(points[j].cluster == i+1){
                printf("\tPoint %d: (%.2lf,%.2lf)\n", j+1, points[j].x[0], points[j].x[1]);
            }
        }
        printf("Centroid: (%.2lf,%.2lf)\n", centroids[i].x[0], centroids[i].x[1]);
    }

    return 0;
}