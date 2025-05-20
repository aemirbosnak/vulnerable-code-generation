//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Entry;

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int search(Entry *table, int size, char *key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(table[mid].key, key);

        if (cmp == 0) {
            return table[mid].value;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int size = 0;
    char input[MAX_SIZE];
    Entry table[MAX_SIZE];

    printf("Enter the size of the table: ");
    scanf("%d", &size);

    printf("Enter the entries:\n");

    while (size < MAX_SIZE) {
        scanf("%s", input);
        table[size].key = strdup(input);
        printf("Enter the value: ");
        scanf("%d", &table[size].value);
        size++;
    }

    qsort(table, size, sizeof(Entry), compare);

    char searchKey[MAX_SIZE];

    while (1) {
        printf("Enter the key to search: ");
        scanf("%s", searchKey);
        int result = search(table, size, searchKey);

        if (result == -1) {
            printf("Key not found.\n");
        } else {
            printf("Value: %d\n", result);
        }

        printf("Search again? (y/n): ");
        char choice[MAX_SIZE];
        scanf("%s", choice);

        if (strcmp(choice, "n") == 0) {
            break;
        }
    }

    return 0;
}