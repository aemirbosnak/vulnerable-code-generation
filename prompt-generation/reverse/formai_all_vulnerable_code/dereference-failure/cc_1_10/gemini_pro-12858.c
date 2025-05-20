//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Diary entry struct
typedef struct {
    char *date;
    char *entry;
} DiaryEntry;

// Create a new diary entry
DiaryEntry *create_entry(char *date, char *entry) {
    DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
    new_entry->date = malloc(strlen(date) + 1);
    new_entry->entry = malloc(strlen(entry) + 1);
    strcpy(new_entry->date, date);
    strcpy(new_entry->entry, entry);
    return new_entry;
}

// Add an entry to the diary
void add_entry(DiaryEntry **diary, int *num_entries, DiaryEntry *new_entry) {
    *diary = realloc(*diary, (*num_entries + 1) * sizeof(DiaryEntry));
    (*diary)[*num_entries] = *new_entry;
    (*num_entries)++;
}

// Print the diary
void print_diary(DiaryEntry *diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

// Free the memory allocated for the diary
void free_diary(DiaryEntry *diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free(diary[i].date);
        free(diary[i].entry);
    }
    free(diary);
}

int main() {
    // Create a new diary
    DiaryEntry *diary = NULL;
    int num_entries = 0;

    // Add some entries to the diary
    add_entry(&diary, &num_entries, create_entry("2023-01-01", "Today was a great day! I went for a walk in the park and saw some beautiful flowers."));
    add_entry(&diary, &num_entries, create_entry("2023-01-02", "Today was a bit stressful. I had a lot of work to do, but I managed to get it all done."));
    add_entry(&diary, &num_entries, create_entry("2023-01-03", "Today was a relaxing day. I spent the day reading and listening to music."));

    // Print the diary
    print_diary(diary, num_entries);

    // Free the memory allocated for the diary
    free_diary(diary, num_entries);

    return 0;
}