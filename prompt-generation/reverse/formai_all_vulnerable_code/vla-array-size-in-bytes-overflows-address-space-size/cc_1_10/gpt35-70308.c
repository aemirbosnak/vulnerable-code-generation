//FormAI DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include<stdio.h> 
#include<stdlib.h> 

int futuristic_search(int arr[], int n, int key) 
{ 
    int jumps = sqrt(n); 
    int left = 0, right = 0; 

    while (right < n && arr[right] < key) 
    { 
        left = right;  
        right += jumps; 
    } 

    if(right > n-1) 
        right = n; 

    for(int i=left;i<right;i++) 
    { 
        if(arr[i] == key) 
            return i; 
    } 

    return -1; 
} 

int main(void) 
{ 
    int n,key,result; 

    printf("Enter the size of array: "); 
    scanf("%d",&n); 

    int arr[n]; 

    printf("Enter the elements of array in ascending order: "); 
    for(int i=0;i<n;i++) 
        scanf("%d",&arr[i]); 

    printf("Enter the element to be searched: "); 
    scanf("%d",&key); 

    result = futuristic_search(arr,n,key); 

    if(result == -1) 
        printf("%d not found in the array.",key); 
    else 
        printf("%d found at index %d.",key,result); 

    return 0; 
}