//FormAI DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants for file paths and max lengths */
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOKSHELF_CAPACITY 100
#define PATH_TO_CATALOG "catalog.txt"
#define PATH_TO_SAVED_BOOKS "saved_books.txt"

/* Define a struct for the Book */
typedef struct {
  char title[MAX_TITLE_LENGTH];
  char author[MAX_AUTHOR_LENGTH];
  int num_pages;
  int current_page;
} Book;

/* Define a struct for the Bookshelf */
typedef struct {
  int num_books;
  Book books[MAX_BOOKSHELF_CAPACITY];
} Bookshelf;

/* Save the Bookshelf to a file */
void save_bookshelf(Bookshelf *shelf) {
  FILE *file = fopen(PATH_TO_SAVED_BOOKS, "w");
  
  for (int i = 0; i < shelf->num_books; i++) {
    fprintf(file, "%s,%s,%d,%d\n", shelf->books[i].title, shelf->books[i].author, shelf->books[i].num_pages, shelf->books[i].current_page);
  }
  
  fclose(file);
}

/* Load the Bookshelf from a file */
void load_bookshelf(Bookshelf *shelf) {
  FILE *file = fopen(PATH_TO_SAVED_BOOKS, "r");
  
  char line[MAX_TITLE_LENGTH + MAX_AUTHOR_LENGTH + 15];
  char *token;
  
  while (fgets(line, MAX_TITLE_LENGTH + MAX_AUTHOR_LENGTH + 15, file) != NULL) {
    token = strtok(line, ",");
    strcpy(shelf->books[shelf->num_books].title, token);
    
    token = strtok(NULL, ",");
    strcpy(shelf->books[shelf->num_books].author, token);
    
    token = strtok(NULL, ",");
    shelf->books[shelf->num_books].num_pages = atoi(token);
    
    token = strtok(NULL, ",");
    shelf->books[shelf->num_books].current_page = atoi(token);
    
    shelf->num_books++;
  }
  
  fclose(file);
}

/* Add a Book to the Bookshelf */
void add_book(Bookshelf *shelf, char *title, char *author, int num_pages, int current_page) {
  if (shelf->num_books < MAX_BOOKSHELF_CAPACITY) {
    strcpy(shelf->books[shelf->num_books].title, title);
    strcpy(shelf->books[shelf->num_books].author, author);
    shelf->books[shelf->num_books].num_pages = num_pages;
    shelf->books[shelf->num_books].current_page = current_page;
    shelf->num_books++;
    
    printf("Book added to Bookshelf!\n");
  } else {
    printf("Bookshelf is full! Cannot add book.\n");
  }
}

/* Display information about all Books in the Bookshelf */
void display_all_books(Bookshelf *shelf) {
  printf("Title, Author, Pages, Current Page\n");
  
  for (int i = 0; i < shelf->num_books; i++) {
    printf("%s, %s, %d, %d\n", shelf->books[i].title, shelf->books[i].author, shelf->books[i].num_pages, shelf->books[i].current_page);
  }
}

/* Let the user read a Book */
void read_book(Bookshelf *shelf) {
  int book_index;
  printf("Which book would you like to read? Enter the book number: ");
  scanf("%d", &book_index);
  
  if (book_index >= 0 && book_index < shelf->num_books) {
    printf("Reading %s...\n", shelf->books[book_index].title);
    printf("You are currently on page %d of %d.\n", shelf->books[book_index].current_page, shelf->books[book_index].num_pages);
    printf("What page would you like to go to? Enter the page number: ");
    scanf("%d", &shelf->books[book_index].current_page);
    printf("You are now on page %d.\n", shelf->books[book_index].current_page);
    
    save_bookshelf(shelf);
  } else {
    printf("Invalid book number.\n");
  }
}

/* Let the user search for a Book */
void search_books(Bookshelf *shelf) {
  char search_title[MAX_TITLE_LENGTH];
  printf("Enter a title to search for: ");
  scanf("%s", search_title);
  
  for (int i = 0; i < shelf->num_books; i++) {
    if (strstr(shelf->books[i].title, search_title) != NULL) {
      printf("'%s' by %s, pages: %d, current page: %d\n", shelf->books[i].title, shelf->books[i].author, shelf->books[i].num_pages, shelf->books[i].current_page);
    }
  }
}

/* Main program loop */
int main () {
  int choice;
  Bookshelf shelf = {0};
  
  load_bookshelf(&shelf);
  
  do {
    printf("What would you like to do?\n");
    printf("1. Add a book\n");
    printf("2. Display all books\n");
    printf("3. Read a book\n");
    printf("4. Search for a book\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        printf("Enter the book title: ");
        char title[MAX_TITLE_LENGTH];
        scanf("%s", title);
        
        printf("Enter the book author: ");
        char author[MAX_AUTHOR_LENGTH];
        scanf("%s", author);
        
        printf("Enter the number of pages in the book: ");
        int num_pages;
        scanf("%d", &num_pages);
        
        printf("Enter the current page you are on: ");
        int current_page;
        scanf("%d", &current_page);
        
        add_book(&shelf, title, author, num_pages, current_page);
        save_bookshelf(&shelf);
        break;
      case 2:
        display_all_books(&shelf);
        break;
      case 3:
        read_book(&shelf);
        break;
      case 4:
        search_books(&shelf);
        break;
      case 0:
        save_bookshelf(&shelf);
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  } while (choice != 0);
  
  return 0;
}