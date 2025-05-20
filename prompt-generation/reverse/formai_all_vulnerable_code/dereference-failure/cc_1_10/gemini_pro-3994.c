//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entry structure
typedef struct {
    char* title;
    char* content;
    time_t timestamp;
} Entry;

// Database of entries
Entry* entries = NULL;
int num_entries = 0;

// Function to add an entry to the database
void add_entry(char* title, char* content) {
    // Allocate memory for the new entry
    Entry* new_entry = malloc(sizeof(Entry));

    // Copy the title and content into the new entry
    new_entry->title = strdup(title);
    new_entry->content = strdup(content);

    // Get the current time
    new_entry->timestamp = time(NULL);

    // Add the new entry to the database
    entries = realloc(entries, (num_entries + 1) * sizeof(Entry));
    entries[num_entries++] = *new_entry;
}

// Function to print an entry
void print_entry(Entry* entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

// Function to get an entry by its title
Entry* get_entry_by_title(char* title) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].title, title) == 0) {
            return &entries[i];
        }
    }

    return NULL;
}

// Function to delete an entry by its title
void delete_entry_by_title(char* title) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].title, title) == 0) {
            // Free the memory for the entry
            free(entries[i].title);
            free(entries[i].content);

            // Remove the entry from the database
            for (int j = i; j < num_entries - 1; j++) {
                entries[j] = entries[j + 1];
            }

            num_entries--;

            return;
        }
    }
}

// Main function
int main() {
    // Add some entries to the database
    add_entry("My first entry", "This is my first entry in my digital diary.");
    add_entry("My second entry", "This is my second entry in my digital diary.");

    // Print the entries
    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
    }

    // Get an entry by its title
    Entry* entry = get_entry_by_title("My first entry");

    // Print the entry
    print_entry(entry);

    // Delete the entry
    delete_entry_by_title("My first entry");

    // Print the entries
    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
    }

    return 0;
}