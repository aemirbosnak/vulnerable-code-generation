//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a book
typedef struct Book {
  char *title;
  char *author;
  int num_pages;
} Book;

// A function to create a new book
Book *create_book(char *title, char *author, int num_pages) {
  Book *book = malloc(sizeof(Book));
  book->title = strdup(title);
  book->author = strdup(author);
  book->num_pages = num_pages;
  return book;
}

// A function to print a book
void print_book(Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Number of pages: %d\n", book->num_pages);
}

// A function to free the memory allocated for a book
void free_book(Book *book) {
  free(book->title);
  free(book->author);
  free(book);
}

// A function to read a book from a file
Book *read_book(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[1024];
  char *title = NULL;
  char *author = NULL;
  int num_pages = 0;

  while (fgets(line, sizeof(line), fp) != NULL) {
    if (strncmp(line, "Title:", 6) == 0) {
      title = strdup(line + 6);
    } else if (strncmp(line, "Author:", 7) == 0) {
      author = strdup(line + 7);
    } else if (strncmp(line, "Number of pages:", 16) == 0) {
      num_pages = atoi(line + 16);
    }
  }

  fclose(fp);

  Book *book = create_book(title, author, num_pages);

  free(title);
  free(author);

  return book;
}

// A function to write a book to a file
void write_book(Book *book, char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    return;
  }

  fprintf(fp, "Title: %s\n", book->title);
  fprintf(fp, "Author: %s\n", book->author);
  fprintf(fp, "Number of pages: %d\n", book->num_pages);

  fclose(fp);
}

// A function to search for a book by title
Book *search_book_by_title(char *title, Book **books, int num_books) {
  for (int i = 0; i < num_books; i++) {
    if (strcmp(books[i]->title, title) == 0) {
      return books[i];
    }
  }

  return NULL;
}

// A function to search for a book by author
Book *search_book_by_author(char *author, Book **books, int num_books) {
  for (int i = 0; i < num_books; i++) {
    if (strcmp(books[i]->author, author) == 0) {
      return books[i];
    }
  }

  return NULL;
}

// A function to sort books by title
void sort_books_by_title(Book **books, int num_books) {
  for (int i = 0; i < num_books - 1; i++) {
    for (int j = i + 1; j < num_books; j++) {
      if (strcmp(books[i]->title, books[j]->title) > 0) {
        Book *temp = books[i];
        books[i] = books[j];
        books[j] = temp;
      }
    }
  }
}

// A function to sort books by author
void sort_books_by_author(Book **books, int num_books) {
  for (int i = 0; i < num_books - 1; i++) {
    for (int j = i + 1; j < num_books; j++) {
      if (strcmp(books[i]->author, books[j]->author) > 0) {
        Book *temp = books[i];
        books[i] = books[j];
        books[j] = temp;
      }
    }
  }
}

// A function to print a list of books
void print_books(Book **books, int num_books) {
  for (int i = 0; i < num_books; i++) {
    print_book(books[i]);
    printf("\n");
  }
}

// A function to free the memory allocated for a list of books
void free_books(Book **books, int num_books) {
  for (int i = 0; i < num_books; i++) {
    free_book(books[i]);
  }
}

int main() {
  // Create a list of books
  Book *books[] = {
    create_book("The Catcher in the Rye", "J.D. Salinger", 277),
    create_book("The Great Gatsby", "F. Scott Fitzgerald", 180),
    create_book("1984", "George Orwell", 328),
    create_book("Brave New World", "Aldous Huxley", 268),
    create_book("The Lord of the Rings", "J.R.R. Tolkien", 1207)
  };

  int num_books = sizeof(books) / sizeof(books[0]);

  // Print the list of books
  printf("Books:\n");
  print_books(books, num_books);
  printf("\n");

  // Search for a book by title
  Book *book = search_book_by_title("Brave New World", books, num_books);
  if (book != NULL) {
    printf("Found book by title:\n");
    print_book(book);
    printf("\n");
  } else {
    printf("Book not found by title.\n");
  }

  // Search for a book by author
  book = search_book_by_author("J.D. Salinger", books, num_books);
  if (book != NULL) {
    printf("Found book by author:\n");
    print_book(book);
    printf("\n");
  } else {
    printf("Book not found by author.\n");
  }

  // Sort the books by title
  sort_books_by_title(books, num_books);

  // Print the sorted list of books by title
  printf("Sorted books by title:\n");
  print_books(books, num_books);
  printf("\n");

  // Sort the books by author
  sort_books_by_author(books, num_books);

  // Print the sorted list of books by author
  printf("Sorted books by author:\n");
  print_books(books, num_books);
  printf("\n");

  // Free the memory allocated for the list of books
  free_books(books, num_books);

  return 0;
}