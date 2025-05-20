//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    char genre[20];
    int quantity;
    struct Book* next;
} Book;

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

void printBooks(Book* head) {
    Book* currentBook = head;
    while (currentBook) {
        printf("%s by %s ( %d copies )\n", currentBook->title, currentBook->author, currentBook->quantity);
        currentBook = currentBook->next;
    }
}

int main() {
    Book* head = NULL;

    // Insert some books
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    strcpy(newBook1->genre, "Coming-of-age");
    newBook1->quantity = 5;
    head = insertBook(head, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "To Kill a Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    strcpy(newBook2->genre, "Classic");
    newBook2->quantity = 10;
    head = insertBook(head, newBook2);

    Book* newBook3 = malloc(sizeof(Book));
    strcpy(newBook3->title, "The Great Gatsby");
    strcpy(newBook3->author, "F. Scott Fitzgerald");
    strcpy(newBook3->genre, "Literary Fiction");
    newBook3->quantity = 7;
    head = insertBook(head, newBook3);

    // Search for a book
    Book* foundBook = searchBook(head, "To Kill a Mockingbird");
    if (foundBook) {
        printf("Found book: %s by %s ( %d copies )\n", foundBook->title, foundBook->author, foundBook->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Delete a book
    head = deleteBook(head, "The Great Gatsby");
    printBooks(head);

    return 0;
}