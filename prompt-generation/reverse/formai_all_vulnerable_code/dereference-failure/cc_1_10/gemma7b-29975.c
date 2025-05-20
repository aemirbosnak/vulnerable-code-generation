//Gemma-7B DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Book {
    char title[MAX_BUFFER_SIZE];
    char author[MAX_BUFFER_SIZE];
    int pages;
    struct Book* next;
} Book;

Book* insertBook(Book* head, char* title, char* author, int pages);
Book* searchBook(Book* head, char* title);

int main() {
    Book* head = NULL;

    // Insert some books
    insertBook(head, "The Lord of the Flies", "William Golding", 384);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 180);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 320);

    // Search for a book
    Book* book = searchBook(head, "The Lord of the Flies");

    // Print book information
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Pages: %d\n", book->pages);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}

Book* insertBook(Book* head, char* title, char* author, int pages) {
    Book* newBook = malloc(sizeof(Book));

    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->pages = pages;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        newBook->next = head;
        head = newBook;
    }

    return head;
}

Book* searchBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}