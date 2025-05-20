//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: rigorous
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

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
    return head;
}

void searchBook(Book* head, char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            printf("Title: %s\n", temp->title);
            printf("Author: %s\n", temp->author);
            printf("Genre: %s\n", temp->genre);
            printf("Quantity: %d\n", temp->quantity);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Insert some books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    strcpy(newBook->genre, "Classic");
    newBook->quantity = 10;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    strcpy(newBook->genre, "Classic");
    newBook->quantity = 8;
    insertBook(head, newBook);

    // Search for a book
    searchBook(head, "The Lord of the Flies");

    return 0;
}