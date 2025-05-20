//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a book record
typedef struct BookRecord {
    char title[50];
    char author[50];
    int year;
    struct BookRecord* next;
} BookRecord;

// Define the book indexing system
typedef struct BookIndexSystem {
    BookRecord* head;
    int size;
    struct BookIndexSystem* next;
} BookIndexSystem;

// Create a new book record
BookRecord* createBookRecord(char* title, char* author, int year) {
    BookRecord* newRecord = (BookRecord*)malloc(sizeof(BookRecord));
    strcpy(newRecord->title, title);
    strcpy(newRecord->author, author);
    newRecord->year = year;
    newRecord->next = NULL;
    return newRecord;
}

// Insert a new book record into the indexing system
void insertBookRecord(BookIndexSystem* system, BookRecord* newRecord) {
    if (system->head == NULL) {
        system->head = newRecord;
    } else {
        BookRecord* currentRecord = system->head;
        while (currentRecord->next != NULL) {
            currentRecord = currentRecord->next;
        }
        currentRecord->next = newRecord;
    }
    system->size++;
}

// Search for a book record in the indexing system
BookRecord* searchBookRecord(BookIndexSystem* system, char* title) {
    BookRecord* currentRecord = system->head;
    while (currentRecord) {
        if (strcmp(currentRecord->title, title) == 0) {
            return currentRecord;
        }
        currentRecord = currentRecord->next;
    }
    return NULL;
}

int main() {
    BookIndexSystem* system = (BookIndexSystem*)malloc(sizeof(BookIndexSystem));
    system->head = NULL;
    system->size = 0;
    system->next = NULL;

    // Create some book records
    BookRecord* book1 = createBookRecord("The Lord of the Flies", "William Golding", 1954);
    BookRecord* book2 = createBookRecord("To Kill a Mockingbird", "Harper Lee", 1960);
    BookRecord* book3 = createBookRecord("The Great Gatsby", "F. Scott Fitzgerald", 1925);

    // Insert the book records into the indexing system
    insertBookRecord(system, book1);
    insertBookRecord(system, book2);
    insertBookRecord(system, book3);

    // Search for a book record
    BookRecord* foundBook = searchBookRecord(system, "To Kill a Mockingbird");

    // Print the book record
    if (foundBook) {
        printf("Title: %s\n", foundBook->title);
        printf("Author: %s\n", foundBook->author);
        printf("Year: %d\n", foundBook->year);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}