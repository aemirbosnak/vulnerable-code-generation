//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book *next;
};

struct Book *insertBook(struct Book *head, char *title, char *author, int quantity) {
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));

    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        struct Book *traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newBook;
    }

    return head;
}

int searchBook(struct Book *head, char *title) {
    struct Book *traverse = head;
    while (traverse) {
        if (strcmp(traverse->title, title) == 0) {
            return 1;
        }
        traverse = traverse->next;
    }

    return 0;
}

void displayBooks(struct Book *head) {
    struct Book *traverse = head;
    while (traverse) {
        printf("%s by %s, quantity: %d\n", traverse->title, traverse->author, traverse->quantity);
        traverse = traverse->next;
    }
}

int main() {
    struct Book *head = NULL;
    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 10);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 7);

    displayBooks(head);

    if (searchBook(head, "The Lord of the Flies") == 1) {
        printf("Book found!\n");
    } else {
        printf("Book not found!\n");
    }

    return 0;
}