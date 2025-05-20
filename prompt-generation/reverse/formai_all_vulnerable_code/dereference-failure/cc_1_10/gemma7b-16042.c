//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[20];
    char author[20];
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

void updateBookQuantity(Book* book, int quantity) {
    book->quantity = quantity;
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
            return;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }

    return;
}

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 10;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 7;
    insertBook(head, newBook);

    searchBook(head, "The Lord of the Flies")->quantity = 15;
    updateBookQuantity(searchBook(head, "To Kill a Mockingbird"), 8);
    deleteBook(head, "The Great Gatsby");

    Book* currentBook = head;
    while (currentBook) {
        printf("%s by %s (Quantity: %d)\n", currentBook->title, currentBook->author, currentBook->quantity);
        currentBook = currentBook->next;
    }

    return 0;
}