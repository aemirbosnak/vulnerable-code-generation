//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct Book {
    char title[100];
    char author[100];
    int pages;
    int year;
} Book;

// Function to create a new book
Book* createBook(char *title, char *author, int pages, int year) {
    Book *book = (Book*)malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pages = pages;
    book->year = year;
    return book;
}

// Function to print a book
void printBook(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Year: %d\n", book->year);
    printf("\n");
}

// Function to read a book from a file
Book* readBookFromFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    char line[256];
    Book *book = (Book*)malloc(sizeof(Book));

    // Read the title
    fgets(line, sizeof(line), file);
    strcpy(book->title, line);

    // Read the author
    fgets(line, sizeof(line), file);
    strcpy(book->author, line);

    // Read the pages
    fgets(line, sizeof(line), file);
    book->pages = atoi(line);

    // Read the year
    fgets(line, sizeof(line), file);
    book->year = atoi(line);

    fclose(file);
    return book;
}

// Function to write a book to a file
void writeBookToFile(Book *book, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    fprintf(file, "%s\n", book->title);
    fprintf(file, "%s\n", book->author);
    fprintf(file, "%d\n", book->pages);
    fprintf(file, "%d\n", book->year);

    fclose(file);
}

// Function to create a new library
typedef struct Library {
    Book **books;
    int numBooks;
} Library;

Library* createLibrary() {
    Library *library = (Library*)malloc(sizeof(Library));
    library->books = (Book**)malloc(sizeof(Book*) * 100);
    library->numBooks = 0;
    return library;
}

// Function to add a book to a library
void addBookToLibrary(Library *library, Book *book) {
    library->books[library->numBooks] = book;
    library->numBooks++;
}

// Function to print a library
void printLibrary(Library *library) {
    for (int i = 0; i < library->numBooks; i++) {
        printBook(library->books[i]);
    }
}

// Function to read a library from a file
Library* readLibraryFromFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    char line[256];
    Library *library = createLibrary();

    // Read the number of books
    fgets(line, sizeof(line), file);
    int numBooks = atoi(line);

    // Read each book
    for (int i = 0; i < numBooks; i++) {
        Book *book = readBookFromFile(filename);
        addBookToLibrary(library, book);
    }

    fclose(file);
    return library;
}

// Function to write a library to a file
void writeLibraryToFile(Library *library, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Write the number of books
    fprintf(file, "%d\n", library->numBooks);

    // Write each book
    for (int i = 0; i < library->numBooks; i++) {
        writeBookToFile(library->books[i], filename);
    }

    fclose(file);
}

// Main function
int main() {
    // Create a new library
    Library *library = createLibrary();

    // Add some books to the library
    Book *book1 = createBook("The Catcher in the Rye", "J.D. Salinger", 277, 1951);
    Book *book2 = createBook("The Great Gatsby", "F. Scott Fitzgerald", 180, 1925);
    Book *book3 = createBook("1984", "George Orwell", 328, 1949);
    addBookToLibrary(library, book1);
    addBookToLibrary(library, book2);
    addBookToLibrary(library, book3);

    // Print the library
    printLibrary(library);

    // Write the library to a file
    writeLibraryToFile(library, "library.txt");

    // Read the library from a file
    Library *library2 = readLibraryFromFile("library.txt");

    // Print the library
    printLibrary(library2);

    return 0;
}