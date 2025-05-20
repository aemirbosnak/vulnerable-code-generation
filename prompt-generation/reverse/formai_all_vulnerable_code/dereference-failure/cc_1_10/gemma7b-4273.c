//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int year;
    struct Book* next;
} Book;

Book* insertBook(Book* head) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book year: ");
    scanf("%d", &newBook->year);

    newBook->next = head;
    head = newBook;

    return head;
}

void searchBook(Book* head, char* title) {
    Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Book title: %s\n", currentBook->title);
            printf("Book author: %s\n", currentBook->author);
            printf("Book year: %d\n", currentBook->year);
            break;
        }
        currentBook = currentBook->next;
    }

    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;
    head = insertBook(head);
    head = insertBook(head);
    head = insertBook(head);

    searchBook(head, "Book 2");

    return 0;
}