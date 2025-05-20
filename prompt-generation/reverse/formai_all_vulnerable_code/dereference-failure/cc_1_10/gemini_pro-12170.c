//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Create a bucket
struct bucket {
    int value;
    struct bucket *next;
};

// Create a bucket list
struct bucket_list {
    struct bucket *head;
    struct bucket *tail;
};

// Create a new bucket
struct bucket *create_bucket(int value) {
    struct bucket *new_bucket = (struct bucket *)malloc(sizeof(struct bucket));
    new_bucket->value = value;
    new_bucket->next = NULL;
    return new_bucket;
}

// Insert a value into a bucket
void insert_into_bucket(struct bucket_list *list, int value) {
    struct bucket *new_bucket = create_bucket(value);
    if (list->head == NULL) {
        list->head = new_bucket;
        list->tail = new_bucket;
    } else {
        list->tail->next = new_bucket;
        list->tail = new_bucket;
    }
}

// Sort the values in a bucket list
void sort_bucket_list(struct bucket_list *list) {
    struct bucket *current = list->head;
    struct bucket *previous = NULL;
    while (current != NULL) {
        if (previous != NULL && previous->value > current->value) {
            // Swap the values of the current and previous buckets
            int temp = current->value;
            current->value = previous->value;
            previous->value = temp;
        }
        previous = current;
        current = current->next;
    }
}

// Create a new bucket list
struct bucket_list *create_bucket_list() {
    struct bucket_list *new_list = (struct bucket_list *)malloc(sizeof(struct bucket_list));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

// Sort an array of values using bucket sort
void bucket_sort(int *array, int size) {
    // Create a bucket list for each possible value in the array
    struct bucket_list *buckets[size];
    for (int i = 0; i < size; i++) {
        buckets[i] = create_bucket_list();
    }

    // Insert each value into the appropriate bucket
    for (int i = 0; i < size; i++) {
        insert_into_bucket(buckets[array[i]], array[i]);
    }

    // Sort each bucket list
    for (int i = 0; i < size; i++) {
        sort_bucket_list(buckets[i]);
    }

    // Concatenate the sorted bucket lists into a single array
    int index = 0;
    for (int i = 0; i < size; i++) {
        struct bucket *current = buckets[i]->head;
        while (current != NULL) {
            array[index++] = current->value;
            current = current->next;
        }
    }
}

// Print an array of values
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Create an array of values to be sorted
    int array[] = {5, 3, 1, 2, 4};
    int size = sizeof(array) / sizeof(array[0]);

    // Sort the array using bucket sort
    bucket_sort(array, size);

    // Print the sorted array
    print_array(array, size);

    return 0;
}