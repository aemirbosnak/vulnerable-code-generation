//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_THREADS 2

// Structure for passing arguments to thread functions
struct thread_data {
    int *arr;
    int left, right, num;
    bool found;
};

// Thread function for searching the array asynchronously
void* search(void *arg) {
    struct thread_data *data = arg;
    int *arr = data->arr;
    int left = data->left;
    int right = data->right;
    int num = data->num;
    bool found = false;
    
    for(int i = left; i <= right; i++) {
        if(arr[i] == num) {
            found = true;
            break;
        }
    }
    
    data->found = found;
    pthread_exit(NULL);
}

// Function to search for a number in an array asynchronously
bool async_search(int *arr, int n, int num) {
    int chunk_size = n / NUM_THREADS;
    pthread_t threads[NUM_THREADS];
    struct thread_data *data = malloc(NUM_THREADS * sizeof(struct thread_data));
    int left = 0;
    int right = chunk_size - 1;
    
    // Create threads to search each chunk of the array
    for(int i = 0; i < NUM_THREADS; i++) {
        data[i].arr = arr;
        data[i].left = left;
        data[i].right = right;
        data[i].num = num;
        data[i].found = false;
        
        pthread_create(&threads[i], NULL, search, (void *)&data[i]);
        
        left += chunk_size;
        right += chunk_size;
        
        if(i == NUM_THREADS - 2 && right < n - 1) {
            right = n - 1; // Last thread takes the remaining elements
        }
    }
    
    // Wait for all threads to finish
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Check if number was found
    bool found = false;
    for(int i = 0; i < NUM_THREADS; i++) {
        if(data[i].found) {
            found = true;
            break;
        }
    }
    
    free(data);
    return found;
}

// Driver program to test async_search function
int main() {
    int arr[] = {4, 6, 1, 7, 3, 9, 2, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num = 7;
    
    bool found = async_search(arr, n, num);
    
    if(found) {
        printf("Number %d is present in the array\n", num);
    }
    else {
        printf("Number %d is not present in the array\n", num);
    }
    
    return 0;
}