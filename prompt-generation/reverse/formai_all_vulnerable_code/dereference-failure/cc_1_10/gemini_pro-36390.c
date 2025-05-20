//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple linked list to store the lines of the book
typedef struct line {
  char *text;
  struct line *next;
} line;

// A struct to represent the book
typedef struct book {
  char *title;
  char *author;
  int num_lines;
  line *first_line;
} book;

// A function to create a new book
book *new_book(char *title, char *author) {
  book *b = malloc(sizeof(book));
  b->title = strdup(title);
  b->author = strdup(author);
  b->num_lines = 0;
  b->first_line = NULL;
  return b;
}

// A function to add a line to the book
void add_line(book *b, char *text) {
  line *new_line = malloc(sizeof(line));
  new_line->text = strdup(text);
  new_line->next = NULL;

  if (b->num_lines == 0) {
    b->first_line = new_line;
  } else {
    line *last_line = b->first_line;
    while (last_line->next != NULL) {
      last_line = last_line->next;
    }
    last_line->next = new_line;
  }
  b->num_lines++;
}

// A function to print the book
void print_book(book *b) {
  printf("%s\n", b->title);
  printf("By %s\n", b->author);
  printf("\n");

  line *current_line = b->first_line;
  while (current_line != NULL) {
    printf("%s\n", current_line->text);
    current_line = current_line->next;
  }
}

// A function to free the memory allocated for the book
void free_book(book *b) {
  line *current_line = b->first_line;
  while (current_line != NULL) {
    line *next_line = current_line->next;
    free(current_line->text);
    free(current_line);
    current_line = next_line;
  }
  free(b->title);
  free(b->author);
  free(b);
}

// The main function
int main() {
  // Create a new book
  book *b = new_book("Ada's Algorithm", "Ada Lovelace");

  // Add some lines to the book
  add_line(b, "The Analytical Engine weaves algebraical patterns just as the Jacquard loom weaves flowers and leaves.");
  add_line(b, "The engine might act upon other things besides number, were objects found whose movements and relations could be expressed by the laws of algebraical and analytical science.");
  add_line(b, "The engine can arrange and combine its numerical relations at will.");

  // Print the book
  print_book(b);

  // Free the memory allocated for the book
  free_book(b);

  return 0;
}