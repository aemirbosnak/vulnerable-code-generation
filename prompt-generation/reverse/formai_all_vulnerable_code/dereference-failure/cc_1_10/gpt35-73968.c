//FormAI DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char title[50];
  char author[50];
  int year;
  char filePath[100];
} Book;

void printBookInfo(Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Year: %d\n", book->year);
  printf("FilePath: %s\n", book->filePath);
}

int main() {
  char fileName[100];
  Book *library = NULL;
  int numBooks = 0;

  while (1) {
    // Prompt the user for input
    printf("Enter the path to a .ebook file or type \"quit\" to exit: ");
    scanf("%s", fileName);

    // Exit the loop if the user types "quit"
    if (strcmp(fileName, "quit") == 0) {
      break;
    }

    // Allocate memory for a new Book object
    Book *newBook = (Book *) malloc(sizeof(Book));

    // Open the file as read-only
    FILE *file = fopen(fileName, "r");

    // Read the book's information from the file
    fgets(newBook->title, 50, file);
    fgets(newBook->author, 50, file);
    fscanf(file, "%d\n", &newBook->year);
    fgets(newBook->filePath, 100, file);

    // Close the file
    fclose(file);

    // Add the book to the library
    numBooks++;
    library = (Book *) realloc(library, numBooks * sizeof(Book));
    library[numBooks - 1] = *newBook;

    // Free the memory used by the newBook variable
    free(newBook);
  }

  printf("\n\nLibrary Contents:\n\n");
  for (int i = 0; i < numBooks; i++) {
    printBookInfo(&library[i]);
    printf("\n");
  }

  // Free the memory used by the library variable
  free(library);

  return 0;
}