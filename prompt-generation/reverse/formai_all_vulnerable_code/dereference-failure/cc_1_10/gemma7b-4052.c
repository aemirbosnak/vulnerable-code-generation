//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: puzzling
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

Book* InsertBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        head->next = newBook;
    }

    return head;
}

Book* SearchBook(Book* head, char* title) {
    Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }

        currentBook = currentBook->next;
    }

    return NULL;
}

void UpdateBookQuantity(Book* book, int newQuantity) {
    book->quantity = newQuantity;
}

void DeleteBook(Book* head, Book* bookToDelete) {
    Book* previousBook = NULL;

    if (bookToDelete == head) {
        head = bookToDelete->next;
    } else {
        previousBook = bookToDelete->next;
        previousBook->next = bookToDelete->next;
    }

    free(bookToDelete);
}

int main() {
    Book* head = NULL;

    InsertBook(head, "The Lord of the Flies", "William Golding", 5);
    InsertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 3);
    InsertBook(head, "To Kill a Mockingbird", "Harper Lee", 2);

    Book* book = SearchBook(head, "The Lord of the Flies");
    UpdateBookQuantity(book, 10);

    DeleteBook(head, book);

    book = SearchBook(head, "The Lord of the Flies");

    if (book) {
        printf("%s by %s, quantity: %d\n", book->title, book->author, book->quantity);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}