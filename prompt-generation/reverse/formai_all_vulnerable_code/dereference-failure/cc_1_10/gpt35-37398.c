//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

// struct for controlling each bucket
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// struct for the bucket sort algorithm
typedef struct {
    int num_buckets;
    Node** buckets;
} BucketSort;

// Function to initialize the bucket sort algorithm
void Init_BucketSort(BucketSort* bs, int num_buckets) {
    bs->num_buckets = num_buckets;
    bs->buckets = (Node**)malloc(num_buckets*sizeof(Node*));
    for(int i=0; i<num_buckets; i++) {
        bs->buckets[i] = NULL;
    }
}

// Function to perform the insertion sort algorithm
void InsertionSort(int* arr, int n) {
    int i, j, temp;
    for(i=1; i<n; i++) {
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// Function to perfor the bucket sort algorithm
void Bucket_Sort(int* arr, int n, int num_buckets) {
    BucketSort bs;
    Init_BucketSort(&bs, num_buckets);

    // place the array elements into the respective buckets
    for(int i=0; i<n; i++) {
        int bi = num_buckets*arr[i]/(100+1);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = bs.buckets[bi];
        bs.buckets[bi] = newNode;
    }

    // Sort each bucket and combine
    int index = 0;
    for(int i=0; i<num_buckets; i++) {
        Node* head = bs.buckets[i];
        int len = 0;
        while(head) {
            head = head->next;
            len++;
        }

        if(len>0) {
            int temp_arr[len];
            Node* current = bs.buckets[i];
            int j = 0;
            while(current) {
                temp_arr[j++] = current->data;
                current = current->next;
            }
            InsertionSort(temp_arr, len);

            for(int k=0; k<len; k++) {
                arr[index++] = temp_arr[k];
            }
        }
    }
}

int main() {
    int arr[] = {23, 70, 15, 6, 65, 21};
    int n = sizeof(arr)/sizeof(arr[0]);
    Bucket_Sort(arr, n, 5);

    printf("Sorted Array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}