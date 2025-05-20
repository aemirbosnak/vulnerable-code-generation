//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structures
typedef struct Entry {
    char *title;
    char *content;
    time_t timestamp;
} Entry;

typedef struct Diary {
    Entry *entries;
    int num_entries;
    int capacity;
} Diary;

// Function prototypes
Diary *create_diary();
void add_entry(Diary *diary, char *title, char *content);
void print_diary(Diary *diary);
void free_diary(Diary *diary);

int main() {
    // Create a new diary
    Diary *my_diary = create_diary();

    // Add some entries to the diary
    add_entry(my_diary, "My First Entry", "This is my first entry in my digital diary.");
    add_entry(my_diary, "A Day in the Life", "Today I woke up early and went for a run. Then I went to work and had a productive day.");
    add_entry(my_diary, "A Night Out", "Last night I went out with friends and had a great time.");

    // Print the diary
    print_diary(my_diary);

    // Free the diary
    free_diary(my_diary);

    return 0;
}

// Function definitions
Diary *create_diary() {
    Diary *diary = malloc(sizeof(Diary));
    diary->entries = malloc(sizeof(Entry));
    diary->num_entries = 0;
    diary->capacity = 1;
    return diary;
}

void add_entry(Diary *diary, char *title, char *content) {
    // Check if the diary is full
    if (diary->num_entries == diary->capacity) {
        // Double the capacity of the diary
        diary->entries = realloc(diary->entries, 2 * diary->capacity * sizeof(Entry));
        diary->capacity *= 2;
    }

    // Add the entry to the diary
    Entry *entry = &diary->entries[diary->num_entries];
    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->timestamp = time(NULL);
    diary->num_entries++;
}

void print_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        Entry *entry = &diary->entries[i];
        printf("Title: %s\n", entry->title);
        printf("Content: %s\n", entry->content);
        printf("Timestamp: %s\n", ctime(&entry->timestamp));
        printf("\n");
    }
}

void free_diary(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        Entry *entry = &diary->entries[i];
        free(entry->title);
        free(entry->content);
    }
    free(diary->entries);
    free(diary);
}