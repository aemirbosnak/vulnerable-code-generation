//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
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
    Book* newBook = malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);
    newBook->next = head;
    return newBook;
}

Book* findBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }
    return NULL;
}

void updateBookQuantity(Book* book, int quantity) {
    book->quantity = quantity;
}

void deleteBook(Book* head, char* title) {
    Book* previousBook = NULL;
    Book* currentBook = head;
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
    return;
}

int main() {
    Book* head = NULL;
    head = insertBook(head);
    head = insertBook(head);
    head = insertBook(head);

    Book* book = findBook(head, "Book 2");
    updateBookQuantity(book, 5);

    deleteBook(head, "Book 1");

    return 0;
}