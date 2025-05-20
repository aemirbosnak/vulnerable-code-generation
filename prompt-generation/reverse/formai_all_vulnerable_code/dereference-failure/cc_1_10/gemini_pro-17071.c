//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
    char date[11];
    char time[9];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

// Define the diary struct
typedef struct {
    diary_entry entries[MAX_ENTRIES];
    int num_entries;
} diary;

// Create a new diary
diary* create_diary() {
    diary* d = malloc(sizeof(diary));
    d->num_entries = 0;
    return d;
}

// Add a new entry to the diary
void add_entry(diary* d, char* date, char* time, char* entry) {
    // Check if the diary is full
    if (d->num_entries == MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    // Copy the date, time, and entry into the diary
    strcpy(d->entries[d->num_entries].date, date);
    strcpy(d->entries[d->num_entries].time, time);
    strcpy(d->entries[d->num_entries].entry, entry);

    // Increment the number of entries
    d->num_entries++;
}

// Print a diary entry
void print_entry(diary_entry* e) {
    printf("Date: %s\n", e->date);
    printf("Time: %s\n", e->time);
    printf("Entry: %s\n\n", e->entry);
}

// Print the entire diary
void print_diary(diary* d) {
    for (int i = 0; i < d->num_entries; i++) {
        print_entry(&d->entries[i]);
    }
}

// Free the memory allocated for the diary
void free_diary(diary* d) {
    free(d);
}

// Main function
int main() {
    // Create a new diary
    diary* d = create_diary();

    // Add some entries to the diary
    add_entry(d, "2023-03-08", "10:00 AM", "I woke up today feeling refreshed and ready to take on the day.");
    add_entry(d, "2023-03-08", "12:00 PM", "I had a great lunch with my friends.");
    add_entry(d, "2023-03-08", "6:00 PM", "I went to the gym and had a great workout.");

    // Print the entire diary
    print_diary(d);

    // Free the memory allocated for the diary
    free_diary(d);

    return 0;
}