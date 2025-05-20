//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Linus Torvalds
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
    struct Book* newBook = malloc(sizeof(struct Book));

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

void displayBooks(struct Book* head) {
    struct Book* currentBook = head;

    while (currentBook) {
        printf("%s by %s, quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
        currentBook = currentBook->next;
    }
}

int main() {
    struct Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 3);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 2);

    displayBooks(head);

    return 0;
}