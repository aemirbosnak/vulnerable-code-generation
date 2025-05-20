//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[255];
    char author[255];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head) {
    Book* newNode = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newNode->title);
    printf("Enter author's name: ");
    scanf("%s", newNode->author);
    printf("Enter quantity: ");
    scanf("%d", &newNode->quantity);
    newNode->next = head;
    return newNode;
}

void searchBook(Book* head) {
    char title[255];
    printf("Enter book title: ");
    scanf("%s", title);
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", currentBook->title);
            printf("Author: %s\n", currentBook->author);
            printf("Quantity: %d\n", currentBook->quantity);
            break;
        }
        currentBook = currentBook->next;
    }
    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

void updateBook(Book* head) {
    char title[255];
    printf("Enter book title: ");
    scanf("%s", title);
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Enter new book title: ");
            scanf("%s", currentBook->title);
            printf("Enter new author's name: ");
            scanf("%s", currentBook->author);
            printf("Enter new quantity: ");
            scanf("%d", &currentBook->quantity);
            break;
        }
        currentBook = currentBook->next;
    }
    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

void deleteBook(Book* head) {
    char title[255];
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
            break;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;
    head = insertBook(head);
    insertBook(head);
    insertBook(head);
    searchBook(head);
    updateBook(head);
    deleteBook(head);
    searchBook(head);
    return 0;
}