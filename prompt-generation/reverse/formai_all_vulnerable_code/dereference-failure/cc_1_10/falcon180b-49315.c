//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

//Function to find maximum element in an array
int findMax(int arr[], int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

//Function to perform bucket sort
void bucketSort(int arr[], int n){
    int max=findMax(arr,n);
    int size=max/10;
    int **bucket=(int **)malloc(size*sizeof(int *));
    for(int i=0;i<size;i++){
        bucket[i]=(int *)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++){
        int index=arr[i]/size;
        bucket[arr[i]/size][index%size]=arr[i];
    }
    int j=0;
    for(int i=0;i<size;i++){
        for(int k=0;k<n;k++){
            arr[j++]=bucket[i][k];
        }
    }
    for(int i=0;i<size;i++){
        free(bucket[i]);
    }
    free(bucket);
}

//Main function
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bucketSort(arr,n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}