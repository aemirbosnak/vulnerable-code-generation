//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

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
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    return head;
}

Member* insertMember(Member* head, char* name, int membership_id) {
    Member* newMember = (Member*)malloc(sizeof(Member));
    strcpy(newMember->name, name);
    newMember->membership_id = membership_id;
    newMember->next = NULL;

    if (head == NULL) {
        head = newMember;
    } else {
        Member* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newMember;
    }

    return head;
}

void displayBooks(Book* head) {
    Book* temp = head;
    while (temp) {
        printf("%s by %s, Quantity: %d\n", temp->title, temp->author, temp->quantity);
        temp = temp->next;
    }
}

void displayMembers(Member* head) {
    Member* temp = head;
    while (temp) {
        printf("%s, Membership ID: %d\n", temp->name, temp->membership_id);
        temp = temp->next;
    }
}

int main() {
    Book* bookHead = NULL;
    Member* memberHead = NULL;

    // Insert some books
    insertBook(bookHead, "The Lord of the Flies", "William Golding", 5);
    insertBook(bookHead, "The Great Gatsby", "F. Scott Fitzgerald", 3);
    insertBook(bookHead, "Pride and Prejudice", "Jane Austen", 2);

    // Insert some members
    insertMember(memberHead, "John Doe", 1);
    insertMember(memberHead, "Jane Doe", 2);
    insertMember(memberHead, "Peter Pan", 3);

    // Display books
    displayBooks(bookHead);

    // Display members
    displayMembers(memberHead);

    return 0;
}