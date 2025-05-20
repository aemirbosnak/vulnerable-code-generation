//FormAI DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

typedef struct {
   char title[MAX_TITLE_LENGTH];
   char author[MAX_AUTHOR_LENGTH];
   char filename[100];
} Book;

void load_books(Book books[], int *num_books);
void display_menu();
void display_books(Book books[], int num_books);
void read_book(Book book);
void error(char *message);

int main() {
   Book books[MAX_BOOKS];
   int num_books = 0, choice = 0;

   // Load the books from the file
   load_books(books, &num_books);

   // Display the menu until the user chooses to exit
   while (choice != 3) {
      display_menu();
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            display_books(books, num_books);
            break;
         case 2:
            read_book(books[0]);  // Temporarily read first book only
            break;
         case 3:
            printf("Thank you for using our Ebook reader.\n");
            break;
         default:
            printf("Invalid choice. Please try again.\n");
            break;
      }
   }

   return 0;
}

/**
 * Load the books from the file into the array
 */
void load_books(Book books[], int *num_books) {
   FILE *fp = NULL;
   char filename[100];
   char line[200];
   char *token;

   // Prompt user for filename
   printf("Please enter the name of the file containing the books: ");
   scanf("%s", filename);

   // Open the file for reading
   fp = fopen(filename, "r");
   if (fp == NULL) {
      error("Could not open file");
   }

   // Read each line of the file and store the book information
   while (fgets(line, 200, fp) != NULL) {
      if (*num_books >= MAX_BOOKS) {
         error("Maximum number of books exceeded");
      }

      token = strtok(line, ",");
      strcpy(books[*num_books].title, token);

      token = strtok(NULL, ",");
      strcpy(books[*num_books].author, token);

      token = strtok(NULL, ",");
      strcpy(books[*num_books].filename, token);

      (*num_books)++;
   }

   // Close the file
   fclose(fp);
}

/**
 * Display the main menu
 */
void display_menu() {
   printf("\nEbook Reader\n");
   printf("============\n");
   printf("1. List all books\n");
   printf("2. Read a book\n");
   printf("3. Exit\n");
   printf("Enter your choice: ");
}

/**
 * Display all the books in the array
 */
void display_books(Book books[], int num_books) {
   int i;

   printf("\nAll Books\n");
   printf("---------\n");
   for (i = 0; i < num_books; i++) {
      printf("%s by %s\n", books[i].title, books[i].author);
   }
}

/**
 * Read a book from the specified file
 */
void read_book(Book book) {
   FILE *fp = NULL;
   char filename[100];
   char line[200];

   // Construct the full filename
   strcpy(filename, "books/");
   strcat(filename, book.filename);

   // Open the file for reading
   fp = fopen(filename, "r");
   if (fp == NULL) {
      error("Could not open file");
   }

   // Read each line of the file and display it to the user
   while (fgets(line, 200, fp) != NULL) {
      printf("%s", line);
   }

   // Close the file
   fclose(fp);
}

/**
 * Display an error message and exit the program
 */
void error(char *message) {
   printf("ERROR: %s\n", message);
   exit(1);
}