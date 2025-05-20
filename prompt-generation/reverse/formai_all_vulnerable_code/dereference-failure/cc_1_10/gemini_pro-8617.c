//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of an entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of entries
#define MAX_ENTRIES 100

// Define the structure of an entry
typedef struct {
    char *text;
    int date;
    int time;
} entry_t;

// Define the structure of the digital diary
typedef struct {
    entry_t entries[MAX_ENTRIES];
    int num_entries;
} digital_diary_t;

// Create a new digital diary
digital_diary_t *create_digital_diary() {
    digital_diary_t *diary = malloc(sizeof(digital_diary_t));
    if (diary == NULL) {
        return NULL;
    }

    diary->num_entries = 0;

    return diary;
}

// Add an entry to the digital diary
int add_entry(digital_diary_t *diary, char *text, int date, int time) {
    if (diary->num_entries >= MAX_ENTRIES) {
        return -1;
    }

    entry_t *entry = &diary->entries[diary->num_entries++];
    entry->text = strdup(text);
    entry->date = date;
    entry->time = time;

    return 0;
}

// Get an entry from the digital diary
entry_t *get_entry(digital_diary_t *diary, int index) {
    if (index < 0 || index >= diary->num_entries) {
        return NULL;
    }

    return &diary->entries[index];
}

// Print an entry
void print_entry(entry_t *entry) {
    printf("%s\n", entry->text);
    printf("Date: %d\n", entry->date);
    printf("Time: %d\n", entry->time);
}

// Print the digital diary
void print_digital_diary(digital_diary_t *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        print_entry(&diary->entries[i]);
        printf("\n");
    }
}

// Destroy the digital diary
void destroy_digital_diary(digital_diary_t *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].text);
    }

    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    digital_diary_t *diary = create_digital_diary();

    // Add some entries to the digital diary
    add_entry(diary, "Today I went to the park and had a picnic.", 20230521, 1230);
    add_entry(diary, "I started learning C programming today.", 20230522, 1400);
    add_entry(diary, "I finished my first C program today.", 20230523, 1600);

    // Print the digital diary
    print_digital_diary(diary);

    // Destroy the digital diary
    destroy_digital_diary(diary);

    return 0;
}