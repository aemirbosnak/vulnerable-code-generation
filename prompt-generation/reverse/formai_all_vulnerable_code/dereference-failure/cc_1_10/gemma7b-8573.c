//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: satisfied
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
} Book;

// Create a linked list of books
typedef struct BookNode {
    Book book;
    struct BookNode* next;
} BookNode;

// Function to insert a book into the library
void insertBook(BookNode** head, Book book) {
    BookNode* newNode = malloc(sizeof(BookNode));
    newNode->book = book;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for a book in the library
BookNode* searchBook(BookNode* head, char* title) {
    while (head) {
        if (strcmp(head->book.title, title) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a book in the library
void updateBookQuantity(BookNode* head, char* title, int quantity) {
    BookNode* bookNode = searchBook(head, title);

    if (bookNode) {
        bookNode->book.quantity = quantity;
    }
}

// Function to list all books in the library
void listBooks(BookNode* head) {
    while (head) {
        printf("%s by %s (Quantity: %d)\n", head->book.title, head->book.author, head->book.quantity);
        head = head->next;
    }
}

int main() {
    BookNode* head = NULL;

    // Insert some books into the library
    Book book1 = {"The Lord of the Flies", "William Golding", 10};
    insertBook(&head, book1);

    Book book2 = {"The Great Gatsby", "F. Scott Fitzgerald", 5};
    insertBook(&head, book2);

    Book book3 = {"To Kill a Mockingbird", "Harper Lee", 7};
    insertBook(&head, book3);

    // Search for a book in the library
    BookNode* bookNode = searchBook(head, "The Great Gatsby");

    if (bookNode) {
        printf("Book found: %s by %s (Quantity: %d)\n", bookNode->book.title, bookNode->book.author, bookNode->book.quantity);
    } else {
        printf("Book not found.\n");
    }

    // Update the quantity of a book in the library
    updateBookQuantity(head, "To Kill a Mockingbird", 12);

    // List all books in the library
    listBooks(head);

    return 0;
}