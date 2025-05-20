//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: portable
#include <stdio.h>
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

    // Insert some books
    insertBook(&head, "The Lord of the Flies", "William Golding", 5);
    insertBook(&head, "The Great Gatsby", "F. Scott Fitzgerald", 3);
    insertBook(&head, "To Kill a Mockingbird", "Harper Lee", 2);

    // Search for a book
    Book* book = searchBook(head, "The Great Gatsby");
    if (book) {
        printf("Book: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Delete a book
    deleteBook(head, "To Kill a Mockingbird");
    book = searchBook(head, "To Kill a Mockingbird");
    if (book) {
        printf("Book: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = malloc(sizeof(Book));

    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        newBook->next = head;
        head = newBook;
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