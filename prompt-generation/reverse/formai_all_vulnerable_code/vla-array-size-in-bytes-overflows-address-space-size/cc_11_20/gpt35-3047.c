//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = 0, min = 0;
    for(int i=0; i<k; i++) {
        if(arr[i] > arr[max]) {
            max = i;
        }
        if(arr[i] < arr[min]) {
            min = i;
        }
    }
    int diff = arr[max] - arr[min];

    for(int i=k; i<n; i++) {
        if(arr[i-k] == arr[max]) {
            max = i-k+1;
            for(int j=i-k+2; j<=i; j++) {
                if(arr[j] > arr[max]) {
                    max = j;
                }
            }
        }
        if(arr[i] > arr[max]) {
            max = i;
        }
        if(arr[i-k] == arr[min]) {
            min = i-k+1;
            for(int j=i-k+2; j<=i; j++) {
                if(arr[j] < arr[min]) {
                    min = j;
                }
            }
        }
        if(arr[i] < arr[min]) {
            min = i;
        }
        if(arr[max] - arr[min] > diff) {
            diff = arr[max] - arr[min];
        }
    }

    printf("Maximum difference after choosing %d elements: %d\n", k, diff);

    return 0;
}