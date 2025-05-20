//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        newBook->next = head;
        head = newBook;
    }
    return head;
}

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
    Book* head = NULL;
    Book* newBook;

    // Inserting books into the library
    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 10;
    insertBook(head, newBook);

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 8;
    insertBook(head, newBook);

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 6;
    insertBook(head, newBook);

    // Searching for a book in the library
    newBook = searchBook(head, "The Lord of the Flies");
    if (newBook) {
        printf("Book found: %s by %s\n", newBook->title, newBook->author);
    } else {
        printf("Book not found.\n");
    }

    // Displaying all books in the library
    newBook = head;
    while (newBook) {
        printf("Book: %s by %s, Quantity: %d\n", newBook->title, newBook->author, newBook->quantity);
        newBook = newBook->next;
    }

    return 0;
}