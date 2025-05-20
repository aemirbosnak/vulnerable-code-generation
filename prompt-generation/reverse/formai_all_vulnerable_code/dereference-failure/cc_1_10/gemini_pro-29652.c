//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct {
  char title[100];
  char author[100];
  int pages;
  char text[10000];
} Book;

// Read a book from a file
Book* readBook(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Allocate memory for the book
  Book* book = malloc(sizeof(Book));

  // Read the book's title from the file
  fscanf(file, "%s\n", book->title);

  // Read the book's author from the file
  fscanf(file, "%s\n", book->author);

  // Read the book's number of pages from the file
  fscanf(file, "%d\n", &book->pages);

  // Read the book's text from the file
  char line[1000];
  while (fgets(line, 1000, file) != NULL) {
    strcat(book->text, line);
  }

  // Close the file
  fclose(file);

  // Return the book
  return book;
}

// Print a book to the console
void printBook(Book* book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Pages: %d\n", book->pages);
  printf("Text:\n%s\n", book->text);
}

// Free the memory allocated for a book
void freeBook(Book* book) {
  free(book);
}

// Main function
int main() {
  // Read a book from the file "book.txt"
  Book* book = readBook("book.txt");

  // Print the book to the console
  printBook(book);

  // Free the memory allocated for the book
  freeBook(book);

  return 0;
}