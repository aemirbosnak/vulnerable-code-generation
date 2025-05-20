//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  FILE *fp;
  int line;
  int col;
  int eof;
} Book;

Book *open_book(char *name) {
  Book *book = malloc(sizeof(Book));
  if (book == NULL) {
    return NULL;
  }
  book->name = strdup(name);
  if (book->name == NULL) {
    free(book);
    return NULL;
  }
  book->fp = fopen(name, "r");
  if (book->fp == NULL) {
    free(book->name);
    free(book);
    return NULL;
  }
  book->line = 1;
  book->col = 0;
  book->eof = 0;
  return book;
}

void close_book(Book *book) {
  fclose(book->fp);
  free(book->name);
  free(book);
}

int next_char(Book *book) {
  if (book->eof) {
    return EOF;
  }
  int c = fgetc(book->fp);
  if (c == '\n') {
    book->line++;
    book->col = 0;
  } else {
    book->col++;
  }
  if (c == EOF) {
    book->eof = 1;
  }
  return c;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <book>\n", argv[0]);
    return EXIT_FAILURE;
  }
  Book *book = open_book(argv[1]);
  if (book == NULL) {
    fprintf(stderr, "Error: could not open book %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  int c;
  while ((c = next_char(book)) != EOF) {
    putchar(c);
  }
  close_book(book);
  return EXIT_SUCCESS;
}