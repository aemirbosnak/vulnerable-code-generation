//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);
Book* searchBook(Book* head, char* title);
Book* deleteBook(Book* head, char* title);

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Inserting books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    strcpy(newBook->genre, "Novel");
    newBook->quantity = 10;
    head = insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    strcpy(newBook->genre, "Novel");
    newBook->quantity = 8;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    strcpy(newBook->genre, "Novel");
    newBook->quantity = 6;
    insertBook(head, newBook);

    // Searching for a book
    newBook = searchBook(head, "To Kill a Mockingbird");
    if (newBook) {
        printf("Title: %s\n", newBook->title);
        printf("Author: %s\n", newBook->author);
        printf("Genre: %s\n", newBook->genre);
        printf("Quantity: %d\n", newBook->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Deleting a book
    deleteBook(head, "The Great Gatsby");
    newBook = searchBook(head, "The Great Gatsby");
    if (newBook) {
        printf("Book deleted successfully.\n");
    } else {
        printf("Book not found.\n");
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

Book* deleteBook(Book* head, char* title) {
    Book* previousBook = NULL;
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            if (previousBook) {
                previousBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(currentBook);
            return head;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
    return NULL;
}