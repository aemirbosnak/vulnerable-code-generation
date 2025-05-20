//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOK_SIZE 1024
#define MAX_PAGES 100

// Structure to hold a book
struct Book {
  char title[50];
  char author[50];
  char contents[MAX_BOOK_SIZE];
  int num_pages;
};

// Function to read a book from a file
struct Book read_book(const char* file_name) {
  struct Book book;
  int num_pages = 0;
  char line[100];
  FILE* file = fopen(file_name, "r");

  // Read the book title and author
  fscanf(file, "%s %s", book.title, book.author);

  // Read the book contents
  while (fgets(line, 100, file) != NULL) {
    strcpy(book.contents + num_pages * 100, line);
    num_pages++;
  }

  // Calculate the number of pages
  book.num_pages = num_pages;

  // Close the file
  fclose(file);

  return book;
}

// Function to display a book
void display_book(struct Book book) {
  int page = 0;
  char line[100];

  printf("Book Title: %s\nAuthor: %s\n\n", book.title, book.author);

  while (page < book.num_pages) {
    // Read the contents of the current page
    sprintf(line, "%s", book.contents + page * 100);

    // Display the page
    printf("%s\n", line);

    // Increment the page number
    page++;
  }

  printf("\n");
}

// Function to turn the page
void turn_page(struct Book book, int page) {
  if (page < book.num_pages - 1) {
    // Go to the next page
    display_book(book);
  } else {
    // End of book, display a message
    printf("End of Book\n");
  }
}

int main() {
  struct Book book = read_book("book1.txt");
  turn_page(book, 0);
  return 0;
}