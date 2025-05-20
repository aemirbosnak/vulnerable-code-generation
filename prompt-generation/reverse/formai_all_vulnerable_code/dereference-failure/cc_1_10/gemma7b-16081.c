//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: creative
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

Book* insertBook(Book* head) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);
    newBook->next = head;
    head = newBook;
    return head;
}

void searchBook(Book* head) {
    char title[20];
    printf("Enter book title: ");
    scanf("%s", title);
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", currentBook->title);
            printf("Author: %s\n", currentBook->author);
            printf("Quantity: %d\n", currentBook->quantity);
            return;
        }
        currentBook = currentBook->next;
    }
    printf("Book not found.\n");
}

void updateBook(Book* head) {
    char title[20];
    printf("Enter book title: ");
    scanf("%s", title);
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Enter new book quantity: ");
            scanf("%d", &currentBook->quantity);
            return;
        }
        currentBook = currentBook->next;
    }
    printf("Book not found.\n");
}

void deleteBook(Book* head) {
    char title[20];
    printf("Enter book title: ");
    scanf("%s", title);
    Book* currentBook = head;
    Book* previousBook = NULL;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            if (previousBook) {
                previousBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(currentBook);
            return;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
    printf("Book not found.\n");
}

int main() {
    Book* head = NULL;
    head = insertBook(head);
    head = insertBook(head);
    head = insertBook(head);
    searchBook(head);
    updateBook(head);
    deleteBook(head);
    return 0;
}