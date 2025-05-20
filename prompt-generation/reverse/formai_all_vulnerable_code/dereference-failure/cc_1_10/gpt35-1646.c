//FormAI DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 5

typedef struct {
    char *title;
    char *author;
    int pages;
    float price;
} Book;

typedef struct {
    Book *books[MAX_BOOKS];
    int num_books;
} Bookshelf;

// Function prototypes
void add_book(Bookshelf *shelf, Book *book);
void display_books(Bookshelf *shelf);

int main() {
    Book books[MAX_BOOKS] = {{"Agile Development", "Robert C. Martin", 384, 42.99},
                             {"Clean Code", "Robert C. Martin", 464, 35.99},
                             {"Code Complete", "Steve McConnell", 960, 39.99},
                             {"The Pragmatic Programmer", "Andrew Hunt and David Thomas", 352, 23.99},
                             {"Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides", 395, 44.99}};
    
    Bookshelf shelf = {0};
    int i;
    for (i = 0; i < MAX_BOOKS; i++) {
        Book *book = &books[i];
        add_book(&shelf, book);
    }

    printf("Welcome to the C Ebook Reader!\n\n");

    while (1) {
        int selection;
        printf("Please select an option:\n");
        printf("1. View all books\n");
        printf("2. Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);

        if (selection == 1) {
            display_books(&shelf);
        } else if (selection == 2) {
            printf("Thank you for using the C Ebook Reader!\n");
            exit(0);
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    }

    return 0;
}

void add_book(Bookshelf *shelf, Book *book) {
    if (shelf->num_books == MAX_BOOKS) {
        printf("Bookshelf is full\n");
        return;
    }
    
    Book *book_copy = malloc(sizeof(Book));
    book_copy->title = book->title;
    book_copy->author = book->author;
    book_copy->pages = book->pages;
    book_copy->price = book->price;
    
    shelf->books[shelf->num_books++] = book_copy;
}

void display_books(Bookshelf *shelf) {
    int i;
    for (i = 0; i < shelf->num_books; i++) {
        Book *book = shelf->books[i];
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Pages: %d\n", book->pages);
        printf("Price: $%.2f\n\n", book->price);
    }
}