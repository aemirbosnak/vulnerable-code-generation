//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
};

struct Library {
    struct Book* head;
    struct Book* tail;
    int numBooks;
};

void insertBook(struct Library* library, char* title, char* author, int quantity) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->quantity = quantity;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = NULL;

    if (library->head == NULL) {
        library->head = newBook;
        library->tail = newBook;
    } else {
        library->tail->next = newBook;
        library->tail = newBook;
    }

    library->numBooks++;
}

void searchBook(struct Library* library, char* title) {
    struct Book* currentBook = library->head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Title: %s\n", currentBook->title);
            printf("Author: %s\n", currentBook->author);
            printf("Quantity: %d\n", currentBook->quantity);
            break;
        }
        currentBook = currentBook->next;
    }

    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    struct Library* library = (struct Library*)malloc(sizeof(struct Library));
    library->head = NULL;
    library->tail = NULL;
    library->numBooks = 0;

    insertBook(library, "The Lord of the Flies", "William Golding", 10);
    insertBook(library, "To Kill a Mockingbird", "Harper Lee", 8);
    insertBook(library, "The Great Gatsby", "F. Scott Fitzgerald", 7);
    insertBook(library, "The Catcher in the Rye", "J.D. Salinger", 6);

    searchBook(library, "The Lord of the Flies");
    searchBook(library, "To Kill a Mockingbird");
    searchBook(library, "Book not found");

    return 0;
}