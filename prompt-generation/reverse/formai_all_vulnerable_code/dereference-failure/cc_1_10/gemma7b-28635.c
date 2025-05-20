//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Bucket {
    char **arr;
    int size;
    struct Bucket *next;
} Bucket;

Bucket *insertBucket(Bucket *head, char *str) {
    Bucket *newBucket = malloc(sizeof(Bucket));
    newBucket->arr = malloc(MAX_SIZE * sizeof(char *));
    newBucket->size = MAX_SIZE;
    newBucket->next = NULL;

    for (int i = 0; i < MAX_SIZE; i++) {
        newBucket->arr[i] = NULL;
    }

    newBucket->arr[0] = str;

    if (head == NULL) {
        head = newBucket;
    } else {
        head->next = newBucket;
    }

    return head;
}

void bucketSort(Bucket *head) {
    Bucket *current = head;
    Bucket *next = NULL;

    while (current) {
        next = current->next;
        current->arr[0] = NULL;
        current = next;
    }

    current = head;

    while (current) {
        next = current->next;
        for (int i = 0; i < current->size; i++) {
            if (current->arr[i] != NULL) {
                printf("%s ", current->arr[i]);
            }
        }
        printf("\n");
        current = next;
    }
}

int main() {
    Bucket *head = NULL;

    insertBucket(head, "abc");
    insertBucket(head, "bcd");
    insertBucket(head, "cde");
    insertBucket(head, "def");

    bucketSort(head);

    return 0;
}