//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *key;
    int value;
} Entry;

int compare_entries(const void *a, const void *b) {
    return strcmp(*(Entry **)a, *(Entry **)b);
}

void print_entries(Entry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s -> %d\n", entries[i].key, entries[i].value);
    }
}

int binary_search(Entry *entries, int num_entries, char *key) {
    int left = 0;
    int right = num_entries - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cmp = strcmp(entries[mid].key, key);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int num_entries = 0;
    Entry *entries = NULL;

    char input[MAX_SIZE];
    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        if (num_entries >= MAX_SIZE - 1) {
            printf("Error: Maximum number of entries reached.\n");
            exit(1);
        }

        char *key = strtok(input, " ");
        int value = atoi(strtok(NULL, " "));

        entries = realloc(entries, sizeof(Entry) * ++num_entries);
        entries[num_entries - 1].key = strdup(key);
        entries[num_entries - 1].value = value;
    }

    qsort(entries, num_entries, sizeof(Entry), compare_entries);

    char search_key[MAX_SIZE];
    while (fgets(search_key, MAX_SIZE, stdin)!= NULL) {
        int index = binary_search(entries, num_entries, search_key);
        if (index == -1) {
            printf("Not found.\n");
        } else {
            printf("Found: %s -> %d\n", entries[index].key, entries[index].value);
        }
    }

    free(entries);
    return 0;
}