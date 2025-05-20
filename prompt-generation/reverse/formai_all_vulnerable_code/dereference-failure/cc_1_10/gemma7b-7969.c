//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: creative
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

void searchBook(Book* head, char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            printf("Title: %s\n", temp->title);
            printf("Author: %s\n", temp->author);
            printf("Quantity: %d\n", temp->quantity);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;

    insertBook(head, "The Lord of the Flies", "William Golding", 5);
    insertBook(head, "The Great Gatsby", "F. Scott Fitzgerald", 10);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 7);

    searchBook(head, "The Lord of the Flies");

    return 0;
}