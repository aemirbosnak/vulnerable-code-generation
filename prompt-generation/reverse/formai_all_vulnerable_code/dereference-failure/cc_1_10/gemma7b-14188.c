//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: calm
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
void updateBookQuantity(char* title, int quantity) {
    Book* book = searchBook(title);
    if (book) {
        book->quantity = quantity;
    }
}

// Function to delete a book from the library
void deleteBook(char* title) {
    Book* book = searchBook(title);
    if (book) {
        Book* prevBook = NULL;
        Book* tempBook = head;
        while (tempBook) {
            if (strcmp(tempBook->title, title) == 0) {
                if (prevBook) {
                    prevBook->next = book->next;
                } else {
                    head = book->next;
                }
                free(book);
                return;
            }
            prevBook = tempBook;
            tempBook = tempBook->next;
        }
    }
}

// Main function
int main() {
    // Insert books into the library
    insertBook("The Lord of the Flies", "William Golding", 5);
    insertBook("To Kill a Mockingbird", "Harper Lee", 10);
    insertBook("The Great Gatsby", "F. Scott Fitzgerald", 7);

    // Search for a book in the library
    Book* book = searchBook("To Kill a Mockingbird");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    // Update the quantity of a book in the library
    updateBookQuantity("The Lord of the Flies", 12);

    // Delete a book from the library
    deleteBook("The Great Gatsby");

    return 0;
}