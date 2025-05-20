//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Diary entry structure
typedef struct diary_entry {
    char *title;
    char *content;
    time_t timestamp;
} diary_entry;

// Create a new diary entry
diary_entry *new_entry(char *title, char *content) {
    diary_entry *entry = malloc(sizeof(diary_entry));
    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->timestamp = time(NULL);
    return entry;
}

// Free a diary entry
void free_entry(diary_entry *entry) {
    free(entry->title);
    free(entry->content);
    free(entry);
}

// Print a diary entry
void print_entry(diary_entry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

// Main function
int main() {
    // Create a new digital diary
    printf("Welcome to your digital diary!\n");

    // Get the user's name
    char name[256];
    printf("What is your name? ");
    scanf("%s", name);

    // Create a welcome message
    char welcome[256];
    sprintf(welcome, "Hello, %s! Welcome to your digital diary.", name);

    // Create a new diary entry
    diary_entry *entry = new_entry("My First Entry", welcome);

    // Print the diary entry
    print_entry(entry);

    // Free the diary entry
    free_entry(entry);

    return 0;
}