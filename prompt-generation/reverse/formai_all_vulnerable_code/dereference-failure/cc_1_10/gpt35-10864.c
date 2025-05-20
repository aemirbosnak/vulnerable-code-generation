//FormAI DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[50];
    char author[50];
    int year_published;
} Book;

typedef struct {
    int num_books;
    Book* books;
} Library;

void display_book(Book b) {
    printf("%s by %s, published in %d\n", b.title, b.author, b.year_published);
}

void display_library(Library lib) {
    printf("Num Books: %d\n", lib.num_books);
    for(int i = 0; i < lib.num_books; i++) {
        display_book(lib.books[i]);
    }
}

void read_book(Book b) {
    printf("Opening %s...\n", b.title);
    // Code to read book goes here
    printf("Closing %s...\n", b.title);
}

int main() {
    // Create some example books
    Book b1 = {"The Catcher in the Rye", "J.D. Salinger", 1951};
    Book b2 = {"To Kill a Mockingbird", "Harper Lee", 1960};
    Book b3 = {"1984", "George Orwell", 1949};
    
    // Add books to library
    Library lib1;
    lib1.num_books = 2;
    lib1.books = malloc(2 * sizeof(Book));
    lib1.books[0] = b1;
    lib1.books[1] = b2;
    
    Library lib2;
    lib2.num_books = 1;
    lib2.books = malloc(sizeof(Book));
    lib2.books[0] = b3;
    
    // Display libraries
    printf("Library 1:\n");
    display_library(lib1);
    
    printf("Library 2:\n");
    display_library(lib2);
    
    // Let user choose book to read
    int choice;
    printf("Which book would you like to read? (Enter corresponding number)\n");
    printf("1. The Catcher in the Rye\n2. To Kill a Mockingbird\n3. 1984\n");
    scanf("%d", &choice);
    
    // Read chosen book
    printf("You have chosen to read ");
    switch(choice) {
        case 1:
            display_book(b1);
            read_book(b1);
            break;
        case 2:
            display_book(b2);
            read_book(b2);
            break;
        case 3:
            display_book(b3);
            read_book(b3);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    
    // Free library book memory
    free(lib1.books);
    free(lib2.books);
    
    return 0;
}