//FormAI DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int pages;
    double price;
} Book;

typedef struct {
    Book *books;
    int num_books;
} Library;

void read_book(Book *book) {
    char title[100], author[100];
    int pages;
    double price;

    printf("\nEnter book title: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0'; // remove newline character
    book->title = (char*) malloc(strlen(title) * sizeof(char));
    strcpy(book->title, title);

    printf("Enter book author: ");
    fgets(author, 100, stdin);
    author[strcspn(author, "\n")] = '\0'; // remove newline character
    book->author = (char*) malloc(strlen(author) * sizeof(char));
    strcpy(book->author, author);

    printf("Enter number of pages: ");
    scanf("%d", &pages);
    book->pages = pages;

    printf("Enter book price: ");
    scanf("%lf", &price);
    book->price = price;

    getchar(); // consume newline character from stdin buffer
}

void print_book(Book book) {
    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
    printf("Price: $%.2lf\n", book.price);
}

void print_library(Library library) {
    int i;
    for (i = 0; i < library.num_books; i++) {
        print_book(library.books[i]);
    }
}

int main() {
    int choice, i;
    Library library;

    printf("Welcome to the Ebook Reader!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a book to the library\n");
        printf("2. View books in the library\n");
        printf("3. Exit the program\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (library.num_books == 0) {
                    library.books = (Book*) malloc(sizeof(Book));
                }
                else {
                    library.books = (Book*) realloc(library.books, (library.num_books+1) * sizeof(Book));
                }
                read_book(&library.books[library.num_books]);
                library.num_books++;
                break;
            case 2:
                if (library.num_books == 0) {
                    printf("\nThe library is currently empty.\n");
                }
                else {
                    printf("\nThe library contains the following books:\n");
                    print_library(library);
                }
                break;
            case 3:
                printf("\nGoodbye!\n");
                for (i = 0; i < library.num_books; i++) {
                    free(library.books[i].title);
                    free(library.books[i].author);
                }
                free(library.books);
                exit(0);
            default:
                printf("\nInvalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}