//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
struct Book {
    char title[100];
    char author[100];
    int num_pages;
    float price;
};

// Function to create a new book
struct Book* create_book(char* title, char* author, int num_pages, float price) {
    struct Book* book = (struct Book*)malloc(sizeof(struct Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->num_pages = num_pages;
    book->price = price;
    return book;
}

// Function to print the details of a book
void print_book(struct Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Price: %.2f\n", book->price);
}

// Function to read a book from a file
struct Book* read_book(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char title[100];
    char author[100];
    int num_pages;
    float price;

    fscanf(fp, "%s %s %d %f", title, author, &num_pages, &price);

    struct Book* book = create_book(title, author, num_pages, price);

    fclose(fp);

    return book;
}

// Function to write a book to a file
void write_book(char* filename, struct Book* book) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%s %s %d %.2f", book->title, book->author, book->num_pages, book->price);

    fclose(fp);
}

// Main function
int main() {
    // Create a new book
    struct Book* book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 183, 12.99);

    // Print the details of the book
    print_book(book);

    // Write the book to a file
    write_book("book.txt", book);

    // Read the book from a file
    struct Book* book2 = read_book("book.txt");

    // Print the details of the book
    print_book(book2);

    // Free the memory allocated for the books
    free(book);
    free(book2);

    return 0;
}