//Gemma-7B DATASET v1.0 Category: Database querying ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LEN 1024

typedef struct Book {
    char title[256];
    char author[256];
    int year;
    struct Book* next;
} Book;

Book* insertBook(Book* head, char* title, char* author, int year) {
    Book* newBook = malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->next = NULL;

    if (head == NULL) {
        return newBook;
    }

    head->next = newBook;
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

    insertBook(&head, "The Lord of the Flies", "William Golding", 1954);
    insertBook(&head, "To Kill a Mockingbird", "Harper Lee", 1960);
    insertBook(&head, "The Great Gatsby", "F. Scott Fitzgerald", 1925);

    Book* foundBook = findBook(head, "To Kill a Mockingbird");

    if (foundBook) {
        printf("Title: %s\n", foundBook->title);
        printf("Author: %s\n", foundBook->author);
        printf("Year: %d\n", foundBook->year);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}