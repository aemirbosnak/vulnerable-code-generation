//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

// Entry structure
typedef struct {
    char title[50];
    char content[500];
    time_t timestamp;
} Entry;

// Diary structure
typedef struct {
    Entry entries[MAX_ENTRIES];
    int num_entries;
} Diary;

// Function to create a new diary
Diary* create_diary() {
    Diary* diary = malloc(sizeof(Diary));
    diary->num_entries = 0;
    return diary;
}

// Function to add a new entry to the diary
void add_entry(Diary* diary, char* title, char* content) {
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Error: Diary is full!\n");
        return;
    }

    // Get current time
    time_t now = time(NULL);

    // Copy title and content into entry
    strcpy(diary->entries[diary->num_entries].title, title);
    strcpy(diary->entries[diary->num_entries].content, content);
    diary->entries[diary->num_entries].timestamp = now;

    // Increment number of entries
    diary->num_entries++;
}

// Function to print the diary
void print_diary(Diary* diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        // Print title
        printf("%s\n", diary->entries[i].title);

        // Print timestamp
        char* timestamp = ctime(&diary->entries[i].timestamp);
        printf("Timestamp: %s", timestamp);

        // Print content
        printf("%s\n", diary->entries[i].content);

        // Print separator
        printf("------------------------\n");
    }
}

// Function to free the diary
void free_diary(Diary* diary) {
    free(diary);
}

// Linus Torvalds style main function
int main(int argc, char* argv[]) {
    // Create a new diary
    Diary* diary = create_diary();

    // Add some entries to the diary
    add_entry(diary, "My First Entry", "This is my first entry in my digital diary.");
    add_entry(diary, "My Second Entry", "This is my second entry in my digital diary.");
    add_entry(diary, "My Third Entry", "This is my third entry in my digital diary.");

    // Print the diary
    print_diary(diary);

    // Free the diary
    free_diary(diary);

    return 0;
}