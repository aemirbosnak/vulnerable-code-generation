//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: innovative
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
        Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
    return head;
}

void SearchBook(Book* head, char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            printf("Book title: %s\n", temp->title);
            printf("Book author: %s\n", temp->author);
            printf("Book quantity: %d\n", temp->quantity);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book not found.\n");
    }
}

void UpdateBookQuantity(Book* head, char* title, int quantity) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            temp->quantity = quantity;
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Inserting books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 10;
    InsertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 5;
    InsertBook(head, newBook);

    // Searching book
    SearchBook(head, "The Lord of the Flies");

    // Updating book quantity
    UpdateBookQuantity(head, "The Great Gatsby", 12);

    // Searching book after update
    SearchBook(head, "The Great Gatsby");

    return 0;
}