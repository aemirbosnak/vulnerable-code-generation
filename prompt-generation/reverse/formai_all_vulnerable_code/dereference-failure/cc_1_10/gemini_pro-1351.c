//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    char *text;
} Book;

// Reader structure
typedef struct Reader {
    Book *current_book;
    int current_page;
} Reader;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *text) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->text = strdup(text);
    return book;
}

// Function to create a new reader
Reader *create_reader() {
    Reader *reader = malloc(sizeof(Reader));
    reader->current_book = NULL;
    reader->current_page = 0;
    return reader;
}

// Function to load a book into the reader
void load_book(Reader *reader, Book *book) {
    reader->current_book = book;
    reader->current_page = 0;
}

// Function to turn a page in the book
void turn_page(Reader *reader, int direction) {
    if (direction == 1 && reader->current_page < reader->current_book->num_pages - 1) {
        reader->current_page++;
    } else if (direction == -1 && reader->current_page > 0) {
        reader->current_page--;
    }
}

// Function to get the current page of the book
char *get_current_page(Reader *reader) {
    return reader->current_book->text + (reader->current_page * 1000);
}

// Function to print the current page of the book
void print_current_page(Reader *reader) {
    printf("%s\n", get_current_page(reader));
}

// Main function
int main() {
    // Create a new book
    Book *book = create_book("The Hobbit", "J.R.R. Tolkien", 310, "In a hole in the ground there lived a hobbit.");

    // Create a new reader
    Reader *reader = create_reader();

    // Load the book into the reader
    load_book(reader, book);

    // Turn a page
    turn_page(reader, 1);

    // Print the current page
    print_current_page(reader);

    // Free the memory allocated for the book and the reader
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
    free(reader);

    return 0;
}