//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int quantity;
    float price;
    struct Book* next;
};

struct Book* insertBook(struct Book* head, char* title, char* author, int quantity, float price) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->price = price;
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

void deleteBook(struct Book* head, char* title) {
    struct Book* temp = head;
    struct Book* prev = NULL;

    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    return;
}

int main() {
    struct Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 10, 10.0);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 15, 12.0);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 8, 15.0);

    struct Book* book = searchBook(head, "To Kill a Mockingbird");
    if (book) {
        printf("Book title: %s\n", book->title);
        printf("Book author: %s\n", book->author);
        printf("Book quantity: %d\n", book->quantity);
        printf("Book price: %f\n", book->price);
    }

    deleteBook(head, "The Great Gatsby");

    book = searchBook(head, "The Great Gatsby");
    if (book) {
        printf("Book title: %s\n", book->title);
        printf("Book author: %s\n", book->author);
        printf("Book quantity: %d\n", book->quantity);
        printf("Book price: %f\n", book->price);
    }

    return 0;
}