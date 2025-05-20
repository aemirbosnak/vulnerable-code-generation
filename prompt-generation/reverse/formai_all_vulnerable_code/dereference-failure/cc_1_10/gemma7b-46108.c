//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
    return head;
}

void searchBook(Book* head, char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            printf("Title: %s\n", temp->title);
            printf("Author: %s\n", temp->author);
            printf("Genre: %s\n", temp->genre);
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

    // Insert some books
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    strcpy(newBook1->genre, "Classic");
    newBook1->quantity = 5;
    insertBook(head, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "To Kill a Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    strcpy(newBook2->genre, "Classic");
    newBook2->quantity = 3;
    insertBook(head, newBook2);

    Book* newBook3 = malloc(sizeof(Book));
    strcpy(newBook3->title, "The Great Gatsby");
    strcpy(newBook3->author, "F. Scott Fitzgerald");
    strcpy(newBook3->genre, "Classic");
    newBook3->quantity = 2;
    insertBook(head, newBook3);

    // Search for a book
    searchBook(head, "To Kill a Mockingbird");

    return 0;
}