//FormAI DATASET v1.0 Category: Ebook reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants and structures
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_pages;
    char *contents;
} Book;

// Function prototypes
void display_menu();
void add_book(Book *library, int *num_books);
void display_books(Book *library, int num_books);
void read_book(Book *library, int num_books);

int main() {
    // Initialize variables
    int choice;
    int num_books = 0;
    Book library[MAX_PAGES];
    
    // Display initial menu and get user input
    display_menu();
    scanf("%d", &choice);
    
    // Loop for menu options
    while (choice != 4) {
        switch (choice) {
            case 1: // Add a new book to the library
                add_book(library, &num_books);
                break;
            case 2: // Display all books in the library
                display_books(library, num_books);
                break;
            case 3: // Read a book from the library
                read_book(library, num_books);
                break;
            default: // Invalid input
                printf("\nInvalid input. Please try again.\n");
                break;
        }
        
        // Display menu again and get new user input
        display_menu();
        scanf("%d", &choice);
    }
    
    // Exit program
    printf("\nExiting Ebook Reader. Goodbye!\n");
    return 0;
}

void display_menu() {
    printf("\nWelcome to the Ebook Reader!\n");
    printf("Please select an option:\n");
    printf("1. Add a book to the library\n");
    printf("2. Display all books in the library\n");
    printf("3. Read a book from the library\n");
    printf("4. Exit Ebook Reader\n");
    printf("Enter choice: ");
}

void add_book(Book *library, int *num_books) {
    // Initialize variables
    Book new_book;
    char temp_contents[MAX_PAGES];
    int i;
    
    // Get book information from user
    printf("\nEnter the title of the book (max %d characters): ", MAX_TITLE_LENGTH);
    scanf(" %[^\n]s", new_book.title);
    printf("Enter the name of the author (max %d characters): ", MAX_AUTHOR_LENGTH);
    scanf(" %[^\n]s", new_book.author);
    printf("Enter the number of pages in the book (max %d pages): ", MAX_PAGES);
    scanf("%d", &new_book.num_pages);
    printf("Enter the contents of the book below:\n");
    for (i = 0; i < new_book.num_pages; i++) {
        printf("Page %d: ", i+1);
        scanf(" %[^\n]s", temp_contents);
        strcat(new_book.contents, temp_contents);
        strcat(new_book.contents, "\n"); // Add new line after each page
    }
    
    // Add book to library and increment number of books
    library[*num_books] = new_book;
    (*num_books)++;
    
    // Confirmation message
    printf("\n%s by %s has been added to the library.\n", new_book.title, new_book.author);
}

void display_books(Book *library, int num_books) {
    // Check if library is empty
    if (num_books <= 0) {
        printf("\nThere are no books in the library.\n");
        return;
    }
    
    // Loop through and display all books in the library
    int i;
    for (i = 0; i < num_books; i++) {
        printf("\nTitle: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Number of pages: %d\n", library[i].num_pages);
    }
}

void read_book(Book *library, int num_books) {
    // Check if library is empty
    if (num_books <= 0) {
        printf("\nThere are no books in the library to read.\n");
        return;
    }
    
    // Get book choice from user
    int book_choice;
    printf("\nEnter the number of the book you want to read: ");
    scanf("%d", &book_choice);
    
    // Check if book choice is valid
    if (book_choice <= 0 || book_choice > num_books) {
        printf("\nInvalid book choice. Please try again.\n");
        return;
    }
    
    // Display book contents and page navigation
    int page_choice = 1;
    int num_pages = library[book_choice-1].num_pages;
    printf("\n%s by %s\n\n", library[book_choice-1].title, library[book_choice-1].author);
    while (page_choice > 0 && page_choice <= num_pages) {
        printf("%s\n", library[book_choice-1].contents + (page_choice-1)*MAX_PAGES);
        printf("\nPage %d of %d. Enter 0 to exit or\n", page_choice, num_pages);
        printf("enter the page number you want to go to: ");
        scanf("%d", &page_choice);
    }
    
    // Exit book
    printf("\nExiting %s by %s.\n", library[book_choice-1].title, library[book_choice-1].author);
}