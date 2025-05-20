//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define the library management structure
typedef struct LibraryManagement {
  char title[50];
  char author[50];
  int quantity;
  struct LibraryManagement* next;
} LibraryManagement;

// Create a linked list of library management structures
LibraryManagement* head = NULL;

// Function to insert a new book into the library
void insertBook(char* title, char* author, int quantity) {
  // Allocate memory for the new book structure
  LibraryManagement* newBook = (LibraryManagement*)malloc(sizeof(LibraryManagement));

  // Copy the book title and author into the structure
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->quantity = quantity;

  // Set the next pointer of the new book to NULL
  newBook->next = NULL;

  // If the head of the list is NULL, then make the new book the head
  if (head == NULL) {
    head = newBook;
  } else {
    // Traverse the list until the last book is reached
    LibraryManagement* lastBook = head;
    while (lastBook->next) {
      lastBook = lastBook->next;
    }

    // Insert the new book at the end of the list
    lastBook->next = newBook;
  }
}

// Function to search for a book in the library
LibraryManagement* searchBook(char* title) {
  // Traverse the list of books
  LibraryManagement* book = head;
  while (book) {
    // Check if the book title is equal to the search title
    if (strcmp(book->title, title) == 0) {
      return book;
    }
    book = book->next;
  }

  // Return NULL if the book is not found
  return NULL;
}

// Function to update the quantity of a book in the library
void updateBookQuantity(char* title, int newQuantity) {
  // Search for the book in the library
  LibraryManagement* book = searchBook(title);

  // If the book is found, update its quantity
  if (book) {
    book->quantity = newQuantity;
  }
}

// Function to delete a book from the library
void deleteBook(char* title) {
  // Search for the book in the library
  LibraryManagement* book = searchBook(title);

  // If the book is found, delete it from the list
  if (book) {
    // If the book is the head of the list, update the head of the list
    if (book == head) {
      head = book->next;
    } else {
      // Traverse the list until the book is found
      LibraryManagement* previousBook = head;
      while (previousBook->next != book) {
        previousBook = previousBook->next;
      }

      // Delete the book from the list
      previousBook->next = book->next;
    }

    // Free the memory allocated for the book structure
    free(book);
  }
}

int main() {
  // Insert some books into the library
  insertBook("The Lord of the Flies", "William Golding", 10);
  insertBook("To Kill a Mockingbird", "Harper Lee", 15);
  insertBook("The Great Gatsby", "F. Scott Fitzgerald", 8);

  // Search for a book in the library
  LibraryManagement* book = searchBook("To Kill a Mockingbird");
  if (book) {
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book quantity: %d\n", book->quantity);
  }

  // Update the quantity of a book in the library
  updateBookQuantity("The Lord of the Flies", 12);

  // Delete a book from the library
  deleteBook("The Great Gatsby");

  // Search for the book after deletion
  book = searchBook("The Great Gatsby");
  if (book) {
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book quantity: %d\n", book->quantity);
  } else {
    printf("Book not found.\n");
  }

  return 0;
}