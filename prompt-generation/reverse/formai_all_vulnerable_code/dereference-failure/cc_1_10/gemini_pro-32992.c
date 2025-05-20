//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Bucket {
    int value;
    struct Bucket *next;
} Bucket;

typedef struct BucketList {
    struct Bucket *head;
    struct Bucket *tail;
} BucketList;

BucketList *create_bucket_list() {
    BucketList *list = (BucketList *)malloc(sizeof(BucketList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insert_bucket(BucketList *list, int value) {
    Bucket *new_bucket = (Bucket *)malloc(sizeof(Bucket));
    new_bucket->value = value;
    new_bucket->next = NULL;

    if (list->head == NULL) {
        list->head = new_bucket;
        list->tail = new_bucket;
    } else {
        list->tail->next = new_bucket;
        list->tail = new_bucket;
    }
}

void print_bucket_list(BucketList *list) {
    Bucket *current = list->head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

void bucket_sort(int *array, int size) {
    BucketList *buckets[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = create_bucket_list();
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = array[i] / MAX_SIZE;
        insert_bucket(buckets[bucket_index], array[i]);
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        Bucket *current = buckets[i]->head;

        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
    }

    printf("\n");
}

int main() {
    int array[] = {5, 3, 1, 7, 4, 2, 6, 8};
    int size = sizeof(array) / sizeof(array[0]);

    bucket_sort(array, size);

    return 0;
}