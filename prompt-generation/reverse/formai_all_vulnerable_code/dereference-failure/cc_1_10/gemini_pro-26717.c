//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entry structure
typedef struct {
    char *title;
    char *content;
    time_t timestamp;
} Entry;

// Diary structure
typedef struct {
    Entry *entries;
    int num_entries;
} Diary;

// Creates a new diary
Diary *new_diary() {
    Diary *diary = malloc(sizeof(Diary));
    diary->entries = NULL;
    diary->num_entries = 0;
    return diary;
}

// Adds an entry to the diary
void add_entry(Diary *diary, char *title, char *content) {
    // Allocate memory for the new entry
    Entry *entry = malloc(sizeof(Entry));

    // Copy the title and content
    entry->title = strdup(title);
    entry->content = strdup(content);

    // Set the timestamp
    entry->timestamp = time(NULL);

    // Add the entry to the diary
    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(Entry));
    diary->entries[diary->num_entries] = *entry;
    diary->num_entries++;
}

// Prints the diary
void print_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("** %s **\n", diary->entries[i].title);
        printf("%s\n", diary->entries[i].content);
        printf("Timestamp: %s\n", ctime(&diary->entries[i].timestamp));
        printf("\n");
    }
}

// Frees the memory allocated for the diary
void free_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].title);
        free(diary->entries[i].content);
    }
    free(diary->entries);
    free(diary);
}

// Main function
int main() {
    // Create a new diary
    Diary *diary = new_diary();

    // Add some entries to the diary
    add_entry(diary, "My First Entry", "This is my first entry in my digital diary.");
    add_entry(diary, "A Day in the Life", "I woke up early this morning and went for a run. It was a beautiful day, and I felt great.");
    add_entry(diary, "A Time to Reflect", "I've been thinking a lot about my life lately. I'm not sure what I want to do with it, but I know that I want to make a difference in the world.");

    // Print the diary
    print_diary(diary);

    // Free the memory allocated for the diary
    free_diary(diary);

    return 0;
}