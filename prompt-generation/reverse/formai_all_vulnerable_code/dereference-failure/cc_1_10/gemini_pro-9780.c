//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct book {
  char *title;
  char *author;
  int num_pages;
  int current_page;
} book;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Read the book title
  char title[256];
  fgets(title, sizeof(title), fp);

  // Read the book author
  char author[256];
  fgets(author, sizeof(author), fp);

  // Read the number of pages in the book
  int num_pages;
  fscanf(fp, "%d\n", &num_pages);

  // Create a new book struct
  book *b = malloc(sizeof(book));
  b->title = strdup(title);
  b->author = strdup(author);
  b->num_pages = num_pages;
  b->current_page = 1;

  // Read the book text
  char text[num_pages][256];
  for (int i = 0; i < num_pages; i++) {
    fgets(text[i], sizeof(text[i]), fp);
  }

  // Close the file
  fclose(fp);

  // Print the book title and author
  printf("Title: %s\n", b->title);
  printf("Author: %s\n", b->author);

  // Print the book text
  for (int i = 0; i < num_pages; i++) {
    printf("%s", text[i]);
  }

  // Free the book struct
  free(b->title);
  free(b->author);
  free(b);

  return EXIT_SUCCESS;
}