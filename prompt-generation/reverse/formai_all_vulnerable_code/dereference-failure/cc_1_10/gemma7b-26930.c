//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        head->next = newBook;
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

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 10);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 7);

    Book* book = searchBook(head, "To Kill a Mockingbird");
    if (book) {
        updateBookQuantity(book, 15);
    }

    deleteBook(head, book);

    return 0;
}