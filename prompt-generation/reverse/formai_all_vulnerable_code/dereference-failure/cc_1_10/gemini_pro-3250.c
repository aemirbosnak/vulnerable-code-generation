//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book {
  char *title;
  char *author;
  int num_pages;
  char *text;
} book;

// Function to create a new book
book *create_book(char *title, char *author, int num_pages, char *text) {
  book *new_book = malloc(sizeof(book));
  new_book->title = strdup(title);
  new_book->author = strdup(author);
  new_book->num_pages = num_pages;
  new_book->text = strdup(text);
  return new_book;
}

// Function to free the memory allocated for a book
void free_book(book *book) {
  free(book->title);
  free(book->author);
  free(book->text);
  free(book);
}

// Function to print the details of a book
void print_book(book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Number of pages: %d\n", book->num_pages);
  printf("Text:\n%s\n", book->text);
}

// Function to read a book from a file
book *read_book_from_file(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the title of the book
  char title[256];
  if (fgets(title, 256, fp) == NULL) {
    perror("Error reading title");
    fclose(fp);
    return NULL;
  }

  // Read the author of the book
  char author[256];
  if (fgets(author, 256, fp) == NULL) {
    perror("Error reading author");
    fclose(fp);
    return NULL;
  }

  // Read the number of pages in the book
  int num_pages;
  if (fscanf(fp, "%d", &num_pages) != 1) {
    perror("Error reading number of pages");
    fclose(fp);
    return NULL;
  }

  // Read the text of the book
  char *text = malloc(sizeof(char) * num_pages);
  if (fread(text, sizeof(char), num_pages, fp) != num_pages) {
    perror("Error reading text");
    fclose(fp);
    return NULL;
  }

  // Close the file
  fclose(fp);

  // Create the book
  book *new_book = create_book(title, author, num_pages, text);

  // Return the book
  return new_book;
}

// Function to write a book to a file
void write_book_to_file(char *filename, book *book) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  // Write the title of the book
  fprintf(fp, "%s\n", book->title);

  // Write the author of the book
  fprintf(fp, "%s\n", book->author);

  // Write the number of pages in the book
  fprintf(fp, "%d\n", book->num_pages);

  // Write the text of the book
  fwrite(book->text, sizeof(char), book->num_pages, fp);

  // Close the file
  fclose(fp);
}

// Function to search for a word in a book
int search_book_for_word(book *book, char *word) {
  char *p = book->text;
  while (*p != '\0') {
    if (strcmp(p, word) == 0) {
      return 1;
    }
    p++;
  }
  return 0;
}

// Function to get the number of words in a book
int get_num_words_in_book(book *book) {
  char *p = book->text;
  int num_words = 0;
  while (*p != '\0') {
    if (*p == ' ' || *p == '\n') {
      num_words++;
    }
    p++;
  }
  return num_words;
}

// Main function
int main() {
  // Create a new book
  book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum eget orci eget sapien lacinia tincidunt. Maecenas non nunc velit. Sed euismod eget nunc sed ultricies. Praesent et lacus eget eros tincidunt tempus. Cras tristique lacus sed nibh maximus, vitae convallis erat aliquam. Mauris consectetur tincidunt enim, eu cursus ipsum ultrices et. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Fusce volutpat vehicula arcu, id sagittis ligula rhoncus non. Integer vitae porttitor augue. Mauris bibendum lacus eu leo dictum, non placerat ex efficitur. Sed vitae ullamcorper turpis, eu consectetur urna. Suspendisse potenti. Donec faucibus velit sit amet lacus consectetur, a luctus mauris aliquam. Phasellus ultrices sed tortor ut posuere. Donec a placerat libero. Curabitur bibendum ornare ultricies. Nunc posuere eleifend massa, et ultrices tellus mollis a. Praesent maximus nec tortor vel consectetur. Phasellus molestie ultricies massa sit amet maximus.");

  // Print the details of the book
  print_book(book);

  // Search for a word in the book
  char *word = "the";
  int found = search_book_for_word(book, word);
  if (found) {
    printf("The word \"%s\" was found in the book.\n", word);
  } else {
    printf("The word \"%s\" was not found in the book.\n", word);
  }

  // Get the number of words in the book
  int num_words = get_num_words_in_book(book);
  printf("The book contains %d words.\n", num_words);

  // Free the memory allocated for the book
  free_book(book);

  return 0;
}