//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Pair;

Pair arr[MAX_SIZE];
int count = 0;

void insert(char *key, int value) {
    if (count >= MAX_SIZE) {
        printf("Error: Table is full\n");
        return;
    }
    strcpy(arr[count].key, key);
    arr[count].value = value;
    count++;
}

void search(char *key) {
    int i = 0;
    while (i < count) {
        if (strcmp(arr[i].key, key) == 0) {
            printf("Key found: %s, Value: %d\n", key, arr[i].value);
            return;
        }
        i++;
    }
    printf("Key not found\n");
}

void delete(char *key) {
    int i = 0;
    while (i < count) {
        if (strcmp(arr[i].key, key) == 0) {
            for (int j = i; j < count - 1; j++) {
                strcpy(arr[j].key, arr[j + 1].key);
                arr[j].value = arr[j + 1].value;
            }
            count--;
            printf("Key deleted: %s\n", key);
            return;
        }
        i++;
    }
    printf("Key not found\n");
}

int main() {
    int choice, value;
    char key[MAX_SIZE];

    while (1) {
        printf("1. Insert\n2. Search\n3. Delete\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(key, value);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%s", key);
            search(key);
            break;
        case 3:
            printf("Enter key to delete: ");
            scanf("%s", key);
            delete(key);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}