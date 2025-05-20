//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Entry structure
typedef struct {
    char *title;
    char *content;
    int date; // YYYYMMDD format
    int time; // HHMM format
} Entry;

// Diary structure
typedef struct {
    char *name;
    int num_entries;
    Entry *entries;
} Diary;

// Create a new diary
Diary *create_diary(char *name) {
    Diary *diary = malloc(sizeof(Diary));
    diary->name = strdup(name);
    diary->num_entries = 0;
    diary->entries = NULL;
    return diary;
}

// Add an entry to a diary
void add_entry(Diary *diary, Entry *entry) {
    diary->entries = realloc(diary->entries, sizeof(Entry) * (diary->num_entries + 1));
    diary->entries[diary->num_entries++] = *entry;
}

// Search for an entry in a diary by title
Entry *search_entry(Diary *diary, char *title) {
    for (int i = 0; i < diary->num_entries; i++) {
        if (strcmp(diary->entries[i].title, title) == 0) {
            return &diary->entries[i];
        }
    }
    return NULL;
}

// Delete an entry from a diary
void delete_entry(Diary *diary, Entry *entry) {
    for (int i = 0; i < diary->num_entries; i++) {
        if (&diary->entries[i] == entry) {
            for (int j = i + 1; j < diary->num_entries; j++) {
                diary->entries[j - 1] = diary->entries[j];
            }
            diary->num_entries--;
            break;
        }
    }
}

// Print a diary
void print_diary(Diary *diary) {
    printf("Diary: %s\n", diary->name);
    for (int i = 0; i < diary->num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", diary->entries[i].title);
        printf("Content: %s\n", diary->entries[i].content);
        printf("Date: %d\n", diary->entries[i].date);
        printf("Time: %d\n\n", diary->entries[i].time);
    }
}

// Free a diary
void free_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].title);
        free(diary->entries[i].content);
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
    Entry entry1 = {.title = "My First Entry", .content = "This is my first entry in my new digital diary.", .date = 20230101, .time = 1200};
    add_entry(diary, &entry1);
    Entry entry2 = {.title = "My Second Entry", .content = "This is my second entry in my new digital diary.", .date = 20230102, .time = 1300};
    add_entry(diary, &entry2);

    // Search for an entry in the diary
    Entry *entry = search_entry(diary, "My First Entry");
    if (entry) {
        printf("Found entry: %s\n", entry->title);
    } else {
        printf("Entry not found.\n");
    }

    // Delete an entry from the diary
    delete_entry(diary, &entry1);

    // Print the diary
    print_diary(diary);

    // Free the diary
    free_diary(diary);

    return 0;
}