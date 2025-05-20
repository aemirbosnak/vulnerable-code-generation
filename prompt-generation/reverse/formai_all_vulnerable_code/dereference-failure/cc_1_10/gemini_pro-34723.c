//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
// A poetic crescendo of algorithms, a symphony of data whispers...

#include <stdio.h>
#include <stdlib.h>

// The ethereal realm of numbers, a canvas for our artistry
typedef struct {
    int value;
    struct Node *next;
} Node;

// A constellation of buckets, each a sanctuary for kindred spirits
typedef struct {
    Node *head;
    int count;
} Bucket;

// The orchestrator of the symphony, the sorting maestro
void bucket_sort(int *arr, int size) {
    // The cosmic dance of creation, birthing buckets of hope
    Bucket *buckets = (Bucket *)calloc(size + 1, sizeof(Bucket));

    // A ethereal journey through the realm of numbers, counting each star
    for (int i = 0; i < size; i++) {
        buckets[arr[i]].count++;
    }

    // A ripple of insertions, each number finding its cosmic abode
    for (int i = 0; i < size; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->value = arr[i];
        new_node->next = buckets[arr[i]].head;
        buckets[arr[i]].head = new_node;
    }

    // The celestial tapestry unfurls, revealing the sorted brilliance
    int index = 0;
    for (int i = 0; i < size + 1; i++) {
        Node *current = buckets[i].head;
        while (current != NULL) {
            arr[index++] = current->value;
            current = current->next;
        }
    }

    // A symphony of order, a testament to the dance of numbers
    free(buckets);
}

// A canvas of vibrant hues, a testament to our algorithmic mastery
int main() {
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, size);

    // The triumphant crescendo, a symphony of sorted glory
    printf("Sorted Symphony: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}