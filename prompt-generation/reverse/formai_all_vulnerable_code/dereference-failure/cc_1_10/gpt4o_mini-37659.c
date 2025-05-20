//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 255
#define MAX_CONTENT_LENGTH 2048

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

void displayBook(const Book *book) {
    printf("\n--- %s ---\n", book->title);
    printf("%s\n", book->content);
}

void loadBook(const char *filename, Book *book) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    fgets(book->title, MAX_TITLE_LENGTH, file);
    book->title[strcspn(book->title, "\n")] = 0; // Remove newline character
    
    fread(book->content, sizeof(char), MAX_CONTENT_LENGTH, file);
    fclose(file);
}

void printMenu() {
    printf("\n--- E-Book Reader Menu ---\n");
    printf("1. Read Book\n");
    printf("2. Exit\n");
    printf("Please enter your choice: ");
}

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    char filename[MAX_TITLE_LENGTH];

    // Load books from files
    for (int i = 0; i < MAX_BOOKS; i++) {
        snprintf(filename, sizeof(filename), "book%d.txt", i + 1);
        FILE *file = fopen(filename, "r");
        if (file == NULL) break;  // Stop if no more files
        
        loadBook(filename, &library[bookCount]);
        bookCount++;
        fclose(file);
    }

    int choice;
    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar();  // Consume newline character
        if (choice == 2) {
            printf("Exiting the E-Book Reader. Thank you!\n");
            break;
        }
        if (choice < 1 || choice > bookCount) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        
        displayBook(&library[choice - 1]);
    }

    return 0;
}