//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: expert-level
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

Book* insertBook(Book* head, Book* newBook);
Book* searchBook(Book* head, char* title);
void updateBookQuantity(Book* head, char* title, int quantity);
void deleteBook(Book* head, char* title);

int main() {
    Book* head = NULL;
    Book* newBook;

    // Inserting books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 3;
    insertBook(head, newBook);

    // Searching for a book
    newBook = searchBook(head, "To Kill a Mockingbird");
    if (newBook) {
        printf("Book found: %s by %s, quantity: %d\n", newBook->title, newBook->author, newBook->quantity);
    } else {
        printf("Book not found\n");
    }

    // Updating book quantity
    updateBookQuantity(head, "The Lord of the Flies", 10);
    newBook = searchBook(head, "The Lord of the Flies");
    if (newBook) {
        printf("Book found: %s by %s, quantity: %d\n", newBook->title, newBook->author, newBook->quantity);
    }

    // Deleting a book
    deleteBook(head, "To Kill a Mockingbird");
    newBook = searchBook(head, "To Kill a Mockingbird");
    if (newBook) {
        printf("Book not found\n");
    }

    return 0;
}

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

void updateBookQuantity(Book* head, char* title, int quantity) {
    Book* currentBook = searchBook(head, title);
    if (currentBook) {
        currentBook->quantity = quantity;
    }
}

void deleteBook(Book* head, char* title) {
    Book* currentBook = head;
    Book* previousBook = NULL;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            if (previousBook) {
                previousBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(currentBook);
            currentBook = NULL;
        } else {
            previousBook = currentBook;
            currentBook = currentBook->next;
        }
    }
}