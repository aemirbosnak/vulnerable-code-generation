//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

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
    Book* newBook;

    // Inserting books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Adventures of Sherlock Holmes");
    strcpy(newBook->author, "Sir Arthur Conan Doyle");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Sign of Four");
    strcpy(newBook->author, "Sir Arthur Conan Doyle");
    newBook->quantity = 3;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Hound of the Baskervilles");
    strcpy(newBook->author, "Sir Arthur Conan Doyle");
    newBook->quantity = 2;
    insertBook(head, newBook);

    // Searching for a book
    searchBook(head, "The Adventures of Sherlock Holmes");

    // Updating book quantity
    updateQuantity(head, "The Sign of Four", 4);

    // Displaying updated book quantity
    searchBook(head, "The Sign of Four");

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
    while (head) {
        if (strcmp(head->title, title) == 0) {
            printf("Title: %s\n", head->title);
            printf("Author: %s\n", head->author);
            printf("Quantity: %d\n", head->quantity);
            return;
        }
        head = head->next;
    }
    printf("Book not found.\n");
}

void updateQuantity(Book* head, char* title, int quantity) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            head->quantity = quantity;
            return;
        }
        head = head->next;
    }
    printf("Book not found.\n");
}