//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

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

void searchBook(Book* head, char* title) {
    if (head != NULL) {
        if (strcmp(head->title, title) == 0) {
            printf("%s by %s, Quantity: %d\n", head->title, head->author, head->quantity);
        } else {
            searchBook(head->next, title);
        }
    }
}

void deleteBook(Book* head, char* title) {
    Book* prev = NULL;
    Book* current = head;

    if (head == NULL) {
        return;
    }

    while (current && strcmp(current->title, title) != 0) {
        prev = current;
        current = current->next;
    }

    if (prev != NULL) {
        prev->next = current->next;
    } else {
        head = current->next;
    }

    free(current);
}

int main() {
    Book* head = NULL;

    // Inserting Books
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

    // Searching Books
    searchBook(head, "The Lord of the Flies");
    searchBook(head, "To Kill a Mockingbird");

    // Deleting Books
    deleteBook(head, "The Great Gatsby");
    searchBook(head, "The Great Gatsby");

    return 0;
}