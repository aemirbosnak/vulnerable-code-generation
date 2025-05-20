//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, char* title, char* author, char* genre, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->genre, genre);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    return head;
}

Book* searchBook(Book* head, char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

Book* deleteBook(Book* head, char* title) {
    Book* prev = NULL;
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    return NULL;
}

int main() {
    Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", "Coming-of-age", 5);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", "Classic", 10);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", "Classic", 7);

    Book* book = searchBook(head, "The Great Gatsby");
    if (book) {
        printf("Book: %s, Author: %s, Quantity: %d\n", book->title, book->author, book->quantity);
    }

    book = deleteBook(head, "To Kill a Mockingbird");
    if (book) {
        printf("Book: %s, Author: %s, Quantity: %d\n", book->title, book->author, book->quantity);
    }

    return 0;
}