//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
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
    Book* newBook = malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* currentBook = head;
        while (currentBook->next != NULL) {
            currentBook = currentBook->next;
        }
        currentBook->next = newBook;
    }
}

// Function to search for a book in the library
Book* searchBook(char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }
    return NULL;
}

// Function to update the quantity of a book
void updateBookQuantity(char* title, int newQuantity) {
    Book* book = searchBook(title);
    if (book) {
        book->quantity = newQuantity;
    }
}

// Main function
int main() {
    insertBook("The Lord of the Flies", "William Golding", 10);
    insertBook("To Kill a Mockingbird", "Harper Lee", 15);
    insertBook("The Great Gatsby", "F. Scott Fitzgerald", 8);

    Book* book = searchBook("To Kill a Mockingbird");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    updateBookQuantity("The Lord of the Flies", 12);

    book = searchBook("The Lord of the Flies");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    return 0;
}