//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Bucket {
    int *arr;
    int size;
    struct Bucket *next;
} Bucket;

void insertBucket(Bucket **head, int data) {
    Bucket *newBucket = malloc(sizeof(Bucket));
    newBucket->arr = malloc(MAX_SIZE * sizeof(int));
    newBucket->size = 0;
    newBucket->next = NULL;

    newBucket->arr[newBucket->size++] = data;

    if (*head == NULL) {
        *head = newBucket;
    } else {
        (*head)->next = newBucket;
    }
}

void sortBuckets(Bucket *head) {
    Bucket *curr = head;
    while (curr) {
        int i = 0;
        for (i = 0; i < curr->size; i++) {
            int data = curr->arr[i];
            insertBucket(&head, data);
        }
        free(curr->arr);
        free(curr);
    }
}

int main() {
    Bucket *head = NULL;
    insertBucket(&head, 5);
    insertBucket(&head, 3);
    insertBucket(&head, 8);
    insertBucket(&head, 2);
    insertBucket(&head, 4);
    insertBucket(&head, 9);

    sortBuckets(head);

    Bucket *curr = head;
    while (curr) {
        printf("%d ", curr->arr[0]);
        curr = curr->next;
    }

    return 0;
}