//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the book struct
typedef struct book {
  char *title;
  char *author;
  int num_pages;
  char *text;
} book;

// Create a new book
book *new_book(char *title, char *author, int num_pages, char *text) {
  book *b = malloc(sizeof(book));
  b->title = strdup(title);
  b->author = strdup(author);
  b->num_pages = num_pages;
  b->text = strdup(text);
  return b;
}

// Free the memory allocated for a book
void free_book(book *b) {
  free(b->title);
  free(b->author);
  free(b->text);
  free(b);
}

// Print the book's information
void print_book(book *b) {
  printf("Title: %s\n", b->title);
  printf("Author: %s\n", b->author);
  printf("Number of pages: %d\n", b->num_pages);
  printf("Text: %s\n", b->text);
}

// Read a book from a file
book *read_book(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char *title = malloc(100);
  char *author = malloc(100);
  int num_pages;
  char *text = malloc(1000);

  fscanf(fp, "%s %s %d %s", title, author, &num_pages, text);

  fclose(fp);

  return new_book(title, author, num_pages, text);
}

// Write a book to a file
void write_book(book *b, char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    return;
  }

  fprintf(fp, "%s %s %d %s", b->title, b->author, b->num_pages, b->text);

  fclose(fp);
}

// Main function
int main() {
  // Create a new book
  book *b = new_book("The Catcher in the Rye", "J.D. Salinger", 277, "I am Holden Caulfield");

  // Print the book's information
  print_book(b);

  // Write the book to a file
  write_book(b, "catcher.txt");

  // Read the book from a file
  book *b2 = read_book("catcher.txt");

  // Print the book's information
  print_book(b2);

  // Free the memory allocated for the books
  free_book(b);
  free_book(b2);

  return 0;
}