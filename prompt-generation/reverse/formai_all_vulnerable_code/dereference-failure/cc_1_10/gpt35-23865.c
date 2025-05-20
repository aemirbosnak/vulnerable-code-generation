//FormAI DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for storing book info
typedef struct {
    char title[50];
    char author[50];
    int year;
    int pages;
    char filename[50];
} book;

// Function to print book info
void printBook(book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Year: %d\n", b.year);
    printf("Pages: %d\n", b.pages);
    printf("Filename: %s\n", b.filename);
}

int main() {

    int choice;
    int numBooks = 0;
    book* myBooks = NULL;

    // Display welcome message
    printf("Welcome to the Cyberpunk Ebook Reader!\n\n");

    // Main menu loop
    do {
        printf("Please choose an option:\n");
        printf("1. Add book\n");
        printf("2. View book\n");
        printf("3. Exit\n");

        // Get user input
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add book function
                printf("Please enter the book title:\n");
                char title[50];
                scanf("%s", title);

                printf("Please enter the book author:\n");
                char author[50];
                scanf("%s", author);

                printf("Please enter the publication year:\n");
                int year;
                scanf("%d", &year);

                printf("Please enter the number of pages:\n");
                int pages;
                scanf("%d", &pages);

                printf("Please enter the filename (including file extension):\n");
                char filename[50];
                scanf("%s", filename);

                // Create book struct and add to array
                book newBook;
                strcpy(newBook.title, title);
                strcpy(newBook.author, author);
                newBook.year = year;
                newBook.pages = pages;
                strcpy(newBook.filename, filename);

                numBooks++;
                myBooks = realloc(myBooks, numBooks * sizeof(book));
                myBooks[numBooks - 1] = newBook;

                printf("Book added successfully!\n\n");
                break;

            case 2:
                // View book function
                if(numBooks == 0) {
                    printf("No books added yet.\n\n");
                    break;
                }

                printf("Please enter the book title:\n");
                char viewTitle[50];
                scanf("%s", viewTitle);

                int found = 0;

                // Search book array for matching title
                for(int i = 0; i < numBooks; i++) {
                    if(strcmp(myBooks[i].title, viewTitle) == 0) {
                        printBook(myBooks[i]);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("Book not found.\n\n");
                }
                break;

            case 3:
                // Exit program
                printf("Thank you for using the Cyberpunk Ebook Reader!\n");
                free(myBooks);
                return 0;

            default:
                printf("Invalid choice.\n\n");
                break;
        }
    } while(choice != 3);

    return 0;
}