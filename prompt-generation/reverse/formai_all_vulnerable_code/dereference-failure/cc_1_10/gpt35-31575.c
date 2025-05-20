//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}

int maxIndex(int *arr, int n) {
    int maxIndx = 0;
    for(int i=0; i<n; i++) {
        if(arr[maxIndx] < arr[i])
            maxIndx = i;
    }
    return maxIndx;
}

void distribute(int *arr, int n, int k) {
    int *distrib = (int *)calloc(k, sizeof(int));
    int maxIndx;
    
    for(int i=0; i<n; i++) {
        maxIndx = maxIndex(distrib, k);
        distrib[maxIndx] += arr[i];
    }
    
    printf("Distribution of packets in %d bags -\n", k);
    for(int i=0; i<k; i++) {
        printf("Bag %d: %d packets\n", i+1, distrib[i]);
    }
    
    free(distrib);
}

int main() {
    int n, k;
    printf("Enter total number of packets: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter number of bags to distribute in: ");
    scanf("%d", &k);
    
    printf("Enter number of packets in each bag -\n");
    for(int i=0; i<n; i++) {
        printf("Packet %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    sort(arr, n);
    distribute(arr, n, k);
    
    free(arr);
    return 0;
}