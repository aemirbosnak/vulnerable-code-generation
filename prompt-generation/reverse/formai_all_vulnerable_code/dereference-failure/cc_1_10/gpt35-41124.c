//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000
#define MAX_TITLE_LENGTH 100

// Book struct
typedef struct {
    char title[MAX_TITLE_LENGTH];
    int book_id;
} Book;

// Initialize books array
Book books[MAX_BOOKS] = { {"Romeo and Juliet", 1}, {"Macbeth", 2}, {"Hamlet", 3}, {"Othello", 4},
                          {"King Lear", 5}, {"Merchant of Venice", 6}, {"Midsummer Night's Dream", 7} };

// Function to print all books in the library
void printLibrary() {
    printf("Books in the library:\n");
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (strlen(books[i].title) > 0) {
            printf("%d - %s\n", books[i].book_id, books[i].title);
        }
    }
    printf("\n");
}

// Function to create an index table for books based on the first letter of their title
void createIndex(char indexTable[]) {
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (strlen(books[i].title) > 0) {
            // Store the first letter of the book's title in the index table (lowercase)
            indexTable[tolower(books[i].title[0])] = i+1;
        }
    }
}

// Function to search for books in the library based on the first letter of their title
void searchLibrary(char indexTable[]) {
    char searchKey;
    printf("Enter the first letter of the book title to search for: ");
    scanf(" %c", &searchKey);
    if (indexTable[tolower(searchKey)] > 0) {
        printf("\nThe following books were found:\n");
        for (int i = 0; i < MAX_BOOKS; i++) {
            if (books[i].book_id == indexTable[tolower(searchKey)]) {
                printf("%s\n", books[i].title);
            }
        }
    } else {
        printf("No books found.\n");
    }
}

int main(void) {
    char indexTable[26] = {0}; // Initialize index table to all 0s (no books)
    createIndex(indexTable);

    // Welcome message
    printf("Welcome to the Romeo and Juliet Library System!\n");
    printf("---------------------------------------------\n");

    // Loop menu
    int menuChoice = 0;
    while (menuChoice != 3) {
        printf("Main Menu:\n");
        printf("1. View all books\n");
        printf("2. Search for books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);
        printf("\n");

        switch(menuChoice) {
            case 1:
                printLibrary();
                break;
            case 2:
                searchLibrary(indexTable);
                break;
            case 3:
                printf("Thank you for using the Romeo and Juliet Library System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}