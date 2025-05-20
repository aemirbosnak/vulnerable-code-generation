//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a page
typedef struct page {
  char *text;
  struct page *next;
  struct page *prev;
} page;

// Define the structure of a book
typedef struct book {
  char *title;
  char *author;
  int num_pages;
  page *first_page;
  page *last_page;
} book;

// Create a new book
book *create_book(char *title, char *author) {
  book *b = malloc(sizeof(book));
  b->title = strdup(title);
  b->author = strdup(author);
  b->num_pages = 0;
  b->first_page = NULL;
  b->last_page = NULL;
  return b;
}

// Add a new page to a book
void add_page(book *b, char *text) {
  page *p = malloc(sizeof(page));
  p->text = strdup(text);
  p->next = NULL;
  p->prev = NULL;
  if (b->num_pages == 0) {
    b->first_page = p;
    b->last_page = p;
  } else {
    b->last_page->next = p;
    p->prev = b->last_page;
    b->last_page = p;
  }
  b->num_pages++;
}

// Print a book
void print_book(book *b) {
  page *p = b->first_page;
  while (p != NULL) {
    printf("%s", p->text);
    p = p->next;
  }
}

// Free a book
void free_book(book *b) {
  page *p = b->first_page;
  while (p != NULL) {
    page *next = p->next;
    free(p->text);
    free(p);
    p = next;
  }
  free(b->title);
  free(b->author);
  free(b);
}

// Read a book from a file
book *read_book(char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    perror("Error opening file");
    return NULL;
  }

  char *title = NULL;
  char *author = NULL;
  int num_pages = 0;
  fscanf(f, "%s %s %d", title, author, &num_pages);

  book *b = create_book(title, author);

  for (int i = 0; i < num_pages; i++) {
    char *text = NULL;
    size_t len = 0;
    getline(&text, &len, f);
    add_page(b, text);
  }

  fclose(f);
  return b;
}

// Write a book to a file
void write_book(book *b, char *filename) {
  FILE *f = fopen(filename, "w");
  if (f == NULL) {
    perror("Error opening file");
    return;
  }

  fprintf(f, "%s %s %d\n", b->title, b->author, b->num_pages);

  page *p = b->first_page;
  while (p != NULL) {
    fprintf(f, "%s", p->text);
    p = p->next;
  }

  fclose(f);
}

// Main function
int main() {
  // Create a new book
  book *b = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");

  // Add some pages to the book
  add_page(b, "The Hitchhiker's Guide to the Galaxy is a comedy science fiction series created by Douglas Adams.");
  add_page(b, "The series follows the adventures of Arthur Dent, a hapless Englishman, who is rescued from Earth just before its destruction by the Vogons, a race of bureaucratic aliens.");
  add_page(b, "Arthur is joined by his friend Ford Prefect, a researcher for the Hitchhiker's Guide to the Galaxy, who reveals that Earth is just a small part of a vast and complex universe.");

  // Print the book
  printf("The Hitchhiker's Guide to the Galaxy\n");
  printf("by Douglas Adams\n\n");
  print_book(b);

  // Free the book
  free_book(b);

  return 0;
}