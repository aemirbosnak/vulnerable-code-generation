//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOOK_NAME 20
#define MAX_AUTHOR_NAME 20
#define MAX_PAGES 100

// Declare global variables
int currentPage = 0;
int totalPages = 0;
char bookName[MAX_BOOK_NAME];
char authorName[MAX_AUTHOR_NAME];

// Function to display the book's cover
void showCover() {
    printf("📚👀");
}

// Function to display the book's title and author
void showTitleAndAuthor() {
    printf("📚 %s by %s\n", bookName, authorName);
}

// Function to display the current page number
void showCurrentPage() {
    printf("Page %d of %d\n", currentPage, totalPages);
}

// Function to advance to the next page
void advanceToNextPage() {
    currentPage++;
    showCurrentPage();
}

// Function to go back to the previous page
void goBackToPreviousPage() {
    currentPage--;
    showCurrentPage();
}

// Function to calculate the total number of pages
void calculateTotalPages() {
    totalPages = (int)((float)strlen(bookName) / 10.0) + 1;
}

int main() {
    // Initialize book name and author name
    strcpy(bookName, "The Adventures of Sherlock Holmes");
    strcpy(authorName, "Sir Arthur Conan Doyle");

    // Display the book's cover
    showCover();

    // Display the book's title and author
    showTitleAndAuthor();

    // Calculate the total number of pages
    calculateTotalPages();

    // Display the current page number
    showCurrentPage();

    // Advance to the next page
    advanceToNextPage();

    // Go back to the previous page
    goBackToPreviousPage();

    // Advance to the next page
    advanceToNextPage();

    // Go back to the previous page
    goBackToPreviousPage();

    return 0;
}