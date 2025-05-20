//FormAI DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int numOfPages = 0;

struct page {
  int pageNumber;
  char content[1000];
  struct page* next;
};

struct page* startPage = NULL;
struct page* currentPage = NULL;

// Function to create a new page
struct page* createPage(int pageNumber, char content[]) {
  struct page* newPage = (struct page*)malloc(sizeof(struct page));
  newPage->pageNumber = pageNumber;
  strcpy(newPage->content, content);
  newPage->next = NULL;

  return newPage;
}

// Function to add new page at the end of the book
void addNewPage(char content[]) {
  struct page* newPage = createPage(numOfPages + 1, content);

  if (startPage == NULL) {
    startPage = newPage;
    currentPage = newPage;
  } else {
    currentPage->next = newPage;
    currentPage = newPage;
  }

  numOfPages++;
}

// Function to read a specific page
void readPage(int pageNumber) {
  struct page* pageToRead = startPage;

  while (pageToRead != NULL) {
    if (pageToRead->pageNumber == pageNumber) {
      printf("Page %d\n", pageNumber);
      printf("%s\n", pageToRead->content);
      break;
    }

    pageToRead = pageToRead->next;
  }
}

// Function to read the entire book
void readBook() {
  struct page* pageToRead = startPage;

  while (pageToRead != NULL) {
    printf("Page %d\n", pageToRead->pageNumber);
    printf("%s\n", pageToRead->content);

    pageToRead = pageToRead->next;
  }
}

int main() {
  // Add some sample pages to the book
  addNewPage("This is the content of page 1.");
  addNewPage("This is the content of page 2.");
  addNewPage("This is the content of page 3.");

  // Read a specific page
  readPage(2);

  // Read the entire book
  readBook();

  return 0;
}