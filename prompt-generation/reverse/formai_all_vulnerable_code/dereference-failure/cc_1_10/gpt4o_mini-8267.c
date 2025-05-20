//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGE_SIZE 512
#define MAX_TITLE_SIZE 100

typedef struct {
    char title[MAX_TITLE_SIZE];
    char content[MAX_PAGE_SIZE];
} Page;

typedef struct {
    Page *pages;
    int totalPages;
    int currentPage;
} Ebook;

// Function to clear the console
void clearConsole() {
    printf("\033[H\033[J");
}

// Function to load an ebook from a file
Ebook* loadEbook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file. Please ensure the file exists.\n");
        return NULL;
    }

    Ebook *ebook = (Ebook *)malloc(sizeof(Ebook));
    ebook->totalPages = 0;
    ebook->currentPage = 0;
    ebook->pages = malloc(sizeof(Page) * 100); // Assume a max of 100 pages for simplicity

    while (fgets(ebook->pages[ebook->totalPages].content, MAX_PAGE_SIZE, file)) {
        // Trim and set title for the current page
        snprintf(ebook->pages[ebook->totalPages].title, MAX_TITLE_SIZE, "Page %d", ebook->totalPages + 1);
        ebook->totalPages++;
    }

    fclose(file);
    return ebook;
}

// Function to display the current page
void displayPage(Ebook *ebook) {
    clearConsole();
    printf("------ %s ------\n", ebook->pages[ebook->currentPage].title);
    printf("%s\n", ebook->pages[ebook->currentPage].content);
    printf("------------------\n");
    printf("Commands: [n] Next, [p] Previous, [q] Quit\n");
}

// Function to handle user input for navigation
void navigateEbook(Ebook *ebook) {
    char command;
    while (1) {
        displayPage(ebook);
        printf("Enter command: ");
        command = getchar();
        getchar(); // Cleans up the newline character left in the buffer

        if (command == 'n' && ebook->currentPage < ebook->totalPages - 1) {
            ebook->currentPage++;
        } else if (command == 'p' && ebook->currentPage > 0) {
            ebook->currentPage--;
        } else if (command == 'q') {
            printf("Exiting the Ebook Reader. Happy Reading!\n");
            break;
        } else {
            printf("Invalid command! Try again.\n");
        }
    }
}

// Function to clean up the ebook
void freeEbook(Ebook *ebook) {
    free(ebook->pages);
    free(ebook);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path-to-ebook.txt>\n", argv[0]);
        return 1;
    }

    Ebook *myEbook = loadEbook(argv[1]);
    if (myEbook) {
        navigateEbook(myEbook);
        freeEbook(myEbook);
    }

    return 0;
}