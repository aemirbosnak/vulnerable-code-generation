//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct book
struct book {
  char *title;
  char *author;
  int pages;
  float rating;
};

// Define the struct library
struct library {
  struct book *books;
  int num_books;
};

// Create a new book
struct book *create_book(char *title, char *author, int pages, float rating) {
  struct book *book = malloc(sizeof(struct book));
  book->title = malloc(strlen(title) + 1);
  strcpy(book->title, title);
  book->author = malloc(strlen(author) + 1);
  strcpy(book->author, author);
  book->pages = pages;
  book->rating = rating;
  return book;
}

// Add a book to the library
void add_book(struct library *library, struct book *book) {
  library->books = realloc(library->books, (library->num_books + 1) * sizeof(struct book));
  library->books[library->num_books++] = *book;
}

// Print the library
void print_library(struct library *library) {
  for (int i = 0; i < library->num_books; i++) {
    printf("Title: %s\n", library->books[i].title);
    printf("Author: %s\n", library->books[i].author);
    printf("Pages: %d\n", library->books[i].pages);
    printf("Rating: %.1f\n\n", library->books[i].rating);
  }
}

// Free the library
void free_library(struct library *library) {
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
  struct library *library = malloc(sizeof(struct library));
  library->books = NULL;
  library->num_books = 0;

  // Add some books to the library
  add_book(library, create_book("The Lord of the Rings", "J.R.R. Tolkien", 1207, 4.9));
  add_book(library, create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184, 4.2));
  add_book(library, create_book("The Great Gatsby", "F. Scott Fitzgerald", 180, 4.0));

  // Print the library
  print_library(library);

  // Free the library
  free_library(library);

  return 0;
}