//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure for a book
struct book {
    char title[50];
    char author[50];
    int published_year;
};

// Define the structure for a library
struct library {
    int num_books;
    struct book books[50];
};

// Function to create a new library
struct library *create_library(void) {
    struct library *lib = malloc(sizeof(struct library));
    lib->num_books = 0;
    return lib;
}

// Function to add a book to a library
void add_book(struct library *lib, char title[50], char author[50], int published_year) {
    struct book *new_book = malloc(sizeof(struct book));
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->published_year = published_year;
    lib->books[lib->num_books++] = *new_book;
}

// Function to search for a book in a library
struct book *search_book(struct library *lib, char title[50]) {
    int i;
    for (i = 0; i < lib->num_books; i++) {
        if (strcmp(lib->books[i].title, title) == 0) {
            return &lib->books[i];
        }
    }
    return NULL;
}

// Function to display the contents of a library
void display_library(struct library *lib) {
    int i;
    for (i = 0; i < lib->num_books; i++) {
        printf("%d. %s by %s published in %d\n", i + 1, lib->books[i].title, lib->books[i].author, lib->books[i].published_year);
    }
}

int main(void) {
    struct library *lib = create_library();

    // Add some books to the library
    add_book(lib, "The Great Gatsby", "F. Scott Fitzgerald", 1925);
    add_book(lib, "To Kill a Mockingbird", "Harper Lee", 1960);
    add_book(lib, "The Catcher in the Rye", "J.D. Salinger", 1951);

    // Search for a book in the library
    struct book *found_book = search_book(lib, "The Catcher in the Rye");
    if (found_book != NULL) {
        printf("Found %s by %s published in %d\n", found_book->title, found_book->author, found_book->published_year);
    } else {
        printf("Not found\n");
    }

    // Display the contents of the library
    display_library(lib);

    // Free the memory allocated for the library
    free(lib);

    return 0;
}