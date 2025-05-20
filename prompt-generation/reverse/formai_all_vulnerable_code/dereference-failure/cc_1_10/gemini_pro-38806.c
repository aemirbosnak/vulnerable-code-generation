//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a diary entry
typedef struct {
    char *title;
    char *content;
    int date;
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry* create_entry(char *title, char *content, int date) {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->date = date;
    return entry;
}

// Function to free the memory allocated for a diary entry
void free_entry(DiaryEntry *entry) {
    free(entry->title);
    free(entry->content);
    free(entry);
}

// Function to add a new diary entry to the diary
void add_entry(DiaryEntry **diary, int *num_entries, DiaryEntry *entry) {
    *diary = realloc(*diary, (*num_entries + 1) * sizeof(DiaryEntry));
    (*diary)[*num_entries] = *entry;
    (*num_entries)++;
}

// Function to print a diary entry
void print_entry(DiaryEntry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Date: %d\n", entry->date);
}

// Function to print the entire diary
void print_diary(DiaryEntry *diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        print_entry(&diary[i]);
        printf("\n");
    }
}

// Function to search the diary for a specific title
DiaryEntry* search_diary(DiaryEntry *diary, int num_entries, char *title) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(diary[i].title, title) == 0) {
            return &diary[i];
        }
    }
    return NULL;
}

// Function to delete a diary entry from the diary
void delete_entry(DiaryEntry **diary, int *num_entries, DiaryEntry *entry) {
    int index = -1;
    for (int i = 0; i < *num_entries; i++) {
        if (&diary[i] == entry) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < *num_entries - 1; i++) {
            diary[i] = diary[i + 1];
        }
        *num_entries = *num_entries - 1;
        *diary = realloc(*diary, *num_entries * sizeof(DiaryEntry));
    }
}

// Main function
int main() {
    // Create a new diary
    DiaryEntry *diary = NULL;
    int num_entries = 0;

    // Add some entries to the diary
    add_entry(&diary, &num_entries, create_entry("My First Entry", "This is my first entry in my digital diary.", 20230101));
    add_entry(&diary, &num_entries, create_entry("My Second Entry", "This is my second entry in my digital diary.", 20230102));
    add_entry(&diary, &num_entries, create_entry("My Third Entry", "This is my third entry in my digital diary.", 20230103));

    // Print the entire diary
    print_diary(diary, num_entries);

    // Search the diary for a specific title
    DiaryEntry *entry = search_diary(diary, num_entries, "My Second Entry");
    if (entry != NULL) {
        printf("Found entry:\n");
        print_entry(entry);
    } else {
        printf("Entry not found.\n");
    }

    // Delete an entry from the diary
    delete_entry(&diary, &num_entries, entry);

    // Print the entire diary again
    print_diary(diary, num_entries);

    // Free the memory allocated for the diary
    for (int i = 0; i < num_entries; i++) {
        free_entry(&diary[i]);
    }
    free(diary);

    return 0;
}