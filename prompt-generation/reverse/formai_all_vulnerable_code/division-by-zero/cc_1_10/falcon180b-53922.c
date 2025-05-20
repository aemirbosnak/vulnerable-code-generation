//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_RANGE 1000000

void bucketSort(int arr[], int n, int range) {
    int i, j, count[MAX_RANGE] = {0};
    int *bucket[MAX_SIZE];

    for(i=0; i<n; i++) {
        count[(arr[i]/range)*range]++;
    }

    for(i=0; i<MAX_RANGE; i++) {
        if(count[i] > 0) {
            bucket[i] = (int*)malloc(count[i]*sizeof(int));
            for(j=0; j<count[i]; j++) {
                bucket[i][j] = i*range;
            }
            count[i] = 0;
        }
    }

    for(i=0; i<n; i++) {
        count[(arr[i]/range)*range]++;
    }

    for(i=0; i<n; i++) {
        int index = (arr[i]/range)*range;
        bucket[index][count[index]++] = arr[i];
    }

    for(i=0; i<n; i++) {
        arr[i] = bucket[((arr[i]/range)*range)][(arr[i]/range)*range - (arr[i]%range)];
    }
}

int main() {
    int n, range, i;
    int arr[MAX_SIZE];

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the range of elements: ");
    scanf("%d", &range);

    printf("Enter the elements:\n");
    for(i=0; i<n; i++) {
        arr[i] = rand()%range;
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n, range);

    printf("Sorted array:\n");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}