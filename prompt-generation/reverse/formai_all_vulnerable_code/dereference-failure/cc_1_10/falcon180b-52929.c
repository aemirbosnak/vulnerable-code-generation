//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    char value[100];
} record;

record *table;
int size;

void init(int n) {
    table = (record *)malloc(n * sizeof(record));
    size = n;
    for (int i = 0; i < n; i++) {
        table[i].key = -1;
    }
}

void insert(int key, char *value) {
    if (size == 0) {
        init(10);
    }
    if (size == 0 || table[0].key == -1) {
        table[0].key = key;
        strcpy(table[0].value, value);
        return;
    }
    for (int i = 0; i < size; i++) {
        if (table[i].key == key) {
            strcpy(table[i].value, value);
            return;
        }
        if (table[i].key > key) {
            for (int j = i; j > 0; j--) {
                table[j].key = table[j - 1].key;
                strcpy(table[j].value, table[j - 1].value);
            }
            table[0].key = key;
            strcpy(table[0].value, value);
            return;
        }
    }
    for (int i = size - 1; i >= 0; i--) {
        if (table[i].key < key) {
            table[i + 1].key = key;
            strcpy(table[i + 1].value, value);
            return;
        }
    }
}

void search(int key) {
    for (int i = 0; i < size; i++) {
        if (table[i].key == key) {
            printf("Value: %s\n", table[i].value);
            return;
        }
    }
    printf("Not found\n");
}

int main() {
    int n, choice, key;
    char value[100];
    init(10);
    while (1) {
        printf("1. Insert\n2. Search\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%s", value);
            insert(key, value);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            search(key);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}