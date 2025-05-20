//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1000

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
void add_entry(DiaryEntry* diary[], int* num_entries, DiaryEntry* new_entry) {
    diary[*num_entries] = new_entry;
    (*num_entries)++;
}

// Print a single diary entry
void print_entry(DiaryEntry* entry) {
    printf("Entry:\n");
    printf("Timestamp: %s", ctime(&entry->timestamp));
    printf("Entry: %s\n", entry->entry);
}

// Print all diary entries
void print_all_entries(DiaryEntry* diary[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        print_entry(diary[i]);
        printf("\n");
    }
}

// Get the current time
time_t get_current_time() {
    time_t current_time;
    time(&current_time);
    return current_time;
}

// Get a diary entry from the user
DiaryEntry* get_entry_from_user() {
    char entry[MAX_ENTRY_LENGTH];
    printf("Enter your diary entry:\n");
    fgets(entry, MAX_ENTRY_LENGTH, stdin);
    return create_entry(get_current_time(), entry);
}

// Main function
int main() {
    // Create an array of diary entries
    DiaryEntry* diary[MAX_ENTRIES];

    // Initialize the number of diary entries to 0
    int num_entries = 0;

    // Get a diary entry from the user
    DiaryEntry* new_entry = get_entry_from_user();

    // Add the new entry to the diary
    add_entry(diary, &num_entries, new_entry);

    // Print all diary entries
    print_all_entries(diary, num_entries);

    return 0;
}