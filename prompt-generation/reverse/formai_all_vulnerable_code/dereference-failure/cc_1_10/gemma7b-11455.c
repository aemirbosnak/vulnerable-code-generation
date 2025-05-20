//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[20];
    char author[20];
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

Book* findBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void updateQuantity(Book* book, int quantity) {
    book->quantity = quantity;
}

int main() {
    Book* head = NULL;
    Book* newBook;

    // Insert some books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 3;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Canterbury Tales");
    strcpy(newBook->author, "Geoffrey Chaucer");
    newBook->quantity = 2;
    insertBook(head, newBook);

    // Find a book
    Book* foundBook = findBook(head, "The Lord of the Flies");
    if (foundBook) {
        printf("Found book: %s by %s\n", foundBook->title, foundBook->author);
        printf("Quantity: %d\n", foundBook->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Update book quantity
    updateQuantity(foundBook, 10);
    foundBook->quantity = 10;

    // Print updated book quantity
    printf("Updated book quantity: %d\n", foundBook->quantity);

    return 0;
}