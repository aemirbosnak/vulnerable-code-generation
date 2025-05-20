//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: medieval
// In ye olde days, when pages were parchment and ink was precious, a humble scribe named Aelfric sought to craft a device for reading electronic books.

#include <stdio.h>
#include <stdlib.h>

// A scroll, unrolled and ready to be read
typedef struct Book {
  char *title;
  char *text;
  int pages;
} Book;

// A quill, inked and ready to write
FILE *fp;

// Open a scroll and prepare it for reading
Book *Unroll(char *filename) {
  Book *book = malloc(sizeof(Book));
  fp = fopen(filename, "r");

  // Read ye title
  fscanf(fp, "%s", book->title);

  // Count ye pages
  int lines = 0;
  char line[1024];
  while (fgets(line, 1024, fp)) { lines++; }
  book->pages = lines;

  // Allocate parchment for ye text
  book->text = malloc(lines * 1024);

  // Copy ye text onto ye parchment
  rewind(fp);
  fgets(book->text, lines * 1024, fp);

  fclose(fp);

  return book;
}

// Turn to a page and read it aloud
void ReadPage(Book *book, int page) {
  if (page < 1 || page > book->pages) {
    printf("Alas, thou art attempting to read a page that doth not exist.\n");
  } else {
    int line = 0;
    char *start = book->text;
    while (line < page) {
      while (*start != '\n') { start++; }
      start++;
      line++;
    }
    char *end = start;
    while (*end != '\n') { end++; }
    *end = '\0';

    printf("%s\n", start);
  }
}

// Close the scroll and bid it farewell
void RollUp(Book *book) {
  free(book->title);
  free(book->text);
  free(book);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: book <filename>\n");
    return 1;
  }

  Book *book = Unroll(argv[1]);

  // Display ye title
  printf("Now reading: '%s'\n\n", book->title);

  // Prompt for page number
  int page;
  printf("Which page wouldst thou read? (1-%d) ", book->pages);
  scanf("%d", &page);

  // Read and display ye page
  ReadPage(book, page);

  RollUp(book);

  return 0;
}