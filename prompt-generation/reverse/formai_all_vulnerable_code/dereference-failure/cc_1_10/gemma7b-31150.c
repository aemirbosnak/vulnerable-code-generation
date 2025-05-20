//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book entry
typedef struct book_entry {
    char title[50];
    char author[50];
    int year;
    struct book_entry* next;
} book_entry;

// Define the book indexing system
typedef struct book_index_system {
    book_entry* head;
    int num_books;
    struct book_index_system* next;
} book_index_system;

// Function to insert a book entry into the index system
void insert_book(book_index_system* system, book_entry* entry) {
    // Allocate memory for the new book entry
    entry = (book_entry*)malloc(sizeof(book_entry));

    // Copy the book entry data into the new book entry
    strcpy(entry->title, entry->title);
    strcpy(entry->author, entry->author);
    entry->year = entry->year;

    // Insert the new book entry into the linked list
    if (system->head == NULL) {
        system->head = entry;
    } else {
        system->head->next = entry;
    }

    // Increment the number of books in the system
    system->num_books++;
}

// Function to search for a book entry in the index system
book_entry* search_book(book_index_system* system, char* title) {
    // Traverse the linked list of book entries
    book_entry* current = system->head;
    while (current) {
        // Compare the book title to the search title
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }

    // Return NULL if the book entry is not found
    return NULL;
}

int main() {
    // Create a new book indexing system
    book_index_system* system = (book_index_system*)malloc(sizeof(book_index_system));
    system->head = NULL;
    system->num_books = 0;

    // Insert some book entries into the system
    book_entry* entry1 = (book_entry*)malloc(sizeof(book_entry));
    strcpy(entry1->title, "The Lord of the Flies");
    strcpy(entry1->author, "William Golding");
    entry1->year = 1954;
    insert_book(system, entry1);

    book_entry* entry2 = (book_entry*)malloc(sizeof(book_entry));
    strcpy(entry2->title, "The Great Gatsby");
    strcpy(entry2->author, "F. Scott Fitzgerald");
    entry2->year = 1925;
    insert_book(system, entry2);

    // Search for a book entry in the system
    book_entry* found_entry = search_book(system, "The Lord of the Flies");

    // Print the book entry data
    if (found_entry) {
        printf("Title: %s\n", found_entry->title);
        printf("Author: %s\n", found_entry->author);
        printf("Year: %d\n", found_entry->year);
    } else {
        printf("Book entry not found.\n");
    }

    return 0;
}