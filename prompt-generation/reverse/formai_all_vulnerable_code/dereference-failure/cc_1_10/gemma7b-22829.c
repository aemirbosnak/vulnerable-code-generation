//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct book {
    char title[50];
    char author[50];
    int quantity;
    struct book* next;
};

struct book* insertBook(struct book* head, char* title, char* author, int quantity) {
    struct book* newBook = (struct book*)malloc(sizeof(struct book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        struct book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    return head;
}

void displayBooks(struct book* head) {
    struct book* temp = head;
    while (temp) {
        printf("%s by %s, quantity: %d\n", temp->title, temp->author, temp->quantity);
        temp = temp->next;
    }
}

int main() {
    struct book* head = NULL;

    insertBook(head, "The Book of Joy", "Haruki Murakami", 5);
    insertBook(head, "The Lord of the Flies", "William Golding", 10);
    insertBook(head, "To Kill a Mockingbird", "Harper Lee", 7);

    displayBooks(head);

    return 0;
}