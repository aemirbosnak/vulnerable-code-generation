//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_PAGES 100

struct Book {
    char title[256];
    char author[256];
    int pages;
    struct Book* next;
};

struct Book* createBook(char* title, char* author, int pages) {
    struct Book* book = malloc(sizeof(struct Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pages = pages;
    book->next = NULL;
    return book;
}

void addBook(struct Book* head, char* title, char* author, int pages) {
    struct Book* newBook = createBook(title, author, pages);
    if (head == NULL) {
        head = newBook;
    } else {
        struct Book* currentBook = head;
        while (currentBook->next) {
            currentBook = currentBook->next;
        }
        currentBook->next = newBook;
    }
}

void readBook(struct Book* head) {
    printf("List of books:\n");
    struct Book* currentBook = head;
    while (currentBook) {
        printf("  - %s by %s (%d pages)\n", currentBook->title, currentBook->author, currentBook->pages);
        currentBook = currentBook->next;
    }
}

int main() {
    struct Book* head = NULL;
    addBook(head, "The Lord of the Flies", "William Golding", 200);
    addBook(head, "To Kill a Mockingbird", "Harper Lee", 250);
    addBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 180);
    readBook(head);

    return 0;
}