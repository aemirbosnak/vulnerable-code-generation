//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int value;
} entry_t;

int compare(const void *a, const void *b) {
    entry_t *entry1 = (entry_t *) a;
    entry_t *entry2 = (entry_t *) b;

    return strcmp(entry1->name, entry2->name);
}

int search(char *name, entry_t *entries, int num_entries) {
    int result = -1;
    qsort(entries, num_entries, sizeof(entry_t), compare);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            result = i;
            break;
        }
    }

    return result;
}

int main() {
    char *names[] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};
    int values[] = {1, 2, 3, 4, 5};
    int num_entries = sizeof(names) / sizeof(char *);

    entry_t *entries = malloc(num_entries * sizeof(entry_t));

    for (int i = 0; i < num_entries; i++) {
        entries[i].name = strdup(names[i]);
        entries[i].value = values[i];
    }

    char *search_name = "Dave";
    int index = search(search_name, entries, num_entries);

    if (index >= 0) {
        printf("Found '%s' at index %d with value %d\n", search_name, index, entries[index].value);
    } else {
        printf("Could not find '%s'\n", search_name);
    }

    free(entries);

    return 0;
}