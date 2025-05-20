//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
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

Book* insertBook(Book* head, Book* newBook);
Book* searchBook(Book* head, char* title);
void updateQuantity(Book* book, int quantity);

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Inserting books
    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 10;
    insertBook(head, newBook);

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 7;
    insertBook(head, newBook);

    // Searching for a book
    newBook = searchBook(head, "To Kill a Mockingbird");
    if (newBook) {
        printf("Book title: %s\n", newBook->title);
        printf("Author: %s\n", newBook->author);
        printf("Quantity: %d\n", newBook->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Updating book quantity
    updateQuantity(newBook, 15);
    newBook = searchBook(head, "To Kill a Mockingbird");
    if (newBook) {
        printf("Updated quantity: %d\n", newBook->quantity);
    }

    return 0;
}

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        newBook->next = head;
        head = newBook;
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

void updateQuantity(Book* book, int quantity) {
    book->quantity = quantity;
}