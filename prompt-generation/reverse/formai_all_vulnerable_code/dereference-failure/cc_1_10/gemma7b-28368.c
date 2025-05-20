//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* CreateBook(char* title, char* author, int quantity) {
    Book* book = malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->quantity = quantity;
    book->next = NULL;
    return book;
}

void AddBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = CreateBook(title, author, quantity);
    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

void SearchBook(Book* head, char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            printf("Title: %s\n", temp->title);
            printf("Author: %s\n", temp->author);
            printf("Quantity: %d\n", temp->quantity);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;
    AddBook(head, "The Lord of the Rings: The Fellowship of the Ring", "J.R.R. Tolkien", 5);
    AddBook(head, "The Hobbit: An Unexpected Journey", "J.R.R. Tolkien", 3);
    AddBook(head, "The Harry Potter and the Sorcerer's Stone", "J.K. Rowling", 2);
    SearchBook(head, "The Lord of the Rings: The Fellowship of the Ring");
    SearchBook(head, "The Hobbit: An Unexpected Journey");
    SearchBook(head, "The Harry Potter and the Sorcerer's Stone");
    SearchBook(head, "Book not found");
    return 0;
}