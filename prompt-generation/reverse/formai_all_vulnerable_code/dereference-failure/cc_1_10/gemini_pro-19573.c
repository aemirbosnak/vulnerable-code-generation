//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Create a struct to represent a diary entry
typedef struct {
    char *title;
    char *content;
    int date;
} DiaryEntry;

// Create a linked list to store the diary entries
typedef struct Node {
    DiaryEntry entry;
    struct Node *next;
} Node;

Node *head = NULL;

// Function to create a new diary entry
DiaryEntry* create_entry(char *title, char *content, int date) {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->date = date;
    return entry;
}

// Function to add a new diary entry to the linked list
void add_entry(DiaryEntry *entry) {
    Node *new_node = malloc(sizeof(Node));
    new_node->entry = *entry;
    new_node->next = head;
    head = new_node;
}

// Function to print a diary entry
void print_entry(DiaryEntry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Date: %d\n", entry->date);
}

// Function to print all the diary entries
void print_all_entries() {
    Node *current = head;
    while (current != NULL) {
        print_entry(&current->entry);
        current = current->next;
    }
}

// Function to get the user input
char* get_input(char *prompt) {
    printf("%s", prompt);
    char *input = malloc(MAX_ENTRY_LENGTH);
    fgets(input, MAX_ENTRY_LENGTH, stdin);
    return input;
}

// Main function
int main() {
    // Get the user input
    char *title = get_input("Enter the title of your diary entry: ");
    char *content = get_input("Enter the content of your diary entry: ");
    int date = atoi(get_input("Enter the date of your diary entry (YYYYMMDD): "));

    // Create a new diary entry
    DiaryEntry *entry = create_entry(title, content, date);

    // Add the new diary entry to the linked list
    add_entry(entry);

    // Print the new diary entry
    printf("\nYour diary entry has been added:\n");
    print_entry(entry);

    // Print all the diary entries
    printf("\nAll your diary entries:\n");
    print_all_entries();

    return 0;
}