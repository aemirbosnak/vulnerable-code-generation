//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

// Structure to store a diary entry
typedef struct diary_entry {
    time_t timestamp;
    char *text;
} diary_entry;

// Array to store diary entries
diary_entry entries[MAX_ENTRIES];

// Current number of entries
int num_entries = 0;

// Function to add a new diary entry
void add_entry(char *text) {
    // Create a new entry
    diary_entry entry;

    // Get the current time
    time(&entry.timestamp);

    // Allocate memory for the text
    entry.text = malloc(strlen(text) + 1);

    // Copy the text into the entry
    strcpy(entry.text, text);

    // Add the entry to the array
    entries[num_entries++] = entry;
}

// Function to print all diary entries
void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        // Print the timestamp
        printf("%s", ctime(&entries[i].timestamp));

        // Print the text
        printf("%s\n", entries[i].text);
    }
}

// Function to delete a diary entry
void delete_entry(int index) {
    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Invalid index\n");
        return;
    }

    // Free the memory for the text
    free(entries[index].text);

    // Shift the remaining entries down
    for (int i = index; i < num_entries - 1; i++) {
        entries[i] = entries[i + 1];
    }

    // Decrement the number of entries
    num_entries--;
}

// Function to edit a diary entry
void edit_entry(int index, char *text) {
    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Invalid index\n");
        return;
    }

    // Allocate memory for the new text
    entries[index].text = realloc(entries[index].text, strlen(text) + 1);

    // Copy the new text into the entry
    strcpy(entries[index].text, text);
}

// Main function
int main() {
    // Add some sample entries
    add_entry("Dear Diary,\nToday was a great day. I went to the park and played with my friends.");
    add_entry("Dear Diary,\nToday was a bad day. I got a bad grade on my test.");
    add_entry("Dear Diary,\nToday was a good day. I went to the movies with my girlfriend.");

    // Print all entries
    print_entries();

    // Delete an entry
    delete_entry(1);

    // Edit an entry
    edit_entry(0, "Dear Diary,\nToday was an okay day.");

    // Print all entries again
    print_entries();

    return 0;
}