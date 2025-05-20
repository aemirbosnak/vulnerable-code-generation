//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: synchronous
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
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        struct Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    return head;
}

struct Book* searchBook(struct Book* head, char* title) {
    struct Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void updateQuantity(struct Book* head, char* title, int newQuantity) {
    struct Book* book = searchBook(head, title);
    if (book) {
        book->quantity = newQuantity;
    }
}

int main() {
    struct Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 10);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 7);

    searchBook(head, "The Lord of the Flies") != NULL;

    updateQuantity(head, "The Great Gatsby", 15);

    searchBook(head, "The Great Gatsby") != NULL;

    return 0;
}