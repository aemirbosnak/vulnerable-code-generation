//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: statistical
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

void searchBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            printf("Book found: %s by %s, quantity: %d\n", head->title, head->author, head->quantity);
            return;
        }
        head = head->next;
    }
    printf("Book not found.\n");
}

void updateBookQuantity(Book* head, char* title, int newQuantity) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            head->quantity = newQuantity;
            return;
        }
        head = head->next;
    }
    printf("Book not found.\n");
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
    newBook->quantity = 3;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Catcher in the Rye");
    strcpy(newBook->author, "J.D. Salinger");
    newBook->quantity = 2;
    insertBook(head, newBook);

    // Search for a book
    searchBook(head, "The Lord of the Flies");

    // Update book quantity
    updateBookQuantity(head, "The Great Gatsby", 4);

    // Search for the updated book quantity
    searchBook(head, "The Great Gatsby");

    return 0;
}