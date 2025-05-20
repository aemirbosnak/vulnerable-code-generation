//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOKS 100
#define MAX_BorrowERS 20

struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
};

struct Borrower {
    char name[50];
    struct Borrower* next;
};

void insertBook(struct Book** head, char* title, char* author, int quantity) {
    struct Book* newNode = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertBorrower(struct Borrower** head, char* name) {
    struct Borrower* newNode = (struct Borrower*)malloc(sizeof(struct Borrower));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void searchBook(struct Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            printf("Title: %s\n", head->title);
            printf("Author: %s\n", head->author);
            printf("Quantity: %d\n", head->quantity);
            break;
        }
        head = head->next;
    }
}

void searchBorrower(struct Borrower* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            break;
        }
        head = head->next;
    }
}

int main() {
    struct Book* bookHead = NULL;
    struct Borrower* borrowerHead = NULL;

    insertBook(&bookHead, "The Lord of the Flies", "William Golding", 10);
    insertBook(&bookHead, "The Great Gatsby", "F. Scott Fitzgerald", 12);
    insertBook(&bookHead, "To Kill a Mockingbird", "Harper Lee", 8);

    insertBorrower(&borrowerHead, "John Doe");
    insertBorrower(&borrowerHead, "Jane Doe");

    searchBook(bookHead, "The Lord of the Flies");
    searchBorrower(borrowerHead, "John Doe");

    return 0;
}