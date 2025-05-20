//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Book {
    char title[50];
    char author[50];
    int year;
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

Book* findBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }
    return NULL;
}

int main() {
    Book* head = NULL;
    Book* newBook;

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->year = 1954;

    insertBook(head, newBook);

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->year = 1925;

    insertBook(head, newBook);

    newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->year = 1960;

    insertBook(head, newBook);

    Book* foundBook = findBook(head, "The Great Gatsby");

    if (foundBook) {
        printf("Title: %s\n", foundBook->title);
        printf("Author: %s\n", foundBook->author);
        printf("Year: %d\n", foundBook->year);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}