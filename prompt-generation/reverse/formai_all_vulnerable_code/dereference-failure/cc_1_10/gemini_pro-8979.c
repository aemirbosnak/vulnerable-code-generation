//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: artistic
// An Artistic C Ebook Reader Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the book structure
typedef struct book {
  char *title;
  char *author;
  int num_pages;
  char *text;
} book;

// Create a new book
book *create_book(char *title, char *author, int num_pages, char *text) {
  book *new_book = malloc(sizeof(book));
  new_book->title = strdup(title);
  new_book->author = strdup(author);
  new_book->num_pages = num_pages;
  new_book->text = strdup(text);
  return new_book;
}

// Free the memory allocated for a book
void free_book(book *book) {
  free(book->title);
  free(book->author);
  free(book->text);
  free(book);
}

// Print the book's information
void print_book(book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Number of pages: %d\n", book->num_pages);
  printf("Text:\n%s\n", book->text);
}

// Read the book from a file
book *read_book(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Get the file size
  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);

  // Allocate memory for the book
  book *book = malloc(sizeof(book));

  // Read the book's title
  char *title = malloc(file_size);
  fread(title, file_size, 1, fp);

  // Read the book's author
  char *author = malloc(file_size);
  fread(author, file_size, 1, fp);

  // Read the book's number of pages
  int num_pages;
  fread(&num_pages, sizeof(int), 1, fp);

  // Read the book's text
  char *text = malloc(file_size);
  fread(text, file_size, 1, fp);

  // Close the file
  fclose(fp);

  // Set the book's fields
  book->title = title;
  book->author = author;
  book->num_pages = num_pages;
  book->text = text;

  // Return the book
  return book;
}

// Write the book to a file
void write_book(book *book, char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  // Write the book's title
  fwrite(book->title, strlen(book->title), 1, fp);

  // Write the book's author
  fwrite(book->author, strlen(book->author), 1, fp);

  // Write the book's number of pages
  fwrite(&book->num_pages, sizeof(int), 1, fp);

  // Write the book's text
  fwrite(book->text, strlen(book->text), 1, fp);

  // Close the file
  fclose(fp);
}

// Main function
int main() {
  // Create a new book
  book *book = create_book("The Great Gatsby", "F. Scott Fitzgerald", 180, "The Great Gatsby is a novel by American author F. Scott Fitzgerald that follows the story of Jay Gatsby, a self-made millionaire who throws lavish parties in his West Egg mansion in the hopes of winning back Daisy Buchanan, a woman he loved and lost five years earlier.");

  // Print the book's information
  print_book(book);

  // Write the book to a file
  write_book(book, "gatsby.txt");

  // Free the memory allocated for the book
  free_book(book);

  return 0;
}