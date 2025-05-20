//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 50

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

typedef struct Member {
    char name[50];
    char membership_type[50];
    struct Member* next;
} Member;

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        head->next = insertBook(head->next, newBook);
    }
    return head;
}

Member* insertMember(Member* head, Member* newMember) {
    if (head == NULL) {
        head = newMember;
    } else {
        head->next = insertMember(head->next, newMember);
    }
    return head;
}

void searchBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            printf("Book: %s, Author: %s, Quantity: %d\n", head->title, head->author, head->quantity);
        }
        head = head->next;
    }
}

void searchMember(Member* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s, Membership Type: %s\n", head->name, head->membership_type);
        }
        head = head->next;
    }
}

int main() {
    Book* headBook = NULL;
    Member* headMember = NULL;

    // Inserting books and members
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    newBook1->quantity = 5;
    insertBook(headBook, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "To Kill a Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    newBook2->quantity = 10;
    insertBook(headBook, newBook2);

    Member* newMember1 = malloc(sizeof(Member));
    strcpy(newMember1->name, "John Doe");
    strcpy(newMember1->membership_type, "Gold");
    insertMember(headMember, newMember1);

    Member* newMember2 = malloc(sizeof(Member));
    strcpy(newMember2->name, "Jane Doe");
    strcpy(newMember2->membership_type, "Silver");
    insertMember(headMember, newMember2);

    // Searching books and members
    searchBook(headBook, "The Lord of the Flies");
    searchMember(headMember, "John Doe");

    return 0;
}