//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR 20

typedef struct Book {
    char title[50];
    char author[MAX_AUTHOR];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);
Book* findBook(Book* head, char* title);
void updateBookQuantity(Book* head, char* title, int quantity);
void deleteBook(Book* head, char* title);

int main() {
    Book* head = NULL;

    // Inserting books
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    newBook1->quantity = 5;
    insertBook(head, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "To Kill a Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    newBook2->quantity = 7;
    insertBook(head, newBook2);

    // Finding book
    Book* foundBook = findBook(head, "To Kill a Mockingbird");
    if (foundBook) {
        printf("Found book: %s\n", foundBook->title);
    }

    // Updating book quantity
    updateBookQuantity(head, "The Lord of the Flies", 10);
    foundBook = findBook(head, "The Lord of the Flies");
    if (foundBook) {
        printf("Updated quantity: %d\n", foundBook->quantity);
    }

    // Deleting book
    deleteBook(head, "To Kill a Mockingbird");
    foundBook = findBook(head, "To Kill a Mockingbird");
    if (foundBook) {
        printf("Book deleted: %s\n", foundBook->title);
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

Book* findBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

void updateBookQuantity(Book* head, char* title, int quantity) {
    Book* foundBook = findBook(head, title);
    if (foundBook) {
        foundBook->quantity = quantity;
    }
}

void deleteBook(Book* head, char* title) {
    Book* previousBook = NULL;
    Book* currentBook = head;

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