//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 100
#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

typedef struct {
  char *title;
  int num_pages;
  char **pages;
} book;

book *new_book(char *title, int num_pages) {
  book *b = malloc(sizeof(book));
  b->title = malloc(strlen(title) + 1);
  strcpy(b->title, title);
  b->num_pages = num_pages;
  b->pages = malloc(num_pages * sizeof(char *));
  for (int i = 0; i < num_pages; i++) {
    b->pages[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
  }
  return b;
}

void free_book(book *b) {
  free(b->title);
  for (int i = 0; i < b->num_pages; i++) {
    free(b->pages[i]);
  }
  free(b->pages);
  free(b);
}

void print_book(book *b) {
  printf("Title: %s\n", b->title);
  printf("Number of pages: %d\n", b->num_pages);
  for (int i = 0; i < b->num_pages; i++) {
    printf("Page %d:\n", i + 1);
    printf("%s\n", b->pages[i]);
  }
}

int main() {
  book *b = new_book("The Iliad", 24);

  FILE *fp = fopen("iliad.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  int page = 0;
  int line_num = 0;
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    if (line_num == MAX_LINES) {
      page++;
      line_num = 0;
    }
    strcpy(b->pages[page], line);
    line_num++;
  }

  fclose(fp);

  print_book(b);

  free_book(b);

  return EXIT_SUCCESS;
}