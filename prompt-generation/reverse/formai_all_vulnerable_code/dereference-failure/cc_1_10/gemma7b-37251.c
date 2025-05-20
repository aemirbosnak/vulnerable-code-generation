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

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        head->next = insertBook(head->next, newBook);
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

void updateQuantity(Book* book, int newQuantity) {
    book->quantity = newQuantity;
}

void printBooks(Book* head) {
    Book* currentBook = head;
    while (currentBook) {
        printf("%s by %s, quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
        currentBook = currentBook->next;
    }
}

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Insert some books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 10;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Catcher in the Rye");
    strcpy(newBook->author, "J.D. Salinger");
    newBook->quantity = 7;
    insertBook(head, newBook);

    // Search for a book
    Book* foundBook = searchBook(head, "The Lord of the Flies");
    if (foundBook) {
        printf("Found book: %s by %s, quantity: %d\n", foundBook->title, foundBook->author, foundBook->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Update book quantity
    updateQuantity(foundBook, 12);

    // Print all books
    printBooks(head);

    return 0;
}