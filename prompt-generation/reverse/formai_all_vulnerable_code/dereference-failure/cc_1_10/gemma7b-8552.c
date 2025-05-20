//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);
Book* searchBook(Book* head, char* title);
Book* deleteBook(Book* head, char* title);

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Inserting a few books
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

    // Searching for a book
    newBook = searchBook(head, "The Lord of the Flies");
    if (newBook) {
        printf("Title: %s\n", newBook->title);
        printf("Author: %s\n", newBook->author);
        printf("Quantity: %d\n", newBook->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Deleting a book
    deleteBook(head, "To Kill a Mockingbird");
    newBook = searchBook(head, "To Kill a Mockingbird");
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