//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
  char *title;
  char *author;
  int num_pages;
  float price;
};

struct Library {
  struct Book *books;
  int num_books;
};

struct Library *create_library(int num_books) {
  struct Library *library = malloc(sizeof(struct Library));
  library->books = malloc(sizeof(struct Book) * num_books);
  library->num_books = num_books;
  return library;
}

void free_library(struct Library *library) {
  for (int i = 0; i < library->num_books; i++) {
    free(library->books[i].title);
    free(library->books[i].author);
  }
  free(library->books);
  free(library);
}

void add_book_to_library(struct Library *library, struct Book book) {
  library->books[library->num_books] = book;
  library->num_books++;
}

void print_library(struct Library *library) {
  for (int i = 0; i < library->num_books; i++) {
    printf("Title: %s\n", library->books[i].title);
    printf("Author: %s\n", library->books[i].author);
    printf("Num Pages: %d\n", library->books[i].num_pages);
    printf("Price: $%.2f\n\n", library->books[i].price);
  }
}

int main() {
  struct Library *library = create_library(3);

  struct Book book1 = {"The Catcher in the Rye", "J.D. Salinger", 277, 8.99};
  struct Book book2 = {"The Great Gatsby", "F. Scott Fitzgerald", 180, 10.99};
  struct Book book3 = {"1984", "George Orwell", 328, 12.99};

  add_book_to_library(library, book1);
  add_book_to_library(library, book2);
  add_book_to_library(library, book3);

  print_library(library);

  free_library(library);

  return 0;
}