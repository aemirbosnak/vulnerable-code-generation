//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHORS 50

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

typedef struct Author {
    char name[50];
    struct Author* next;
} Author;

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
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

    return head;
}

Author* insertAuthor(Author* head, char* name) {
    Author* newAuthor = (Author*)malloc(sizeof(Author));
    strcpy(newAuthor->name, name);
    newAuthor->next = NULL;

    if (head == NULL) {
        head = newAuthor;
    } else {
        Author* currentAuthor = head;
        while (currentAuthor->next != NULL) {
            currentAuthor = currentAuthor->next;
        }
        currentAuthor->next = newAuthor;
    }

    return head;
}

void searchBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Book: %s\nAuthor: %s\nQuantity: %d\n", currentBook->title, currentBook->author, currentBook->quantity);
        }
        currentBook = currentBook->next;
    }
}

void searchAuthor(Author* head, char* name) {
    Author* currentAuthor = head;
    while (currentAuthor) {
        if (strcmp(currentAuthor->name, name) == 0) {
            printf("Books written by %s:\n", currentAuthor->name);
            Book* currentBook = head;
            while (currentBook) {
                if (strcmp(currentBook->author, currentAuthor->name) == 0) {
                    printf("Book: %s\n", currentBook->title);
                }
                currentBook = currentBook->next;
            }
        }
        currentAuthor = currentAuthor->next;
    }
}

int main() {
    Book* bookHead = NULL;
    Author* authorHead = NULL;

    insertBook(bookHead, "The Lord of the Flies", "William Golding", 5);
    insertBook(bookHead, "To Kill a Mockingbird", "Harper Lee", 10);
    insertBook(bookHead, "The Great Gatsby", "F. Scott Fitzgerald", 7);
    insertBook(bookHead, "Pride and Prejudice", "Jane Austen", 8);

    insertAuthor(authorHead, "William Golding");
    insertAuthor(authorHead, "Harper Lee");
    insertAuthor(authorHead, "F. Scott Fitzgerald");
    insertAuthor(authorHead, "Jane Austen");

    searchBook(bookHead, "To Kill a Mockingbird");
    searchAuthor(authorHead, "William Golding");

    return 0;
}