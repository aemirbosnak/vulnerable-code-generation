//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: peaceful
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

Book* searchBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

Book* deleteBook(Book* head, char* title) {
    Book* prev = NULL;
    Book* current = head;

    while (current) {
        if (strcmp(current->title, title) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }

    return NULL;
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
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 3;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 2;
    insertBook(head, newBook);

    // Search for a book
    newBook = searchBook(head, "To Kill a Mockingbird");
    if (newBook) {
        printf("Title: %s\n", newBook->title);
        printf("Author: %s\n", newBook->author);
        printf("Quantity: %d\n", newBook->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Delete a book
    deleteBook(head, "The Great Gatsby");
    newBook = searchBook(head, "The Great Gatsby");
    if (newBook) {
        printf("Book deleted.\n");
    } else {
        printf("Book not found.\n");
    }

    return 0;
}