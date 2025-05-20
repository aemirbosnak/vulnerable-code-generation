//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 10

typedef struct book {
  char title[50];
  char author[50];
  int quantity;
  struct book* next;
} book;

book* insertBook(book* head) {
  book* newNode = (book*)malloc(sizeof(book));
  printf("Enter book title: ");
  scanf("%s", newNode->title);
  printf("Enter book author: ");
  scanf("%s", newNode->author);
  printf("Enter book quantity: ");
  scanf("%d", &newNode->quantity);
  newNode->next = head;
  return newNode;
}

book* searchBook(book* head, char* title) {
  book* currentBook = head;
  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      return currentBook;
    }
    currentBook = currentBook->next;
  }
  return NULL;
}

void updateBookQuantity(book* book, int newQuantity) {
  book->quantity = newQuantity;
}

void deleteBook(book* head, book* bookToDelete) {
  book* previousBook = NULL;
  book* currentBook = head;
  while (currentBook) {
    if (currentBook == bookToDelete) {
      if (previousBook) {
        previousBook->next = currentBook->next;
      } else {
        head = currentBook->next;
      }
      free(currentBook);
      return;
    }
    previousBook = currentBook;
    currentBook = currentBook->next;
  }
  printf("Book not found.");
}

int main() {
  book* head = NULL;
  head = insertBook(head);
  head = insertBook(head);
  head = insertBook(head);

  book* bookToSearch = searchBook(head, "Book 2");
  if (bookToSearch) {
    printf("Book title: %s", bookToSearch->title);
    printf("Book author: %s", bookToSearch->author);
    printf("Book quantity: %d", bookToSearch->quantity);
  } else {
    printf("Book not found.");
  }

  updateBookQuantity(bookToSearch, 10);

  deleteBook(head, bookToSearch);

  book* remainingBooks = head;
  while (remainingBooks) {
    printf("Book title: %s", remainingBooks->title);
    printf("Book author: %s", remainingBooks->author);
    printf("Book quantity: %d\n", remainingBooks->quantity);
    remainingBooks = remainingBooks->next;
  }

  return 0;
}