//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    int key;
    int value;
} Pair;

void create(Pair arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        arr[i].key = rand() % MAX_SIZE;
        arr[i].value = rand() % MAX_SIZE;
    }
}

void print(Pair arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d %d\n", arr[i].key, arr[i].value);
    }
}

void search(Pair arr[], int size, int key) {
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i].key == key) {
            printf("Found key %d with value %d\n", key, arr[i].value);
            return;
        }
    }

    printf("Key %d not found\n", key);
}

int main() {
    int size, key;

    printf("Enter array size: ");
    scanf("%d", &size);

    Pair arr[size];

    create(arr, size);
    print(arr, size);

    printf("Enter key to search: ");
    scanf("%d", &key);

    search(arr, size, key);

    return 0;
}