//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 1000
#define MAX_BOOK_TITLE 256

void clearScreen() {
    printf("\033[H\033[J");
}

void printPage(const char *content, int start) {
    clearScreen();
    printf("=== eBook Reader ===\n\n");
    printf("%s", content + start);
    printf("\n\n Press 'n' for Next Page, 'p' for Previous Page, 's' to Search, or 'q' to Quit.\n");
}

char *loadBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open the book file.\n");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *content = malloc(fileSize + 1);
    fread(content, 1, fileSize, file);
    content[fileSize] = '\0';

    fclose(file);
    return content;
}

void searchInBook(const char *content) {
    char keyword[50];
    printf("Enter keyword to search: ");
    scanf("%49s", keyword);

    char *found = strstr(content, keyword);
    if (found) {
        printf("Keyword '%s' found at position: %ld\n", keyword, found - content);
    } else {
        printf("Keyword '%s' not found in the book.\n", keyword);
    }
}

int main() {
    printf("Welcome to the Exciting eBook Reader!\n");
    
    char bookFilename[MAX_BOOK_TITLE];
    printf("Please enter the book filename you want to read: ");
    scanf("%255s", bookFilename);

    char *bookContent = loadBook(bookFilename);
    if (bookContent == NULL) {
        return 1;
    }

    int start = 0;
    int totalLength = strlen(bookContent);

    while (1) {
        printPage(bookContent, start);

        char command = getchar();
        while (command == '\n' || command == '\r') {
            command = getchar(); // Ignore newlines
        }

        if (command == 'n') {
            start += PAGE_SIZE;
            if (start >= totalLength) {
                start = totalLength - PAGE_SIZE; // Don't go past the end
            }
        } else if (command == 'p') {
            start -= PAGE_SIZE;
            if (start < 0) {
                start = 0; // Don't go before the beginning
            }
        } else if (command == 's') {
            searchInBook(bookContent);
            printf("Press Enter to continue...");
            getchar(); // Wait for user to press Enter
        } else if (command == 'q') {
            printf("Thank you for using the eBook Reader! Goodbye!\n");
            break;
        }
    }

    free(bookContent);
    return 0;
}