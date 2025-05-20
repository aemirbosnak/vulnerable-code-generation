//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
struct diary_entry {
    time_t timestamp;
    char *entry;
};

// Define the structure of the digital diary
struct digital_diary {
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries;
};

// Create a new digital diary
struct digital_diary *new_diary() {
    struct digital_diary *diary = malloc(sizeof(struct digital_diary));
    diary->num_entries = 0;
    return diary;
}

// Add a new entry to the digital diary
void add_entry(struct digital_diary *diary, char *entry) {
    if (diary->num_entries < MAX_ENTRIES) {
        struct diary_entry *new_entry = malloc(sizeof(struct diary_entry));
        new_entry->timestamp = time(NULL);
        new_entry->entry = strdup(entry);
        diary->entries[diary->num_entries++] = *new_entry;
    } else {
        printf("Error: Diary is full\n");
    }
}

// Get an entry from the digital diary by index
struct diary_entry *get_entry(struct digital_diary *diary, int index) {
    if (index < diary->num_entries) {
        return &diary->entries[index];
    } else {
        printf("Error: Invalid index\n");
        return NULL;
    }
}

// Delete an entry from the digital diary by index
void delete_entry(struct digital_diary *diary, int index) {
    if (index < diary->num_entries) {
        free(diary->entries[index].entry);
        for (int i = index + 1; i < diary->num_entries; i++) {
            diary->entries[i - 1] = diary->entries[i];
        }
        diary->num_entries--;
    } else {
        printf("Error: Invalid index\n");
    }
}

// Print the digital diary
void print_diary(struct digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        struct diary_entry *entry = get_entry(diary, i);
        printf("Entry %d:\n", i + 1);
        printf("\tTimestamp: %s\n", ctime(&entry->timestamp));
        printf("\tEntry: %s\n", entry->entry);
    }
}

// Free the memory allocated for the digital diary
void free_diary(struct digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].entry);
    }
    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    struct digital_diary *diary = new_diary();

    // Add some entries to the digital diary
    add_entry(diary, "Today was a great day!");
    add_entry(diary, "I learned a lot in class today.");
    add_entry(diary, "I went for a walk in the park this evening.");

    // Print the digital diary
    print_diary(diary);

    // Delete an entry from the digital diary
    delete_entry(diary, 1);

    // Print the digital diary again
    print_diary(diary);

    // Free the memory allocated for the digital diary
    free_diary(diary);

    return 0;
}