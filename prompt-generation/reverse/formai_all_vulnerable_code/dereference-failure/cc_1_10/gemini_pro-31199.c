//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 10

// Define the structure of a diary entry
typedef struct {
    char *title;
    char *text;
    time_t timestamp;
} DiaryEntry;

// Define the structure of the digital diary
typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries;
} DigitalDiary;

// Create a new digital diary
DigitalDiary *create_digital_diary() {
    DigitalDiary *diary = malloc(sizeof(DigitalDiary));
    if (diary == NULL) {
        return NULL;
    }

    diary->num_entries = 0;

    return diary;
}

// Destroy a digital diary
void destroy_digital_diary(DigitalDiary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].title);
        free(diary->entries[i].text);
    }

    free(diary);
}

// Add a new entry to the digital diary
int add_entry(DigitalDiary *diary, char *title, char *text) {
    if (diary->num_entries >= MAX_ENTRIES) {
        return -1;
    }

    DiaryEntry *entry = &diary->entries[diary->num_entries];
    entry->title = strdup(title);
    entry->text = strdup(text);
    entry->timestamp = time(NULL);

    diary->num_entries++;

    return 0;
}

// Print the digital diary
void print_diary(DigitalDiary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        DiaryEntry *entry = &diary->entries[i];
        printf("%s\n", entry->title);
        printf("%s\n", entry->text);
        printf("%s\n", ctime(&entry->timestamp));
        printf("\n");
    }
}

// Get the number of entries in the digital diary
int get_num_entries(DigitalDiary *diary) {
    return diary->num_entries;
}

// Get the entry at the given index
DiaryEntry *get_entry(DigitalDiary *diary, int index) {
    if (index < 0 || index >= diary->num_entries) {
        return NULL;
    }

    return &diary->entries[index];
}

// Edit the entry at the given index
int edit_entry(DigitalDiary *diary, int index, char *title, char *text) {
    if (index < 0 || index >= diary->num_entries) {
        return -1;
    }

    DiaryEntry *entry = &diary->entries[index];
    free(entry->title);
    free(entry->text);
    entry->title = strdup(title);
    entry->text = strdup(text);

    return 0;
}

// Delete the entry at the given index
int delete_entry(DigitalDiary *diary, int index) {
    if (index < 0 || index >= diary->num_entries) {
        return -1;
    }

    for (int i = index + 1; i < diary->num_entries; i++) {
        diary->entries[i - 1] = diary->entries[i];
    }

    diary->num_entries--;

    return 0;
}

// Main function
int main() {
    // Create a new digital diary
    DigitalDiary *diary = create_digital_diary();

    // Add some entries to the diary
    add_entry(diary, "My first entry", "This is my first entry in my digital diary.");
    add_entry(diary, "My second entry", "This is my second entry in my digital diary.");
    add_entry(diary, "My third entry", "This is my third entry in my digital diary.");

    // Print the diary
    print_diary(diary);

    // Get the number of entries in the diary
    int num_entries = get_num_entries(diary);

    // Get the entry at the given index
    DiaryEntry *entry = get_entry(diary, 1);

    // Edit the entry at the given index
    edit_entry(diary, 1, "My second entry (edited)", "This is my second entry in my digital diary (edited).");

    // Delete the entry at the given index
    delete_entry(diary, 2);

    // Print the diary again
    print_diary(diary);

    // Destroy the digital diary
    destroy_digital_diary(diary);

    return 0;
}