//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry.
#define MAX_ENTRY_LENGTH 1024

// Define the structure of a diary entry.
typedef struct diary_entry {
    char *date;
    char *entry;
} diary_entry;

// Create a new diary entry.
diary_entry *new_diary_entry(char *date, char *entry) {
    diary_entry *new_entry = malloc(sizeof(diary_entry));
    if (new_entry == NULL) {
        return NULL;
    }
    new_entry->date = malloc(strlen(date) + 1);
    if (new_entry->date == NULL) {
        free(new_entry);
        return NULL;
    }
    strcpy(new_entry->date, date);
    new_entry->entry = malloc(strlen(entry) + 1);
    if (new_entry->entry == NULL) {
        free(new_entry->date);
        free(new_entry);
        return NULL;
    }
    strcpy(new_entry->entry, entry);
    return new_entry;
}

// Free the memory allocated for a diary entry.
void free_diary_entry(diary_entry *entry) {
    free(entry->date);
    free(entry->entry);
    free(entry);
}

// Add a new diary entry to the diary.
void add_diary_entry(diary_entry *entry) {
    // Open the diary file.
    FILE *diary = fopen("diary.txt", "a");
    if (diary == NULL) {
        printf("Error opening diary file.\n");
        return;
    }

    // Write the diary entry to the file.
    fprintf(diary, "%s: %s\n", entry->date, entry->entry);

    // Close the diary file.
    fclose(diary);
}

// Print the diary.
void print_diary() {
    // Open the diary file.
    FILE *diary = fopen("diary.txt", "r");
    if (diary == NULL) {
        printf("Error opening diary file.\n");
        return;
    }

    // Read the diary entries from the file.
    char line[MAX_ENTRY_LENGTH];
    while (fgets(line, MAX_ENTRY_LENGTH, diary)) {
        // Parse the diary entry.
        char *date = strtok(line, ":");
        char *entry = strtok(NULL, "\n");

        // Print the diary entry.
        printf("%s: %s\n", date, entry);
    }

    // Close the diary file.
    fclose(diary);
}

// Main function.
int main() {
    // Create a new diary entry.
    diary_entry *entry1 = new_diary_entry("2023-03-08", "Today was a long and difficult day. I scavenged for food and water in the ruins of the city, but I didn't find much. I'm starting to lose hope.");

    // Add the diary entry to the diary.
    add_diary_entry(entry1);

    // Print the diary.
    print_diary();

    // Free the memory allocated for the diary entry.
    free_diary_entry(entry1);

    return 0;
}