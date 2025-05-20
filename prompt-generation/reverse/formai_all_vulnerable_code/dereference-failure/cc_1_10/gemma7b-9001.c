//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 10

typedef struct Book {
  char title[50];
  char author[50];
  int quantity;
  struct Book* next;
} Book;

typedef struct Member {
  char name[50];
  char email[50];
  struct Member* next;
} Member;

Book* createBook(char* title, char* author, int quantity) {
  Book* newBook = (Book*)malloc(sizeof(Book));
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  newBook->quantity = quantity;
  newBook->next = NULL;
  return newBook;
}

Member* createMember(char* name, char* email) {
  Member* newMember = (Member*)malloc(sizeof(Member));
  strcpy(newMember->name, name);
  strcpy(newMember->email, email);
  newMember->next = NULL;
  return newMember;
}

int main() {
  Book* headBook = NULL;
  Member* headMember = NULL;

  // Create a book
  Book* newBook = createBook("The Lord of the Flies", "William Golding", 5);
  headBook = newBook;

  // Create a member
  Member* newMember = createMember("John Doe", "john.doe@example.com");
  headMember = newMember;

  // Display book information
  printf("Book title: %s\n", headBook->title);
  printf("Book author: %s\n", headBook->author);
  printf("Book quantity: %d\n", headBook->quantity);

  // Display member information
  printf("Member name: %s\n", headMember->name);
  printf("Member email: %s\n", headMember->email);

  return 0;
}