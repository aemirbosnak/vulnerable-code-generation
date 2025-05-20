//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void create_bucket(Bucket *b, int size) {
    b->arr = (int *)malloc(size * sizeof(int));
    b->size = size;
}

void free_bucket(Bucket *b) {
    free(b->arr);
    b->arr = NULL;
    b->size = 0;
}

void insert_bucket(Bucket *b, int val) {
    if (b->size == 0) {
        create_bucket(b, 1);
    } else if (b->size >= MAX_SIZE) {
        int new_size = b->size * 2;
        int *new_arr = (int *)malloc(new_size * sizeof(int));
        memcpy(new_arr, b->arr, b->size * sizeof(int));
        free_bucket(b);
        create_bucket(b, new_size);
        memcpy(b->arr, new_arr, b->size * sizeof(int));
        free(new_arr);
    }
    int idx = val % b->size;
    int i = 0;
    while (i < b->size && b->arr[i]!= val) {
        i++;
    }
    if (i == b->size) {
        b->arr[i] = val;
        b->size++;
    } else {
        b->arr[idx] = b->arr[i];
        b->arr[i] = val;
    }
}

void print_bucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Bucket b;
    create_bucket(&b, 1);
    for (int i = 0; i < n; i++) {
        insert_bucket(&b, arr[i]);
    }
    printf("Sorted array: ");
    print_bucket(&b);
    free_bucket(&b);
    return 0;
}