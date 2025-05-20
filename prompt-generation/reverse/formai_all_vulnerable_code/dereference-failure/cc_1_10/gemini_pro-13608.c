//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *title;
  char *author;
  char *content;
  int page_count;
} Book;

Book *read_file(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  Book *book = malloc(sizeof(Book));
  book->title = NULL;
  book->author = NULL;
  book->content = NULL;
  book->page_count = 0;

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (strncmp(line, "Title: ", 7) == 0) {
      book->title = strdup(line + 7);
    } else if (strncmp(line, "Author: ", 8) == 0) {
      book->author = strdup(line + 8);
    } else if (strncmp(line, "Content: ", 9) == 0) {
      book->content = strdup(line + 9);
    } else if (strncmp(line, "Page Count: ", 12) == 0) {
      book->page_count = atoi(line + 12);
    }
  }

  fclose(fp);

  return book;
}

void print_book(Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Content: %s\n", book->content);
  printf("Page Count: %d\n", book->page_count);
}

void free_book(Book *book) {
  free(book->title);
  free(book->author);
  free(book->content);
  free(book);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  Book *book = read_file(argv[1]);
  if (book == NULL) {
    fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  print_book(book);
  free_book(book);

  return EXIT_SUCCESS;
}