//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: artistic
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
        Book* currentBook = head;
        while (currentBook->next != NULL) {
            currentBook = currentBook->next;
        }
        currentBook->next = newBook;
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

void updateBookQuantity(Book* book, int newQuantity) {
    book->quantity = newQuantity;
}

void deleteBook(Book* head, Book* bookToDelete) {
    Book* currentBook = head;
    Book* previousBook = NULL;
    while (currentBook) {
        if (currentBook == bookToDelete) {
            if (previousBook) {
                previousBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(bookToDelete);
            return;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
    return;
}

int main() {
    Book* head = NULL;
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    newBook1->quantity = 5;
    insertBook(head, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "To Kill a Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    newBook2->quantity = 10;
    insertBook(head, newBook2);

    Book* bookToSearch = searchBook(head, "To Kill a Mockingbird");
    if (bookToSearch) {
        printf("Title: %s\n", bookToSearch->title);
        printf("Author: %s\n", bookToSearch->author);
        printf("Quantity: %d\n", bookToSearch->quantity);
    } else {
        printf("Book not found.\n");
    }

    updateBookQuantity(bookToSearch, 15);
    bookToSearch->quantity = 15;

    printf("Updated quantity: %d\n", bookToSearch->quantity);

    deleteBook(head, bookToSearch);
    bookToSearch = NULL;

    printf("Book deleted.\n");

    return 0;
}