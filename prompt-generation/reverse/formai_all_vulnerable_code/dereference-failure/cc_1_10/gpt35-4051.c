//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Bucket node definition
typedef struct node {
    int value;
    struct node* next;
} node;

// Function to insert a value into a bucket
void insert_into_bucket(int value, node** bucket)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;

    if (*bucket == NULL) {
        *bucket = new_node;
    }
    else {
        node* current = *bucket;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to get the index of the bucket for a value
int get_bucket_index(int value, int range, int num_buckets)
{
    return (int)((double)value / range * (num_buckets - 1));
}

// Function to generate random integer array of given size
int* generate_array(int size)
{
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

// Function to print an integer array
void print_array(int* array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to free all nodes in a bucket
void free_bucket(node* bucket)
{
    while (bucket != NULL) {
        node* temp = bucket;
        bucket = bucket->next;
        free(temp);
    }
}

// Bucket sort function
void bucket_sort(int* array, int size, int num_buckets)
{
    // Create an array of buckets
    node** buckets = (node**)calloc(num_buckets, sizeof(node*));

    // Determine the range of values in the array
    int min_value = array[0];
    int max_value = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
        }
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    int range = max_value - min_value + 1;

    // Insert each value in the array into the appropriate bucket
    for (int i = 0; i < size; i++) {
        int index = get_bucket_index(array[i], range, num_buckets);
        insert_into_bucket(array[i], &buckets[index]);
    }

    // Replace the original array with the sorted values in the buckets
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        node* current = buckets[i];
        while (current != NULL) {
            array[index++] = current->value;
            current = current->next;
        }
        free_bucket(buckets[i]);
    }

    // Free the array of buckets
    free(buckets);
}

int main()
{
    // Generate random array and print it
    int size = 10;
    int* array = generate_array(size);
    printf("Unsorted array:\n");
    print_array(array, size);

    // Sort the array using bucket sort and print it
    int num_buckets = 5;
    bucket_sort(array, size, num_buckets);
    printf("Sorted array:\n");
    print_array(array, size);

    // Free the allocated array
    free(array);

    return 0;
}