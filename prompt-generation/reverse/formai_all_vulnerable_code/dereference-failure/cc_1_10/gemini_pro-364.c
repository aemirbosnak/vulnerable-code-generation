//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
    char *text;
    time_t timestamp;
} diary_entry;

// Define the structure of a digital diary
typedef struct {
    diary_entry entries[MAX_ENTRIES];
    int num_entries;
} digital_diary;

// Create a new digital diary
digital_diary *create_diary() {
    digital_diary *diary = malloc(sizeof(digital_diary));
    diary->num_entries = 0;
    return diary;
}

// Add a new entry to the digital diary
void add_entry(digital_diary *diary, char *text) {
    // Check if the diary is full
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Error: The diary is full.\n");
        return;
    }

    // Allocate memory for the new entry
    diary->entries[diary->num_entries].text = malloc(strlen(text) + 1);

    // Copy the text of the new entry into the diary
    strcpy(diary->entries[diary->num_entries].text, text);

    // Set the timestamp of the new entry
    diary->entries[diary->num_entries].timestamp = time(NULL);

    // Increment the number of entries in the diary
    diary->num_entries++;
}

// Print the contents of the digital diary
void print_diary(digital_diary *diary) {
    // Loop through the entries in the diary
    for (int i = 0; i < diary->num_entries; i++) {
        // Print the text of the entry
        printf("%s\n", diary->entries[i].text);

        // Print the timestamp of the entry
        printf("%s\n", ctime(&diary->entries[i].timestamp));
    }
}

// Free the memory used by the digital diary
void free_diary(digital_diary *diary) {
    // Loop through the entries in the diary
    for (int i = 0; i < diary->num_entries; i++) {
        // Free the memory used by the text of the entry
        free(diary->entries[i].text);
    }

    // Free the memory used by the diary
    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    digital_diary *diary = create_diary();

    // Add some entries to the diary
    add_entry(diary, "Dear diary, I had a great day today.");
    add_entry(diary, "I went to the park and played with my friends.");
    add_entry(diary, "I also went to the library and read a book.");

    // Print the contents of the diary
    print_diary(diary);

    // Free the memory used by the diary
    free_diary(diary);

    return 0;
}