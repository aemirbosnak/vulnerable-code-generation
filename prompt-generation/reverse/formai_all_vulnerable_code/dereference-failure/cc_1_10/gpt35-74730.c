//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int array[], int n, int max){
    int i,j;
    int *buckets = (int*)malloc(max*sizeof(int));

    for(i=0; i<max; i++){
        buckets[i] = 0;
    }

    for(i=0; i<n; i++){
        ++buckets[array[i]];
    }

    for(i=0,j=0; i<max; i++){
        for(; buckets[i]>0; buckets[i]--){
            array[j++] = i;
        }
    }
    free(buckets);
}

int main(){
    int num;
    int max = -1;
    int *arr;
    int i;

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &num);
    arr = (int*)malloc(num*sizeof(int));

    printf("Enter the elements:\n");
    for(i=0; i<num; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > max){
            max = arr[i];
        }
    }

    bucketSort(arr,num,max+1);

    printf("Sorted Array:\n");
    for(i=0; i<num; i++){
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}