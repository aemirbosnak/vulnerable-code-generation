//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct Entry {
    char* key;
    char* value;
    struct Entry* next;
};

void add_entry(struct Entry** entries, char* key, char* value) {
    struct Entry* entry = (struct Entry*)malloc(sizeof(struct Entry));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;

    for (struct Entry* e = *entries; e!= NULL; e = e->next) {
        if (strcmp(e->key, key) == 0) {
            free(e);
            entry->next = *entries;
            *entries = entry;
            return;
        }
    }

    entry->next = *entries;
    *entries = entry;
}

int main() {
    struct Entry* entries = NULL;

    add_entry(&entries, "apple", "fruit");
    add_entry(&entries, "banana", "fruit");
    add_entry(&entries, "cherry", "fruit");
    add_entry(&entries, "date", "fruit");
    add_entry(&entries, "elderberry", "fruit");

    printf("Total entries: %d\n", count_entries(entries));

    add_entry(&entries, "apple", "fruit");
    add_entry(&entries, "banana", "fruit");
    add_entry(&entries, "cherry", "fruit");
    add_entry(&entries, "date", "fruit");
    add_entry(&entries, "elderberry", "fruit");

    printf("Total entries: %d\n", count_entries(entries));

    free(entries);

    return 0;
}

int count_entries(struct Entry* entries) {
    int count = 0;
    struct Entry* e = entries;

    while (e!= NULL) {
        count++;
        e = e->next;
    }

    return count;
}