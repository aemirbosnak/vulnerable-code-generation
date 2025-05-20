//FormAI DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This struct represents a single entry in the database
struct Entry {
    int id;
    char name[50];
    char email[50];
};

// This struct represents an index entry
struct IndexEntry {
    int id;
    long file_offset;
};

// This struct represents the index
struct Index {
    struct IndexEntry *entries; // Pointer to dynamically allocated array of index entries
    int num_entries;
};

// This function creates a new index with space for `num_entries` entries
struct Index *create_index(int num_entries) {
    struct Index *index = (struct Index *)malloc(sizeof(struct Index));
    index->entries = (struct IndexEntry *)malloc(sizeof(struct IndexEntry) * num_entries);
    index->num_entries = 0;
    return index;
}

// This function adds an entry to the index
void add_entry_to_index(struct Index *index, int id, long file_offset) {
    struct IndexEntry *new_entry = &(index->entries[index->num_entries]); // Get pointer to new entry
    new_entry->id = id;
    new_entry->file_offset = file_offset;
    index->num_entries++;
}

// This function finds the file offset of a given id in the index
long find_entry_in_index(struct Index *index, int id) {
    for (int i = 0; i < index->num_entries; i++) {
        if (index->entries[i].id == id) {
            return index->entries[i].file_offset;
        }
    }
    return -1; // Entry not found
}

// This function writes an entry to a file and returns the file offset of the entry
long write_entry_to_file(FILE *fp, struct Entry *entry) {
    long file_offset = ftell(fp); // Get current file offset
    fwrite(&(entry->id), sizeof(int), 1, fp);
    fwrite(&(entry->name[0]), sizeof(char), sizeof(entry->name), fp);
    fwrite(&(entry->email[0]), sizeof(char), sizeof(entry->email), fp);
    return file_offset;
}

// This function reads an entry from a file at the given file offset
void read_entry_from_file(FILE *fp, long file_offset, struct Entry *entry) {
    fseek(fp, file_offset, SEEK_SET); // Seek to the correct file offset
    fread(&(entry->id), sizeof(int), 1, fp);
    fread(&(entry->name[0]), sizeof(char), sizeof(entry->name), fp);
    fread(&(entry->email[0]), sizeof(char), sizeof(entry->email), fp);
}

int main() {
    struct Index *index = create_index(100); // Create an index with space for 100 entries
    FILE *fp = fopen("database.bin", "wb"); // Open the file for writing in binary mode

    // Write some example entries to the file and add them to the index
    struct Entry entry1 = {1, "Alice", "alice@example.com"};
    struct Entry entry2 = {2, "Bob", "bob@example.com"};
    long offset1 = write_entry_to_file(fp, &entry1);
    long offset2 = write_entry_to_file(fp, &entry2);
    add_entry_to_index(index, entry1.id, offset1);
    add_entry_to_index(index, entry2.id, offset2);

    // Read an entry from the file using the index
    int id_to_find = 2;
    long offset_to_find = find_entry_in_index(index, id_to_find);
    if (offset_to_find != -1) {
        struct Entry entry_to_find;
        read_entry_from_file(fp, offset_to_find, &entry_to_find);
        printf("Found entry with id %d: %s <%s>\n", entry_to_find.id, entry_to_find.name, entry_to_find.email);
    } else {
        printf("Entry with id %d not found\n", id_to_find);
    }

    fclose(fp); // Close the file
    free(index->entries); // Free the dynamically allocated memory for the index
    free(index); // Free the index struct
    return 0;
}