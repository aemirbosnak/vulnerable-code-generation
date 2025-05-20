//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Book {
    char title[20];
    char author[20];
    int year;
    struct Book* next;
} Book;

Book* insertBook(Book* head, char* title, char* author, int year) {
    Book* newBook = malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->next = NULL;

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

int searchBook(Book* head, char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

int main() {
    Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 1954);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 1925);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 1960);

    if (searchBook(head, "The Lord of the Flies") == 1) {
        printf("Book found!\n");
    } else {
        printf("Book not found.\n");
    }

    return 0;
}