//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10

typedef struct Book {
    char title[20];
    char author[20];
    int pages;
    struct Book* next;
} Book;

Book* createBook(char* title, char* author, int pages) {
    Book* book = (Book*)malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pages = pages;
    book->next = NULL;
    return book;
}

Book* insertBook(Book* head, char* title, char* author, int pages) {
    Book* book = createBook(title, author, pages);
    if (head == NULL) {
        return book;
    }
    Book* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = book;
    return head;
}

void displayBooks(Book* head) {
    Book* temp = head;
    while (temp) {
        printf("%s by %s, %d pages\n", temp->title, temp->author, temp->pages);
        temp = temp->next;
    }
}

int main() {
    Book* head = NULL;
    head = insertBook(head, "The Lord of the Flies", "William Golding", 200);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 250);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 225);
    insertBook(head, "The Catcher in the Rye", "J.D. Salinger", 240);

    displayBooks(head);

    return 0;
}