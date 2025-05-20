//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BORROWERS 50

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

typedef struct Borrower {
    char name[50];
    struct Borrower* next;
    Book* borrowedBooks;
} Borrower;

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newNode = (Book*)malloc(sizeof(Book));
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Book* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

Borrower* insertBorrower(Borrower* head, char* name) {
    Borrower* newNode = (Borrower*)malloc(sizeof(Borrower));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->borrowedBooks = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Borrower* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void borrowBook(Book* book, Borrower* borrower) {
    Book* tempBook = book;
    Borrower* tempBorrower = borrower;

    while (tempBook) {
        if (strcmp(book->title, tempBook->title) == 0) {
            tempBook->quantity--;
            Book* newBook = insertBook(tempBorrower->borrowedBooks, book->title, book->author, book->quantity);
            tempBorrower->borrowedBooks = newBook;
            return;
        }
        tempBook = tempBook->next;
    }

    printf("Book not found.\n");
}

void returnBook(Book* book, Borrower* borrower) {
    Book* tempBook = book;
    Borrower* tempBorrower = borrower;

    while (tempBook) {
        if (strcmp(book->title, tempBook->title) == 0) {
            tempBook->quantity++;
            Book* tempBookToRemove = NULL;
            Book* tempBookPtr = tempBorrower->borrowedBooks;

            while (tempBookPtr) {
                if (strcmp(book->title, tempBookPtr->title) == 0) {
                    tempBookToRemove = tempBookPtr;
                    tempBookPtr = tempBookPtr->next;
                    free(tempBookToRemove);
                }
            }

            returnBook(book, borrower);
            return;
        }
        tempBook = tempBook->next;
    }

    printf("Book not found.\n");
}

int main() {
    Book* bookHead = NULL;
    Borrower* borrowerHead = NULL;

    insertBook(bookHead, "The Lord of the Flies", "William Golding", 5);
    insertBook(bookHead, "The Great Gatsby", "F. Scott Fitzgerald", 10);
    insertBook(bookHead, "The Catcher in the Rye", "J.D. Salinger", 7);

    insertBorrower(borrowerHead, "John Doe");
    insertBorrower(borrowerHead, "Jane Doe");

    borrowBook(bookHead, borrowerHead->next);
    returnBook(bookHead, borrowerHead);

    return 0;
}