//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 5
#define MAX_BOOKS 10

typedef struct Book {
    char title[20];
    char author[20];
    int pages;
    struct Book* next;
} Book;

Book* createBook(char* title, char* author, int pages) {
    Book* book = malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pages = pages;
    book->next = NULL;
    return book;
}

void displayBook(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("\n");
}

Book* findBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int main() {
    Book* head = NULL;
    head = createBook("The Lord of the Flies", "William Golding", 200);
    head = createBook("The Great Gatsby", "F. Scott Fitzgerald", 180);
    head = createBook("To Kill a Mockingbird", "Harper Lee", 220);

    displayBook(head);

    Book* book = findBook(head, "The Great Gatsby");
    displayBook(book);

    return 0;
}