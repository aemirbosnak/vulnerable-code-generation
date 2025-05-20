//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char title[100];
    char author[100];
    int num_pages;
    char *text;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *text) {
    Book *book = malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->num_pages = num_pages;
    book->text = malloc(strlen(text) + 1);
    strcpy(book->text, text);
    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->text);
    free(book);
}

// Function to print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text:\n%s\n", book->text);
}

// Function to read a book from a file
Book *read_book_from_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char title[100], author[100];
    int num_pages;
    char *text;

    fscanf(file, "%s %s %d", title, author, &num_pages);

    // Allocate memory for the text
    text = malloc(100000);

    // Read the text from the file
    while (!feof(file)) {
        fgets(text, 100000, file);
    }

    // Close the file
    fclose(file);

    // Create a new book
    Book *book = create_book(title, author, num_pages, text);

    // Return the book
    return book;
}

// Function to write a book to a file
void write_book_to_file(Book *book, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    fprintf(file, "%s %s %d\n", book->title, book->author, book->num_pages);
    fprintf(file, "%s", book->text);

    // Close the file
    fclose(file);
}

// Function to search for a string in a book
int search_book(Book *book, char *string) {
    char *result = strstr(book->text, string);
    if (result == NULL) {
        return -1;
    } else {
        return result - book->text;
    }
}

// Function to replace a string in a book
void replace_string(Book *book, char *old_string, char *new_string) {
    char *result = strstr(book->text, old_string);
    while (result != NULL) {
        int old_string_length = strlen(old_string);
        int new_string_length = strlen(new_string);
        memmove(result + new_string_length, result + old_string_length, strlen(result + old_string_length) + 1);
        memcpy(result, new_string, new_string_length);
        result = strstr(result + new_string_length, old_string);
    }
}

int main() {
    // Create a new book
    Book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277, "In the beginning of the story Holden Caulfield leaves Pencey Prep, his prep school, because he's flunking four of his five subjects and doesn't feel like going to the Christmas pageant given by his school.");

    // Print the book
    print_book(book);

    // Read a book from a file
    Book *book2 = read_book_from_file("book.txt");

    // Print the book
    print_book(book2);

    // Write the book to a file
    write_book_to_file(book, "book.txt");

    // Search for a string in the book
    int result = search_book(book, "Holden Caulfield");
    if (result == -1) {
        printf("String not found.\n");
    } else {
        printf("String found at index %d.\n", result);
    }

    // Replace a string in the book
    replace_string(book, "Holden Caulfield", "Harry Potter");

    // Print the book
    print_book(book);

    // Free the memory allocated for the books
    free_book(book);
    free_book(book2);

    return 0;
}