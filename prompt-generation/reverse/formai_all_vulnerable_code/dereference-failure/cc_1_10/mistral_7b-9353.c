//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int bookId;
    char title[50];
    char author[50];
    char status;
    struct book *next;
} book;

book *head = NULL;

void addBook(int id, char title[], char author[]) {
    book *newBook = (book *)malloc(sizeof(book));
    newBook->bookId = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->status = 'A';
    newBook->next = head;
    head = newBook;
}

void displayLibrary() {
    book *temp = head;
    printf("\nLibrary Details:\n");
    while (temp != NULL) {
        printf("\nBook Id: %d\nTitle: %s\nAuthor: %s\nStatus: %c", temp->bookId, temp->title, temp->author, temp->status);
        temp = temp->next;
    }
}

void issueBook(int bookId) {
    book *temp = head, *prev = NULL;
    while (temp != NULL) {
        if (temp->bookId == bookId) {
            if (temp->status == 'A') {
                temp->status = 'B';
                printf("\nBook with id %d has been issued successfully.\n", bookId);
            } else {
                printf("\nSorry! This book is already issued.\n");
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\nBook not found in the library.\n");
}

int main() {
    int choice;
    char title[50], author[50];
    int bookId;

    addBook(101, "The Alchemist", "Paulo Coelho");
    addBook(102, "The Da Vinci Code", "Dan Brown");
    addBook(103, "The Great Gatsby", "F. Scott Fitzgerald");

    do {
        printf("\n1. Display Library\n2. Issue Book\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayLibrary();
                break;
            case 2:
                printf("Enter the Book Id to issue: ");
                scanf("%d", &bookId);
                issueBook(bookId);
                break;
            case 3:
                printf("Exiting the Library Management System...\n");
                break;
            default:
                printf("Invalid Choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}