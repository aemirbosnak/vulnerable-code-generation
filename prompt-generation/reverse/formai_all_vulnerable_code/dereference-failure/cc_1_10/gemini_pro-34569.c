//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 256

typedef struct {
  char *text;
  int size;
} Page;

typedef struct {
  Page *pages;
  int num_pages;
} Book;

Book *load_book(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);

  int num_pages = file_size / PAGE_SIZE;
  if (file_size % PAGE_SIZE != 0) {
    num_pages++;
  }

  Book *book = malloc(sizeof(Book));
  book->pages = malloc(sizeof(Page) * num_pages);
  book->num_pages = num_pages;

  for (int i = 0; i < num_pages; i++) {
    Page *page = &book->pages[i];
    page->text = malloc(PAGE_SIZE + 1);
    fread(page->text, 1, PAGE_SIZE, fp);
    page->text[PAGE_SIZE] = '\0';
  }

  fclose(fp);

  return book;
}

void free_book(Book *book) {
  for (int i = 0; i < book->num_pages; i++) {
    free(book->pages[i].text);
  }
  free(book->pages);
  free(book);
}

void print_page(Page *page) {
  for (int i = 0; i < page->size; i++) {
    putchar(page->text[i]);
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  Book *book = load_book(argv[1]);
  if (book == NULL) {
    fprintf(stderr, "Error loading book.\n");
    return 1;
  }

  int page_num = 0;
  while (page_num < book->num_pages) {
    printf("Page %d\n", page_num + 1);
    print_page(&book->pages[page_num]);
    printf("\n");

    char input[10];
    printf("Press [ENTER] to continue, [N] to go to the next page, or [P] to go to the previous page: ");
    fgets(input, sizeof(input), stdin);

    if (strcmp(input, "\n") == 0) {
      page_num++;
    } else if (strcmp(input, "N\n") == 0) {
      page_num++;
      if (page_num >= book->num_pages) {
        page_num = book->num_pages - 1;
      }
    } else if (strcmp(input, "P\n") == 0) {
      page_num--;
      if (page_num < 0) {
        page_num = 0;
      }
    }
  }

  free_book(book);

  return 0;
}