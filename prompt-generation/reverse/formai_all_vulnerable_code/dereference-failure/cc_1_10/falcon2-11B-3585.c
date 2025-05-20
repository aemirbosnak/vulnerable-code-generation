//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char title[100];
    char author[100];
    int pages;
} Book;

void readBook(Book *book) {
    printf("Enter book title: ");
    scanf("%s", book->title);

    printf("Enter book author: ");
    scanf("%s", book->author);

    printf("Enter number of pages: ");
    scanf("%d", &book->pages);
}

void displayBook(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
}

void addBook(Book *book, int count) {
    book[count].title[0] = '\0';
    book[count].author[0] = '\0';
    book[count].pages = 0;
}

int main() {
    Book books[100];
    int i;

    printf("Welcome to the C Ebook Reader!\n");

    for (i = 0; i < 100; i++) {
        addBook(&books[i], i);
    }

    while (1) {
        int choice;
        char input[100];

        printf("1. Add a new book\n");
        printf("2. Display all books\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                scanf("%s", input);

                printf("Enter book author: ");
                scanf("%s", input);

                printf("Enter number of pages: ");
                scanf("%d", &books[i].pages);

                addBook(&books[i], i);
                break;

            case 2:
                for (i = 0; i < 100; i++) {
                    displayBook(books[i]);
                }
                break;

            case 3:
                printf("Thank you for using the C Ebook Reader!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}