//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 10

// Define the structure of a diary entry
typedef struct diary_entry {
    char *date;
    char *title;
    char *entry;
} diary_entry_t;

// Define the structure of a digital diary
typedef struct digital_diary {
    diary_entry_t entries[MAX_ENTRIES];
    int num_entries;
} digital_diary_t;

// Create a new digital diary
digital_diary_t *create_diary() {
    digital_diary_t *diary = malloc(sizeof(digital_diary_t));
    diary->num_entries = 0;
    return diary;
}

// Add a new entry to the digital diary
void add_entry(digital_diary_t *diary, char *date, char *title, char *entry) {
    // Check if the diary is full
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Error: The diary is full.\n");
        return;
    }

    // Allocate memory for the new entry
    diary_entry_t *new_entry = malloc(sizeof(diary_entry_t));

    // Copy the date, title, and entry into the new entry
    new_entry->date = malloc(strlen(date) + 1);
    strcpy(new_entry->date, date);
    new_entry->title = malloc(strlen(title) + 1);
    strcpy(new_entry->title, title);
    new_entry->entry = malloc(strlen(entry) + 1);
    strcpy(new_entry->entry, entry);

    // Add the new entry to the diary
    diary->entries[diary->num_entries] = *new_entry;
    diary->num_entries++;
}

// Print the contents of the digital diary
void print_diary(digital_diary_t *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("Date: %s\n", diary->entries[i].date);
        printf("Title: %s\n", diary->entries[i].title);
        printf("Entry: %s\n\n", diary->entries[i].entry);
    }
}

// Free the memory allocated for the digital diary
void free_diary(digital_diary_t *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].date);
        free(diary->entries[i].title);
        free(diary->entries[i].entry);
    }
    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    digital_diary_t *diary = create_diary();

    // Add some entries to the diary
    add_entry(diary, "2023-01-01", "New Year's Day", "I woke up this morning feeling refreshed and excited for the new year. I went for a walk in the park and enjoyed the beautiful weather. I am looking forward to all the possibilities that this year has to offer.");
    add_entry(diary, "2023-01-02", "Work", "I went to work today and had a productive day. I finished a few important projects and made some good progress on others. I am feeling good about my work and am excited to see what the future holds.");
    add_entry(diary, "2023-01-03", "Date night", "I went on a date night with my significant other tonight. We had a lovely dinner and then went to see a movie. I am so grateful to have them in my life.");

    // Print the contents of the diary
    print_diary(diary);

    // Free the memory allocated for the digital diary
    free_diary(diary);

    return 0;
}