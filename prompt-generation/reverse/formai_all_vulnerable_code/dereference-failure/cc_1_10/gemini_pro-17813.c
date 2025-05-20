//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the library structure
typedef struct library {
  char *name;
  char *location;
  int num_books;
  struct book *books;
} library;

// Define the book structure
typedef struct book {
  char *title;
  char *author;
  int year;
} book;

// Create a new library
library *create_library(char *name, char *location) {
  library *new_library = malloc(sizeof(library));
  new_library->name = strdup(name);
  new_library->location = strdup(location);
  new_library->num_books = 0;
  new_library->books = NULL;
  return new_library;
}

// Add a book to a library
void add_book(library *library, book *book) {
  library->num_books++;
  library->books = realloc(library->books, library->num_books * sizeof(book));
  library->books[library->num_books - 1] = *book;
}

// Print the details of a library
void print_library(library *library) {
  printf("Name: %s\n", library->name);
  printf("Location: %s\n", library->location);
  printf("Number of books: %d\n", library->num_books);
  for (int i = 0; i < library->num_books; i++) {
    printf("Book %d:\n", i + 1);
    printf("Title: %s\n", library->books[i].title);
    printf("Author: %s\n", library->books[i].author);
    printf("Year: %d\n", library->books[i].year);
  }
}

// Free the memory allocated for a library
void free_library(library *library) {
  free(library->name);
  free(library->location);
  for (int i = 0; i < library->num_books; i++) {
    free(library->books[i].title);
    free(library->books[i].author);
  }
  free(library->books);
  free(library);
}

// Main function
int main() {
  // Create a new library
  library *library = create_library("Central Library", "Downtown");

  // Add some books to the library
  book book1 = {"The Catcher in the Rye", "J.D. Salinger", 1951};
  add_book(library, &book1);
  book book2 = {"To Kill a Mockingbird", "Harper Lee", 1960};
  add_book(library, &book2);
  book book3 = {"The Great Gatsby", "F. Scott Fitzgerald", 1925};
  add_book(library, &book3);

  // Print the details of the library
  print_library(library);

  // Free the memory allocated for the library
  free_library(library);

  return 0;
}