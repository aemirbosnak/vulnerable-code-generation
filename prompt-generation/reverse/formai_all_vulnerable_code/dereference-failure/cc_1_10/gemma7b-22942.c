//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
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

// Function to add a book to the library
void addBook(char* title, char* author, int quantity) {
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
void updateQuantity(char* title, int newQuantity) {
    Book* book = searchBook(title);

    if (book) {
        book->quantity = newQuantity;
    }
}

// Function to remove a book from the library
void removeBook(char* title) {
    Book* book = searchBook(title);

    if (book) {
        Book* prevBook = NULL;

        if (book == head) {
            head = book->next;
        } else {
            prevBook = head;
            while (prevBook->next != book) {
                prevBook = prevBook->next;
            }
            prevBook->next = book->next;
        }

        free(book);
    }
}

int main() {
    addBook("The Lord of the Flies", "William Golding", 5);
    addBook("The Great Gatsby", "F. Scott Fitzgerald", 10);
    addBook("To Kill a Mockingbird", "Harper Lee", 7);

    Book* book = searchBook("The Lord of the Flies");

    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    updateQuantity("The Lord of the Flies", 12);

    book = searchBook("The Lord of the Flies");

    if (book) {
        printf("Updated Title: %s\n", book->title);
        printf("Updated Author: %s\n", book->author);
        printf("Updated Quantity: %d\n", book->quantity);
    }

    removeBook("To Kill a Mockingbird");

    book = searchBook("To Kill a Mockingbird");

    if (book) {
        printf("Book not found.\n");
    }

    return 0;
}