//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of books in the library
#define MAX_BOOKS 100

// Define the book structure
typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

// Create a singly linked list of books
Book* createBookList() {
    return NULL;
}

// Insert a book into the linked list
void insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        newBook->next = head;
        head = newBook;
    }
}

// Search for a book in the linked list
Book* searchBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }
    return NULL;
}

int main() {
    Book* head = createBookList();

    // Insert some books into the list
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    newBook1->quantity = 10;
    insertBook(head, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "The Great Gatsby");
    strcpy(newBook2->author, "F. Scott Fitzgerald");
    newBook2->quantity = 5;
    insertBook(head, newBook2);

    // Search for a book in the list
    Book* foundBook = searchBook(head, "The Lord of the Flies");

    // Print the book information
    if (foundBook) {
        printf("Title: %s\n", foundBook->title);
        printf("Author: %s\n", foundBook->author);
        printf("Quantity: %d\n", foundBook->quantity);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}