//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: visionary
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
    char address[100];
    int membership_id;
    struct Member* next;
} Member;

Book* insertBook(Book* head, char* title, char* author, int quantity);
Member* insertMember(Member* head, char* name, char* address, int membership_id);
void displayBooks(Book* head);
void displayMembers(Member* head);

int main() {
    Book* bookHead = NULL;
    Member* memberHead = NULL;

    // Insert some books
    insertBook(bookHead, "The Lord of the Flies", "William Golding", 5);
    insertBook(bookHead, "To Kill a Mockingbird", "Harper Lee", 8);
    insertBook(bookHead, "The Great Gatsby", "F. Scott Fitzgerald", 2);

    // Insert some members
    insertMember(memberHead, "John Doe", "123 Main St.", 1);
    insertMember(memberHead, "Jane Doe", "456 Oak Ave.", 2);
    insertMember(memberHead, "Peter Pan", "Neverland", 3);

    // Display the books
    displayBooks(bookHead);

    // Display the members
    displayMembers(memberHead);

    return 0;
}

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));

    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        head->next = newBook;
    }

    return head;
}

Member* insertMember(Member* head, char* name, char* address, int membership_id) {
    Member* newMember = (Member*)malloc(sizeof(Member));

    strcpy(newMember->name, name);
    strcpy(newMember->address, address);
    newMember->membership_id = membership_id;
    newMember->next = NULL;

    if (head == NULL) {
        head = newMember;
    } else {
        head->next = newMember;
    }

    return head;
}

void displayBooks(Book* head) {
    while (head) {
        printf("Title: %s\n", head->title);
        printf("Author: %s\n", head->author);
        printf("Quantity: %d\n", head->quantity);
        printf("\n");
        head = head->next;
    }
}

void displayMembers(Member* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Address: %s\n", head->address);
        printf("Membership ID: %d\n", head->membership_id);
        printf("\n");
        head = head->next;
    }
}