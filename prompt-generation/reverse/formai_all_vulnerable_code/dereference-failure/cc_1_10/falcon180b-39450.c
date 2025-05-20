//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 100

typedef struct {
    char *key;
    char *value;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries;

void init() {
    num_entries = 0;
}

int hash(char *key) {
    int hash_value = 0;
    int i = 0;
    while (key[i]) {
        hash_value += key[i++];
    }
    return hash_value % MAX_ENTRIES;
}

int search(char *key) {
    int index = hash(key);
    while (entries[index].key!= NULL) {
        if (strcmp(entries[index].key, key) == 0) {
            return index;
        }
        index = (index + 1) % MAX_ENTRIES;
    }
    return -1;
}

int insert(char *key, char *value) {
    int index = search(key);
    if (index!= -1) {
        strcpy(entries[index].value, value);
        return 0;
    }
    if (num_entries >= MAX_ENTRIES) {
        return -1;
    }
    strcpy(entries[num_entries].key, key);
    strcpy(entries[num_entries].value, value);
    num_entries++;
    return 0;
}

int delete(char *key) {
    int index = search(key);
    if (index == -1) {
        return -1;
    }
    strcpy(entries[index].key, "");
    strcpy(entries[index].value, "");
    return 0;
}

void print_entry(int index) {
    if (entries[index].key == NULL) {
        printf("[%d] Empty\n", index);
    } else {
        printf("[%d] Key: %s, Value: %s\n", index, entries[index].key, entries[index].value);
    }
}

void print_table() {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (entries[i].key!= NULL) {
            print_entry(i);
        }
    }
}

int main() {
    init();
    insert("apple", "red");
    insert("banana", "yellow");
    insert("cherry", "red");
    print_table();
    delete("banana");
    print_table();
    return 0;
}