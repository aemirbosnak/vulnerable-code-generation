//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
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

Book* createBook(char* title, char* author, char* genre, int quantity) {
    Book* book = (Book*)malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    strcpy(book->genre, genre);
    book->quantity = quantity;
    book->next = NULL;
    return book;
}

void addBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        Book* currentBook = head;
        while (currentBook->next) {
            currentBook = currentBook->next;
        }
        currentBook->next = newBook;
    }
}

void searchBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Book found: %s by %s\n", currentBook->title, currentBook->author);
            printf("Quantity: %d\n", currentBook->quantity);
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

    // Create some books
    Book* book1 = createBook("Romeo and Juliet", "William Shakespeare", "Drama", 10);
    Book* book2 = createBook("The Merchant of Venice", "William Shakespeare", "Comedy", 15);
    Book* book3 = createBook("Hamlet", "William Shakespeare", "Tragedy", 8);

    // Add books to the library
    addBook(head, book1);
    addBook(head, book2);
    addBook(head, book3);

    // Search for a book
    searchBook(head, "Romeo and Juliet");

    return 0;
}