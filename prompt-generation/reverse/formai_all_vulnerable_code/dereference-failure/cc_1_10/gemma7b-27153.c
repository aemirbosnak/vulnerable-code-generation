//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: standalone
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

Book* InsertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        head->next = InsertBook(head->next, newBook);
    }
    return head;
}

void SearchBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            printf("Book: %s, Author: %s, Quantity: %d\n", head->title, head->author, head->quantity);
            return;
        }
        head = head->next;
    }
    printf("Book not found.\n");
}

void UpdateBookQuantity(Book* head, char* title, int quantity) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            head->quantity = quantity;
            return;
        }
        head = head->next;
    }
    printf("Book not found.\n");
}

void DeleteBook(Book* head, char* title) {
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

    printf("Book not found.\n");
}

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    head = InsertBook(head, newBook);

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 10;
    head = InsertBook(head, newBook);

    SearchBook(head, "The Lord of the Flies");
    UpdateBookQuantity(head, "To Kill a Mockingbird", 15);
    DeleteBook(head, "The Lord of the Flies");

    SearchBook(head, "The Lord of the Flies");

    return 0;
}