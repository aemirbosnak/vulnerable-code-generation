//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lines and characters per line in the book
#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 100

// Define the structure of a book
typedef struct {
  char title[MAX_CHARS_PER_LINE];
  char author[MAX_CHARS_PER_LINE];
  char lines[MAX_LINES][MAX_CHARS_PER_LINE];
  int num_lines;
} Book;

// Define the function to read a book from a file
Book* read_book(const char* filename) {
  // Allocate memory for the book
  Book* book = malloc(sizeof(Book));

  // Open the file
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Read the title and author
  fscanf(file, "%s %s\n", book->title, book->author);

  // Read the lines of the book
  int line_num = 0;
  while (fgets(book->lines[line_num], MAX_CHARS_PER_LINE, file) != NULL) {
    // Remove the newline character from the end of the line
    book->lines[line_num][strlen(book->lines[line_num]) - 1] = '\0';
    line_num++;
  }

  // Close the file
  fclose(file);

  // Set the number of lines in the book
  book->num_lines = line_num;

  // Return the book
  return book;
}

// Define the function to free the memory allocated for a book
void free_book(Book* book) {
  // Free the memory allocated for the book's title and author
  free(book->title);
  free(book->author);

  // Free the memory allocated for the book's lines
  for (int i = 0; i < book->num_lines; i++) {
    free(book->lines[i]);
  }

  // Free the memory allocated for the book itself
  free(book);
}

// Define the function to print a book
void print_book(Book* book) {
  // Print the title and author
  printf("%s by %s\n\n", book->title, book->author);

  // Print the lines of the book
  for (int i = 0; i < book->num_lines; i++) {
    printf("%s\n", book->lines[i]);
  }
}

// Define the main function
int main() {
  // Read the book from the file
  Book* book = read_book("book.txt");
  if (book == NULL) {
    return 1;
  }

  // Print the book
  print_book(book);

  // Free the memory allocated for the book
  free_book(book);

  return 0;
}