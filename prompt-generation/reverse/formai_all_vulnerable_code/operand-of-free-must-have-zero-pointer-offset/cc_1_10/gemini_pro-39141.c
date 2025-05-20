//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_SIZE 1000000

typedef struct {
  char *title;
  char *author;
  char *content;
  int size;
} Book;

Book *read_book(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char *buffer = malloc(MAX_BOOK_SIZE);
  if (buffer == NULL) {
    fclose(fp);
    return NULL;
  }

  size_t size = fread(buffer, 1, MAX_BOOK_SIZE, fp);
  fclose(fp);

  Book *book = malloc(sizeof(Book));
  if (book == NULL) {
    free(buffer);
    return NULL;
  }

  book->title = strtok(buffer, "\n");
  book->author = strtok(NULL, "\n");
  book->content = strtok(NULL, "\0");
  book->size = size;

  free(buffer);

  return book;
}

void free_book(Book *book) {
  free(book->title);
  free(book->author);
  free(book->content);
  free(book);
}

void print_book(Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Content: %s\n", book->content);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  Book *book = read_book(argv[1]);
  if (book == NULL) {
    printf("Error reading book.\n");
    return EXIT_FAILURE;
  }

  print_book(book);
  free_book(book);

  return EXIT_SUCCESS;
}