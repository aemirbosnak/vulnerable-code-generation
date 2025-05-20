//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct {
  char *title;
  char *author;
  int num_pages;
} Book;

// Create a new book
Book *create_book(char *title, char *author, int num_pages) {
  Book *book = malloc(sizeof(Book));
  book->title = strdup(title);
  book->author = strdup(author);
  book->num_pages = num_pages;
  return book;
}

// Free the memory allocated for a book
void free_book(Book *book) {
  free(book->title);
  free(book->author);
  free(book);
}

// Print the details of a book
void print_book(Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Number of pages: %d\n", book->num_pages);
}

// Read a book from a file
Book *read_book(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the title of the book
  char *title = malloc(100);
  fgets(title, 100, fp);

  // Read the author of the book
  char *author = malloc(100);
  fgets(author, 100, fp);

  // Read the number of pages in the book
  int num_pages;
  fscanf(fp, "%d", &num_pages);

  // Create a new book and populate it with the data from the file
  Book *book = create_book(title, author, num_pages);

  // Close the file
  fclose(fp);

  return book;
}

// Write a book to a file
void write_book(Book *book, char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  // Write the title of the book to the file
  fprintf(fp, "%s\n", book->title);

  // Write the author of the book to the file
  fprintf(fp, "%s\n", book->author);

  // Write the number of pages in the book to the file
  fprintf(fp, "%d\n", book->num_pages);

  // Close the file
  fclose(fp);
}

// Main function
int main() {
  // Create a new book
  Book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184);

  // Print the details of the book
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Number of pages: %d\n", book->num_pages);

  // Write the book to a file
  write_book(book, "book.txt");

  // Read the book from a file
  Book *book2 = read_book("book.txt");

  // Print the details of the book
  printf("Title: %s\n", book2->title);
  printf("Author: %s\n", book2->author);
  printf("Number of pages: %d\n", book2->num_pages);

  // Free the memory allocated for the books
  free_book(book);
  free_book(book2);

  return 0;
}