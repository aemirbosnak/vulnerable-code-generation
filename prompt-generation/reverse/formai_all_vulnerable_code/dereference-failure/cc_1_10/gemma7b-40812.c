//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
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

Book* insertBook(Book* head) {
    Book* newBook = malloc(sizeof(Book));
    scanf("%s", newBook->title);
    scanf("%s", newBook->author);
    scanf("%s", newBook->genre);
    scanf("%d", &newBook->quantity);

    newBook->next = head;
    head = newBook;

    return head;
}

void searchBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            printf("Title: %s\n", head->title);
            printf("Author: %s\n", head->author);
            printf("Genre: %s\n", head->genre);
            printf("Quantity: %d\n", head->quantity);
            break;
        }
        head = head->next;
    }

    if (head == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;
    head = insertBook(head);
    insertBook(head);
    insertBook(head);

    searchBook(head, "The Lord of the Flies");

    return 0;
}