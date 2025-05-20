//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entry structure
typedef struct Entry {
    char *text;
    time_t timestamp;
} Entry;

// Diary structure
typedef struct Diary {
    Entry *entries;
    int num_entries;
    int capacity;
} Diary;

// Create a new diary
Diary *diary_new() {
    Diary *diary = malloc(sizeof(Diary));
    if (!diary) {
        return NULL;
    }

    diary->entries = NULL;
    diary->num_entries = 0;
    diary->capacity = 0;

    return diary;
}

// Free the memory allocated for a diary
void diary_free(Diary *diary) {
    if (!diary) {
        return;
    }

    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].text);
    }

    free(diary->entries);
    free(diary);
}

// Add a new entry to the diary
int diary_add_entry(Diary *diary, const char *text) {
    if (!diary || !text) {
        return -1;
    }

    // Resize the entries array if needed
    if (diary->num_entries >= diary->capacity) {
        diary->entries = realloc(diary->entries, (diary->capacity + 1) * sizeof(Entry));
        if (!diary->entries) {
            return -1;
        }
        diary->capacity++;
    }

    // Add the new entry
    diary->entries[diary->num_entries].text = strdup(text);
    diary->entries[diary->num_entries].timestamp = time(NULL);
    diary->num_entries++;

    return 0;
}

// Print the diary entries
void diary_print_entries(Diary *diary) {
    if (!diary) {
        return;
    }

    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s (%s)\n", diary->entries[i].text, ctime(&diary->entries[i].timestamp));
    }
}

// Search the diary for a specific text
int diary_search_text(Diary *diary, const char *text) {
    if (!diary || !text) {
        return -1;
    }

    for (int i = 0; i < diary->num_entries; i++) {
        if (strstr(diary->entries[i].text, text)) {
            return i;
        }
    }

    return -1;
}

// Main function
int main() {
    // Create a new diary
    Diary *diary = diary_new();
    if (!diary) {
        printf("Error: Could not create diary.\n");
        return EXIT_FAILURE;
    }

    // Add some entries to the diary
    diary_add_entry(diary, "Dear Diary,\n\nToday was a great day!");
    diary_add_entry(diary, "I went for a walk in the park and it was so beautiful.\n\nThe sun was shining and the birds were singing.\n\nI felt so peaceful and happy.");
    diary_add_entry(diary, "I can't wait to come back tomorrow!");

    // Print the diary entries
    printf("Diary Entries:\n");
    diary_print_entries(diary);

    // Search the diary for a specific text
    int index = diary_search_text(diary, "beautiful");
    if (index >= 0) {
        printf("Found entry at index %d.\n", index);
    } else {
        printf("No entry found.\n");
    }

    // Free the memory allocated for the diary
    diary_free(diary);

    return EXIT_SUCCESS;
}