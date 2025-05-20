//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// A futuristic structure representing an element in a bucket
typedef struct Element {
    float value;
    struct Element* next;
} Element;

// A futuristic bucket structure to hold elements
typedef struct Bucket {
    Element* head;
} Bucket;

// Function prototypes
void initialize_buckets(Bucket* buckets, int num_buckets);
void insert_into_bucket(Bucket* bucket, float value);
void bucket_sort(float* array, int n);
void print_array(float* array, int n);
void free_buckets(Bucket* buckets, int num_buckets);

int main() {
    // Initialize random seed for futuristic randomness
    srand((unsigned int)time(NULL));

    // Size of the futuristic data set
    int n = 100;
    float* data_to_sort = (float*)malloc(n * sizeof(float));

    // Filling the array with futuristic random floating-point numbers
    for (int i = 0; i < n; i++) {
        data_to_sort[i] = (float)(rand() % 10000) / 100.0; // Random float between 0.0 and 100.0
    }

    printf("Unsorted Data:\n");
    print_array(data_to_sort, n);

    // Perform Bucket Sort
    bucket_sort(data_to_sort, n);

    printf("\nSorted Data:\n");
    print_array(data_to_sort, n);

    // Free allocated memory
    free(data_to_sort);

    return 0;
}

// Function to initialize futuristic buckets
void initialize_buckets(Bucket* buckets, int num_buckets) {
    for (int i = 0; i < num_buckets; i++) {
        buckets[i].head = NULL;
    }
}

// Function to insert an element into a bucket
void insert_into_bucket(Bucket* bucket, float value) {
    Element* new_element = (Element*)malloc(sizeof(Element));
    new_element->value = value;
    new_element->next = bucket->head;
    bucket->head = new_element;
}

// The main function implementing Bucket Sort
void bucket_sort(float* array, int n) {
    // Create futuristic buckets
    int num_buckets = 10;
    Bucket* buckets = (Bucket*)malloc(num_buckets * sizeof(Bucket));
    initialize_buckets(buckets, num_buckets);

    // Distribute elements into the buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(array[i] * num_buckets / 100); // Assuming values are in 0-100 range
        if (index >= num_buckets) {
            index = num_buckets - 1; // Handle the upper edge case
        }
        insert_into_bucket(&buckets[index], array[i]);
    }

    // Sort individual buckets and collect back
    int array_index = 0;
    for (int i = 0; i < num_buckets; i++) {
        // Retrieve elements from the bucket and sort them
        Element* current = buckets[i].head;
        float* bucket_array = (float*)malloc(n * sizeof(float));
        int bucket_size = 0;

        while (current != NULL) {
            bucket_array[bucket_size++] = current->value;
            current = current->next;
        }

        // Sort the bucket using simple insertion sort
        for (int j = 1; j < bucket_size; j++) {
            float key = bucket_array[j];
            int k = j - 1;

            // Shift elements of bucket_array while finding the position for key
            while (k >= 0 && bucket_array[k] > key) {
                bucket_array[k + 1] = bucket_array[k];
                k--;
            }
            bucket_array[k + 1] = key;
        }

        // Insert sorted bucket data back into the main array
        for (int j = 0; j < bucket_size; j++) {
            array[array_index++] = bucket_array[j];
        }

        free(bucket_array); // Free the bucket array
    }

    // Free all buckets
    free_buckets(buckets, num_buckets);
}

// Function to print the array in a futuristic style
void print_array(float* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Function to free allocated memory for buckets
void free_buckets(Bucket* buckets, int num_buckets) {
    for (int i = 0; i < num_buckets; i++) {
        Element* current = buckets[i].head;
        while (current != NULL) {
            Element* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets); // Freeing the buckets themselves
}