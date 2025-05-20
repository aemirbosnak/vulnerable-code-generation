//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the structure of a diary entry
typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Create a new diary entry
DiaryEntry* create_entry(time_t timestamp, char* entry) {
    DiaryEntry* new_entry = malloc(sizeof(DiaryEntry));
    new_entry->timestamp = timestamp;
    strcpy(new_entry->entry, entry);
    return new_entry;
}

// Add a new entry to the diary
void add_entry(DiaryEntry** diary, int* num_entries, DiaryEntry* new_entry) {
    *diary = realloc(*diary, sizeof(DiaryEntry) * (*num_entries + 1));
    (*diary)[*num_entries] = *new_entry;
    (*num_entries)++;
}

// Print the diary
void print_diary(DiaryEntry* diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Timestamp: %s\n", ctime(&diary[i].timestamp));
        printf("Entry: %s\n\n", diary[i].entry);
    }
}

// Free the memory allocated for the diary
void free_diary(DiaryEntry* diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free(diary[i].entry);
    }
    free(diary);
}

// Main function
int main() {
    // Create a new diary
    DiaryEntry* diary = NULL;
    int num_entries = 0;

    // Add some entries to the diary
    add_entry(&diary, &num_entries, create_entry(time(NULL), "This is my first diary entry."));
    add_entry(&diary, &num_entries, create_entry(time(NULL), "This is my second diary entry."));
    add_entry(&diary, &num_entries, create_entry(time(NULL), "This is my third diary entry."));

    // Print the diary
    print_diary(diary, num_entries);

    // Free the memory allocated for the diary
    free_diary(diary, num_entries);

    return 0;
}