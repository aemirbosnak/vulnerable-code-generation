//FormAI DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    int year;
    double price;
    char id[10];
} Book;

typedef struct {
    Book *books;
    int num_books;
} Library;

void print_book(Book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Year: %d\n", b.year);
    printf("Price: %.2lf\n", b.price);
    printf("ID: %s\n", b.id);
}

Library *create_library() {
    Library *lib = (Library *)malloc(sizeof(Library));
    lib->books = (Book *)malloc(sizeof(Book) * 10);
    lib->num_books = 0;
    return lib;
}

void add_book(Library *lib, Book b) {
    lib->books[lib->num_books] = b;
    lib->num_books++;
}

void print_library(Library *lib) {
    printf("Library:\n");
    for(int i = 0; i < lib->num_books; i++) {
        print_book(lib->books[i]);
        printf("\n");
    }
}

void save_library(Library *lib, char *filename) {
    FILE *f = fopen(filename, "wb");
    for(int i = 0; i < lib->num_books; i++) {
        fwrite(&(lib->books[i]), sizeof(Book), 1, f);
    }
    fclose(f);
}

Library *load_library(char *filename) {
    FILE *f = fopen(filename, "rb");
    Library *lib = create_library();
    Book b;
    while(fread(&b, sizeof(Book), 1, f)) {
        add_book(lib, b);
    }
    fclose(f);
    return lib;
}

void main() {
    printf("Welcome to the futuristic C Ebook Reader Program!\n");
    Library *lib = create_library();
    Book b1 = {"The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979, 9.99, "0001"};
    Book b2 = {"1984", "George Orwell", 1949, 8.99, "0002"};
    Book b3 = {"Dune", "Frank Herbert", 1965, 7.99, "0003"};
    add_book(lib, b1);
    add_book(lib, b2);
    add_book(lib, b3);
    print_library(lib);
    save_library(lib, "library.bin");
    Library *loaded_lib = load_library("library.bin");
    print_library(loaded_lib);
}