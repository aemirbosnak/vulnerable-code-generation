//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = malloc(sizeof(Book));
    newBook->quantity = quantity;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newBook;
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
    Book* currentBook = head;
    Book* previousBook = NULL;

    if (bookToDelete == head) {
        head = bookToDelete->next;
    } else {
        while (currentBook) {
            if (currentBook == bookToDelete) {
                previousBook->next = bookToDelete->next;
            }
            previousBook = currentBook;
            currentBook = currentBook->next;
        }
    }

    free(bookToDelete);
}

int main() {
    Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 10);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 7);

    Book* book = searchBook(head, "The Lord of the Flies");
    updateBookQuantity(book, 12);

    deleteBook(head, book);

    book = searchBook(head, "The Lord of the Flies");
    if (book) {
        printf("%s by %s has a quantity of %d.\n", book->title, book->author, book->quantity);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}