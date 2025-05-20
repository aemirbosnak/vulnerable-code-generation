//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: scalable
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

// Function to insert a book into the library
void insertBook(Book** head, Book* newBook) {
    if (*head == NULL) {
        *head = newBook;
    } else {
        (*head)->next = newBook;
        *head = newBook;
    }
}

// Function to search for a book in the library
Book* searchBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update the quantity of a book in the library
void updateQuantity(Book* book, int newQuantity) {
    book->quantity = newQuantity;
}

// Function to delete a book from the library
void deleteBook(Book* head, char* title) {
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
            return;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }

    return;
}

int main() {
    Book* head = NULL;

    // Insert some books into the library
    insertBook(&head, malloc(sizeof(Book)));
    strcpy(head->title, "The Lord of the Flies");
    strcpy(head->author, "William Golding");
    head->quantity = 10;

    insertBook(&head, malloc(sizeof(Book)));
    strcpy(head->title, "To Kill a Mockingbird");
    strcpy(head->author, "Harper Lee");
    head->quantity = 15;

    insertBook(&head, malloc(sizeof(Book)));
    strcpy(head->title, "The Great Gatsby");
    strcpy(head->author, "F. Scott Fitzgerald");
    head->quantity = 20;

    // Search for a book in the library
    Book* book = searchBook(head, "The Lord of the Flies");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Update the quantity of a book in the library
    updateQuantity(book, 12);

    // Search for the book again after updating the quantity
    book = searchBook(head, "The Lord of the Flies");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Delete a book from the library
    deleteBook(head, "The Great Gatsby");

    // Search for the book after deleting it
    book = searchBook(head, "The Great Gatsby");
    if (book) {
        printf("Book not found.\n");
    } else {
        printf("Book deleted successfully.\n");
    }

    return 0;
}