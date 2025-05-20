//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
};

struct Book* insertBook(struct Book* head, char* title, char* author, int quantity) {
    struct Book* newNode = (struct Book*)malloc(sizeof(struct Book));
    newNode->quantity = quantity;
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    return head;
}

struct Book* findBook(struct Book* head, char* title) {
    struct Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }

    return NULL;
}

void updateBookQuantity(struct Book* book, int newQuantity) {
    book->quantity = newQuantity;
}

void deleteBook(struct Book* head, char* title) {
    struct Book* previousBook = NULL;
    struct Book* currentBook = head;

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

int main() {
    struct Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 10);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 7);

    struct Book* book = findBook(head, "To Kill a Mockingbird");
    if (book) {
        updateBookQuantity(book, 15);
    }

    deleteBook(head, "The Lord of the Flies");

    book = findBook(head, "To Kill a Mockingbird");
    if (book) {
        printf("%s by %s has a quantity of %d", book->title, book->author, book->quantity);
    }

    return 0;
}