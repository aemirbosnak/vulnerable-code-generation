//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include<stdio.h>

// shape shifting function to sort array in ascending order using greedy approach
void sortArray(int n, int* arr){
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// shape shifting function to find maximum sum of contiguous subarray using greedy approach
int maxSubArraySum(int n, int* arr){
    int max_so_far = arr[0];
    int curr_max = arr[0];

    for(int i=1;i<n;i++){
        curr_max = (curr_max+arr[i]>arr[i]) ? curr_max+arr[i] : arr[i];
        max_so_far = (curr_max>max_so_far) ? curr_max : max_so_far; 
    }

    return max_so_far;
}

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter elements of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Given array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    sortArray(n,arr);

    printf("\nSorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    int max_sum = maxSubArraySum(n,arr);

    printf("\nMaximum sum of contiguous subarray: %d",max_sum);

    return 0;
}