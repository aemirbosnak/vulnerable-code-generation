//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);
Book* searchBook(Book* head, char* title);
Book* deleteBook(Book* head, char* title);

int main() {
    Book* head = NULL;

    // Insert books
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    newBook1->quantity = 5;
    head = insertBook(head, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "To Kill a Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    newBook2->quantity = 10;
    head = insertBook(head, newBook2);

    // Search books
    Book* foundBook = searchBook(head, "To Kill a Mockingbird");
    if (foundBook) {
        printf("Found book: %s by %s, quantity: %d\n", foundBook->title, foundBook->author, foundBook->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Delete books
    deleteBook(head, "The Lord of the Flies");
    foundBook = searchBook(head, "The Lord of the Flies");
    if (foundBook) {
        printf("Book deleted: %s by %s, quantity: %d\n", foundBook->title, foundBook->author, foundBook->quantity);
    } else {
        printf("Book not found.\n");
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
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

Book* deleteBook(Book* head, char* title) {
    Book* prevBook = NULL;
    Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            if (prevBook) {
                prevBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(currentBook);
            return head;
        }
        prevBook = currentBook;
        currentBook = currentBook->next;
    }

    return NULL;
}