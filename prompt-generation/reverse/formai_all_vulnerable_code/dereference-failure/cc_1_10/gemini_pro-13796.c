//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the structure of a diary entry
typedef struct diary_entry {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

// Define the structure of the digital diary
typedef struct digital_diary {
    char name[256];
    int num_entries;
    diary_entry* entries;
} digital_diary;

// Create a new digital diary
digital_diary* create_diary(char* name) {
    digital_diary* diary = malloc(sizeof(digital_diary));
    strcpy(diary->name, name);
    diary->num_entries = 0;
    diary->entries = NULL;
    return diary;
}

// Add a new entry to the digital diary
void add_entry(digital_diary* diary, char* entry) {
    // Allocate memory for the new entry
    diary_entry* new_entry = malloc(sizeof(diary_entry));

    // Set the timestamp of the new entry
    new_entry->timestamp = time(NULL);

    // Copy the entry text to the new entry
    strcpy(new_entry->entry, entry);

    // Add the new entry to the array of entries
    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(diary_entry));
    diary->entries[diary->num_entries++] = *new_entry;
}

// Print the digital diary
void print_diary(digital_diary* diary) {
    printf("Digital Diary: %s\n", diary->name);
    printf("Number of entries: %d\n", diary->num_entries);
    for (int i = 0; i < diary->num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("\tTimestamp: %s", ctime(&diary->entries[i].timestamp));
        printf("\tEntry: %s\n", diary->entries[i].entry);
    }
}

// Free the memory allocated for the digital diary
void free_diary(digital_diary* diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(&diary->entries[i]);
    }
    free(diary->entries);
    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    digital_diary* diary = create_diary("My Diary");

    // Add some entries to the digital diary
    add_entry(diary, "Today was a great day! I went for a walk in the park and saw some beautiful flowers.");
    add_entry(diary, "I had a job interview today. I think it went well, but I'm not sure if I'll get the job.");
    add_entry(diary, "I'm feeling really stressed about my exams. I need to start studying more.");

    // Print the digital diary
    print_diary(diary);

    // Free the memory allocated for the digital diary
    free_diary(diary);

    return 0;
}