//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR 20

struct Book {
    char title[50];
    char author[20];
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
        struct Book* temp = head;
        while (temp->next) {
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

void updateBookQuantity(struct Book* head, char* title, int quantity) {
    struct Book* book = searchBook(head, title);
    if (book) {
        book->quantity = quantity;
    }
}

void deleteBook(struct Book* head, char* title) {
    struct Book* book = searchBook(head, title);
    if (book) {
        struct Book* prev = NULL;
        struct Book* temp = head;
        while (temp) {
            if (strcmp(temp->title, book->title) == 0) {
                if (prev) {
                    prev->next = book->next;
                } else {
                    head = book->next;
                }
                free(book);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    struct Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 10);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 7);

    updateBookQuantity(head, "To Kill a Mockingbird", 12);

    deleteBook(head, "The Lord of the Flies");

    struct Book* book = searchBook(head, "To Kill a Mockingbird");
    if (book) {
        printf("%s - %d\n", book->title, book->quantity);
    }

    return 0;
}