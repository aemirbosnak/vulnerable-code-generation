//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Book structure
typedef struct book {
  char *title;
  char *author;
  int num_pages;
  struct book *next;
} book;

// Library structure
typedef struct library {
  book *head;
  int num_books;
} library;

// Create a new book
book *create_book(char *title, char *author, int num_pages) {
  book *new_book = malloc(sizeof(book));
  new_book->title = strdup(title);
  new_book->author = strdup(author);
  new_book->num_pages = num_pages;
  new_book->next = NULL;
  return new_book;
}

// Add a book to the library
void add_book(library *lib, book *new_book) {
  if (lib->head == NULL) {
    lib->head = new_book;
  } else {
    book *current_book = lib->head;
    while (current_book->next != NULL) {
      current_book = current_book->next;
    }
    current_book->next = new_book;
  }
  lib->num_books++;
}

// Print the library
void print_library(library *lib) {
  book *current_book = lib->head;
  while (current_book != NULL) {
    printf("%s by %s (%d pages)\n", current_book->title, current_book->author, current_book->num_pages);
    current_book = current_book->next;
  }
}

// Free the library
void free_library(library *lib) {
  book *current_book = lib->head;
  while (current_book != NULL) {
    book *next_book = current_book->next;
    free(current_book->title);
    free(current_book->author);
    free(current_book);
    current_book = next_book;
  }
  free(lib);
}

// Main function
int main() {
  // Create a new library
  library *lib = malloc(sizeof(library));
  lib->head = NULL;
  lib->num_books = 0;

  // Add some books to the library
  add_book(lib, create_book("The Catcher in the Rye", "J.D. Salinger", 277));
  add_book(lib, create_book("To Kill a Mockingbird", "Harper Lee", 324));
  add_book(lib, create_book("The Great Gatsby", "F. Scott Fitzgerald", 180));
  add_book(lib, create_book("1984", "George Orwell", 328));
  add_book(lib, create_book("Brave New World", "Aldous Huxley", 268));

  // Print the library
  print_library(lib);

  // Free the library
  free_library(lib);

  return 0;
}