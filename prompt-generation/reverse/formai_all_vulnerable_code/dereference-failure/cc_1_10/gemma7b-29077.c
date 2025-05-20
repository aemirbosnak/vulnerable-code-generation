//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        Book* current = head;
        Book* previous = NULL;
        while (current) {
            if (strcmp(newBook->title, current->title) < 0) {
                previous = current;
                current = current->next;
            }
        }
        if (previous) {
            previous->next = newBook;
        } else {
            head = newBook;
        }
    }
    return head;
}

void displayBooks(Book* head) {
    Book* current = head;
    while (current) {
        printf("%s by %s ( %d copies)\n", current->title, current->author, current->quantity);
        current = current->next;
    }
}

int main() {
    Book* head = NULL;
    Book* newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    strcpy(newBook->genre, "Classic");
    newBook->quantity = 10;
    head = insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    strcpy(newBook->genre, "Classic");
    newBook->quantity = 15;
    head = insertBook(head, newBook);

    displayBooks(head);

    return 0;
}