//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure for each node of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the bucket
struct Bucket {
    struct Node* head;
    struct Node* tail;
};

// Function prototype for insertion sort
void insertion_sort(int arr[], int n);

// Function prototype for bucket sort
void bucket_sort(int arr[], int n, int k);

// Function prototype for printing the array
void print_array(int arr[], int n);

// Main function
int main() {
    int arr[] = { 98, 71, 33, 17, 80, 5, 42, 52 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    printf("Original array: ");
    print_array(arr, n);
    bucket_sort(arr, n, k);
    printf("  Sorted array: ");
    print_array(arr, n);
    return 0;
}

// Definition of insertion_sort function
void insertion_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Definition of bucket_sort function
void bucket_sort(int arr[], int n, int k) {
    int i, j;
    struct Bucket* buckets = (struct Bucket*) calloc(k, sizeof(struct Bucket));
    for (i = 0; i < k; i++) {
        buckets[i].head = NULL;
        buckets[i].tail = NULL;
    }
    for (i = 0; i < n; i++) {
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->data = arr[i];
        new_node->next = NULL;
        int bucket_index = arr[i] / k;
        if (buckets[bucket_index].head == NULL) {
            buckets[bucket_index].head = new_node;
            buckets[bucket_index].tail = new_node;
        } else {
            buckets[bucket_index].tail->next = new_node;
            buckets[bucket_index].tail = new_node;
        }
    }
    for (i = 0, j = 0; i < k; i++) {
        if (buckets[i].head != NULL) {
            struct Node* current = buckets[i].head;
            int bucket_size = 0;
            while (current != NULL) {
                bucket_size++;
                current = current->next;
            }
            int bucket[bucket_size];
            current = buckets[i].head;
            int l = 0;
            while (current != NULL) {
                bucket[l] = current->data;
                l++;
                current = current->next;
            }
            insertion_sort(bucket, bucket_size);
            for (l = 0; l < bucket_size; l++) {
                arr[j] = bucket[l];
                j++;
            }
        }
    }
    for (i = 0; i < k; i++) {
        struct Node* current = buckets[i].head;
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets);
}

// Definition of print_array function
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}