//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>  
#include <stdlib.h>  

// defining the structure of a bucket node  
struct BucketNode {  
    int data;  
    struct BucketNode* next;  
};  
  
void Bucket_Sort(int arr[], int n, int max_value) {    
    int i, j;  
    struct BucketNode** buckets;  

    //creating buckets array based on the maximum value   
    buckets = (struct BucketNode**) malloc(sizeof(struct BucketNode*) * (max_value + 1));  
  
    // setting each element of the bucket array to null initially  
    for (i = 0; i < max_value + 1; ++i) {  
        buckets[i] = NULL;  
    }  
  
    // inserting the values in the buckets based on their corresponding indices  
    for (i = 0; i < n; ++i) {  
        struct BucketNode* current;  
        int pos = arr[i];  
        current = (struct BucketNode*) malloc(sizeof(struct BucketNode));  
        current->data = arr[i];  
        current->next = buckets[pos];  
        buckets[pos] = current;  
    }  
  
    // iterating through each bucket and sorting their elements individually  
    for (i = 0; i < max_value + 1; ++i) {  
        struct BucketNode* current;  
        current = buckets[i];  
        while (current != NULL) {  
            arr[j++] = current->data;  
            current = current->next;  
        }  
    }  

    // freeing the nodes used in the buckets  
    for (i = 0; i < max_value + 1; ++i) {  
        struct BucketNode* current;  
        current = buckets[i];  
        while (current != NULL) {  
            struct BucketNode* temp;  
            temp = current;  
            current = current->next;  
            free(temp);  
        }  
    }  
  
    // freeing the bucket array  
    free(buckets);  
}  
  
int main() {  
    int n, i, max = 0;    
    printf("\nEnter the number of elements : ");  
    scanf("%d", &n);    
    int arr[n];    
    printf("\nEnter the elements to be sorted :\n\n");  
    for(i = 0; i < n; i++) {   
        scanf("%d",&arr[i]);   
        if(arr[i] > max){    
            max = arr[i];    
        }    
    }    
    printf("\nArray before sorting : \n");  
    for (i = 0;i < n;++i) {  
        printf("%d ", arr[i]);  
    }  
    Bucket_Sort(arr, n, max);  
    printf("\n\nArray after sorting : \n");  
    for (i = 0;i < n;++i) {  
        printf("%d ", arr[i]);  
    }  
    return 0;  
}