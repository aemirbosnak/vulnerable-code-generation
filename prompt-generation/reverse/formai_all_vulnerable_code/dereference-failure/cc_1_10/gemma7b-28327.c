//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int quantity;
    float price;
};

struct Node {
    struct Book book;
    struct Node* next;
};

struct Library {
    struct Node* head;
    struct Node* tail;
};

void insertBook(struct Library* lib, struct Book book) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->book = book;
    newNode->next = NULL;

    if (lib->head == NULL) {
        lib->head = newNode;
        lib->tail = newNode;
    } else {
        lib->tail->next = newNode;
        lib->tail = newNode;
    }
}

void searchBook(struct Library* lib, char* title) {
    struct Node* current = lib->head;

    while (current) {
        if (strcmp(current->book.title, title) == 0) {
            printf("Book found: %s by %s, quantity: %d, price: %.2f\n", current->book.title, current->book.author, current->book.quantity, current->book.price);
            return;
        }
        current = current->next;
    }

    printf("Book not found.\n");
}

int main() {
    struct Library* lib = malloc(sizeof(struct Library));
    lib->head = NULL;
    lib->tail = NULL;

    struct Book book1 = {"The Lord of the Flies", "William Golding", 20, 10.0};
    insertBook(lib, book1);

    struct Book book2 = {"The Great Gatsby", "F. Scott Fitzgerald", 15, 12.0};
    insertBook(lib, book2);

    searchBook(lib, "The Lord of the Flies");
    searchBook(lib, "The Great Gatsby");

    return 0;
}