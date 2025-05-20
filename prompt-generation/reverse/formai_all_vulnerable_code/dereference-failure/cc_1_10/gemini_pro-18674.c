//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure to store a single diary entry
typedef struct diary_entry {
    time_t timestamp;
    char *title;
    char *content;
} diary_entry;

// Structure to store the entire digital diary
typedef struct digital_diary {
    int num_entries;
    diary_entry *entries;
} digital_diary;

// Function to create a new digital diary
digital_diary *create_diary() {
    digital_diary *diary = malloc(sizeof(digital_diary));
    diary->num_entries = 0;
    diary->entries = NULL;
    return diary;
}

// Function to add a new entry to the diary
void add_entry(digital_diary *diary, char *title, char *content) {
    // Create a new diary entry
    diary_entry *entry = malloc(sizeof(diary_entry));
    entry->timestamp = time(NULL);
    entry->title = strdup(title);
    entry->content = strdup(content);

    // Add the new entry to the diary
    diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(diary_entry));
    diary->entries[diary->num_entries++] = *entry;
}

// Function to print a single diary entry
void print_entry(diary_entry *entry) {
    printf("----------------------------------------\n");
    printf("Title: %s\n", entry->title);
    printf("Timestamp: %s", ctime(&entry->timestamp));
    printf("Content: %s\n", entry->content);
}

// Function to print the entire digital diary
void print_diary(digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        print_entry(&diary->entries[i]);
    }
}

// Function to free the memory allocated for the diary
void free_diary(digital_diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].title);
        free(diary->entries[i].content);
    }
    free(diary->entries);
    free(diary);
}

int main() {
    // Create a new digital diary
    digital_diary *diary = create_diary();

    // Add some entries to the diary
    add_entry(diary, "My first entry", "This is my first entry in my digital diary. I'm so excited to start using it!");
    add_entry(diary, "My second entry", "Today was a great day. I went for a walk in the park and saw some beautiful flowers.");
    add_entry(diary, "My third entry", "I'm starting to get the hang of this digital diary thing. It's really easy to use and I love being able to keep track of my thoughts and experiences in one place.");

    // Print the entire digital diary
    print_diary(diary);

    // Free the memory allocated for the diary
    free_diary(diary);

    return 0;
}