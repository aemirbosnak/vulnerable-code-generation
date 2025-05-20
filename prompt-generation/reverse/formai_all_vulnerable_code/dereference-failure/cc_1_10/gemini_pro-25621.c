//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *text;
  int len;
} Book;

Book *read_book(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    perror("Unable to open file");
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  long len = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *text = malloc(len + 1);
  if (!text) {
    perror("Unable to allocate memory");
    fclose(fp);
    return NULL;
  }

  fread(text, 1, len, fp);
  text[len] = '\0';

  fclose(fp);

  Book *book = malloc(sizeof(Book));
  if (!book) {
    perror("Unable to allocate memory");
    free(text);
    return NULL;
  }

  book->text = text;
  book->len = len;

  return book;
}

void free_book(Book *book) {
  free(book->text);
  free(book);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  Book *book = read_book(argv[1]);
  if (!book) {
    return EXIT_FAILURE;
  }

  printf("%s", book->text);

  free_book(book);

  return EXIT_SUCCESS;
}