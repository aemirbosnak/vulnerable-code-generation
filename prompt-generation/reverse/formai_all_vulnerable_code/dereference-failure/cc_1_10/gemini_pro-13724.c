//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Structure to store the book's data
typedef struct book {
  char *title;
  char *author;
  int num_pages;
  char *text;
} book;

// Function to read a book from a file
book *read_book(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Allocate memory for the book
  book *b = malloc(sizeof(book));
  if (b == NULL) {
    printf("Error allocating memory for book\n");
    fclose(fp);
    return NULL;
  }

  // Read the title
  char line[1024];
  fgets(line, sizeof(line), fp);
  b->title = malloc(strlen(line) + 1);
  strcpy(b->title, line);

  // Read the author
  fgets(line, sizeof(line), fp);
  b->author = malloc(strlen(line) + 1);
  strcpy(b->author, line);

  // Read the number of pages
  fgets(line, sizeof(line), fp);
  b->num_pages = atoi(line);

  // Read the text
  b->text = malloc(sizeof(char) * b->num_pages);
  fread(b->text, sizeof(char), b->num_pages, fp);

  // Close the file
  fclose(fp);

  // Return the book
  return b;
}

// Function to print a book
void print_book(book *b) {
  // Print the title
  printf("Title: %s\n", b->title);

  // Print the author
  printf("Author: %s\n", b->author);

  // Print the number of pages
  printf("Number of pages: %d\n", b->num_pages);

  // Print the text
  printf("Text:\n");
  for (int i = 0; i < b->num_pages; i++) {
    printf("%s", b->text[i]);
  }
}

// Free the memory allocated for a book
void free_book(book *b) {
  free(b->title);
  free(b->author);
  free(b->text);
  free(b);
}

// Main function
int main() {
  // Read the book from the file
  book *b = read_book("book.txt");
  if (b == NULL) {
    printf("Error reading book\n");
    return 1;
  }

  // Print the book
  print_book(b);

  // Free the memory allocated for the book
  free_book(b);

  return 0;
}