//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
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

Book* insertBook(Book* head, char* title, char* author, int quantity);
Book* searchBook(Book* head, char* title);
Book* deleteBook(Book* head, char* title);

int main() {
    Book* head = NULL;

    // Case: The Adventure of the Missing Manuscript
    insertBook(&head, "The Adventure of the Missing Manuscript", "Sir Arthur Conan Doyle", 5);
    insertBook(&head, "The Sign of Four", "Sir Arthur Conan Doyle", 3);
    insertBook(&head, "The Hound of the Baskervilles", "Sir Arthur Conan Doyle", 2);

    // Query: Find the manuscript
    Book* book = searchBook(head, "The Adventure of the Missing Manuscript");
    if (book) {
        printf("Book found: %s by %s, quantity: %d\n", book->title, book->author, book->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Query: Delete the manuscript
    deleteBook(head, "The Adventure of the Missing Manuscript");
    book = searchBook(head, "The Adventure of the Missing Manuscript");
    if (book) {
        printf("Book not found.\n");
    } else {
        printf("Book deleted: %s by %s, quantity: %d\n", book->title, book->author, book->quantity);
    }

    return 0;
}

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    return head;
}

Book* searchBook(Book* head, char* title) {
    Book* book = head;
    while (book) {
        if (strcmp(book->title, title) == 0) {
            return book;
        }
        book = book->next;
    }

    return NULL;
}

Book* deleteBook(Book* head, char* title) {
    Book* book = head;
    Book* previousBook = NULL;

    while (book) {
        if (strcmp(book->title, title) == 0) {
            if (previousBook) {
                previousBook->next = book->next;
            } else {
                head = book->next;
            }
            free(book);
            return head;
        }
        previousBook = book;
        book = book->next;
    }

    return NULL;
}