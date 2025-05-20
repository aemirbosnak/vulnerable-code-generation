//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: sophisticated
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
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Define the structure of the digital diary
typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries;
} DigitalDiary;

// Create a new digital diary
DigitalDiary* create_digital_diary() {
    DigitalDiary* diary = malloc(sizeof(DigitalDiary));
    diary->num_entries = 0;
    return diary;
}

// Add a new entry to the digital diary
void add_entry(DigitalDiary* diary, char* entry) {
    // Check if the diary is full
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Error: The diary is full.\n");
        return;
    }

    // Get the current timestamp
    time(&diary->entries[diary->num_entries].timestamp);

    // Copy the entry into the diary
    strcpy(diary->entries[diary->num_entries].entry, entry);

    // Increment the number of entries
    diary->num_entries++;
}

// Print the entries in the digital diary
void print_entries(DigitalDiary* diary) {
    // Iterate over the entries in the diary
    for (int i = 0; i < diary->num_entries; i++) {
        // Print the timestamp of the entry
        printf("%s", ctime(&diary->entries[i].timestamp));

        // Print the entry
        printf("%s\n", diary->entries[i].entry);
    }
}

// Free the memory allocated for the digital diary
void free_digital_diary(DigitalDiary* diary) {
    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    DigitalDiary* diary = create_digital_diary();

    // Add some entries to the diary
    add_entry(diary, "This is my first entry.");
    add_entry(diary, "This is my second entry.");
    add_entry(diary, "This is my third entry.");

    // Print the entries in the diary
    print_entries(diary);

    // Free the memory allocated for the diary
    free_digital_diary(diary);

    return 0;
}