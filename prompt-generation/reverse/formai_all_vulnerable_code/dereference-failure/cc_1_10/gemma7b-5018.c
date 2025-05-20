//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);

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

Book* searchBook(Book* head, char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void deleteBook(Book* head, char* title) {
    Book* temp = head;
    Book* prev = NULL;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    return;
}

int main() {
    Book* head = NULL;
    head = insertBook(head);
    head = insertBook(head);
    head = insertBook(head);

    Book* book = searchBook(head, "Book 2");
    if (book) {
        printf("Book found: %s", book->title);
    } else {
        printf("Book not found");
    }

    deleteBook(head, "Book 2");

    book = searchBook(head, "Book 2");
    if (book) {
        printf("Book found: %s", book->title);
    } else {
        printf("Book not found");
    }

    return 0;
}