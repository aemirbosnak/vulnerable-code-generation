//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entry structure
typedef struct {
    char *text;
    time_t timestamp;
} Entry;

// Diary structure
typedef struct {
    Entry *entries;
    int num_entries;
} Diary;

// Create a new diary
Diary *new_diary() {
    Diary *diary = malloc(sizeof(Diary));
    diary->entries = NULL;
    diary->num_entries = 0;
    return diary;
}

// Add an entry to the diary
void add_entry(Diary *diary, char *text) {
    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(Entry));
    diary->entries[diary->num_entries].text = strdup(text);
    diary->entries[diary->num_entries].timestamp = time(NULL);
    diary->num_entries++;
}

// Print the diary
void print_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s\n\n", diary->entries[i].text);
    }
}

// Free the diary
void free_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].text);
    }
    free(diary->entries);
    free(diary);
}

// Main function
int main() {
    // Create a new diary
    Diary *diary = new_diary();

    // Add some entries to the diary
    add_entry(diary, "Dear Diary,\n\nToday was a good day. I woke up feeling refreshed and went for a run in the park. The weather was beautiful, and I felt so alive.");
    add_entry(diary, "Dear Diary,\n\nToday was a bad day. I had a fight with my best friend, and I don't know if we'll ever be able to make up.");

    // Print the diary
    print_diary(diary);

    // Free the diary
    free_diary(diary);

    return 0;
}