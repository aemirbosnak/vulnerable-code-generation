//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char title[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    int pages;
    int id;
    struct Node* next;
} Book;

typedef struct Node {
    Book data;
    struct Node* next;
} Node;

bool compareBooks(Book book1, Book book2) {
    return strcmp(book1.title, book2.title) == 0;
}

Node* createNode(Book data) {
    Node* newNode = (Node*) calloc(1, sizeof(Node));
    if (newNode == NULL) {
        perror("Error allocating memory for new node.");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertBook(Node** head, Book newBook) {
    Node* newNode = createNode(newBook);
    Node* current = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (current->next != NULL && compareBooks(current->data, newBook) < 0) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteBook(Node** head, int bookId) {
    Node* current = *head;
    Node* previous = NULL;

    while (current != NULL && current->data.id != bookId) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Book not found.\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

void displayList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("Title: %s, Author: %s, Pages: %d, ID: %d\n", current->data.title, current->data.author, current->data.pages, current->data.id);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    Book newBook1 = {"The Great Gatsby", "F. Scott Fitzgerald", 180, 1};
    Book newBook2 = {"To Kill a Mockingbird", "Harper Lee", 281, 2};
    Book newBook3 = {"Pride and Prejudice", "Jane Austen", 238, 3};

    insertBook(&head, newBook1);
    insertBook(&head, newBook2);
    insertBook(&head, newBook3);

    displayList(head);

    deleteBook(&head, 3);

    printf("\nList after deleting Pride and Prejudice:\n");
    displayList(head);

    return 0;
}