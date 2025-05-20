//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: intelligent
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
        head->next = insertBook(head->next, newBook);
    }
    return head;
}

void searchBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Book: %s, Author: %s, Quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
        }
        currentBook = currentBook->next;
    }
}

void updateBookQuantity(Book* head, char* title, int quantity) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            currentBook->quantity = quantity;
        }
        currentBook = currentBook->next;
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
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
}

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Insert some books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 3;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 2;
    insertBook(head, newBook);

    // Search for a book
    searchBook(head, "The Lord of the Flies");

    // Update book quantity
    updateBookQuantity(head, "The Great Gatsby", 4);

    // Delete a book
    deleteBook(head, "To Kill a Mockingbird");

    // Search for the updated book quantity
    searchBook(head, "The Great Gatsby");

    return 0;
}