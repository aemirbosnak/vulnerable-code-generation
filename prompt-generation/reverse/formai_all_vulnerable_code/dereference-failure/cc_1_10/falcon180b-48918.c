//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    char *key;
    int value;
} pair;

pair arr[MAX_SIZE];
int count = 0;

int binarySearch(char *key) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(arr[mid].key, key) == 0) {
            return mid;
        } else if (strcmp(arr[mid].key, key) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void insert(char *key, int value) {
    if (count >= MAX_SIZE) {
        printf("Error: Table is full\n");
        return;
    }
    int pos = binarySearch(key);
    if (pos == -1) {
        strcpy(arr[count].key, key);
        arr[count].value = value;
        count++;
    } else {
        printf("Key already exists\n");
    }
}

void delete(char *key) {
    int pos = binarySearch(key);
    if (pos == -1) {
        printf("Key not found\n");
    } else {
        for (int i = pos; i < count - 1; i++) {
            strcpy(arr[i].key, arr[i + 1].key);
            arr[i].value = arr[i + 1].value;
        }
        count--;
    }
}

void search(char *key) {
    int pos = binarySearch(key);
    if (pos == -1) {
        printf("Key not found\n");
    } else {
        printf("Value: %d\n", arr[pos].value);
    }
}

int main() {
    insert("apple", 10);
    insert("banana", 20);
    insert("cherry", 30);
    search("apple");
    search("orange");
    delete("banana");
    search("banana");
    return 0;
}