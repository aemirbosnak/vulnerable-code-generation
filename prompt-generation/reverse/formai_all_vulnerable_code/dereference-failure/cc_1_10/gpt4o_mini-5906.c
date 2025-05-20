//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a simple Book
typedef struct {
    char *title;
    char *author;
    int year;
} Book;

// Function to create a new Book
Book* createBook(const char *title, const char *author, int year) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) {
        fprintf(stderr, "Memory allocation failed for new book.\n");
        exit(EXIT_FAILURE);
    }
    
    newBook->title = (char *)malloc(strlen(title) + 1);
    if (newBook->title == NULL) {
        free(newBook);
        fprintf(stderr, "Memory allocation failed for book title.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newBook->title, title);
    
    newBook->author = (char *)malloc(strlen(author) + 1);
    if (newBook->author == NULL) {
        free(newBook->title);
        free(newBook);
        fprintf(stderr, "Memory allocation failed for book author.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newBook->author, author);
    
    newBook->year = year;
    
    return newBook;
}

// Function to display book information
void displayBook(const Book *book) {
    if (book == NULL) {
        fprintf(stderr, "No book to display.\n");
        return;
    }

    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Year: %d\n\n", book->year);
}

// Function to free allocated memory for a book
void freeBook(Book *book) {
    if (book != NULL) {
        free(book->title);
        free(book->author);
        free(book);
    }
}

// Function to create a dynamic array of Books
Book** createBookArray(int size) {
    Book **books = (Book **)malloc(size * sizeof(Book *));
    if (books == NULL) {
        fprintf(stderr, "Memory allocation failed for book array.\n");
        exit(EXIT_FAILURE);
    }
    return books;
}

// Function to add a new book to the array
void addBook(Book **books, int index, const char *title, const char *author, int year) {
    books[index] = createBook(title, author, year);
}

// Function to display all books in the array
void displayBooks(Book **books, int size) {
    for (int i = 0; i < size; i++) {
        displayBook(books[i]);
    }
}

// Function to free the book array
void freeBookArray(Book **books, int size) {
    for (int i = 0; i < size; i++) {
        freeBook(books[i]);
    }
    free(books);
}

// Entry point of the program
int main() {
    int numberOfBooks = 3;
    Book **myBooks = createBookArray(numberOfBooks);
    
    // Add some books
    addBook(myBooks, 0, "The Great Gatsby", "F. Scott Fitzgerald", 1925);
    addBook(myBooks, 1, "1984", "George Orwell", 1949);
    addBook(myBooks, 2, "To Kill a Mockingbird", "Harper Lee", 1960);
    
    // Display all books
    printf("Displaying the Books:\n");
    displayBooks(myBooks, numberOfBooks);
    
    // Free the allocated memory
    freeBookArray(myBooks, numberOfBooks);
    
    return 0;
}