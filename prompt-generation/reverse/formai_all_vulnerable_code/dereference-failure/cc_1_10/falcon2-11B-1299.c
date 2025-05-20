//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a book
typedef struct {
    char title[50];
    int pages;
    char author[50];
    char ISBN[13];
} Book;

// A structure to represent a library
typedef struct {
    Book* books;
    int size;
    int capacity;
} Library;

// Function to initialize a library
void initialize_library(Library* lib) {
    lib->size = 0;
    lib->capacity = 10;
    lib->books = malloc(lib->capacity * sizeof(Book));
}

// Function to add a book to the library
void add_book(Library* lib, Book book) {
    if (lib->size >= lib->capacity) {
        printf("Library is full, cannot add more books\n");
        return;
    }
    lib->books[lib->size++] = book;
}

// Function to search for a book by ISBN
int search_by_ISBN(Library* lib, char* ISBN) {
    for (int i = 0; i < lib->size; i++) {
        if (strcmp(lib->books[i].ISBN, ISBN) == 0) {
            printf("Book found with ISBN %s\n", lib->books[i].ISBN);
            return 1;
        }
    }
    return 0;
}

// Function to display all books in the library
void display_books(Library* lib) {
    for (int i = 0; i < lib->size; i++) {
        printf("Title: %s\n", lib->books[i].title);
        printf("Pages: %d\n", lib->books[i].pages);
        printf("Author: %s\n", lib->books[i].author);
        printf("ISBN: %s\n", lib->books[i].ISBN);
        printf("\n");
    }
}

// Function to delete a book from the library by ISBN
void delete_book(Library* lib, char* ISBN) {
    for (int i = 0; i < lib->size; i++) {
        if (strcmp(lib->books[i].ISBN, ISBN) == 0) {
            for (int j = i; j < lib->size - 1; j++) {
                lib->books[j] = lib->books[j + 1];
            }
            lib->size--;
            break;
        }
    }
}

int main() {
    Library lib;
    initialize_library(&lib);

    Book book1 = {"The Great Gatsby", 200, "F. Scott Fitzgerald", "9780743273565"};
    Book book2 = {"To Kill a Mockingbird", 300, "Harper Lee", "9780061120084"};

    add_book(&lib, book1);
    add_book(&lib, book2);

    printf("Displaying all books in the library:\n");
    display_books(&lib);

    printf("Searching for book by ISBN '9780061120084':\n");
    if (search_by_ISBN(&lib, "9780061120084")) {
        printf("Book found\n");
    } else {
        printf("Book not found\n");
    }

    printf("Deleting book with ISBN '9780061120084':\n");
    delete_book(&lib, "9780061120084");

    printf("Displaying all books in the library:\n");
    display_books(&lib);

    return 0;
}