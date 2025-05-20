//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of books
#define MAX_BOOKS 100

// Define the book structure
typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
} Book;

// Create a linked list of books
typedef struct Node {
    Book book;
    struct Node* next;
} Node;

// Function to insert a book into the linked list
void insertBook(Node** head, Book book) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->book = book;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for a book in the linked list
Book* searchBook(Node* head, char* title) {
    while (head) {
        if (strcmp(head->book.title, title) == 0) {
            return &head->book;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a book in the linked list
void updateQuantity(Node* head, char* title, int quantity) {
    Book* book = searchBook(head, title);

    if (book) {
        book->quantity = quantity;
    }
}

// Function to delete a book from the linked list
void deleteBook(Node** head, char* title) {
    Book* book = searchBook(head, title);

    if (book) {
        Node* prev = NULL;
        Node* current = *head;

        while (current) {
            if (strcmp(current->book.title, title) == 0) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    *head = current->next;
                }
                free(current);
                return;
            }
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    // Create a linked list of books
    Node* head = NULL;

    // Insert some books into the linked list
    Book book1 = {"The Lord of the Flies", "William Golding", 50};
    insertBook(&head, book1);

    Book book2 = {"To Kill a Mockingbird", "Harper Lee", 20};
    insertBook(&head, book2);

    Book book3 = {"The Great Gatsby", "F. Scott Fitzgerald", 30};
    insertBook(&head, book3);

    // Search for a book in the linked list
    Book* book = searchBook(head, "To Kill a Mockingbird");

    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Update the quantity of a book in the linked list
    updateQuantity(head, "The Lord of the Flies", 20);

    book = searchBook(head, "The Lord of the Flies");

    if (book) {
        printf("Updated quantity: %d\n", book->quantity);
    }

    // Delete a book from the linked list
    deleteBook(&head, "The Great Gatsby");

    book = searchBook(head, "The Great Gatsby");

    if (book) {
        printf("Book not found.\n");
    }

    return 0;
}