//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold book information
typedef struct {
    char title[100];
    char author[100];
    int year;
    char *content; // Dynamic content
} Book;

// Dynamic array to hold multiple books
typedef struct {
    Book *books;
    int count;
} Library;

// Function prototypes
Library* create_library();
void add_book(Library *lib, const char *title, const char *author, int year, const char *content);
void display_book(const Book *book);
void read_book(const Book *book);
void free_library(Library *lib);
char* read_file(const char *filename);

int main() {
    Library *myLibrary = create_library();
    
    // Adding books to the library
    add_book(myLibrary, "1984", "George Orwell", 1949, read_file("1984.txt"));
    add_book(myLibrary, "The Great Gatsby", "F. Scott Fitzgerald", 1925, read_file("gatsby.txt"));
    add_book(myLibrary, "Moby Dick", "Herman Melville", 1851, read_file("mobydick.txt"));
    
    // Let's display the books in the library
    for (int i = 0; i < myLibrary->count; i++) {
        printf("\nBook %d:\n", i + 1);
        display_book(&myLibrary->books[i]);
    }
    
    // Read a specific book
    printf("\nReading '1984':\n");
    read_book(&myLibrary->books[0]);

    // Free the library
    free_library(myLibrary);
    
    return 0;
}

// Function to create a library
Library* create_library() {
    Library *lib = (Library*)malloc(sizeof(Library));
    lib->count = 0;
    lib->books = NULL;
    return lib;
}

// Function to add a book to the library
void add_book(Library *lib, const char *title, const char *author, int year, const char *content) {
    lib->books = (Book*)realloc(lib->books, sizeof(Book) * (lib->count + 1));
    Book *newBook = &lib->books[lib->count];
    
    strncpy(newBook->title, title, sizeof(newBook->title));
    strncpy(newBook->author, author, sizeof(newBook->author));
    newBook->year = year;
    newBook->content = strdup(content); // Duplicate the content
    
    lib->count++;
}

// Function to display book information
void display_book(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Year: %d\n", book->year);
}

// Function to read the book content
void read_book(const Book *book) {
    if (book->content) {
        printf("%s\n", book->content);
    } else {
        printf("No content available.\n");
    }
}

// Function to free the library and its contents
void free_library(Library *lib) {
    for (int i = 0; i < lib->count; i++) {
        free(lib->books[i].content); // Freeing individual book contents
    }
    free(lib->books); // Freeing the array of books
    free(lib); // Freeing the library structure
}

// Function to read file content into a string
char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char*)malloc(length + 1);
    fread(buffer, 1, length, file);
    buffer[length] = '\0'; // Null-terminate the string

    fclose(file);
    return buffer;
}