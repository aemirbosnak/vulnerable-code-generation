//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the structure of a diary entry
typedef struct {
    time_t timestamp;
    char *entry;
} DiaryEntry;

// Create a new diary entry
DiaryEntry *create_entry(time_t timestamp, char *entry) {
    DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
    new_entry->timestamp = timestamp;
    new_entry->entry = strdup(entry);
    return new_entry;
}

// Free the memory allocated for a diary entry
void free_entry(DiaryEntry *entry) {
    free(entry->entry);
    free(entry);
}

// Add a new entry to the diary
void add_entry(DiaryEntry **diary, int *num_entries, DiaryEntry *new_entry) {
    *diary = realloc(*diary, (*num_entries + 1) * sizeof(DiaryEntry));
    (*diary)[*num_entries] = *new_entry;
    (*num_entries)++;
}

// Print the diary
void print_diary(DiaryEntry *diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", ctime(&diary[i].timestamp));
        printf("%s\n", diary[i].entry);
        printf("\n");
    }
}

// Get the current time
time_t get_current_time() {
    time_t current_time;
    time(&current_time);
    return current_time;
}

// Get user input
char *get_user_input() {
    char *input = malloc(MAX_ENTRY_LENGTH);
    fgets(input, MAX_ENTRY_LENGTH, stdin);
    return input;
}

// Main function
int main() {
    // Initialize the diary
    DiaryEntry *diary = NULL;
    int num_entries = 0;

    // Get user input
    char *entry;
    printf("Enter your diary entry (enter 'q' to quit):\n");
    while ((entry = get_user_input()) && strcmp(entry, "q\n") != 0) {
        // Create a new entry
        DiaryEntry *new_entry = create_entry(get_current_time(), entry);

        // Add the new entry to the diary
        add_entry(&diary, &num_entries, new_entry);
    }

    // Print the diary
    print_diary(diary, num_entries);

    // Free the memory allocated for the diary
    for (int i = 0; i < num_entries; i++) {
        free_entry(&diary[i]);
    }
    free(diary);

    return 0;
}