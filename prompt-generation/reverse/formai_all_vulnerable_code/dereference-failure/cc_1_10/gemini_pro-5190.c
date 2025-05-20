//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a line in the book.
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines in the book.
#define MAX_LINES 10000

// Define the maximum number of pages in the book.
#define MAX_PAGES 1000

// Define the structure of a book.
typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char text[MAX_LINES][MAX_LINE_LENGTH];
    int num_lines;
    int num_pages;
} Book;

// Function to read a book from a file.
Book* read_book(char* filename) {
    // Allocate memory for the book.
    Book* book = (Book*)malloc(sizeof(Book));

    // Open the file.
    FILE* bookFile = fopen(filename, "r");
    if (bookFile == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the title of the book.
    fgets(book->title, MAX_LINE_LENGTH, bookFile);

    // Read the author of the book.
    fgets(book->author, MAX_LINE_LENGTH, bookFile);

    // Read the text of the book.
    int line = 0;
    while (fgets(book->text[line], MAX_LINE_LENGTH, bookFile) != NULL) {
        line++;
    }

    // Close the file.
    fclose(bookFile);

    // Set the number of lines in the book.
    book->num_lines = line;

    // Set the number of pages in the book.
    book->num_pages = line / 50;

    // Return the book.
    return book;
}

// Function to print a book to the console.
void print_book(Book* book) {
    // Print the title of the book.
    printf("%s\n", book->title);

    // Print the author of the book.
    printf("%s\n", book->author);

    // Print the text of the book.
    for (int i = 0; i < book->num_lines; i++) {
        printf("%s\n", book->text[i]);
    }
}

// Function to free the memory allocated for a book.
void free_book(Book* book) {
    // Free the memory allocated for the book.
    free(book);
}

#define STR_LEN (20 + 10)
char *to_lower(char *s) {
	int i = 0;
	while (s[i] != '\0') {
		s[i] = tolower(s[i]);
		i++;
	}
	return s;
}

int main() {
  char book_title[STR_LEN];
  char search_term[STR_LEN];
  char *book_content = NULL;
  int word_cnt = 0;

  printf("Hello! Welcome to the E-Book Reader!\n");
  printf("Please enter the name of the book you want to read:\n");
  scanf("%s", book_title);

  // Read the book from the file.
  Book* book = read_book(book_title);
  if (book == NULL) {
    printf("Error reading book %s\n", book_title);
    return 1;
  }
  book_content = strcat(book->title, book->text);
  
  printf("Please enter the search term:\n");
  scanf("%s", search_term);

  // Convert the search term to lowercase for case-insensitive search.
  to_lower(search_term);

  // Search for the search term in the book.
  int found = 0;
  for (int i = 0; i < book->num_lines; i++) {
    if (strstr(book->text[i], search_term) != NULL) {
      found = 1;
      word_cnt++;
    }
  }

  // Print the results of the search.
  if (found) {
    printf("The search term '%s' was found %d times in the book '%s'.\n", search_term, word_cnt, book_title);
  } else {
    printf("The search term '%s' was not found in the book '%s'.\n", search_term, book_title);
  }

  // Free the memory allocated for the book.
  free_book(book);

  return 0;
}