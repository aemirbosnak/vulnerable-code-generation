//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 1024  // Number of characters displayed per page

void displayPage(char *content, int page, int pageSize) {
    int start = page * pageSize;
    int end = start + pageSize;

    if (content[start] == '\0') {
        printf("You've reached the end of the book! 🎉\n");
        return;
    }

    // Print the page content
    printf("📖 Page %d:\n", page + 1);
    for (int i = start; i < end && content[i] != '\0'; i++) {
        putchar(content[i]);
    }
    printf("\n\n");

    // Check if there is more content to display
    if (content[end] != '\0') {
        printf("Press 'n' for next page, 'q' to quit, or 'p' for previous page: ");
    } else {
        printf("Press 'q' to quit or 'p' for previous page: ");
    }
}

int main() {
    FILE *file;
    char *content = (char *)malloc(PAGE_SIZE * 100); // Assume book is under 100 pages
    int currentPage = 0;

    // Open the book
    file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Oops! The book file can't be found! 📚\n");
        return 1;
    }

    // Read the entire book content
    fread(content, sizeof(char), PAGE_SIZE * 100, file);
    fclose(file);

    char choice;
    do {
        displayPage(content, currentPage, PAGE_SIZE);

        // Get user input
        choice = getchar();
        getchar(); // Consume newline character

        switch (choice) {
            case 'n':
                currentPage++;
                break;
            case 'p':
                if (currentPage > 0) {
                    currentPage--;
                }
                break;
            case 'q':
                printf("Thank you for reading! Goodbye! 🌈\n");
                break;
            default:
                printf("That's not a valid choice! Please try again! 😊\n");
                break;
        }
        
        // Clear the screen for next display
        printf("\033[H\033[J"); // ANSI escape code to clear the screen
    } while (choice != 'q');

    free(content);
    return 0;
}