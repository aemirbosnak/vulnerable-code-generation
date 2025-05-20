//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
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

Book* insertBook(Book* head, Book* newBook);
void searchBook(Book* head, char* title);
void updateQuantity(Book* head, char* title, int quantity);
void deleteBook(Book* head, char* title);

int main() {
    Book* head = NULL;

    // Inserting books
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    newBook1->quantity = 10;
    head = insertBook(head, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "To Kill a Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    newBook2->quantity = 5;
    head = insertBook(head, newBook2);

    Book* newBook3 = malloc(sizeof(Book));
    strcpy(newBook3->title, "The Great Gatsby");
    strcpy(newBook3->author, "F. Scott Fitzgerald");
    newBook3->quantity = 20;
    head = insertBook(head, newBook3);

    // Searching for a book
    searchBook(head, "The Lord of the Flies");

    // Updating quantity of a book
    updateQuantity(head, "To Kill a Mockingbird", 10);

    // Deleting a book
    deleteBook(head, "The Great Gatsby");

    return 0;
}

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        newBook->next = head;
        head = newBook;
    }
    return head;
}

void searchBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            printf("Book found: %s by %s\n", head->title, head->author);
            printf("Quantity: %d\n", head->quantity);
            return;
        }
        head = head->next;
    }
    printf("Book not found.\n");
}

void updateQuantity(Book* head, char* title, int quantity) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            head->quantity = quantity;
            printf("Quantity updated to: %d\n", head->quantity);
            return;
        }
        head = head->next;
    }
    printf("Book not found.\n");
}

void deleteBook(Book* head, char* title) {
    Book* previousBook = NULL;
    Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            if (previousBook) {
                previousBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(currentBook);
            printf("Book deleted: %s by %s\n", currentBook->title, currentBook->author);
            return;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }

    printf("Book not found.\n");
}