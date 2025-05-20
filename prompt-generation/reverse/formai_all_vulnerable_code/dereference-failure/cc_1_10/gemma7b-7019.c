//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[256];
    char author[256];
    int pages;
    struct Book* next;
} Book;

Book* InsertBook(Book* head, char* title, char* author, int pages) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->pages = pages;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* currentBook = head;
        while (currentBook->next) {
            currentBook = currentBook->next;
        }
        currentBook->next = newBook;
    }

    return head;
}

void PrintBooks(Book* head) {
    Book* currentBook = head;
    while (currentBook) {
        printf("%s by %s, %d pages\n", currentBook->title, currentBook->author, currentBook->pages);
        currentBook = currentBook->next;
    }
}

int main() {
    Book* head = NULL;

    InsertBook(head, "The Lord of the Flies", "William Golding", 200);
    InsertBook(head, "To Kill a Mockingbird", "Harper Lee", 320);
    InsertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 250);

    PrintBooks(head);

    return 0;
}