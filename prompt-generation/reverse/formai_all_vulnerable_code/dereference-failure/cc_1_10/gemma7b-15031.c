//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

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

    insertBook(head, "Book 1", "Author 1", 10);
    insertBook(head, "Book 2", "Author 2", 5);
    insertBook(head, "Book 3", "Author 3", 7);

    Book* book = searchBook(head, "Book 2");
    if (book) {
        printf("%s by %s, quantity: %d\n", book->title, book->author, book->quantity);
    }

    deleteBook(head, "Book 2");

    book = searchBook(head, "Book 2");
    if (book) {
        printf("%s by %s, quantity: %d\n", book->title, book->author, book->quantity);
    }

    return 0;
}