//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to hold a key-value pair
struct kv_pair {
    char* key;
    int value;
};

// Structure to hold the index
struct index {
    struct kv_pair* entries;
    int num_entries;
};

void insert(struct index* index, char* key, int value) {
    if (index->num_entries == 0) {
        index->entries = (struct kv_pair*)malloc(sizeof(struct kv_pair));
        index->entries->key = key;
        index->entries->value = value;
        index->num_entries = 1;
    } else {
        struct kv_pair* new_entry = (struct kv_pair*)malloc(sizeof(struct kv_pair));
        new_entry->key = key;
        new_entry->value = value;
        index->entries = (struct kv_pair*)realloc(index->entries, (index->num_entries + 1) * sizeof(struct kv_pair));
        index->entries[index->num_entries] = *new_entry;
        index->num_entries++;
    }
}

void delete(struct index* index, char* key) {
    if (index->num_entries == 0) {
        return;
    }

    int i;
    for (i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            for (int j = i; j < index->num_entries - 1; j++) {
                index->entries[j] = index->entries[j + 1];
            }
            index->num_entries--;
            break;
        }
    }
}

int search(struct index* index, char* key) {
    if (index->num_entries == 0) {
        return -1;
    }

    int i;
    for (i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }

    return -1;
}

int main() {
    struct index index;
    index.entries = NULL;
    index.num_entries = 0;

    insert(&index, "A", 1);
    insert(&index, "B", 2);
    insert(&index, "C", 3);

    printf("Key: A, Value: %d\n", search(&index, "A"));
    printf("Key: B, Value: %d\n", search(&index, "B"));
    printf("Key: C, Value: %d\n", search(&index, "C"));

    delete(&index, "A");

    printf("Key: A, Value: %d\n", search(&index, "A"));
    printf("Key: B, Value: %d\n", search(&index, "B"));
    printf("Key: C, Value: %d\n", search(&index, "C"));

    return 0;
}