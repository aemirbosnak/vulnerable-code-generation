//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: calm
// Digital Diary
// A place to reflect and express myself

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_SIZE 256

// Structure to store diary entries
typedef struct {
    char date[20];
    char entry[256];
} diary_entry_t;

// Array to store diary entries
diary_entry_t entries[MAX_ENTRIES];

// Function to print the diary entries
void print_diary() {
    int i;
    printf("--- Digital Diary ---\n");
    for (i = 0; i < MAX_ENTRIES; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
    printf("\n--- End of Diary ---\n");
}

// Function to add a new diary entry
void add_entry(char *date, char *entry) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            // Entry already exists, update the entry
            strcpy(entries[i].entry, entry);
            return;
        }
    }
    // Entry does not exist, add it to the end of the array
    strcpy(entries[i].date, date);
    strcpy(entries[i].entry, entry);
    i++;
}

// Main function
int main() {
    // Initialize the diary entries
    for (int i = 0; i < MAX_ENTRIES; i++) {
        strcpy(entries[i].date, "");
        strcpy(entries[i].entry, "");
    }

    // Print the diary entries
    print_diary();

    // Add a new diary entry
    char *date = "Today";
    char *entry = "Went for a walk in the park and enjoyed the sunshine.";
    add_entry(date, entry);

    // Print the updated diary entries
    print_diary();

    return 0;
}