//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Library record structure
typedef struct {
    int id;
    char *title;
    char *artist;
    int year;
    int checked_out;
} LibraryRecord;

// Linked list node structure
typedef struct Node {
    LibraryRecord *record;
    struct Node *next;
} Node;

// Linked list head
Node *head = NULL;

// Function to add a record to the library
void add_record(int id, char *title, char *artist, int year) {
    // Create a new record
    LibraryRecord *record = (LibraryRecord *)malloc(sizeof(LibraryRecord));
    record->id = id;
    record->title = strdup(title);
    record->artist = strdup(artist);
    record->year = year;
    record->checked_out = 0;

    // Create a new node
    Node *node = (Node *)malloc(sizeof(Node));
    node->record = record;
    node->next = head;

    // Update the head of the list
    head = node;
}

// Function to print the library records
void print_records() {
    // Iterate over the linked list and print each record
    Node *current = head;
    while (current != NULL) {
        printf("%d %s %s %d\n", current->record->id, current->record->title, current->record->artist, current->record->year);
        current = current->next;
    }
}

// Function to check out a record
void check_out_record(int id) {
    // Iterate over the linked list and find the record with the given id
    Node *current = head;
    while (current != NULL) {
        if (current->record->id == id) {
            // Check out the record
            current->record->checked_out = 1;
            break;
        }
        current = current->next;
    }
}

// Function to return a record
void return_record(int id) {
    // Iterate over the linked list and find the record with the given id
    Node *current = head;
    while (current != NULL) {
        if (current->record->id == id) {
            // Return the record
            current->record->checked_out = 0;
            break;
        }
        current = current->next;
    }
}

// Function to search for a record by title
void search_by_title(char *title) {
    // Iterate over the linked list and find the record with the given title
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->record->title, title) == 0) {
            // Print the record
            printf("%d %s %s %d\n", current->record->id, current->record->title, current->record->artist, current->record->year);
        }
        current = current->next;
    }
}

// Function to search for a record by artist
void search_by_artist(char *artist) {
    // Iterate over the linked list and find the record with the given artist
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->record->artist, artist) == 0) {
            // Print the record
            printf("%d %s %s %d\n", current->record->id, current->record->title, current->record->artist, current->record->year);
        }
        current = current->next;
    }
}

// Function to search for a record by year
void search_by_year(int year) {
    // Iterate over the linked list and find the record with the given year
    Node *current = head;
    while (current != NULL) {
        if (current->record->year == year) {
            // Print the record
            printf("%d %s %s %d\n", current->record->id, current->record->title, current->record->artist, current->record->year);
        }
        current = current->next;
    }
}

// Main function
int main() {
    // Add some records to the library
    add_record(1, "The Hound of the Baskervilles", "Arthur Conan Doyle", 1902);
    add_record(2, "The Adventures of Sherlock Holmes", "Arthur Conan Doyle", 1892);
    add_record(3, "The Sign of the Four", "Arthur Conan Doyle", 1890);
    add_record(4, "A Study in Scarlet", "Arthur Conan Doyle", 1887);
    add_record(5, "The Valley of Fear", "Arthur Conan Doyle", 1915);

    // Print the library records
    printf("Library Records:\n");
    print_records();

    // Check out a record
    printf("\nChecking out The Hound of the Baskervilles...\n");
    check_out_record(1);

    // Print the library records
    printf("\nLibrary Records After Checkout:\n");
    print_records();

    // Return a record
    printf("\nReturning The Hound of the Baskervilles...\n");
    return_record(1);

    // Print the library records
    printf("\nLibrary Records After Return:\n");
    print_records();

    // Search for a record by title
    printf("\nSearching for The Adventures of Sherlock Holmes...\n");
    search_by_title("The Adventures of Sherlock Holmes");

    // Search for a record by artist
    printf("\nSearching for Arthur Conan Doyle...\n");
    search_by_artist("Arthur Conan Doyle");

    // Search for a record by year
    printf("\nSearching for records from 1890...\n");
    search_by_year(1890);

    return 0;
}