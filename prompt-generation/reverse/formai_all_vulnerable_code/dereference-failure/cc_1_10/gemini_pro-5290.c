//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    float price;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, float price) {
    Book *book = (Book *)malloc(sizeof(Book));
    book->title = (char *)malloc(strlen(title) + 1);
    strcpy(book->title, title);
    book->author = (char *)malloc(strlen(author) + 1);
    strcpy(book->author, author);
    book->num_pages = num_pages;
    book->price = price;
    return book;
}

// Function to print the details of a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Price: $%.2f\n", book->price);
}

// Function to read a book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char title[256];
    char author[256];
    int num_pages;
    float price;

    fscanf(fp, "%s %s %d %f", title, author, &num_pages, &price);

    Book *book = create_book(title, author, num_pages, price);

    fclose(fp);

    return book;
}

// Function to write a book to a file
void write_book(char *filename, Book *book) {
    FILE *fp = fopen(filename, "w");
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
    Book *book = create_book("The Great Gatsby", "F. Scott Fitzgerald", 180, 12.99);

    // Print the details of the book
    print_book(book);

    // Write the book to a file
    write_book("great_gatsby.txt", book);

    // Read the book from the file
    Book *new_book = read_book("great_gatsby.txt");

    // Print the details of the new book
    print_book(new_book);

    // Free the memory allocated for the books
    free(book->title);
    free(book->author);
    free(book);
    free(new_book->title);
    free(new_book->author);
    free(new_book);

    return 0;
}