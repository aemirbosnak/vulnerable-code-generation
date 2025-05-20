//GEMINI-pro DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom data structure to represent a book
typedef struct Book {
    char title[100];
    char author[100];
    int year;
} Book;

// A custom function to compare two books by their titles
int compare_books(const void *a, const void *b) {
    const Book *book1 = (const Book *)a;
    const Book *book2 = (const Book *)b;

    return strcmp(book1->title, book2->title);
}

// A custom function to print a book
void print_book(const Book *book) {
    printf("%s by %s (%d)\n", book->title, book->author, book->year);
}

int main() {
    // Open the file containing the book data
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the number of books from the file
    int num_books;
    fscanf(file, "%d", &num_books);

    // Allocate memory for the array of books
    Book *books = malloc(sizeof(Book) * num_books);
    if (books == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Read the book data from the file
    for (int i = 0; i < num_books; i++) {
        fscanf(file, "%s %s %d", books[i].title, books[i].author, &books[i].year);
    }

    // Close the file
    fclose(file);

    // Sort the books by their titles
    qsort(books, num_books, sizeof(Book), compare_books);

    // Print the books
    for (int i = 0; i < num_books; i++) {
        print_book(&books[i]);
    }

    // Free the memory allocated for the array of books
    free(books);

    return 0;
}