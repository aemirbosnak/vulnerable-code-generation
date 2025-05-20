//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of books in the library
#define NUM_BOOKS 100

// Define the book structure
struct book {
  char title[50];
  char author[50];
  int quantity;
  int available;
  struct book* next;
};

// Define the library management functions
void insertBook(struct book** head);
void searchBook(struct book* head);
void updateBook(struct book* head);
void deleteBook(struct book* head);

int main() {
  // Create the library head
  struct book* head = NULL;

  // Insert some books into the library
  insertBook(&head);
  insertBook(&head);
  insertBook(&head);

  // Search for a book
  searchBook(head);

  // Update a book
  updateBook(head);

  // Delete a book
  deleteBook(head);

  return 0;
}

void insertBook(struct book** head) {
  // Allocate memory for a new book
  struct book* newBook = (struct book*)malloc(sizeof(struct book));

  // Get the book's title, author, and quantity
  printf("Enter book title: ");
  scanf("%s", newBook->title);

  printf("Enter book author: ");
  scanf("%s", newBook->author);

  printf("Enter book quantity: ");
  scanf("%d", &newBook->quantity);

  newBook->available = 1;
  newBook->next = NULL;

  // If the library is empty, make the new book the first book
  if (*head == NULL) {
    *head = newBook;
  } else {
    // Traverse the library to the last book and insert the new book there
    struct book* lastBook = *head;
    while (lastBook->next != NULL) {
      lastBook = lastBook->next;
    }
    lastBook->next = newBook;
  }
}

void searchBook(struct book* head) {
  // Get the book's title
  printf("Enter book title: ");
  char title[50];
  scanf("%s", title);

  // Search for the book
  struct book* book = head;
  while (book) {
    if (strcmp(book->title, title) == 0) {
      // Display the book's information
      printf("Book title: %s\n", book->title);
      printf("Book author: %s\n", book->author);
      printf("Book quantity: %d\n", book->quantity);
      printf("Book available: %d\n", book->available);
      break;
    }
    book = book->next;
  }

  // If the book is not found, display an error message
  if (book == NULL) {
    printf("Book not found.\n");
  }
}

void updateBook(struct book* head) {
  // Get the book's title
  printf("Enter book title: ");
  char title[50];
  scanf("%s", title);

  // Search for the book
  struct book* book = head;
  while (book) {
    if (strcmp(book->title, title) == 0) {
      // Update the book's information
      printf("Enter new book title: ");
      scanf("%s", book->title);

      printf("Enter new book author: ");
      scanf("%s", book->author);

      printf("Enter new book quantity: ");
      scanf("%d", &book->quantity);

      break;
    }
    book = book->next;
  }

  // If the book is not found, display an error message
  if (book == NULL) {
    printf("Book not found.\n");
  }
}

void deleteBook(struct book* head) {
  // Get the book's title
  printf("Enter book title: ");
  char title[50];
  scanf("%s", title);

  // Search for the book
  struct book* book = head;
  struct book* prevBook = NULL;
  while (book) {
    if (strcmp(book->title, title) == 0) {
      // Delete the book
      if (prevBook) {
        prevBook->next = book->next;
      } else {
        head = book->next;
      }
      free(book);
      break;
    }
    prevBook = book;
    book = book->next;
  }

  // If the book is not found, display an error message
  if (book == NULL) {
    printf("Book not found.\n");
  }
}