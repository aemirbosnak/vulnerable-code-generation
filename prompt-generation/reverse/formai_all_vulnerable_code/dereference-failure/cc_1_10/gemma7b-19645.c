//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
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
        head->next = insertBook(head->next, newBook);
    }
    return head;
}

void displayBooks(Book* head) {
    while (head) {
        printf("%s by %s, Quantity: %d\n", head->title, head->author, head->quantity);
        head = head->next;
    }
}

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
    newBook2->quantity = 3;
    insertBook(head, newBook2);

    Book* newBook3 = malloc(sizeof(Book));
    strcpy(newBook3->title, "The Great Gatsby");
    strcpy(newBook3->author, "F. Scott Fitzgerald");
    newBook3->quantity = 2;
    insertBook(head, newBook3);

    // Displaying books
    displayBooks(head);

    return 0;
}