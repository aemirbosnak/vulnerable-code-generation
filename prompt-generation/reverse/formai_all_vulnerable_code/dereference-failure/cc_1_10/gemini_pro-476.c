//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entry structure
typedef struct Entry {
    char *title;
    char *body;
    time_t timestamp;
} Entry;

// Diary structure
typedef struct Diary {
    char *name;
    int num_entries;
    Entry **entries;
} Diary;

// Function to create a new diary
Diary *create_diary(char *name) {
    Diary *diary = malloc(sizeof(Diary));
    diary->name = strdup(name);
    diary->num_entries = 0;
    diary->entries = NULL;
    return diary;
}

// Function to add an entry to a diary
void add_entry(Diary *diary, char *title, char *body) {
    Entry *entry = malloc(sizeof(Entry));
    entry->title = strdup(title);
    entry->body = strdup(body);
    entry->timestamp = time(NULL);

    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(Entry *));
    diary->entries[diary->num_entries++] = entry;
}

// Function to print a diary
void print_diary(Diary *diary) {
    printf("Diary: %s\n", diary->name);
    for (int i = 0; i < diary->num_entries; i++) {
        Entry *entry = diary->entries[i];
        printf("Title: %s\n", entry->title);
        printf("Body: %s\n", entry->body);
        printf("Timestamp: %s\n", ctime(&entry->timestamp));
        printf("\n");
    }
}

// Function to free the memory allocated for a diary
void free_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i]->title);
        free(diary->entries[i]->body);
        free(diary->entries[i]);
    }
    free(diary->entries);
    free(diary->name);
    free(diary);
}

// Main function
int main() {
    // Create a new diary
    Diary *diary = create_diary("My Diary");

    // Add some entries to the diary
    add_entry(diary, "First Entry", "This is my first entry in my new digital diary.");
    add_entry(diary, "Second Entry", "Today I went to the store and bought some groceries.");
    add_entry(diary, "Third Entry", "I had a great time at work today.");

    // Print the diary
    print_diary(diary);

    // Free the memory allocated for the diary
    free_diary(diary);

    return 0;
}