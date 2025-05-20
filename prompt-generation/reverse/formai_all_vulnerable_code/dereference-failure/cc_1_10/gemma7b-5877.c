//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);
void displayBooks(Book* head);
void updateQuantity(Book* head, char* title, int quantity);

int main() {
    Book* head = NULL;
    Book* newBook = NULL;

    // Inserting a few books
    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Lord of the Flies");
    strcpy(newBook->author, "William Golding");
    newBook->quantity = 5;
    head = insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "To Kill a Mockingbird");
    strcpy(newBook->author, "Harper Lee");
    newBook->quantity = 3;
    insertBook(head, newBook);

    newBook = malloc(sizeof(Book));
    strcpy(newBook->title, "The Great Gatsby");
    strcpy(newBook->author, "F. Scott Fitzgerald");
    newBook->quantity = 2;
    insertBook(head, newBook);

    // Displaying all books
    displayBooks(head);

    // Updating the quantity of "The Lord of the Flies"
    updateQuantity(head, "The Lord of the Flies", 10);

    // Displaying updated books
    displayBooks(head);

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

void displayBooks(Book* head) {
    while (head) {
        printf("%s by %s, quantity: %d\n", head->title, head->author, head->quantity);
        head = head->next;
    }
}

void updateQuantity(Book* head, char* title, int quantity) {
    Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            currentBook->quantity = quantity;
            break;
        }
        currentBook = currentBook->next;
    }

    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}