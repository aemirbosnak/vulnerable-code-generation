//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *title;
  char *author;
  int num_pages;
  char **pages;
} book;

book *create_book(char *title, char *author, int num_pages) {
  book *b = malloc(sizeof(book));
  b->title = malloc(strlen(title) + 1);
  strcpy(b->title, title);
  b->author = malloc(strlen(author) + 1);
  strcpy(b->author, author);
  b->num_pages = num_pages;
  b->pages = malloc(num_pages * sizeof(char *));
  for (int i = 0; i < num_pages; i++) {
    b->pages[i] = malloc(1024);
  }
  return b;
}

void free_book(book *b) {
  free(b->title);
  free(b->author);
  for (int i = 0; i < b->num_pages; i++) {
    free(b->pages[i]);
  }
  free(b->pages);
  free(b);
}

void print_book(book *b) {
  printf("Title: %s\n", b->title);
  printf("Author: %s\n", b->author);
  printf("Number of pages: %d\n", b->num_pages);
  for (int i = 0; i < b->num_pages; i++) {
    printf("Page %d:\n%s\n", i + 1, b->pages[i]);
  }
}

int main() {
  book *b = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 246);
  strcpy(b->pages[0], "On his way back to Earth with a pint of beer, Arthur Dent is astonished to see a bulldozer heading directly for his house. He runs into the garden just in time to save his beloved home from being demolished, and is completely bewildered when he sees the huge spaceship hovering where his house was. ");
  strcpy(b->pages[1], "The spaceship lands and out steps Ford Prefect, a human from the planet Betelgeuse. Ford was sent to Earth by the Galactic Federation to do research for the Hitchhiker's Guide to the Galaxy, the second best-selling book in the universe. ");
  print_book(b);
  free_book(b);
  return 0;
}