//FormAI DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct ebook {
  char title[100];
  char author[100];
  float price;
  char format[10];
  char filepath[100];
};

struct ebook_collection {
  int num_books;
  struct ebook books[MAX_BOOKS];
};

void print_book_details(struct ebook b) {
  printf("\n");
  printf("Title: %s\nAuthor: %s\nPrice: $%.2f\nFormat: %s\nFilepath: %s\n", b.title, b.author, b.price, b.format, b.filepath);
}

void load_ebook_collection(struct ebook_collection *collection, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file '%s'\n", filename);
    exit(1);
  }

  char buffer[100];
  while (fgets(buffer, 100, file) != NULL) {
    char *title = strtok(buffer, ",");
    char *author = strtok(NULL, ",");
    char *price_str = strtok(NULL, ",");
    char *format = strtok(NULL, ",");
    char *filepath = strtok(NULL, "\n");

    struct ebook book = {
      .title = "",
      .author = "",
      .price = 0.0,
      .format = "",
      .filepath = ""
    };

    strcpy(book.title, title);
    strcpy(book.author, author);
    book.price = atof(price_str);
    strcpy(book.format, format);
    strcpy(book.filepath, filepath);

    collection->books[collection->num_books++] = book;
  }

  fclose(file);
}

void display_ebook_collection(struct ebook_collection collection) {
  printf("\n==== Ebook Collection (%d books) ====\n", collection.num_books);
  for (int i = 0; i < collection.num_books; i++) {
    printf("%d. %s", i + 1, collection.books[i].title);
  }
}

int main() {
  struct ebook_collection collection = {
    .num_books = 0,
    .books = {}
  };

  load_ebook_collection(&collection, "books.csv");
  display_ebook_collection(collection);

  int selection;
  do {
    printf("\nEnter a book number to view details (0 to exit): ");
    scanf("%d", &selection);

    if (selection > 0 && selection <= collection.num_books) {
      struct ebook selected_book = collection.books[selection - 1];
      print_book_details(selected_book);
    } else if (selection != 0) {
      printf("Invalid selection. Please try again.\n");
    }
  } while (selection != 0);

  return 0;
}