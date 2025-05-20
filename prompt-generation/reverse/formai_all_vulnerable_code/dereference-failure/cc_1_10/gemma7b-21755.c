//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    struct Book* next;
};

struct Book* insertBook(struct Book* head, char* title, char* author, char* genre, int quantity) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->genre, genre);
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

int main() {
    struct Book* head = NULL;

    insertBook(head, "The Adventures of Sherlock Holmes", "Sir Arthur Conan Doyle", "Detective Fiction", 5);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", "Classic Fiction", 3);
    insertBook(head, "The Lord of the Flies", "William Golding", "Young Adult Fiction", 2);

    struct Book* book = searchBook(head, "The Adventures of Sherlock Holmes");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Genre: %s\n", book->genre);
        printf("Quantity: %d\n", book->quantity);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}