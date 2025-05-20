//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Our virtual ebook
typedef struct eBook {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} eBook;

// Loads an ebook from a file
eBook* load_ebook(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }

    // Read the title and author
    char title[256];
    char author[256];
    fscanf(fp, "%s %s", title, author);

    // Read the number of pages
    int num_pages;
    fscanf(fp, "%d", &num_pages);

    // Allocate memory for the ebook
    eBook *book = malloc(sizeof(eBook));
    book->title = malloc(strlen(title) + 1);
    book->author = malloc(strlen(author) + 1);
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(char*) * num_pages);

    // Read the pages
    for (int i = 0; i < num_pages; i++) {
        char page[256];
        fscanf(fp, "%s", page);
        book->pages[i] = malloc(strlen(page) + 1);
        strcpy(book->pages[i], page);
    }

    fclose(fp);
    return book;
}

// Unloads an ebook
void unload_ebook(eBook *book) {
    // Free the pages
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }

    // Free the ebook
    free(book->pages);
    free(book->author);
    free(book->title);
    free(book);
}

// Prints the ebook's information
void print_ebook_info(eBook *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
}

// Prints a specific page
void print_page(eBook *book, int page_num) {
    if (page_num < 1 || page_num > book->num_pages) {
        printf("Invalid page number: %d\n", page_num);
        return;
    }

    printf("Page %d:\n", page_num);
    printf("%s\n", book->pages[page_num - 1]);
}

// Main function
int main() {
    // Load an ebook
    eBook *book = load_ebook("ebook.txt");
    if (!book) {
        printf("Error loading ebook.\n");
        return -1;
    }

    // Print the ebook's information
    print_ebook_info(book);

    // Print a specific page
    print_page(book, 3);

    // Unload the ebook
    unload_ebook(book);

    return 0;
}