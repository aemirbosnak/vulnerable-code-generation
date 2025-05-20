//FormAI DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGE_SIZE 1024
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char *title;
    char *author;
    int total_pages;
    char **pages;
} Ebook;

/* Function to load an Ebook from a file */
Ebook *load_ebook(char *filename) {
    Ebook *ebook = malloc(sizeof(Ebook));
    char buffer[MAX_PAGE_SIZE], *page;
    int i, page_count = 0;
    FILE *file = fopen(filename, "r");

    /* Read the title and author from the first two lines */
    fgets(buffer, MAX_PAGE_SIZE, file);
    ebook->title = strdup(buffer);
    fgets(buffer, MAX_PAGE_SIZE, file);
    ebook->author = strdup(buffer);

    /* Count the number of pages */
    while (fgets(buffer, MAX_PAGE_SIZE, file) != NULL) {
        ++page_count;
    }

    /* Allocate memory for the pages */
    ebook->pages = malloc(page_count * sizeof(char*));
    rewind(file);

    /* Skip the first two lines */
    fgets(buffer, MAX_PAGE_SIZE, file);
    fgets(buffer, MAX_PAGE_SIZE, file);

    /* Read the pages */
    for (i = 0; i < page_count; ++i) {
        fgets(buffer, MAX_PAGE_SIZE, file);
        page = strdup(buffer);
        ebook->pages[i] = page;
    }

    ebook->total_pages = page_count;
    fclose(file);
    return ebook;
}

/* Function to print the Ebook information */
void print_ebook(Ebook *ebook) {
    int i;
    printf("Title: %s", ebook->title);
    printf("Author: %s", ebook->author);
    printf("Total Pages: %d\n\n", ebook->total_pages);

    for (i = 0; i < ebook->total_pages; ++i) {
        printf("Page %d:\n%s\n", i + 1, ebook->pages[i]);
    }
}

/* Main function to test the program */
int main() {
    char filename[MAX_FILENAME_LENGTH];
    Ebook *ebook;

    /* Ask the user for the filename */
    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    strtok(filename, "\n");

    /* Load the Ebook */
    ebook = load_ebook(filename);

    /* Print the Ebook information */
    print_ebook(ebook);

    /* Free the memory */
    free(ebook->title);
    free(ebook->author);

    int i;
    for (i = 0; i < ebook->total_pages; ++i) {
        free(ebook->pages[i]);
    }

    free(ebook->pages);
    free(ebook);

    return 0;
}