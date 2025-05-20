//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: puzzling
#include<stdio.h>

int main() {
    printf("Welcome to the Clustering Algorithm Implementation Program!\n");
    printf("Enter the number of data points: ");
    int n;
    scanf("%d", &n);

    int data[n];
    printf("Enter the data points separated by space: ");
    for(int i=0;i<n;i++) {
        scanf("%d", &data[i]);
    }

    int clusters;
    printf("Enter the number of clusters: ");
    scanf("%d", &clusters);

    printf("Creating initial centroids...\n");
    int centroids[clusters];
    for(int i=0;i<clusters;i++) {
        centroids[i] = data[i];
    }

    int new_centroids[clusters];
    int cluster[n];
    
    printf("Clustering data...\n");
    while(1) {
        int flag = 0;
        
        for(int i=0;i<n;i++) {
            int min_dist = 99999;
            int min_index;
            for(int j=0;j<clusters;j++) {
                int dist = abs(data[i] - centroids[j]);
                if(dist < min_dist) {
                    min_dist = dist;
                    min_index = j;
                }
            }
            if(cluster[i] != min_index) {
                flag = 1;
                cluster[i] = min_index;
            }
        }
        
        if(flag == 0) {
            break;
        }
        
        for(int i=0;i<clusters;i++) {
            int sum = 0;
            int count = 0;
            for(int j=0;j<n;j++) {
                if(cluster[j] == i) {
                    sum += data[j];
                    count++;
                }
            }
            if(count == 0) {
                new_centroids[i] = centroids[i];
            }
            else {
                new_centroids[i] = sum / count;
            }
        }

        int same = 1;
        for(int i=0;i<clusters;i++) {
            if(new_centroids[i] != centroids[i]) {
                same = 0;
                centroids[i] = new_centroids[i];
            }
        }
        if(same) {
            break;
        }
    }

    printf("Data Points grouped into the following clusters: \n");
    for(int i=0;i<clusters;i++) {
        printf("Cluster %d: ", i+1);
        for(int j=0;j<n;j++) {
            if(cluster[j] == i) {
                printf("%d ", data[j]);
            }
        }
        printf("\n");
    }
    return 0;
}