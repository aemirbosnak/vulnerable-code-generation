//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    char *text;
} Book;

// Function to create a new book
Book* create_book(char *title, char *author, int num_pages, char *text) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->text = strdup(text);
    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Function to print the details of a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text:\n%s\n", book->text);
}

// Function to read a book from a file
Book* read_book_from_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the title of the book
    char *title = NULL;
    size_t title_len = 0;
    getline(&title, &title_len, fp);

    // Read the author of the book
    char *author = NULL;
    size_t author_len = 0;
    getline(&author, &author_len, fp);

    // Read the number of pages in the book
    int num_pages;
    fscanf(fp, "%d", &num_pages);

    // Read the text of the book
    char *text = NULL;
    size_t text_len = 0;
    while (!feof(fp)) {
        char *line = NULL;
        size_t line_len = 0;
        getline(&line, &line_len, fp);
        text = realloc(text, text_len + line_len + 1);
        strcat(text, line);
    }

    fclose(fp);

    // Create a new book with the data from the file
    Book *book = create_book(title, author, num_pages, text);

    // Free the memory allocated for the title, author, and text
    free(title);
    free(author);
    free(text);

    return book;
}

// Function to write a book to a file
void write_book_to_file(Book *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the title of the book
    fprintf(fp, "%s\n", book->title);

    // Write the author of the book
    fprintf(fp, "%s\n", book->author);

    // Write the number of pages in the book
    fprintf(fp, "%d\n", book->num_pages);

    // Write the text of the book
    fprintf(fp, "%s\n", book->text);

    fclose(fp);
}

// Function to search for a string in the text of a book
int search_book_text(Book *book, char *query) {
    char *result = strstr(book->text, query);
    if (result == NULL) {
        return -1;
    } else {
        return result - book->text;
    }
}

// Function to replace a string in the text of a book
void replace_book_text(Book *book, char *old_text, char *new_text) {
    char *result = strstr(book->text, old_text);
    if (result != NULL) {
        int old_text_len = strlen(old_text);
        int new_text_len = strlen(new_text);
        int diff = new_text_len - old_text_len;

        // Reallocate the memory for the text
        book->text = realloc(book->text, strlen(book->text) + diff + 1);

        // Move the text after the old text to the right
        memmove(result + new_text_len, result + old_text_len, strlen(result + old_text_len) + 1);

        // Copy the new text into the text
        memcpy(result, new_text, new_text_len);
    }
}

// Function to test the ebook reader
int main() {
    // Create a new book
    Book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277, "In the rye.");

    // Print the details of the book
    print_book(book);

    // Read a book from a file
    Book *book2 = read_book_from_file("book.txt");

    // Print the details of the book
    print_book(book2);

    // Write the book to a file
    write_book_to_file(book, "book.txt");

    // Search for a string in the text of the book
    int result = search_book_text(book, "rye");
    if (result == -1) {
        printf("The string was not found.\n");
    } else {
        printf("The string was found at position %d.\n", result);
    }

    // Replace a string in the text of the book
    replace_book_text(book, "rye", "wheat");

    // Print the details of the book again
    print_book(book);

    // Free the memory allocated for the books
    free_book(book);
    free_book(book2);

    return 0;
}