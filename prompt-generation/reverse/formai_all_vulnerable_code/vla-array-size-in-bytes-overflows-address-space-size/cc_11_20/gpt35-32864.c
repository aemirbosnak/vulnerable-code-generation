//FormAI DATASET v1.0 Category: Scientific ; Style: sophisticated
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int sum=0;
    float avg;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    avg = (float)sum/n;
    printf("The sum of %d elements is %d\n", n, sum);
    printf("The average of %d elements is %.2f\n", n, avg);
    int max=arr[0], min=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    printf("The maximum element is %d\n", max);
    printf("The minimum element is %d\n", min);
    int count=0;
    for(int i=0; i<n; i++){
        if(arr[i]%2==0){
            count++;
        }
    }
    printf("The number of even elements is %d\n", count);
    int largest_even=-1;
    for(int i=0; i<n; i++){
        if(arr[i]%2==0 && arr[i]>largest_even){
            largest_even=arr[i];
        }
    }
    if(largest_even!=-1){
        printf("The largest even element is %d\n", largest_even);
    }else{
        printf("There is no even element.\n");
    }
    return 0;
}