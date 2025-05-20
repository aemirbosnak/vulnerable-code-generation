//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Entry structure
typedef struct {
    int id;
    char *date;
    char *title;
    char *text;
} Entry;

// Function to create a new entry
Entry *create_entry(int id, char *date, char *title, char *text) {
    Entry *entry = malloc(sizeof(Entry));
    entry->id = id;
    entry->date = strdup(date);
    entry->title = strdup(title);
    entry->text = strdup(text);
    return entry;
}

// Function to free an entry
void free_entry(Entry *entry) {
    free(entry->date);
    free(entry->title);
    free(entry->text);
    free(entry);
}

// Main function
int main() {
    // Create some entries
    Entry *entry1 = create_entry(1, "2023-01-01", "My First Entry", "This is my first entry in my digital diary.");
    Entry *entry2 = create_entry(2, "2023-01-02", "My Second Entry", "This is my second entry in my digital diary.");

    // Print the entries
    printf("Entry 1:\n");
    printf("ID: %d\n", entry1->id);
    printf("Date: %s\n", entry1->date);
    printf("Title: %s\n", entry1->title);
    printf("Text: %s\n", entry1->text);

    printf("\nEntry 2:\n");
    printf("ID: %d\n", entry2->id);
    printf("Date: %s\n", entry2->date);
    printf("Title: %s\n", entry2->title);
    printf("Text: %s\n", entry2->text);

    // Free the entries
    free_entry(entry1);
    free_entry(entry2);

    return 0;
}