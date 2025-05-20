//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for book
typedef struct {
    char title[50];
    char author[50];
    int pages;
} Book;

// Struct for node in linked list
typedef struct Node {
    Book book;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(Book book) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->book = book;
    newNode->next = NULL;
    return newNode;
}

// Function to add a book to linked list
void addBook(Node** headRef, Book book) {
    Node* newNode = createNode(book);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to delete a book by title
void deleteBook(Node** headRef, char* title) {
    Node* currNode = *headRef;
    Node* prevNode = NULL;

    while (currNode != NULL) {
        if (strcmp(currNode->book.title, title) == 0) {
            if (prevNode == NULL) {
                *headRef = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode);
            return;
        } else {
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
}

// Function to print all books in linked list
void printBooks(Node** headRef) {
    Node* currNode = *headRef;

    while (currNode != NULL) {
        printf("%s by %s, %d pages\n", currNode->book.title, currNode->book.author, currNode->book.pages);
        currNode = currNode->next;
    }
}

// Function to free all memory used by linked list
void freeList(Node** headRef) {
    Node* currNode = *headRef;
    Node* nextNode = NULL;

    while (currNode != NULL) {
        nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }

    *headRef = NULL;
}

int main() {
    // Create empty linked list
    Node* head = NULL;

    // Add some books to linked list
    Book book1 = {"The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 224};
    Book book2 = {"1984", "George Orwell", 328};
    Book book3 = {"Brave New World", "Aldous Huxley", 288};
    Book book4 = {"The Catcher in the Rye", "J.D. Salinger", 224};
    addBook(&head, book1);
    addBook(&head, book2);
    addBook(&head, book3);
    addBook(&head, book4);

    // Print all books
    printf("All books:\n");
    printBooks(&head);
    printf("\n");

    // Delete a book by title
    char* titleToDelete = "Brave New World";
    printf("Deleting book %s...\n", titleToDelete);
    deleteBook(&head, titleToDelete);

    // Print all books again
    printf("\nAll books after deleting %s:\n", titleToDelete);
    printBooks(&head);
    printf("\n");

    // Free memory used by linked list
    freeList(&head);

    return 0;
}