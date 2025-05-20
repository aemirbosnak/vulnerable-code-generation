//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1000

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
    time_t timestamp;
    char *entry;
} DiaryEntry;

// Define the structure of a digital diary
typedef struct {
    char *name;
    int num_entries;
    DiaryEntry entries[MAX_ENTRIES];
} DigitalDiary;

// Create a new digital diary
DigitalDiary *create_diary(char *name) {
    DigitalDiary *diary = malloc(sizeof(DigitalDiary));
    diary->name = name;
    diary->num_entries = 0;
    return diary;
}

// Add a new entry to a digital diary
void add_entry(DigitalDiary *diary, char *entry) {
    if (diary->num_entries == MAX_ENTRIES) {
        printf("Error: Diary is full.\n");
        return;
    }

    DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
    new_entry->timestamp = time(NULL);
    new_entry->entry = strdup(entry);

    diary->entries[diary->num_entries] = *new_entry;
    diary->num_entries++;
}

// Print all the entries in a digital diary
void print_entries(DigitalDiary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Timestamp: %s\n", ctime(&diary->entries[i].timestamp));
        printf("Entry: %s\n\n", diary->entries[i].entry);
    }
}

// Free the memory allocated for a digital diary
void free_diary(DigitalDiary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].entry);
    }

    free(diary->name);
    free(diary);
}

int main() {
    // Create a new digital diary
    DigitalDiary *diary = create_diary("My Diary");

    // Add some entries to the diary
    add_entry(diary, "Today was a good day. I went for a walk in the park and saw some beautiful flowers.");
    add_entry(diary, "I had a great time at work today. I finished a big project and my boss was very happy with it.");
    add_entry(diary, "I went to the movies with my friends tonight. We saw a really funny movie and had a lot of laughs.");

    // Print all the entries in the diary
    print_entries(diary);

    // Free the memory allocated for the diary
    free_diary(diary);

    return 0;
}