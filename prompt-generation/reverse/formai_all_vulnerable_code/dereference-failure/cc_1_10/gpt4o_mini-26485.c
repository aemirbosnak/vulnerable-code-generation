//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about books
typedef struct {
    char title[50];
    char author[50];
    int year;
} Book;

// Function to create a new book
Book* create_book(const char* title, const char* author, int year) {
    Book* new_book = (Book*)malloc(sizeof(Book));
    if (!new_book) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(new_book->title, title, sizeof(new_book->title) - 1);
    new_book->title[sizeof(new_book->title) - 1] = '\0'; // ensure null termination
    strncpy(new_book->author, author, sizeof(new_book->author) - 1);
    new_book->author[sizeof(new_book->author) - 1] = '\0'; // ensure null termination
    new_book->year = year;
    return new_book;
}

// Function to display book information
void display_book(const Book* book) {
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Year: %d\n", book->year);
    } else {
        printf("No book information available.\n");
    }
}

// Function to free the allocated memory for the book
void free_book(Book* book) {
    free(book);
}

// Function to create an array of books
Book** create_book_array(int count) {
    Book** books = (Book**)malloc(count * sizeof(Book*));
    if (!books) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return books;
}

// Function to free the array of books
void free_book_array(Book** books, int count) {
    for (int i = 0; i < count; i++) {
        free_book(books[i]);
    }
    free(books);
}

// Function to add a book to the book array
void add_book(Book** books, int index, const char* title, const char* author, int year) {
    books[index] = create_book(title, author, year);
}

int main() {
    int number_of_books = 5;
    Book** book_collection = create_book_array(number_of_books);
    
    // Adding books to the collection
    add_book(book_collection, 0, "1984", "George Orwell", 1949);
    add_book(book_collection, 1, "To Kill a Mockingbird", "Harper Lee", 1960);
    add_book(book_collection, 2, "The Great Gatsby", "F. Scott Fitzgerald", 1925);
    add_book(book_collection, 3, "Moby Dick", "Herman Melville", 1851);
    add_book(book_collection, 4, "War and Peace", "Leo Tolstoy", 1869);
    
    // Display all books in the collection
    printf("Book Collection:\n");
    for (int i = 0; i < number_of_books; i++) {
        printf("\nBook %d:\n", i + 1);
        display_book(book_collection[i]);
    }

    // Cleaning up allocated memory
    free_book_array(book_collection, number_of_books);
    
    return 0;
}