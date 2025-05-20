//FormAI DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to represent an ebook
typedef struct EBook {
  char title[50];
  char author[50];
  int pageCount;
  char* content;
} EBook;

// define a function to read an ebook's content from a file
void readEBookContentFromFile(char* filename, char** content) {
  FILE* ebookFile = fopen(filename, "r");
  if (ebookFile == NULL) {
    printf("Error: could not open file %s\n", filename);
    exit(1);
  }
  fseek(ebookFile, 0, SEEK_END);
  long fileSize = ftell(ebookFile);
  rewind(ebookFile);
  *content = (char*) malloc(sizeof(char) * (fileSize + 1));
  fread(*content, sizeof(char), fileSize, ebookFile);
  fclose(ebookFile);
  (*content)[fileSize] = '\0';
}

// define a function to display an ebook
void printEBook(EBook ebook) {
  printf("Title: %s\n", ebook.title);
  printf("Author: %s\n", ebook.author);
  printf("Page Count: %d\n", ebook.pageCount);
  printf("Content: %s\n", ebook.content);
}

// define main function
int main() {
  // define an Ebook variable and set its fields
  EBook ebook;
  strcpy(ebook.title, "The Adventures of Sherlock Holmes");
  strcpy(ebook.author, "Arthur Conan Doyle");
  ebook.pageCount = 307;
  readEBookContentFromFile("sherlock.txt", &ebook.content);

  // display the Ebook
  printf("Displaying ebook...\n");
  printf("--------------------\n");
  printEBook(ebook);

  // free the memory allocated for the Ebook's content
  free(ebook.content);

  return 0;
}