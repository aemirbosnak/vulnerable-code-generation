//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOK_SIZE 100000

int main() {
  // Open the book file
  FILE *book_file = fopen("book.txt", "r");
  if (book_file == NULL) {
    printf("Error opening book file.\n");
    return EXIT_FAILURE;
  }

  // Get the size of the book file
  fseek(book_file, 0, SEEK_END);
  long book_size = ftell(book_file);
  rewind(book_file);

  // Allocate memory for the book
  char *book = malloc(book_size + 1);
  if (book == NULL) {
    printf("Error allocating memory for book.\n");
    fclose(book_file);
    return EXIT_FAILURE;
  }

  // Read the book into memory
  fread(book, 1, book_size, book_file);
  book[book_size] = '\0';

  // Close the book file
  fclose(book_file);

  // Split the book into lines
  char **lines = malloc(sizeof(char *) * MAX_LINE_LENGTH);
  if (lines == NULL) {
    printf("Error allocating memory for lines.\n");
    free(book);
    return EXIT_FAILURE;
  }

  int num_lines = 0;
  char *line = strtok(book, "\n");
  while (line != NULL) {
    lines[num_lines++] = line;
    line = strtok(NULL, "\n");
  }

  // Create a reader object
  struct reader {
    char **lines;
    int num_lines;
    int current_line;
  };

  struct reader reader = {lines, num_lines, 0};

  // Read the book
  while (reader.current_line < reader.num_lines) {
    printf("%s\n", reader.lines[reader.current_line++]);
  }

  // Free the memory allocated for the book and lines
  free(book);
  free(lines);

  return EXIT_SUCCESS;
}