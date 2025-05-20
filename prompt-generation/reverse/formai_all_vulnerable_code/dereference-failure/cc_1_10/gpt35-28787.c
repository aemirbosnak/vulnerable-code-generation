//FormAI DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKMARKS 10

// Function to display a welcome message
void displayWelcomeMessage() {
    printf("Welcome to C Ebook Reader!\n");
}

// Function for displaying the main menu
void displayMainMenu() {
    printf("1. Open Ebook\n");
    printf("2. View Bookmarks\n");
    printf("3. Exit\n");
}

// Function for opening an Ebook
void openEbook(char *filename) {
    FILE *fp;
    char ch;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening ebook!\n");
        return;
    }
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

// Function for adding a bookmark
void addBookmark(char **bookmarks, char *filename, int *numBookmarks) {
    if (*numBookmarks >= MAX_BOOKMARKS) {
        printf("Maximum number of bookmarks reached!\n");
        return;
    }
    bookmarks[*numBookmarks] = filename;
    (*numBookmarks)++;
    printf("Bookmark added successfully!\n");
}

// Function for viewing bookmarks
void viewBookmarks(char **bookmarks, int numBookmarks) {
    if (numBookmarks == 0) {
        printf("No bookmarks found!\n");
        return;
    }
    printf("Bookmarks:\n");
    for (int i = 0; i < numBookmarks; i++) {
        printf("%d. %s\n", i+1, bookmarks[i]);
    }
}

int main() {
    char **bookmarks;
    int numBookmarks = 0;
    int choice;
    char filename[50];
    displayWelcomeMessage();
    bookmarks = (char **)malloc(MAX_BOOKMARKS * sizeof(char *));
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter ebook filename: ");
                scanf("%s", filename);
                openEbook(filename);
                printf("Do you want to add a bookmark? (y/n): ");
                char answer;
                scanf(" %c", &answer);
                if (answer == 'y') {
                    addBookmark(bookmarks, filename, &numBookmarks);
                }
                break;
            case 2:
                viewBookmarks(bookmarks, numBookmarks);
                break;
            case 3:
                printf("Exiting C Ebook Reader...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    free(bookmarks);
    return 0;
}