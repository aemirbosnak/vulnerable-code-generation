//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book {
  char *title;
  char *author;
  char *text;
  int num_pages;
} book;

// Function to create a new book
book *create_book(char *title, char *author, char *text, int num_pages) {
  book *new_book = malloc(sizeof(book));
  new_book->title = strdup(title);
  new_book->author = strdup(author);
  new_book->text = strdup(text);
  new_book->num_pages = num_pages;
  return new_book;
}

// Function to free the memory allocated for a book
void free_book(book *book) {
  free(book->title);
  free(book->author);
  free(book->text);
  free(book);
}

// Function to print the title and author of a book
void print_book_info(book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
}

// Function to print the text of a book
void print_book_text(book *book) {
  printf("%s", book->text);
}

// Function to turn a page of a book
void turn_page(book *book) {
  if (book->num_pages > 1) {
    book->num_pages--;
  }
}

// Function to read a book
void read_book(book *book) {
  // Print the book's info
  print_book_info(book);

  // Loop through the book's pages
  while (book->num_pages > 0) {
    // Print the current page
    print_book_text(book);

    // Turn the page
    turn_page(book);
  }
}

// Main function
int main() {
  // Create a new book
  book *my_book = create_book("The Canterbury Tales", "Geoffrey Chaucer", "Incipit prologus", 100);

  // Read the book
  read_book(my_book);

  // Free the memory allocated for the book
  free_book(my_book);

  return 0;
}