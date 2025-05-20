//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of books in the library
#define MAX_BOOKS 100

// Define the book structure
typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

// Create a linked list of books
Book* head = NULL;

// Function to insert a book into the library
void insertBook(char* title, char* author, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

// Function to search for a book in the library
Book* searchBook(char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update the quantity of a book in the library
void updateBookQuantity(char* title, int newQuantity) {
    Book* book = searchBook(title);
    if (book) {
        book->quantity = newQuantity;
    }
}

// Function to delete a book from the library
void deleteBook(char* title) {
    Book* book = searchBook(title);
    if (book) {
        Book* prev = NULL;
        Book* temp = head;
        while (temp) {
            if (book == temp) {
                if (prev) {
                    prev->next = book->next;
                } else {
                    head = book->next;
                }
                free(book);
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return;
}

int main() {
    insertBook("The Lord of the Flies", "William Golding", 5);
    insertBook("The Great Gatsby", "F. Scott Fitzgerald", 10);
    insertBook("The Canterbury Tales", "Geoffrey Chaucer", 7);

    Book* book = searchBook("The Lord of the Flies");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    updateBookQuantity("The Great Gatsby", 15);

    book = searchBook("The Great Gatsby");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    deleteBook("The Canterbury Tales");

    book = searchBook("The Canterbury Tales");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    return 0;
}