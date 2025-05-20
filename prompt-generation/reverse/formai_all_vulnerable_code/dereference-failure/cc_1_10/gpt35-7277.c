//FormAI DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent an ebook
typedef struct {
    char* title;
    char* author;
    int pageCount;
    char** pages;
} Ebook;

// Define a function to read an ebook from a file
Ebook* readEbookFromFile(char* filename) {
    Ebook* ebook = (Ebook*)malloc(sizeof(Ebook));
    FILE* fp = fopen(filename, "r");

    // Read title, author, and page count from the first 3 lines
    char* title = (char*)malloc(255);
    char* author = (char*)malloc(255);
    int pageCount;
    fscanf(fp, "%s", title);
    fscanf(fp, "%s", author);
    fscanf(fp, "%d", &pageCount);

    ebook->title = title;
    ebook->author = author;
    ebook->pageCount = pageCount;

    // Allocate space for the array of pages
    char** pages = (char**)malloc(sizeof(char*) * pageCount);

    // Read each page from the file
    for (int i = 0; i < pageCount; i++) {
        char* page = (char*)malloc(255);
        fscanf(fp, "%s", page);
        pages[i] = page;
    }

    ebook->pages = pages;

    return ebook;
}

// Define a function to display the ebook
void displayEbook(Ebook* ebook, int currentPage) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Page %d of %d:\n\n", currentPage, ebook->pageCount);
    printf("%s\n", ebook->pages[currentPage - 1]);
}

int main() {
    Ebook* ebook = readEbookFromFile("book.txt");
    int currentPage = 1;
    
    while (1) {
        displayEbook(ebook, currentPage);
        printf("\nPress 'n' for next page, 'p' for previous page, or 'q' to quit: ");
        char choice = getchar();

        if (choice == 'n') {
            if (currentPage < ebook->pageCount) {
                currentPage++;
            }
        } else if (choice == 'p') {
            if (currentPage > 1) {
                currentPage--;
            }
        } else if (choice == 'q') {
            break;
        }
    }

    return 0;
}