//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);
void searchBook(Book* head, char* title);
void updateQuantity(Book* head, char* title, int quantity);

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Insert a few books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 3;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 2;
    insertBook(head, newBook);

    // Search for a book
    searchBook(head, "To Kill a Mockingbird");

    // Update the quantity of a book
    updateQuantity(head, "The Lord of the Flies", 10);

    // Print the updated list of books
    for (Book* currentBook = head; currentBook; currentBook = currentBook->next) {
        printf("%s by %s, quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
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

void searchBook(Book* head, char* title) {
    for (Book* currentBook = head; currentBook; currentBook = currentBook->next) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Book found: %s by %s, quantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
            return;
        }
    }

    printf("Book not found.\n");
}

void updateQuantity(Book* head, char* title, int quantity) {
    for (Book* currentBook = head; currentBook; currentBook = currentBook->next) {
        if (strcmp(currentBook->title, title) == 0) {
            currentBook->quantity = quantity;
            return;
        }
    }

    printf("Book not found.\n");
}