//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a diary entry
typedef struct diary_entry {
    char *title;
    char *body;
    char *date;
} diary_entry;

// Array to store diary entries
diary_entry *entries[100];
int num_entries = 0;

// Function to create a new diary entry
void create_entry(char *title, char *body, char *date) {
    // Allocate memory for the new entry
    diary_entry *entry = malloc(sizeof(diary_entry));

    // Copy the title, body, and date into the new entry
    entry->title = strdup(title);
    entry->body = strdup(body);
    entry->date = strdup(date);

    // Add the new entry to the array of entries
    entries[num_entries++] = entry;
}

// Function to edit a diary entry
void edit_entry(int index, char *title, char *body, char *date) {
    // Get the entry at the specified index
    diary_entry *entry = entries[index];

    // Update the title, body, and date of the entry
    free(entry->title);
    entry->title = strdup(title);
    free(entry->body);
    entry->body = strdup(body);
    free(entry->date);
    entry->date = strdup(date);
}

// Function to delete a diary entry
void delete_entry(int index) {
    // Get the entry at the specified index
    diary_entry *entry = entries[index];

    // Free the memory allocated for the entry
    free(entry->title);
    free(entry->body);
    free(entry->date);
    free(entry);

    // Remove the entry from the array of entries
    for (int i = index; i < num_entries - 1; i++) {
        entries[i] = entries[i + 1];
    }

    num_entries--;
}

// Function to print a diary entry
void print_entry(diary_entry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Body: %s\n", entry->body);
    printf("Date: %s\n", entry->date);
}

// Function to print all diary entries
void print_all_entries() {
    for (int i = 0; i < num_entries; i++) {
        print_entry(entries[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create some diary entries
    create_entry("My First Entry", "This is my first entry in my digital diary.", "2023-01-01");
    create_entry("My Second Entry", "This is my second entry in my digital diary.", "2023-01-02");
    create_entry("My Third Entry", "This is my third entry in my digital diary.", "2023-01-03");

    // Print all diary entries
    print_all_entries();

    // Edit the first diary entry
    edit_entry(0, "My First Entry (Edited)", "This is my first entry in my digital diary. (Edited)", "2023-01-01");

    // Print all diary entries
    print_all_entries();

    // Delete the second diary entry
    delete_entry(1);

    // Print all diary entries
    print_all_entries();

    return 0;
}