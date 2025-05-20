//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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
        head->next = insertBook(head->next, title, author, quantity);
    }

    return head;
}

Book* searchBook(Book* head, char* title) {
    if (head == NULL) {
        return NULL;
    }

    if (strcmp(head->title, title) == 0) {
        return head;
    } else {
        return searchBook(head->next, title);
    }
}

void displayBooks(Book* head) {
    while (head) {
        printf("%s by %s, quantity: %d\n", head->title, head->author, head->quantity);
        head = head->next;
    }
}

int main() {
    Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 10);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 7);

    displayBooks(head);

    Book* book = searchBook(head, "The Great Gatsby");

    if (book) {
        printf("Book found: %s by %s, quantity: %d\n", book->title, book->author, book->quantity);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}