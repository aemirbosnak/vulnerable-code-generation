//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: scientific
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
} diary_entry;

// Define the structure of a digital diary
typedef struct {
    int num_entries;
    diary_entry entries[MAX_ENTRIES];
} digital_diary;

// Create a new digital diary
digital_diary* create_digital_diary() {
    digital_diary* diary = malloc(sizeof(digital_diary));
    diary->num_entries = 0;
    return diary;
}

// Add a new entry to a digital diary
void add_entry(digital_diary* diary, char* entry) {
    // Get the current timestamp
    time_t timestamp = time(NULL);

    // Create a new diary entry
    diary_entry new_entry;
    new_entry.timestamp = timestamp;
    strcpy(new_entry.entry, entry);

    // Add the new entry to the diary
    diary->entries[diary->num_entries] = new_entry;
    diary->num_entries++;
}

// Print a digital diary
void print_diary(digital_diary* diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        // Get the timestamp of the entry
        time_t timestamp = diary->entries[i].timestamp;

        // Convert the timestamp to a human-readable string
        char* timestamp_string = ctime(&timestamp);

        // Print the entry
        printf("%s: %s\n", timestamp_string, diary->entries[i].entry);
    }
}

// Free the memory allocated for a digital diary
void free_digital_diary(digital_diary* diary) {
    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    digital_diary* diary = create_digital_diary();

    // Add some entries to the diary
    add_entry(diary, "Dear Diary,\nI had a great day today. I went for a walk in the park and saw some beautiful flowers. I also met a new friend and we had a lot of fun talking about science.");
    add_entry(diary, "Dear Diary,\nI'm feeling a little down today. I'm not sure what's wrong, but I just don't feel like myself. I'm going to try to get some rest and see how I feel tomorrow.");
    add_entry(diary, "Dear Diary,\nI had a really productive day today. I finished my science project and got an A on it. I'm so happy with how it turned out.");

    // Print the diary
    print_diary(diary);

    // Free the memory allocated for the diary
    free_digital_diary(diary);

    return 0;
}