//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR 20

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
    return head;
}

Book* findBook(Book* head, char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void updateBookQuantity(Book* head, char* title, int quantity) {
    Book* book = findBook(head, title);
    if (book) {
        book->quantity = quantity;
    }
}

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 10;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 5;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Hobbit");
    strcpy(newBook->author, "J.R.R. Tolkien");
    newBook->quantity = 7;
    insertBook(head, newBook);

    updateBookQuantity(head, "The Lord of the Flies", 15);

    Book* book = findBook(head, "The Great Gatsby");
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Quantity: %d\n", book->quantity);
    }

    return 0;
}