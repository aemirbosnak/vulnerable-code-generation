//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[20];
    char author[20];
    int quantity;
    struct Book* next;
} Book;

Book* createBook(char* title, char* author, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    return newBook;
}

void addBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = createBook(title, author, quantity);
    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

void searchBook(Book* head, char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            printf("Title: %s\n", temp->title);
            printf("Author: %s\n", temp->author);
            printf("Quantity: %d\n", temp->quantity);
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

    addBook(head, "The Lord of the Flies", "William Golding", 5);
    addBook(head, "To Kill a Mockingbird", "Harper Lee", 10);
    addBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 7);

    searchBook(head, "To Kill a Mockingbird");

    return 0;
}