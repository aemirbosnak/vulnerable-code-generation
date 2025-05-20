//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct DiaryEntry {
    char *entry;
    int length;
    struct DiaryEntry *next;
} DiaryEntry;

// Define the head of the linked list of diary entries
DiaryEntry *head = NULL;

// Create a new diary entry
DiaryEntry *create_entry(char *entry) {
    DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
    new_entry->entry = malloc(strlen(entry) + 1);
    strcpy(new_entry->entry, entry);
    new_entry->length = strlen(entry);
    new_entry->next = NULL;
    return new_entry;
}

// Add a new diary entry to the linked list
void add_entry(char *entry) {
    DiaryEntry *new_entry = create_entry(entry);
    if (head == NULL) {
        head = new_entry;
    } else {
        DiaryEntry *current_entry = head;
        while (current_entry->next != NULL) {
            current_entry = current_entry->next;
        }
        current_entry->next = new_entry;
    }
}

// Print a diary entry
void print_entry(DiaryEntry *entry) {
    printf("%s", entry->entry);
}

// Print all diary entries
void print_all_entries() {
    DiaryEntry *current_entry = head;
    while (current_entry != NULL) {
        print_entry(current_entry);
        current_entry = current_entry->next;
    }
}

// Main function
int main() {
    // Add some diary entries
    add_entry("Dear Diary,\n\nI am so grateful for this beautiful day.");
    add_entry("Dear Diary,\n\nI am so grateful for my family and friends.");
    add_entry("Dear Diary,\n\nI am so grateful for my health.");

    // Print all diary entries
    print_all_entries();

    return 0;
}