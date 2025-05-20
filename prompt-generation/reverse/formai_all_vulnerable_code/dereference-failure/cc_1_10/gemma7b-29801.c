//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

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

    // Inserting books
    Book* book1 = malloc(sizeof(Book));
    strcpy(book1->title, "The Lord of the Flies");
    strcpy(book1->author, "William Golding");
    book1->quantity = 5;
    head = insertBook(head, book1);

    Book* book2 = malloc(sizeof(Book));
    strcpy(book2->title, "The Great Gatsby");
    strcpy(book2->author, "F. Scott Fitzgerald");
    book2->quantity = 3;
    head = insertBook(head, book2);

    Book* book3 = malloc(sizeof(Book));
    strcpy(book3->title, "To Kill a Mockingbird");
    strcpy(book3->author, "Harper Lee");
    book3->quantity = 2;
    head = insertBook(head, book3);

    // Searching for a book
    book2 = searchBook(head, "The Great Gatsby");
    if (book2) {
        printf("Title: %s\n", book2->title);
        printf("Author: %s\n", book2->author);
        printf("Quantity: %d\n", book2->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Deleting a book
    book3 = deleteBook(head, "To Kill a Mockingbird");
    if (book3) {
        printf("Title: %s\n", book3->title);
        printf("Author: %s\n", book3->author);
        printf("Quantity: %d\n", book3->quantity);
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
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
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
            return currentBook;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
    return NULL;
}