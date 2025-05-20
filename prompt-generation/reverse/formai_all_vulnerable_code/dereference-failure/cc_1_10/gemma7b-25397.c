//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head) {
    Book* newBook = malloc(sizeof(Book));
    newBook->next = NULL;

    printf("Enter book title: ");
    scanf("%s", newBook->title);

    printf("Enter book author: ");
    scanf("%s", newBook->author);

    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);

    if (head == NULL) {
        head = newBook;
    } else {
        head->next = newBook;
    }

    return head;
}

Book* searchBook(Book* head, char* title) {
    Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }

    return NULL;
}

void updateBookQuantity(Book* book, int newQuantity) {
    book->quantity = newQuantity;
}

void deleteBook(Book* head, Book* bookToDelete) {
    Book* previousBook = NULL;

    while (bookToDelete) {
        if (bookToDelete == head) {
            head = bookToDelete->next;
        } else {
            previousBook->next = bookToDelete->next;
        }

        free(bookToDelete);
        bookToDelete = previousBook->next;
    }
}

int main() {
    Book* bookList = NULL;

    // Insert books
    insertBook(bookList);
    insertBook(bookList);
    insertBook(bookList);

    // Search books
    Book* book = searchBook(bookList, "Book 2");
    if (book) {
        printf("Book title: %s\n", book->title);
        printf("Book author: %s\n", book->author);
        printf("Book quantity: %d\n", book->quantity);
    }

    // Update book quantity
    updateBookQuantity(book, 10);

    // Delete book
    deleteBook(bookList, book);

    return 0;
}