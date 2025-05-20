//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int membership_id;
    struct Member* next;
} Member;

Book* insertBook(Book* head, Book* newBook);
Member* insertMember(Member* head, Member* newMember);
void displayBooks(Book* head);
void displayMembers(Member* head);

int main() {
    Book* headBook = NULL;
    Member* headMember = NULL;

    // Insert some books
    Book* newBook1 = malloc(sizeof(Book));
    strcpy(newBook1->title, "The Lord of the Flies");
    strcpy(newBook1->author, "William Golding");
    newBook1->quantity = 10;
    insertBook(headBook, newBook1);

    Book* newBook2 = malloc(sizeof(Book));
    strcpy(newBook2->title, "To Kill a Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    newBook2->quantity = 5;
    insertBook(headBook, newBook2);

    // Insert some members
    Member* newMember1 = malloc(sizeof(Member));
    strcpy(newMember1->name, "John Doe");
    newMember1->membership_id = 1;
    insertMember(headMember, newMember1);

    Member* newMember2 = malloc(sizeof(Member));
    strcpy(newMember2->name, "Jane Doe");
    newMember2->membership_id = 2;
    insertMember(headMember, newMember2);

    // Display books
    displayBooks(headBook);

    // Display members
    displayMembers(headMember);

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

Member* insertMember(Member* head, Member* newMember) {
    if (head == NULL) {
        head = newMember;
    } else {
        newMember->next = head;
        head = newMember;
    }
    return head;
}

void displayBooks(Book* head) {
    while (head) {
        printf("%s by %s, quantity: %d\n", head->title, head->author, head->quantity);
        head = head->next;
    }
}

void displayMembers(Member* head) {
    while (head) {
        printf("%s, membership id: %d\n", head->name, head->membership_id);
        head = head->next;
    }
}