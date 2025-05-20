//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: creative
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
void displayBooks(Book* head);

int main() {
    Book* head = NULL;
    head = insertBook(head, "The Lord of the Flies", "William Golding", 5);
    head = insertBook(head, "To Kill a Mockingbird", "Harper Lee", 10);
    head = insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 7);
    head = insertBook(head, "The Catcher in the Rye", "J.D. Salinger", 8);

    displayBooks(head);

    Book* book = searchBook(head, "To Kill a Mockingbird");
    if (book) {
        printf("Book found: %s\n", book->title);
    } else {
        printf("Book not found.\n");
    }

    book = deleteBook(head, "The Great Gatsby");
    if (book) {
        printf("Book deleted: %s\n", book->title);
    } else {
        printf("Book not deleted.\n");
    }

    displayBooks(head);

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
    Book* book = searchBook(head, title);
    if (book) {
        Book* prevBook = NULL;
        Book* tempBook = head;
        while (tempBook) {
            if (tempBook == book) {
                if (prevBook) {
                    prevBook->next = book->next;
                } else {
                    head = book->next;
                }
                free(book);
                return head;
            }
            prevBook = tempBook;
            tempBook = tempBook->next;
        }
    }

    return NULL;
}

void displayBooks(Book* head) {
    Book* book = head;
    while (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
        printf("\n");
        book = book->next;
    }
}