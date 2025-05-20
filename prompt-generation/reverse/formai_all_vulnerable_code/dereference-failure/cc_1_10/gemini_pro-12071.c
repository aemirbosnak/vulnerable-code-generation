//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the structure of a book
typedef struct {
  char title[100];
  char author[100];
  int num_pages;
  char *text;
} Book;

// Create a new book
Book *create_book(char *title, char *author, int num_pages, char *text) {
  Book *book = malloc(sizeof(Book));
  strcpy(book->title, title);
  strcpy(book->author, author);
  book->num_pages = num_pages;
  book->text = malloc(strlen(text) + 1);
  strcpy(book->text, text);
  return book;
}

// Free the memory allocated for a book
void free_book(Book *book) {
  free(book->text);
  free(book);
}

// Print the information about a book
void print_book(Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Number of pages: %d\n", book->num_pages);
  printf("Text:\n%s\n", book->text);
}

// Read a book from a file
Book *read_book(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the title of the book
  char title[100];
  if (fgets(title, 100, fp) == NULL) {
    perror("Error reading title");
    fclose(fp);
    return NULL;
  }

  // Read the author of the book
  char author[100];
  if (fgets(author, 100, fp) == NULL) {
    perror("Error reading author");
    fclose(fp);
    return NULL;
  }

  // Read the number of pages in the book
  int num_pages;
  if (fscanf(fp, "%d", &num_pages) != 1) {
    perror("Error reading number of pages");
    fclose(fp);
    return NULL;
  }

  // Read the text of the book
  char *text = malloc(100000);
  if (fread(text, 1, 100000, fp) != 100000) {
    perror("Error reading text");
    fclose(fp);
    return NULL;
  }

  // Create a new book
  Book *book = create_book(title, author, num_pages, text);

  // Close the file
  fclose(fp);

  return book;
}

// Write a book to a file
void write_book(char *filename, Book *book) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  // Write the title of the book
  fprintf(fp, "%s\n", book->title);

  // Write the author of the book
  fprintf(fp, "%s\n", book->author);

  // Write the number of pages in the book
  fprintf(fp, "%d\n", book->num_pages);

  // Write the text of the book
  fwrite(book->text, 1, strlen(book->text), fp);

  // Close the file
  fclose(fp);
}

// Main function
int main() {
  // Create a new book
  Book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184, "Once upon a time, there was a planet called Earth...");

  // Print the information about the book
  print_book(book);

  // Write the book to a file
  write_book("hitchhikers_guide.txt", book);

  // Free the memory allocated for the book
  free_book(book);

  return 0;
}