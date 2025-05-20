//FormAI DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

/* Define a structure to hold an index entry */
typedef struct {
    int key;
    long offset;
} index_entry;

/* Define a structure to hold index information */
typedef struct {
    int num_entries;
    index_entry* entries;
} index_table;

/* Function to create a new index entry */
index_entry create_entry(int key, long offset) {
    index_entry entry = { key, offset };
    return entry;
}

/* Function to compare two index entries for sorting */
int compare_entries(const void* a, const void* b) {
    index_entry* entry1 = (index_entry*)a;
    index_entry* entry2 = (index_entry*)b;
    return entry1->key - entry2->key;
}

/* Function to create a new index table */
index_table create_table() {
    index_table table = { 0, NULL };
    return table;
}

/* Function to add an entry to the index table */
void add_entry(index_table* table, index_entry entry) {
    /* Reallocate memory to hold the new entry */
    table->entries = (index_entry*)realloc(table->entries, (table->num_entries + 1) * sizeof(index_entry));

    /* Add the new entry to the end of the table */
    table->entries[table->num_entries] = entry;
    table->num_entries++;
}

/* Function to build the index */
index_table build_index(char* filename) {
    /* Open the file for reading */
    FILE* file = fopen(filename, "rb");

    /* Initialize the index table */
    index_table table = create_table();

    /* Read through the file and add entries to the index */
    int key;
    long offset = 0;
    while (fread(&key, sizeof(int), 1, file) == 1) {
        index_entry entry = create_entry(key, offset);
        add_entry(&table, entry);
        offset += sizeof(int);
    }

    /* Sort the index entries by key */
    qsort(table.entries, table.num_entries, sizeof(index_entry), compare_entries);

    /* Close the file and return the index table */
    fclose(file);
    return table;
}

/* Function to perform a binary search for a key in the index table */
long binary_search(index_table* table, int key) {
    int left = 0;
    int right = table->num_entries - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (table->entries[mid].key == key) {
            return table->entries[mid].offset;
        }
        else if (table->entries[mid].key < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    /* Return -1 if the key is not found */
    return -1;
}

int main() {
    /* Build the index */
    index_table table = build_index("data.dat");

    /* Perform a binary search for a key */
    int key = 42;
    long offset = binary_search(&table, key);
    if (offset != -1) {
        printf("Key %d found at offset %ld\n", key, offset);
    }
    else {
        printf("Key %d not found\n", key);
    }

    /* Free the memory used by the index */
    free(table.entries);

    return 0;
}